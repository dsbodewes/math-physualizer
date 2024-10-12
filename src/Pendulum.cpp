#include "Pendulum.h"
#include <cmath>
#include <iostream>

// Constructor
Pendulum::Pendulum(Vector2 initOrigin, float initLength, float initAngle, float initMass) 
    : origin(initOrigin), length(initLength), angle(initAngle), mass(initMass) {
    angularVelocity = 0.0f;
    angularAcceleration = 0.0f;
}

void Pendulum::Update(){
    // Logic
}

void Pendulum::Draw(){
    // Draw
}





