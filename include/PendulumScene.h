// PendulumScene.h
#ifndef PENDULUMSCENE_H
#define PENDULUMSCENE_H

#include "Scene.h"
#include "Pendulum.h" 

class PendulumScene : public Scene {
public:
    PendulumScene();
    ~PendulumScene();
    void Update() override;
    void Draw() override;

private:
    Pendulum pendulum;
};

#endif // PENDULUMSCENE_H
