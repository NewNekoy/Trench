#include "Core.h"

Player::Player()
{
    sprite.setSize(Vector2f(64, 64));
    sprite.setFillColor(Color::Green);
    _speed = 255;
}

Player::~Player()
{

}
