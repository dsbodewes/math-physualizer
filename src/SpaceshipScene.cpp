// SpaceshipScene.cpp
#include "SpaceshipScene.h"

SpaceshipScene::SpaceshipScene() : spaceship({800, 400}, 50.0f) {

}

SpaceshipScene::~SpaceshipScene() {}

void SpaceshipScene::Update() {
    spaceship.Update();  
}

void SpaceshipScene::Draw() {
    ClearBackground(NAVYBLUE);
    spaceship.Draw();
    DrawText("A and D to rotate", 50, 50, 25, RAYWHITE);  
    DrawText("W to thrust", 50, 75, 25, RAYWHITE);        
}
