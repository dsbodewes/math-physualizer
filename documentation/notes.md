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
