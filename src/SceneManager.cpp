// SceneManager.cpp
#include "SceneManager.h"

SceneManager::SceneManager() : currentScene(nullptr) {}

SceneManager::~SceneManager() {}

void SceneManager::ChangeScene(Scene* newScene) {
    if (currentScene != newScene) {
        currentScene = newScene; // Simply switch to the new scene without deleting
    }
}

void SceneManager::Update() {
    if (currentScene != nullptr) {
        currentScene->Update();
    }
}

void SceneManager::Draw() {
    if (currentScene != nullptr) {
        currentScene->Draw();
    }
}
