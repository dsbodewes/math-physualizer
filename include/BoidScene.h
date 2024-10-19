// BoidScene.h
#ifndef BOIDSCENE_H
#define BOIDSCENE_H

#include "Scene.h"
#include "Boid.h"
#include <vector>

class BoidScene : public Scene {
public:
    BoidScene();
    ~BoidScene();
    void Update() override;
    void Draw() override;

private:
    Boid boid;
};

#endif // BOIDSCENE_H
