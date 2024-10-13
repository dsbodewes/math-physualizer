// SpaceshipScene.h
#ifndef SPACESHIPSCENE_H
#define SPACESHIPSCENE_H

#include "Scene.h"
#include "Spaceship.h" 

class SpaceshipScene : public Scene {
public:
    SpaceshipScene();
    ~SpaceshipScene();
    void Update() override;
    void Draw() override;

private:
    Spaceship spaceship;
};

#endif // SPACESHIPSCENE_H
