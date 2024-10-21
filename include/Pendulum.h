// Pendulum.h
#ifndef PENDULUM_H
#define PENDULUM_H

#include "raylib.h"

class Pendulum {
    public:
    Pendulum(Vector2 origin, float length);

    void Update();
    void Draw();  
    void ApplyForce(float force);
    float* GetPointerXPossition(){return &position.x;};
    float* GetPointerYPossition(){return &position.y;};

    private:
    Vector2 origin; // Point from which the pendulum is suspended
    Vector2 position; // Current position of the pendulum bob
    
    float angle; // Angle of the pendulum (in radians)
    float length; // Length of the pendulum
    float angularVelocity; // Angular velocity of the pendulum (how fast the angle changes)
    float angularAcceleration; // Angular acceleration of the pendulum (how fast the angular velocity changes)
    float gravity; // Gravitational constant
};

#endif // PENDULUM_H
