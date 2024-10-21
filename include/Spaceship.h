// Spaceship.h
#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "raylib.h"

class Spaceship {
public:
    // Constructor
    Spaceship(Vector2 initPosition, float initSpeed);

    // Update the spaceship's position and rotation
    void Update();
    void Draw();

private:
    Vector2 position;
    Vector2 velocity;
    
    float angle;
    float speed;

    void HandleInput(); 
};

#endif // SPACESHIP_H
