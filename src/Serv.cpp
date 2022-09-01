#include "Serv.h"

Serv::Serv()
{
    //ctor
}

void Serv::use(Core *core)
{
    while(core->sfml->window.pollEvent(core->sfml->event))
    {
        if (core->sfml->event.type == sf::Event::Closed) core->switchScene(-1);
    }

    core->sfml->window.clear(sf::Color::White);
    core->sfml->window.display();
}

Serv::~Serv()
{
    //dtor
}
