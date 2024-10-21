// main.cpp
#include "raylib.h"
#include "SceneManager.h"
#include "MenuScene.h"
#include "SpaceshipScene.h"
#include "PendulumScene.h"
#include "BoidScene.h"

int main() {
    const int screenWidth = 1600;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Math-Visualization");

    SetTargetFPS(60);

    // Create the scene manager and scenes
    SceneManager sceneManager;

    // Initialize all scenes once
    SpaceshipScene spaceshipScene;
    PendulumScene pendulumScene;
    BoidScene boidScene;
    MenuScene menuScene;

    // Set initial scene to menu
    sceneManager.ChangeScene(&menuScene);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update and draw the current scene
        sceneManager.Update();

        BeginDrawing();
        ClearBackground(NAVYBLUE);
        sceneManager.Draw();
        EndDrawing();

        // Scene switching logic
        if (IsKeyPressed(KEY_ONE)) {
            sceneManager.ChangeScene(&spaceshipScene);  // Switch to SpaceshipScene
        }
        if (IsKeyPressed(KEY_TWO)) {
            sceneManager.ChangeScene(&pendulumScene);  // Switch to PendulumScene
        }
        if (IsKeyPressed(KEY_THREE)) {
            sceneManager.ChangeScene(&boidScene);  // Switch to BoidScene
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            sceneManager.ChangeScene(&menuScene);  // Switch back to MenuScene
        }
    }

    // Close window and clean up
    CloseWindow();

    return 0;
}
