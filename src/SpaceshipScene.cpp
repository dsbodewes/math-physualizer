// SpaceshipScene.cpp
#include "SpaceshipScene.h"

SpaceshipScene::SpaceshipScene() : spaceship({800, 400}, 50.0f) {}

SpaceshipScene::~SpaceshipScene() {}

void SpaceshipScene::Update() {
    spaceship.Update();  
}

void SpaceshipScene::Draw() {
    ClearBackground(ORANGE2);
    spaceship.Draw();    
}
