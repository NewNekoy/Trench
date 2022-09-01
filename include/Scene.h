#ifndef SCENE_H
#define SCENE_H

class Core;

class Scene
{
    public:
        Scene();
        virtual ~Scene();
        virtual void use(Core *core);
};

#endif // SCENE_H
