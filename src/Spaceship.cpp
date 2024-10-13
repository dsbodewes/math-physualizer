// Spaceship.cpp
#include "Spaceship.h"
#include <cmath>
#include <iostream>

// Constructor
Spaceship::Spaceship(Vector2 initPosition, float initSpeed) {
    position = initPosition;
    speed = initSpeed;
    angle = 0.0f; // Starts facing upwards
    velocity = { 0.0f, 0.0f }; 
}

void Spaceship::HandleInput() {
    if(IsKeyDown(KEY_A)) {
        angle -= 3.0f;
    }

    if(IsKeyDown(KEY_D)) {
        angle += 3.0f;
    }

    // Thrust (based on angle)
    if (IsKeyDown(KEY_W)) {
        // Adjust the angle for the ship's orientation (starts pointing up, so subtract 90 degrees)
        float radians = (angle - 90) * DEG2RAD;

        // Apply thrust in the direction of the angle
        velocity.x += cosf(radians) * speed * GetFrameTime();
        velocity.y += sinf(radians) * speed * GetFrameTime();
    }

    // Velocity damping to prevent infinite acceleration
    velocity.x *= 0.95f;
    velocity.y *= 0.95f;
}

void Spaceship::Update() {
    HandleInput();

    // Update position
    position.x += velocity.x;
    position.y += velocity.y;

    // Screen wrap
    if (position.x > GetScreenWidth()) position.x = 0;
    if (position.x < 0) position.x = GetScreenWidth();
    if (position.y > GetScreenHeight()) position.y = 0;
    if (position.y < 0) position.y = GetScreenHeight();
}

// Draw the spaceship on the screen
void Spaceship::Draw() {
    float shipLength = 80.0f;   // Length of the spaceship (triangle height)
    float shipWidth = 70.0f;    // Width of the spaceship's base (triangle width)

    // Define original (unrotated) triangle vertices relative to the spaceship's position
    Vector2 v1 = { 0, -shipLength };  // Top vertex (front)
    Vector2 v2 = { -shipWidth / 2, shipLength / 2 };  // Bottom left vertex
    Vector2 v3 = { shipWidth / 2, shipLength / 2 };   // Bottom right vertex

    // Rotation function to rotate a point around a center
    auto rotatePoint = [](Vector2 point, float angleDeg, Vector2 origin) {
        float angleRad = angleDeg * DEG2RAD;
        float cosA = cosf(angleRad);
        float sinA = sinf(angleRad);
        return Vector2{
            origin.x + point.x * cosA - point.y * sinA,
            origin.y + point.x * sinA + point.y * cosA
        };
    };

    // Apply rotation to each vertex, rotating around the spaceship's current position
    Vector2 rotatedV1 = rotatePoint(v1, angle, position);
    Vector2 rotatedV2 = rotatePoint(v2, angle, position);
    Vector2 rotatedV3 = rotatePoint(v3, angle, position);

    // Draw the spaceship as a triangle with the rotated vertices
    DrawTriangle(rotatedV1, rotatedV2, rotatedV3, DARKBLUE);
}
