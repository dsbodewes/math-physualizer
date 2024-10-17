*What I'm using*
ProjectName/
│
├── src/                 # Source files
│   ├── main.cpp         # Entry point of the program
│   ├── Vector2.cpp      # Implementation of Vector2 class
│   └── OtherClass.cpp   # Implementation of other classes
│
├── include/             # Header files
│   ├── Vector2.h        # Declaration of Vector2 class
│   └── OtherClass.h     # Declaration of other classes
│
├── build/               # Compiled object files (optional)
│
├── lib/                 # Third-party libraries (optional)
│   └── raylib/          # e.g., Raylib library files
│
└── CMakeLists.txt       # Build configuration (or Makefile)

*Alternative*
ProjectName/
├── src/
│   ├── main.cpp
│   ├── Vector2/
│   │   ├── Vector2.cpp
│   │   └── Vector2.h
│   └── OtherClass/
│       ├── OtherClass.cpp
│       └── OtherClass.h
└── CMakeLists.txt

*Draw a simple triangle for the spaceship*
Vector2 v1 = { position.x + 20 * cosf((angle - 90) * DEG2RAD), position.y + 20 * sinf((angle - 90) * DEG2RAD) };
Vector2 v2 = { position.x + 20 * cosf((angle + 120) * DEG2RAD), position.y + 20 * sinf((angle + 120) * DEG2RAD) };
Vector2 v3 = { position.x + 20 * cosf((angle - 120) * DEG2RAD), position.y + 20 * sinf((angle - 120) * DEG2RAD) }; 

         v1
        / \
       /   \
      /     \
    v2-------v3


*Projectile Motion Simulator*
Concepts: Vectors, trigonometry, gravity, physics

Create a 2D simulation where the player can launch a projectile at a given angle and velocity.
Calculate the projectile’s trajectory using physics equations that incorporate gravity.
You can display the projectile’s path and allow the player to adjust launch parameters (angle, speed).
Features:

Adjust launch angle and speed using keys.
Display trajectory path with dots or lines.
Show real-time motion with gravity pulling the projectile down.
Math Focus: The key formula is x = v * cos(θ) * t and y = v * sin(θ) * t - 0.5 * g * t^2, where v is initial velocity, θ is the angle, g is gravity, and t is time.


