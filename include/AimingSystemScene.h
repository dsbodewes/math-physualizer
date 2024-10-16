// AimingSystemScene.h
#ifndef AIMINGSYSTEMSCENE_H
#define AIMINGSYSTEMSCENE_H

#include "Scene.h"
#include "AimingSystem.h" 

class AimingSystemScene : public Scene {
public:
    AimingSystemScene();
    ~AimingSystemScene();
    void Update() override;
    void Draw() override;

private:
    AimingSystem aimingSystem;
};

#endif // AIMINGSYSTEMSCENE_H
