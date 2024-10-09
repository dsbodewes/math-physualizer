// SceneManager.h
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"

class SceneManager {
private:
    Scene* currentScene;

public:
    SceneManager();
    ~SceneManager();
    void ChangeScene(Scene* newScene);
    void Update();
    void Draw();
};

#endif // SCENEMANAGER_H
