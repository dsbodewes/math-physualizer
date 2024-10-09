// SceneManager.cpp
#include "SceneManager.h"
#include <iostream>

SceneManager::SceneManager() : currentScene(nullptr) {}

SceneManager::~SceneManager() {
    delete currentScene;
}

void SceneManager::ChangeScene(Scene* newScene) {
    delete currentScene;
    currentScene = newScene;
}

void SceneManager::Update() {
    if (currentScene) currentScene->Update();
}

void SceneManager::Draw() {
    if (currentScene) currentScene->Draw();
}
