#include "Serv.h"

Player::Player()
{
    sprite.setSize(Vector2f(64, 64));
    sprite.setFillColor(Color::Green);
    _speed = 255;
}

Player::~Player()
{

}

Serv::Serv(Core *core) : Scene(core)
{
    vector<vector<string>> OtherPlayers = core->sql->GETTER("SELECT * FROM Player WHERE name!='" + core->_username + "'");

    Player temp;
    temp.sprite.setSize(Vector2f(64, 64));
    temp.sprite.setFillColor(Color::Red);

    for(int i = 0; i < OtherPlayers.size(); i++)
    {
        temp.name = OtherPlayers[i][1];
        temp.sprite.setPosition(Vector2f(stoi(OtherPlayers[i][2]), stoi(OtherPlayers[i][3])));
        other.push_back(temp);
    }

    me.name = core->_username;
}

void Serv::movement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        me.sprite.move({me._speed * dt, 0.0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        me.sprite.move(-me._speed * dt, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        me.sprite.move(0.0f, -me._speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        me.sprite.move(0.0f, me._speed * dt);
    }
}

void Serv::fillPlayer(Core *core)
{

}

void Serv::updatePlayer(Core *core)
{

}

void Serv::use(Core *core)
{
    dt = dtClock.restart().asSeconds();
    while(core->sfml->window.pollEvent(core->sfml->event))
    {
        if (core->sfml->event.type == sf::Event::Closed) core->switchScene(-1);
    }

    movement();
    fillPlayer(core);

    core->sfml->window.clear(sf::Color::White);

    core->sfml->window.draw(me.sprite);
    core->sfml->printText(me.name, {me.sprite.getPosition().x - (me.sprite.getSize().x / 2), me.sprite.getPosition().y - 32}, 35, Color::Black);

    for(int i = 0 ; i < other.size(); i++)
    {
        core->sfml->window.draw(other[i].sprite);
        core->sfml->printText(other[i].name, {other[i].sprite.getPosition().x - (other[i].sprite.getSize().x / 2), other[i].sprite.getPosition().y - 32}, 35, Color::Black);

    }

    core->sfml->window.display();
}

Serv::~Serv()
{
    //dtor
}
