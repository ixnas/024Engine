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
        src/GameObject.cpp
        src/GraphicsEngine.cpp
        src/main.cpp
        src/AssetLoader.cpp
        include/AssetLoader.h
        src/Asset.cpp
        include/Asset.h
        src/FPSCounter.cpp include/FPSCounter.h include/InputController.h src/InputControllerFactory.cpp include/InputControllerFactory.h)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        include)

add_executable(clion_sdl ${SOURCE_FILES})
target_link_libraries(clion_sdl ${SDL2_LIBRARY};${SDL2_IMAGE_LIBRARIES};${SDL2_TTF_LIBRARIES};${SDL2_MIXER_LIBRARIES})
