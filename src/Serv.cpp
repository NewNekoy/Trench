#include "Serv.h"
#include "Shoot.h"

Serv::Serv(Core *core) : Scene(core)
{
    vector<vector<string>> OtherPlayers = core->sql->GETTER("SELECT * FROM Player WHERE name!='" + core->_username + "'");

    Player temp;
    temp.sprite.setSize(Vector2f(64, 64));
    temp.sprite.setFillColor(Color::Red);

    for(size_t i = 0; i < OtherPlayers.size(); i++)
    {
        temp.name = OtherPlayers[i][1];
        temp.sprite.setPosition(Vector2f(stof(OtherPlayers[i][2]), stof(OtherPlayers[i][3])));
        other.push_back(temp);
    }

    view = core->sfml->window.getView();
    view.zoom(2.f);

    me.name = core->_username;
}

void Serv::fillPlayer(Core *core)
{
    string query = "SELECT * FROM Player WHERE name!='" + core->_username + "' ";
    for (size_t i = 0; i < other.size(); i++)
    {
        query = query + "AND name!='" + other[i].name + "' ";
    }
    vector<vector<string>> morePlayers = core->sql->GETTER(query);

    Player temp;
    temp.sprite.setSize(Vector2f(64, 64));
    temp.sprite.setFillColor(Color::Red);

    for(size_t i = 0; i < morePlayers.size(); i++)
    {
        temp.name = morePlayers[i][1];
        temp.sprite.setPosition(Vector2f(stof(morePlayers[i][2]), stof(morePlayers[i][3])));
        other.push_back(temp);
        cout << temp.name + " JUST CONNECT !" << endl;
    }

    query = "SELECT * FROM Player";
    vector<vector<string>> playerList = core->sql->GETTER(query);

    vector<Player> test = other;

    for(size_t i = 0; i < playerList.size(); i++)
    {
        for (size_t j = 0; j < test.size(); j++)
        {
            if (playerList[i][1] == test[j].name)
            {
                test.erase(test.begin() + j);
            }
        }
    }

    for(size_t i = 0; i < test.size(); i++)
    {
        for(size_t j = 0; j < other.size(); j++)
        {
            if (other[j].name == test[i].name)
            {
                other.erase(other.begin() + j);
                cout << test[i].name + " DISCONNECTED !" << endl;
            }
        }
    }
}

void Serv::updatePlayer(Core *core)
{
    vector<vector<string>> OtherPlayers = core->sql->GETTER("SELECT * FROM Player WHERE name!='" + core->_username + "'");

    for(size_t i = 0; i < OtherPlayers.size(); i++)
    {
        for (size_t j = 0; j < other.size(); j++)
        {
            if (other[j].name == OtherPlayers[i][1])
            {
                if (other[j].sprite.getPosition().x != stof(OtherPlayers[i][2]) ||
                    other[j].sprite.getPosition().y != stof(OtherPlayers[i][3]))
                    {
                        other[j].sprite.setPosition(Vector2f(stof(OtherPlayers[i][2]), stof(OtherPlayers[i][3])));
                        cout << "POSITION UPDATE FOR : " + other[j].name << endl;
                    }
            }
        }
    }
}

void Serv::updateMe(Core *core)
{
    if (mePreviously != me.sprite.getPosition())
    {
        string query = "UPDATE Player SET posX = " + to_string(me.sprite.getPosition().x) + ", posY = " + to_string(me.sprite.getPosition().y) + " WHERE name = '" + core->_username + "'";
        core->sql->EXECUTE(query);
        cout << "UPDATE ME POSITION !" << endl;
    }
    mePreviously = me.sprite.getPosition();
}

void Serv::use(Core *core)
{
    core->dt = core->dtClock.restart().asSeconds();
    Event event;
    while(core->sfml->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) core->switchScene(-1);

    }
    me.movement(core);


    fillPlayer(core);
    updatePlayer(core);

    updateMe(core);

    me._shoot->use(core);



    view.setCenter(me.sprite.getPosition().x + me.sprite.getSize().x / 2,
                        me.sprite.getPosition().y + me.sprite.getSize().y / 2);
    core->sfml->window.setView(view);


    core->sfml->window.clear(sf::Color::White);

    core->sfml->window.draw(me.sprite);
    //core->sfml->printText(core->_username, {me.sprite.getPosition().x - (me.sprite.getSize().x / 2), me.sprite.getPosition().y - 32}, 35, Color::Black);

    for(size_t i = 0 ; i < other.size(); i++)
    {
        core->sfml->window.draw(other[i].sprite);
    }

    for(size_t i = 0; i < me._shoot->_projectiles.size(); i++)
    {
        core->sfml->window.draw(me._shoot->_projectiles[i].shape);
    }

    core->sfml->window.display();
}

Serv::~Serv()
{
    //dtor
}
