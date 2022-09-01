#ifndef SERV_H
#define SERV_H

#include "Scene.h"
#include "Core.h"

class Serv : public Scene
{
public:
    Serv();
    ~Serv();

    void movement();
    void use(Core *core);
private:
    sf::RectangleShape me;
    float dt;
    sf::Clock dtClock;
    float _speed;
};

#endif // SERV_H
