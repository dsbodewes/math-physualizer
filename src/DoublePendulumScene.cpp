// DoublePendentulumScene.cpp
#include "DoublePendulumScene.h"

DoublePendulumScene::DoublePendulumScene() : doublePendulum({800, -20}, 400.0f, 350.0f, 12.0f, 4.0f) {}  

DoublePendulumScene::~DoublePendulumScene() {}

void DoublePendulumScene::Update() {
    doublePendulum.Update();
}

void DoublePendulumScene::Draw() {
    ClearBackground(NAVYBLUE);
    doublePendulum.Draw();
    DrawText("Double Pendulum Scene", 50, 50, 20, WHITE);
}
