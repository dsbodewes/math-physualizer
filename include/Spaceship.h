// Spaceship.h

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "raylib.h"

class Spaceship {
public:
    Vector2 position;
    Vector2 velocity;
    float angle;
    float speed;

    // Constructor
    Spaceship(Vector2 initPosition, float initSpeed);

    // Update the spaceship's position and rotation
    void Update();


    // Draw the spaceship on the screen
    void Draw();

private:
    void HandleInput(); // Handle user input for moving the spaceship
};

#endif // SPACESHIP_H
