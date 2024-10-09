// SpaceshipScene.h
#ifndef SPACESHIPSCENE_H
#define SPACESHIPSCENE_H

#include "Scene.h"
#include "Spaceship.h" 

class SpaceshipScene : public Scene {
private:
    Spaceship spaceship;

public:
    SpaceshipScene();
    ~SpaceshipScene();
    void Update() override;
    void Draw() override;
};

#endif // SPACESHIPSCENE_H
