// Boid.cpp
#include "Boid.h"
#include <cmath>
#include <raymath.h>
#include <iostream>

// Constructor
Boid::Boid(Vector2 initPosition, Vector2 initVelocity) {
    position = initPosition;
    velocity = initVelocity;
}

void Boid::Update(const std::vector<Boid>& boids) {
    Vector2 seperation = Separation(boids);
    Vector2 alignment = Alignment(boids);
    Vector2 cohesion = Cohesion(boids);

    // Combine the forces
    velocity.x += seperation.x + alignment.x + cohesion.x;
    velocity.y += seperation.y + alignment.y + cohesion.y;

    position.x += velocity.x;
    position.y += velocity.y;

    // Screen wrapping
    if (position.x > GetScreenWidth()) position.x = 0;
    if (position.x < 0) position.x = GetScreenWidth();
    if (position.y > GetScreenHeight()) position.y = 0;
    if (position.y < 0) position.y = GetScreenHeight();
}

void Boid::Draw() const {
    DrawCircleV(position, 5, DARKGRAY);
}

Vector2 Boid::Separation(const std::vector<Boid>& boids) {
    Vector2 steer = {0.0f, 0.0f}; //
    for (const Boid& other : boids) {
        float dist = Vector2Distance(position, other.GetPosition());
        if (&other != this && dist < 50.0f) { // Avoid boids within 50 pixels
            steer.x += position.x - other.GetPosition().x;
            steer.y += position.y - other.GetPosition().y;
        }
    }
    return steer;
}

Vector2 Boid::Alignment(const std::vector<Boid>& boids) {
    Vector2 avarageVelocity = { 0, 0 };
    int count = 0;
    for (const Boid& other : boids) {
        float distance = Vector2Distance(position, other.GetPosition());
        if (&other != this && distance < 100.0f) {
            avarageVelocity.x += other.GetVelocity().x;
            avarageVelocity.y += other.GetVelocity().y;
            count++;
        }
    }
    if (count > 0) {
        avarageVelocity.x /= count;
        avarageVelocity.y /= count;
        //avarageVelocity = Vector2Normalize(avarageVelocity);
    }
    return avarageVelocity;
} 
