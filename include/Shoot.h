#ifndef SHOOT_H
#define SHOOT_H

#include "Core.h"

class Shoot
{
public:
    Shoot();
    ~Shoot();

    class Bullet
    {
    public:
        float angleShot;
        CircleShape shape;
    };

    void use(Core *core);
    void input(Core *core, Vector2f pos);


    Bullet _bullet_type;
    vector<Bullet> _projectiles;
    float _cooldown;
    sf::Clock _timer;
    float _speed, _size;
    int _damage;
};

#endif // SHOOT_H
