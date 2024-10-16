// PendulumScene.cpp
#include "PendulumScene.h"

PendulumScene::PendulumScene() : pendulum({800, 200}, 400.0f) {}  

PendulumScene::~PendulumScene() {}

void PendulumScene::Update() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        pendulum.ApplyForce(0.1f);
    }
    pendulum.Update();
}

void PendulumScene::Draw() {
    ClearBackground(NAVYBLUE);
    pendulum.Draw();
    DrawText("LEFT-CLICK to add force", 50, 50, 25, RAYWHITE);  
}
