// Pendulum.h
#ifndef PENDULUM_H
#define PENDULUM_H

#include "raylib.h"

class Pendulum {
    public:
        Pendulum(Vector2 origin, float length, float angle, float mass);
        void Update();
        void Draw();

    private:
    Vector2 origin;
    float length;
    float angle;
    float mass;
    float angularVelocity; // Angular velocity (rad/s)  
    float angularAcceleration; // Angular acceleration (rad/s^2)

    const float gravity = 9.81f; // Gravity acceleration (m/s^2)
};

#endif // PENDULUM_H
