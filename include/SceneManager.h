// SceneManager.h
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"

class SceneManager {
public:
    SceneManager();
    ~SceneManager();
    void ChangeScene(Scene* newScene);
    void Update();
    void Draw();

private:
    Scene* currentScene;
};

#endif // SCENEMANAGER_H
