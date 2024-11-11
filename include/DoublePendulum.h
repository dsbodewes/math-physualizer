// DoublePendulum.h
#ifndef DOUBLE_PENDULUM_H
#define DOUBLE_PENDULUM_H

#include "raylib.h"

class DoublePendulum {
public:
    DoublePendulum(/*Vector2 initOrigin, float length1, float length2*/);

    void Update();
    void Draw();
    
private:
    Vector2 origin;
    Vector2 position1; // First bob position
    Vector2 position2; // Second bob position
    
    float angle1; // Angle for the first pendulum
    float angle2; // Angle for the second pendulum
    float length1; // Length of the first pendulum
    float length2; // Length of the second pendulum
    float angularVelocity1; // Angular velocity of the first pendulum
    float angularVelocity2; // Angular velocity of the second pendulum
    float angularAcceleration1; // Angular acceleration of the first pendulum
    float angularAcceleration2; // Angular acceleration of the second pendulum
    float gravity;
};

#endif // DOUBLE_PENDULUM_H
