// PendulumScene.h
#ifndef PENDULUMSCENE_H
#define PENDULUMSCENE_H

#include "Scene.h"
#include "Pendulum.h" 

class PendulumScene : public Scene {
private:
    Pendulum pendulum;

public:
    PendulumScene();
    ~PendulumScene();
    void Update() override;
    void Draw() override;
};

#endif // PENDULUMSCENE_H
