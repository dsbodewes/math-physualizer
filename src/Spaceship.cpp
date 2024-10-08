// Spaceship.cpp
#include "Spaceship.h"
#include <cmath>
#include <iostream>

// Constructor
Spaceship::Spaceship(Vector2 initPosition, float initSpeed) {
    position = initPosition;
    speed = initSpeed;
    angle = { 0.0f }; // Starts facing upwards
    velocity = { 0.0f, 0.0f }; // Starts with no velocity
}

void Spaceship::HandleInput() {
    // Rotate left
    if(IsKeyDown(KEY_A)){
        angle -= 2.0f;
    }

    // Rotate right
    if(IsKeyDown(KEY_D)){
        angle += 2.0f;
    }

    // Thrust (based on angle)
    if(IsKeyDown(KEY_W)){
        // Convert angle to radians 
        float radians = angle * DEG2RAD; // DEG2RAD = M_PI / 180

        velocity.x += std::cos(radians) * speed * GetFrameTime(); 
        velocity.y += std::sin(radians) * speed * GetFrameTime();
    }
}

void Spaceship::Update() {
    HandleInput();

    position.x += velocity.x;
    position.y += velocity.y;

    // Screen wrap
    if (position.x > GetScreenWidth()) position.x = 0;
    if (position.x < 0) position.x = GetScreenWidth();
    if (position.y > GetScreenHeight()) position.y = 0;
    if (position.y < 0) position.y = GetScreenHeight();

    std::cout << "Position: (" << position.x << ", " << position.y << ")" << std::endl;
}

// Draw the spaceship on the screen
void Spaceship::Draw() {
    // Draw a simple triangle for the spaceship
    Vector2 v1 = { position.x + 20 * cosf((angle - 90) * DEG2RAD), position.y + 20 * sinf((angle - 90) * DEG2RAD) };
    Vector2 v2 = { position.x + 20 * cosf((angle + 120) * DEG2RAD), position.y + 20 * sinf((angle + 120) * DEG2RAD) };
    Vector2 v3 = { position.x + 20 * cosf((angle - 120) * DEG2RAD), position.y + 20 * sinf((angle - 120) * DEG2RAD) };

    DrawTriangle(v1, v2, v3, RED);
}

