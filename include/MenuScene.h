// MenuScene.h
#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "Scene.h"
#include "raylib.h"

class MenuScene : public Scene {
public:
    MenuScene();
    ~MenuScene();
    void Update() override;
    void Draw() override;
};

#endif // MENUSCENE_H
