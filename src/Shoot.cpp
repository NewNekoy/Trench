#include "Shoot.h"
#include <cmath>

Shoot::Shoot()
{
    _cooldown = 400;
    _speed = 600;
    _size = 8.f;
    _bullet_type.shape.setFillColor(Color::Magenta);
    _bullet_type.shape.setRadius(_size);

}

void Shoot::use(Core *core)
{
    for(size_t i = 0; i < _projectiles.size(); i++)
    {
        _projectiles[i].shape.move(cos(_projectiles[i].angleShot) * _speed * core->dt, 0);
        _projectiles[i].shape.move(0, sin(_projectiles[i].angleShot) * _speed * core->dt);
    }
}

void Shoot::input(Core *core, Vector2f pos)
{
    if (_timer.getElapsedTime().asMilliseconds() >= _cooldown)
    {
        _bullet_type.shape.setPosition(pos);
        Vector2f mousePosition = core->sfml->window.mapPixelToCoords(Mouse::getPosition(core->sfml->window));
        _bullet_type.angleShot = atan2(mousePosition.y - _bullet_type.shape.getPosition().y,
                                mousePosition.x - _bullet_type.shape.getPosition().x);
        _projectiles.push_back(_bullet_type);
        _timer.restart();
    }
    cout << "CAN'T SHOOT, TIME IS " + to_string(_timer.getElapsedTime().asMilliseconds()) << "/" + to_string(_cooldown) << endl;
}

Shoot::~Shoot()
{
    //dtor
}
