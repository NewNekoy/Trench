#ifndef SERV_H
#define SERV_H

#include "Scene.h"
#include "Core.h"
#include <algorithm>

class Player
{
public:
    Player();
    ~Player();

    RectangleShape sprite;
    float _speed;
    string name;
};

class Serv : public Scene
{
public:
    Serv(Core *core);
    ~Serv();

    void movement(Core *core);
    void use(Core *core);
    void fillPlayer(Core *core);
    void updatePlayer(Core *core);
    void updateMe(Core *core);
private:
    Player me;
    vector<Player> other;
    float dt;
    sf::Clock dtClock;
    Vector2f mePreviously;
};

#endif // SERV_H
