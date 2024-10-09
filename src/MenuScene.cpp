// MenuScene.cpp
#include "MenuScene.h"

MenuScene::MenuScene() {}

MenuScene::~MenuScene() {}

void MenuScene::Update() {
    // Menu logic (could add keyboard inputs for scene transitions)
}

void MenuScene::Draw() {
    DrawText("Press 1 to start Spaceship", 100, 100, 50, YELLOW);
    DrawText("Press BACKSPACE to return to menu", 100, 175, 50, YELLOW);
}
