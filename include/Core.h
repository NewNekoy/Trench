#ifndef CORE_H
#define CORE_H

#include "SQL_Gestion.h"
#include "SFML_Gestion.h"
#include "Scene.h"
#include "Serv.h"

class Core
{
public:
    Core();
    ~Core();

    void switchScene(int id);
    void run();
    void premice();
    SFML_Gestion *sfml;
    SQL_Gestion *sql;

    string _username;
    Clock dtClock;
    float dt;
private:
    Scene *scene;
    int _id;

};

#endif // CORE_H
