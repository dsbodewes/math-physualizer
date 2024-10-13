// PendulumScene.cpp
#include "PendulumScene.h"

PendulumScene::PendulumScene() 
    : pendulum({800, 200}, 500.0f)  // Create the pendulum with origin at (800, 200) and length 300
{}

PendulumScene::~PendulumScene() {}

void PendulumScene::Update() {
    pendulum.Update();
}

void PendulumScene::Draw() {
    ClearBackground(DARKPURPLE);  
    pendulum.Draw();
}
