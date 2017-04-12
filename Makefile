#MAKEFLAGS = -j

CC = clang++
CXXFLAGS = -O3 -Wall \
		   -std=c++1y \
		   -I /Library/Frameworks/SDL2.framework/Headers \
		   -I /Library/Frameworks/SDL2_mixer.framework/Headers \
		   -I /Library/Frameworks/SDL2_image.framework/Headers \
		   -I /Library/Frameworks/SDL2_ttf.framework/Headers
LDFLAGS = -framework SDL2 \
		  -framework SDL2_mixer \
		  -framework SDL2_image \
		  -framework SDL2_ttf
INPUT = obj/*
OUTPUT = -o bin/game

all:
	@echo -- Compiling modules
	@$(MAKE) compile
	@echo
	@echo -- Building executable
	@$(MAKE) build
	@echo

compile: asset assetloader bullet engine explosion camera collisioncontroller debugger gameobject game player movablecharacter playablecharacter temporarygameobject crate tree keyboardcontroller main bush bush2 groundmiddle groundmiddleleft groundmiddleright groundtop groundtopleft groundtopright fpscounter platformleft platformmiddle platformright inputcontrollerfactory

clean:
	rm obj/*

asset:
	@echo 
	@echo -- Compilling Asset
	$(CC) $(CXXFLAGS) -c -o obj/Asset.o src/Asset.cpp

assetloader:
	@echo 
	@echo -- Compilling AssetLoader
	$(CC) $(CXXFLAGS) -c -o obj/AssetLoader.o src/AssetLoader.cpp

build:
	$(CC) $(LDFLAGS) $(OUTPUT) $(INPUT)
	@echo
	@echo --Copying to app bundle
	@cp -r assets App.app/Contents/Resources/
	@cp -r fonts App.app/Contents/Resources/
	@cp -r bin/game App.app/Contents/MacOS/App

bullet:
	@echo 
	@echo -- Compilling Bullet
	$(CC) $(CXXFLAGS) -c -o obj/Bullet.o src/Bullet.cpp

engine:
	@echo 
	@echo -- Compilling GraphicsEngine
	$(CC) $(CXXFLAGS) -c -o obj/GraphicsEngine.o src/GraphicsEngine.cpp

explosion:
	@echo 
	@echo -- Compilling Explosion
	$(CC) $(CXXFLAGS) -c -o obj/Explosion.o src/Explosion.cpp

camera:
	@echo 
	@echo -- Compilling Camera
	$(CC) $(CXXFLAGS) -c -o obj/Camera.o src/Camera.cpp

collisioncontroller:
	@echo 
	@echo -- Compilling CollisionController
	$(CC) $(CXXFLAGS) -c -o obj/CollisionController.o src/CollisionController.cpp

debugger:
	@echo 
	@echo -- Compilling Debugger
	$(CC) $(CXXFLAGS) -c -o obj/Debugger.o src/Debugger.cpp

main:
	@echo 
	@echo -- Compilling Main
	$(CC) $(CXXFLAGS) -c -o obj/main.o src/main.cpp

gameobject:
	@echo 
	@echo -- Compilling GameObject
	$(CC) $(CXXFLAGS) -c -o obj/GameObject.o src/GameObject.cpp

game:
	@echo 
	@echo -- Compilling Game
	$(CC) $(CXXFLAGS) -c -o obj/Game.o src/Game.cpp

player:
	@echo 
	@echo -- Compilling Player
	$(CC) $(CXXFLAGS) -c -o obj/Character.o src/Character.cpp

movablecharacter:
	@echo 
	@echo -- Compilling MovableCharacter
	$(CC) $(CXXFLAGS) -c -o obj/MovableCharacter.o src/MovableCharacter.cpp

playablecharacter:
	@echo 
	@echo -- Compilling PlayableCharacter
	$(CC) $(CXXFLAGS) -c -o obj/PlayableCharacter.o src/PlayableCharacter.cpp

temporarygameobject:
	@echo 
	@echo -- Compilling TemporaryGameObject
	$(CC) $(CXXFLAGS) -c -o obj/TemporaryGameObject.o src/TemporaryGameObject.cpp

crate:
	@echo 
	@echo -- Compilling Crate
	$(CC) $(CXXFLAGS) -c -o obj/Crate.o src/Crate.cpp

tree:
	@echo 
	@echo -- Compilling Tree
	$(CC) $(CXXFLAGS) -c -o obj/Tree.o src/Tree.cpp

keyboardcontroller:
	@echo 
	@echo -- Compilling KeyboardController
	$(CC) $(CXXFLAGS) -c -o obj/KeyboardController.o src/KeyboardController.cpp

bush:
	@echo 
	@echo -- Compilling Bush
	$(CC) $(CXXFLAGS) -c -o obj/Bush.o src/Bush.cpp

bush2:
	@echo 
	@echo -- Compilling Bush2
	$(CC) $(CXXFLAGS) -c -o obj/Bush2.o src/Bush2.cpp

groundmiddle:
	@echo 
	@echo -- Compilling GroundMiddle
	$(CC) $(CXXFLAGS) -c -o obj/GroundMiddle.o src/GroundMiddle.cpp

groundmiddleleft:
	@echo 
	@echo -- Compilling GroundMiddleLeft
	$(CC) $(CXXFLAGS) -c -o obj/GroundMiddleLeft.o src/GroundMiddleLeft.cpp

groundmiddleright:
	@echo 
	@echo -- Compilling GroundMiddleRight
	$(CC) $(CXXFLAGS) -c -o obj/GroundMiddleRight.o src/GroundMiddleRight.cpp

groundtop:
	@echo 
	@echo -- Compilling GroundTop
	$(CC) $(CXXFLAGS) -c -o obj/GroundTop.o src/GroundTop.cpp

groundtopleft:
	@echo 
	@echo -- Compilling GroundTopLeft
	$(CC) $(CXXFLAGS) -c -o obj/GroundTopLeft.o src/GroundTopLeft.cpp

groundtopright:
	@echo 
	@echo -- Compilling GroundTopRight
	$(CC) $(CXXFLAGS) -c -o obj/GroundTopRight.o src/GroundTopRight.cpp

fpscounter:
	@echo
	@echo -- Compilling FPSCounter
	$(CC) $(CXXFLAGS) -c -o obj/FPSCounter.o src/FPSCounter.cpp

platformleft:
	@echo
	@echo -- Compilling PlatformLeft
	$(CC) $(CXXFLAGS) -c -o obj/PlatformLeft.o src/PlatformLeft.cpp

platformmiddle:
	@echo
	@echo -- Compilling PlatformMiddle
	$(CC) $(CXXFLAGS) -c -o obj/PlatformMiddle.o src/PlatformMiddle.cpp

platformright:
	@echo
	@echo -- Compilling PlatformRight
	$(CC) $(CXXFLAGS) -c -o obj/PlatformRight.o src/PlatformRight.cpp

inputcontrollerfactory:
	@echo
	@echo -- Compilling InputControllerFactory
	$(CC) $(CXXFLAGS) -c -o obj/InputControllerFactory.o src/InputControllerFactory.cpp
