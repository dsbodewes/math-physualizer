// DoublePendulumScene.cpp
#ifndef DOUBLEPENDULUMSCENE_H
#define DOUBLEPENDULUMSCENE_H

#include "Scene.h"
#include "DoublePendulum.h" 

class DoublePendulumScene : public Scene {
public:
    DoublePendulumScene();
    ~DoublePendulumScene();

    void Update() override;
    void Draw() override;

private:
    DoublePendulum doublePendulum;
};

#endif // DOUBlEPENDULUMSCENE_H
