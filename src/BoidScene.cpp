// BoidScene.cpp
#include "BoidScene.h"


BoidScene::BoidScene() {}

BoidScene::~BoidScene() {}

void BoidScene::Update() {
    boid.Update();
}

void BoidScene::Draw() {
    ClearBackground(NAVYBLUE);
    DrawText("Boid Scene", 50, 50, 25, RAYWHITE);
}
