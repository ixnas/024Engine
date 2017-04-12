#ifndef COLLISIONCONTROLLER_H
#define COLLISIONCONTROLLER_H

#include "../include/GameObject.h"
#include <vector>

class CollisionController {
	private:
		int playerLeftPos;
		int playerRightPos;
		int playerTopPos;
		int playerBottomPos;
		int objectLeftPos;
		int objectRightPos;
		int objectTopPos;
		int objectBottomPos;
		bool left, right, top, bottom;
		std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > gameObjects;
		std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > lastObjects;
		bool checkCollisionLeft ();
		bool checkCollisionRight ();
		bool checkCollisionTop ();
		bool checkCollisionBottom ();
		void setPlayerValues (const int playerX, const int playerY, const int playerW, const int playerH);
		void getObjectValues (const int index);
	public:
		CollisionController ();
		~CollisionController ();
		void setGameObjects (std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > gameObjects);
		void checkCollisions (GameObject* requestingObject, const int playerX, const int playerY, const int playerW, const int playerH);
		bool playerCollideLeft ();
		bool playerCollideRight ();
		bool playerCollideTop ();
		bool playerCollideBottom ();
		bool playerCollide ();
		std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > getLastObjects ();
};

#endif
