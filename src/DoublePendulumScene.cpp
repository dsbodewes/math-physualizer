// DoublePendentulumScene.cpp
#include "DoublePendulumScene.h"

DoublePendulumScene::DoublePendulumScene() : doublePendulum({800, -20}, 380.0f, 290.0f, 20.0f, 4.5f) {}  

DoublePendulumScene::~DoublePendulumScene() {}

void DoublePendulumScene::Update() {
    doublePendulum.Update();
}

void DoublePendulumScene::Draw() {
    ClearBackground(NAVYBLUE);
    doublePendulum.Draw();
    DrawText("Double Pendulum Scene", 50, 50, 20, WHITE);
}
