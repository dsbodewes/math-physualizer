// PhysicsObject.h
#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include "raylib.h"

class PhysicsObject {
    public:
    PhysicsObject();
    virtual ~PhysicsObject();

    private:
    Vector2 position;
    Vector2 velocity;

    float angle;
    float speed;
    float length;
    float angularVelocity;
    float angularAcceleration;
    float gravity;
    float maxSpeed;
}; 

#endif // PHYSICSOBJECT_H
