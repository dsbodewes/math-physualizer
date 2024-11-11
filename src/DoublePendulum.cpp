// DoublePendulum.cpp
#include "DoublePendulum.h"
#include <cmath>
#include <iostream>

// Constructor  
DoublePendulum::DoublePendulum(Vector2 initOrigin, float initLength1, float initLength2, float initMass1, float initMass2)  
    : origin(initOrigin), length1(initLength1), length2(initLength2), mass1(initMass1), mass2(initMass2) {
    
    angle1 = PI / 4; // Starts both arms at 45 degrees
    angle2 = PI / 4;
    angularVelocity1 = 0.0f;
    angularVelocity2 = 0.0f;
    angularAcceleration1 = 0.0f;
    angularAcceleration2 = 0.0f;
    gravity = 4.45f;
    //gravity = 9.81f; // Earth's gravity

    // Calculate initial positions of the pendulum bobs
    position1 = { origin.x + length1 * sinf(angle1), origin.y + length1 * cosf(angle1) };
    position2 = { position1.x + length2 * sinf(angle2), position1.y + length2 * cosf(angle2) };
}

void DoublePendulum::Update() {
    // Calculate first pendulum's angular acceleration
    float num1 = -gravity * (2 * mass1 + mass2) * sinf(angle1);
    float num2 = -mass2 * gravity * sinf(angle1 - 2 * angle2);
    float num3 = -2 * sinf(angle1 - angle2) * mass2;
    float num4 = angularVelocity2 * angularVelocity2 * length2 + angularVelocity1 * angularVelocity1 * length1 * cosf(angle1 - angle2);
    float denom = length1 * (2 * mass1 + mass2 - mass2 * cosf(2 * angle1 - 2 * angle2));
    angularAcceleration1 = (num1 + num2 + num3 * num4) / denom;

    // Calculate second pendulum's angular acceleration
    num1 = 2 * sinf(angle1 - angle2);
    num2 = (angularVelocity1 * angularVelocity1 * length1 * (mass1 + mass2));
    num3 = gravity * (mass1 + mass2) * cosf(angle1);
    num4 = angularVelocity2 * angularVelocity2 * length2 * mass2 * cosf(angle1 - angle2);
    denom = length2 * (2 * mass1 + mass2 - mass2 * cosf(2 * angle1 - 2 * angle2));
    angularAcceleration2 = (num1 * (num2 + num3 + num4)) / denom;

    // Update angular velocities
    angularVelocity1 += angularAcceleration1;
    angularVelocity2 += angularAcceleration2;
    angle1 += angularVelocity1;
    angle2 += angularVelocity2;

    // Update positions
    position1.x = origin.x + length1 * sinf(angle1);
    position1.y = origin.y + length1 * cosf(angle1);
    position2.x = position1.x + length2 * sinf(angle2);
    position2.y = position1.y + length2 * cosf(angle2);
}

void DoublePendulum::Draw() {
    DrawLineEx(origin, position1, 15.0f, WHITE);
    DrawLineEx(origin, position1, 13.0f, BLACK);

    DrawLineEx(position1, position2, 15.0f, WHITE);
    DrawLineEx(position1, position2, 13.0f, BLACK);


    DrawCircleV(position1, 50, WHITE);
    DrawCircleV(position1, 48, DARKBLUE);

    DrawCircleV(position2, 50, WHITE);
    DrawCircleV(position2, 48, CRIMSON);
}
