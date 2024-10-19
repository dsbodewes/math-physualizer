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
    if (position.x > GetScreenWidth()) {
        position.x = 0;
    } else if (position.x < 0) {
        position.x = GetScreenWidth();
    }
}

void Boid::Draw() const {
    DrawCircleV(position, 5, DARKGRAY);
}

Vector2 Boid::Separation(const std::vector<Boid>& boids) {
    Vector2 steer = {0.0f, 0.0f};
    for (const Boid& other : boids) {
        float distance = Vector2Distance(position, other.GetPosition());
        if (&other != this && distance < 1.0f) { // Avoid boids within 50 pixels
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
        if (&other != this && distance < 10.0f) { // Move in the same direction as nearby boids
            avarageVelocity.x += other.GetVelocity().x;
            avarageVelocity.y += other.GetVelocity().y;
            count++;
        }
    }
    if (count > 0) {
        avarageVelocity.x /= count;
        avarageVelocity.y /= count;
        avarageVelocity = Vector2Normalize(avarageVelocity);
    }
    return avarageVelocity;
} 

Vector2 Boid::Cohesion(const std::vector<Boid>& boids) {
    Vector2 center = {0.0f, 0.0f};
    int count = 0;
    for (const Boid& other : boids) {
        float distance = Vector2Distance(position, other.GetPosition());
        if (&other != this && distance < 10.0f) {  // Move towards nearby boids
            center.x += other.GetPosition().x;
            center.y += other.GetPosition().y;
            count++;
        }
    }
    if (count > 0) {
        center.x /= count;
        center.y /= count;
        center.x -= position.x;
        center.y -= position.y;
    }
    return center;
}
