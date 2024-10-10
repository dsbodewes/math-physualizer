// PendulumScene.cpp
#include "PendulumScene.h"

PendulumScene::PendulumScene() : pendulum() {}

PendulumScene::~PendulumScene() {}

void PendulumScene::Update() {
    pendulum.Update();
}

void PendulumScene::Draw() {
    ClearBackground(VIOLET);  
}
