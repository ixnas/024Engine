#ifndef GAME_H
#define GAME_H

#include "../include/InputControllerFactory.h"
#include "../include/GraphicsEngine.h"
#include "../include/GameObject.h"
#include "../include/Bullet.h"
#include "../include/Camera.h"
#include "../include/PlayableCharacter.h"
#include "../include/CollisionController.h"
#include <vector>

class Game {
	private:
		std::shared_ptr <InputController> inputController;
		std::unique_ptr <Camera> camera;
		std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > gameObjects;
		std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > gameObjectsForeground;
		std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > players;
		std::shared_ptr <CollisionController> collisionController;
		int blockx, blocky;
		int background;
		int watermark;
		void setCamera ();
		void prepareCameraAndObjects ();
		bool checkObjectWithinCamera (const int objectX, const int objectY, const int objectW, const int objectH);
		void drawObjects (std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > objects);
		void drawBackground ();
		void drawWatermark ();
		void prepareObjects (std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > objects);
	public:
		Game (std::shared_ptr <InputController> inputController, std::shared_ptr <CollisionController> collisionController, std::unique_ptr <Camera> camera, int background);
		void loop ();
		void addGameObject (std::shared_ptr <GameObject> gameObject);
		void addGameObjectForeground (std::shared_ptr <GameObject> gameObject);
		std::shared_ptr <CollisionController> getCollisionController ();
};

#endif
