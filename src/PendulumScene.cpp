// PendulumScene.cpp
#include "PendulumScene.h"

PendulumScene::PendulumScene() : pendulum({800, -20}, 500.0f) {}  

PendulumScene::~PendulumScene() {}

void PendulumScene::Update() {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        pendulum.ApplyForce(0.02f);
    }
    if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
        pendulum.ApplyForce(-0.01f);
    }
    pendulum.Update();
}

void PendulumScene::Draw() {
    ClearBackground(NAVYBLUE);
    pendulum.Draw();
    DrawText("LEFT-CLICK to add force", 50, 50, 25, RAYWHITE); 
    DrawText("SHIFT for Double Pendulum", 50, 100, 25, RAYWHITE); 
}
