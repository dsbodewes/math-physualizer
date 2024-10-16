#include "AimingSystemScene.h"

AimingSystemScene::AimingSystemScene() {}

AimingSystemScene::~AimingSystemScene() {}

void AimingSystemScene::Update() {}

void AimingSystemScene::Draw() {
    ClearBackground(NAVYBLUE);
    DrawText("Aiming System Scene", 50, 50, 25, RAYWHITE);
    DrawText("Press BACKSPACE to return to menu", 50, 75, 25, RAYWHITE);
}
