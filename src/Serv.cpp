#include "Serv.h"

Serv::Serv()
{
    me.setSize(Vector2f(64, 64));
    me.setFillColor(Color::Red);
    _speed = 200;
}

void Serv::movement()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        me.move({_speed * dt, 0.0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        me.move(-_speed * dt, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        me.move(0.0f, -_speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        me.move(0.0f, _speed * dt);
    }
}

void Serv::use(Core *core)
{
    dt = dtClock.restart().asSeconds();
    while(core->sfml->window.pollEvent(core->sfml->event))
    {
        if (core->sfml->event.type == sf::Event::Closed) core->switchScene(-1);
    }

    movement();

    core->sfml->window.clear(sf::Color::White);

    core->sfml->window.draw(me);

    core->sfml->window.display();
}

Serv::~Serv()
{
    //dtor
}
