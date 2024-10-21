// Boid.h
#ifndef BOID_H
#define BOID_H

#include "raylib.h"
#include <vector>

class Boid {
public:
    Boid(Vector2 initPosition, Vector2 initVelocity);
    void Update(const std::vector<Boid>& boids); 
    void Draw() const;

    Vector2 GetPosition() const { return position; }
    Vector2 GetVelocity() const { return velocity; }

private:
    Vector2 position;
    Vector2 velocity;

    float maxSpeed;
    float angle;

    Vector2 Separation(const std::vector<Boid>& boids);
    Vector2 Alignment(const std::vector<Boid>& boids);
    Vector2 Cohesion(const std::vector<Boid>& boids);
};

#endif // BOID_H
