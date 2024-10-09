// Scene.h
#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual ~Scene() {}
};

#endif // SCENE_H
