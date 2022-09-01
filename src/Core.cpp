#include "Core.h"

Core::Core()
{
    sql = new SQL_Gestion();
}

void Core::premice()
{
    string username;
    string password;
    while(1)
    {
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;

        if (sql->checkConnection(username, password))
        {
            break;
        }
        cout << "Invalid Username or Password !" << endl;
    }

    _username = username;

    cout << "Connected !" << endl;
    cout << "Joining World..." << endl;

    sql->EXECUTE("INSERT INTO Player(name) VALUES ('" + username + "')");

    sfml = new SFML_Gestion();
    scene = new Serv();

    run();
}

void Core::switchScene(int id)
{
    if (id == -1) sfml->close();
    if (id == 0) scene = new Serv();
}

void Core::run()
{
    while (sfml->window.isOpen())
    {
        scene->use(this);
    }
}

Core::~Core()
{
    sql->EXECUTE("DELETE FROM Player WHERE name='" + _username + "'");
}
