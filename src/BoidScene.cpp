// BoidScene.cpp
#include "BoidScene.h"


BoidScene::BoidScene() {
    // Initialize boids with random positions and velocities
    for (int i = 0; i < 100; i++) {
        Vector2 randomPosition = {(float)(GetRandomValue(0, GetScreenWidth())), (float)(GetRandomValue(0, GetScreenHeight()))};
        Vector2 randomVelocity = {(float)(GetRandomValue(-100, 100) / 100.0), (float)(GetRandomValue(-100, 100) / 100.0)};
        boids.push_back(Boid(randomPosition, randomVelocity));
    }
}

BoidScene::~BoidScene() {}

void BoidScene::Update() {
    for (Boid& boid : boids) {
        boid.Update(boids);
    }
}

void BoidScene::Draw() {
    ClearBackground(NAVYBLUE);
    for (const Boid& boid : boids) {
        boid.Draw();
    }
    DrawText("Boid Scene", 50, 50, 25, RAYWHITE);
}
