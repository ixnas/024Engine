cmake_minimum_required(VERSION 3.6)
project(clion_sdl)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeSDL")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/KeyboardController.cpp
        src/Camera.cpp
        src/CollisionController.cpp
        src/Game.cpp
        src/GameObject.cpp
        src/GraphicsEngine.cpp
        src/main.cpp
        src/MovableCharacter.cpp
        src/PlayableCharacter.cpp
        src/Tree.cpp
        src/Character.cpp
        src/Debugger.cpp
        src/Bullet.cpp
        include/TemporaryGameObject.h
        src/TemporaryGameObject.cpp
        src/AssetLoader.cpp
        include/AssetLoader.h
        src/Asset.cpp
        include/Asset.h
        src/Crate.cpp
        include/Crate.h
        src/Explosion.cpp
        include/Explosion.h src/Bush.cpp include/Bush.h src/Bush2.cpp src/GroundTop.cpp include/GroundTop.h src/GroundMiddle.cpp include/GroundMiddle.h src/GroundTopLeft.cpp include/GroundTopLeft.h src/GroundMiddleLeft.cpp include/GroundMiddleLeft.h src/GroundTopRight.cpp include/GroundTopRight.h src/GroundMiddleRight.cpp include/GroundMiddleRight.h src/FPSCounter.cpp include/FPSCounter.h include/InputController.h include/PlatformLeft.h src/PlatformLeft.cpp src/PlatformMiddle.cpp include/PlatformMiddle.h src/PlatformRight.cpp include/PlatformRight.h src/InputControllerFactory.cpp include/InputControllerFactory.h)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        include)

add_executable(clion_sdl ${SOURCE_FILES})
target_link_libraries(clion_sdl ${SDL2_LIBRARY};${SDL2_IMAGE_LIBRARIES};${SDL2_TTF_LIBRARIES};${SDL2_MIXER_LIBRARIES})
