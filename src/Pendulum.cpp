// Pendulum.cpp
#include "Pendulum.h"
#include <cmath>
#include <iostream>

// Constructor
Pendulum::Pendulum(Vector2 initOrigin, float initLength) {
    origin = initOrigin;
    length = initLength;
    angle = PI / 4; // Starts at 45 degrees
    angularVelocity = 0.0f;
    angularAcceleration = 0.0f;
    gravity = 9.81f; // Earth's gravity

    // Calculate initial position of the pendulum bob
    position = { origin.x + length * sinf(angle), origin.y + length * cosf(angle) };
}

void Pendulum::ApplyForce(float force) {
    angularVelocity += force; // Adjust angular velocity based on the force applied
}    

void Pendulum::Update() {
    angularAcceleration = (-gravity / length) * sinf(angle); // Calculate acceleration (using formula)
    angularVelocity += angularAcceleration; // Update angular velocity
    angle += angularVelocity; // Update angle

    angularVelocity *= 0.99f; // Damping to reduce velocity over time

    // Update position of the pendulum bob
    position.x = origin.x + length * sinf(angle);
    position.y = origin.y + length * cosf(angle);
}

void Pendulum::Draw() {
    DrawLineEx(origin, position, 15.0f, WHITE); // Draw line from origin to pendulum bob
    DrawLineEx(origin, position, 13.0f, BLACK); // Draw line from origin to pendulum bob
    DrawCircleV(position, 50, WHITE); // Draw pendulum bob outline
    DrawCircleV(position, 48, RED); // Draw pendulum bob
}





