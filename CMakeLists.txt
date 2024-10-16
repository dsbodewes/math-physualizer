cmake_minimum_required(VERSION 3.5)
project(main C CXX)

set(CMAKE_CXX_STANDARD 11)

# Setting parameters for OpenGL
set(OpenGL_GL_PREFERENCE GLVND)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

# Add raylib as a subdirectory (assuming it's in libs/raylib)
add_subdirectory(libs/raylib)

# Include directories (tell CMake where to find header files)
include_directories(include)

# Add the source files to the project
add_executable(${PROJECT_NAME} 
src/main.cpp 
src/Spaceship.cpp 
src/SpaceshipScene.cpp
src/MenuScene.cpp
src/SceneManager.cpp
src/Pendulum.cpp
src/PendulumScene.cpp
src/AimingSystem.cpp
src/AimingSystemScene.cpp)

# Link raylib to the project
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Copy assets folder to the build directory
file(
    COPY assets
    DESTINATION ${CMAKE_BINARY_DIR}
)

# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release mode
