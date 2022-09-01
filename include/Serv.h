#ifndef SERV_H
#define SERV_H

#include "Scene.h"
#include "Core.h"
#include <algorithm>

class Shoot;

class Player
{
public:
    Player();
    ~Player();

    void movement(Core *core);

    RectangleShape sprite;
    float _speed;
    string name;
    Shoot *_shoot;
};

class Serv : public Scene
{
public:
    Serv(Core *core);
    ~Serv();

    void use(Core *core);
    void fillPlayer(Core *core);
    void updatePlayer(Core *core);
    void updateMe(Core *core);
private:
    Player me;
    vector<Player> other;
    Vector2f mePreviously;
    View view;
};

#endif // SERV_H
