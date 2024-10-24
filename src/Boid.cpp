// Boid.cpp
#include "Boid.h"
#include <cmath>
#include <raymath.h>
#include <iostream>

// Constructor
Boid::Boid(Vector2 initPosition, Vector2 initVelocity) {
    position = initPosition;
    velocity = initVelocity;
    maxSpeed = 5.0f;
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

    if (Vector2Length(velocity) > maxSpeed) {
    velocity = Vector2Scale(Vector2Normalize(velocity), maxSpeed);
    }

    // Screen wrapping
    position.x = fmod(position.x + GetScreenWidth(), GetScreenWidth());
    position.y = fmod(position.y + GetScreenHeight(), GetScreenHeight());
}

void Boid::Draw() const {
    DrawCircleV(position, 12, RAYWHITE);
    DrawCircleV(position, 8, YELLOW);
}

Vector2 Boid::Separation(const std::vector<Boid>& boids) {
    Vector2 steer = {0.0f, 0.0f};
    for (const Boid& other : boids) {
        float distance = Vector2Distance(position, other.GetPosition());
        if (&other != this && distance < 17.5f) { // Move away from nearby boids
            steer.x += position.x - other.GetPosition().x;
            steer.y += position.y - other.GetPosition().y;
        }
    }
    return steer;
}

Vector2 Boid::Alignment(const std::vector<Boid>& boids) {
    Vector2 averageVelocity = { 0, 0 };
    int count = 0;
    for (const Boid& other : boids) {
        float distance = Vector2Distance(position, other.GetPosition());
        if (&other != this && distance < 55.0f) { // Move in the same direction as nearby boids
            averageVelocity.x += other.GetVelocity().x;
            averageVelocity.y += other.GetVelocity().y;
            count++;
        }
    }
    if (count > 0) {
        averageVelocity.x /= count;
        averageVelocity.y /= count;
        averageVelocity = Vector2Normalize(averageVelocity);
    }
    return averageVelocity;
} 

Vector2 Boid::Cohesion(const std::vector<Boid>& boids) {
    Vector2 center = {0.0f, 0.0f};
    int count = 0;
    for (const Boid& other : boids) {
        float distance = Vector2Distance(position, other.GetPosition());
        if (&other != this && distance < 12.5f) {  // Move towards nearby boids
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

