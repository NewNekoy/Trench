#ifndef SCENE_H
#define SCENE_H

class Core;

class Scene
{
    public:
        Scene(Core *core);
        virtual ~Scene();
        virtual void use(Core *core);
};

#endif // SCENE_H
