// PhysicsObject.cpp
#include "PhysicsObject.h"

PhysicsObject::PhysicsObject() {
    position = { 0.0f, 0.0f };
    velocity = { 0.0f, 0.0f };
    angle = 0.0f;
    speed = 0.0f;
    length = 0.0f;
    angularVelocity = 0.0f;
    angularAcceleration = 0.0f;
    gravity = 0.0f;
    maxSpeed = 0.0f;
}

PhysicsObject::~PhysicsObject() {
    
}
