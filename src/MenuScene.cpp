// MenuScene.cpp
#include "MenuScene.h"

MenuScene::MenuScene() {}

MenuScene::~MenuScene() {}

void MenuScene::Update() {
    // Menu logic (could add keyboard inputs for scene transitions)
}

void MenuScene::Draw() {
    DrawText("Press 1 to start Spaceship", 100, 100, 50, RAYWHITE);
    DrawText("Press 2 to start Pendulum", 100, 180, 50, RAYWHITE);
    DrawText("Press 3 to start Double Pendulum", 100, 260, 50, RAYWHITE);
    DrawText("Press 4 to start Boids", 100, 340, 50, RAYWHITE);
    DrawText("Press BACKSPACE to return to menu", 100, 420, 50, RAYWHITE);
}
