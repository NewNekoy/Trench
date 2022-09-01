#include "Core.h"
#include "Shoot.h"

Player::Player()
{
    sprite.setSize(Vector2f(64, 64));
    sprite.setFillColor(Color::Green);
    _speed = 255;
    _shoot = new Shoot();
}

void Player::movement(Core *core)
{
    if (!core->sfml->window.hasFocus()) return;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move({_speed * core->dt, 0.0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        sprite.move(-_speed * core->dt, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        sprite.move(0.0f, -_speed * core->dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(0.0f, _speed * core->dt);
    }
    /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        _shoot->input(core, {sprite.getPosition().x + sprite.getSize().x / 2,
                    sprite.getPosition().y + sprite.getSize().y / 2});
    }*/
}

Player::~Player()
{

}
