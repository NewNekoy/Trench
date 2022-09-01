#ifndef SERV_H
#define SERV_H

#include "Scene.h"
#include "Core.h"

class Serv : public Scene 
{
    public:
        Serv();
        ~Serv();

    void use(Core *core);
};

#endif // SERV_H
