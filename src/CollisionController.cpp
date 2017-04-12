#include "../include/CollisionController.h"
#include <iostream>

CollisionController::CollisionController () {
	lastObjects = std::make_shared <std::vector <std::shared_ptr <GameObject> > > ();
	std::cout << "CollisionController started" << std::endl;
}

CollisionController::~CollisionController () {
	std::cout << "CollisionController stopped" << std::endl;
}

bool CollisionController::checkCollisionLeft () {
	bool result = false;
	if (
			playerLeftPos < objectRightPos &&
			playerRightPos > objectLeftPos &&
			playerTopPos < objectBottomPos &&
			playerBottomPos > objectTopPos
	   ) {
		result = true;
	}
	return result;
}

bool CollisionController::checkCollisionRight () {
	bool result = false;
	if (
			playerRightPos > objectLeftPos &&
			playerLeftPos < objectRightPos &&
			playerTopPos < objectBottomPos &&
			playerBottomPos > objectTopPos
	   ) {
		result = true;
	}
	return result;
}

bool CollisionController::checkCollisionTop () {
	bool result = false;
	if (
			playerTopPos < objectBottomPos &&
			playerBottomPos > objectTopPos &&
			playerLeftPos < objectRightPos &&
			playerRightPos > objectLeftPos
	   ) {
		result = true;
	}
	return result;
}

bool CollisionController::checkCollisionBottom () {
	bool result = false;
	if (
			playerBottomPos > objectTopPos &&
			playerTopPos < objectBottomPos &&
			playerLeftPos < objectRightPos &&
			playerRightPos > objectLeftPos
	   ) {
		result = true;
	}
	return result;
}

void CollisionController::setPlayerValues (const int playerX, const int playerY, const int playerW, const int playerH) {
	playerLeftPos = playerX;
	playerRightPos = playerX + playerW;
	playerTopPos = playerY;
	playerBottomPos = playerY + playerH;
}

void CollisionController::getObjectValues (int index) {
	objectLeftPos = (*gameObjects) [index]->getX ();
	objectRightPos = (*gameObjects) [index]->getX () + (*gameObjects) [index]->getW ();
	objectTopPos = (*gameObjects) [index]->getY ();
	objectBottomPos = (*gameObjects) [index]->getY () + (*gameObjects) [index]->getH ();
}

void CollisionController::checkCollisions (GameObject* requestingObject, const int playerX, const int playerY, const int playerW, const int playerH) {
	GameObject* gameObject;
	setPlayerValues (playerX, playerY, playerW, playerH);
	lastObjects->clear ();

	left = false;
	right = false;
	top = false;
	bottom = false;

	for (int i = 0; i < gameObjects->size (); i++) {
		gameObject = (*gameObjects) [i].get();

		if ((*gameObjects) [i]->isCollidable () && &gameObject != &requestingObject) {

			getObjectValues (i);

			if (checkCollisionLeft ()) {
				left = true;
			}

			if (checkCollisionRight ()) {
				right = true;
			}

			if (checkCollisionTop ()) {
				top = true;
			}

			if (checkCollisionBottom ()) {
				bottom = true;
			}

			if (checkCollisionLeft () || checkCollisionRight () || checkCollisionTop () || checkCollisionBottom ()) {
				lastObjects->push_back ((*gameObjects) [i]);
			}


		}
	}

}

bool CollisionController::playerCollideLeft () {
	return left;
}

bool CollisionController::playerCollideRight () {
	return right;
}

bool CollisionController::playerCollideTop () {
	return top;
}

bool CollisionController::playerCollideBottom () {
	return bottom;
}

bool CollisionController::playerCollide () {
	if (left || right || top || bottom) {
		return true;
	} else {
		return false;
	}
}

std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > CollisionController::getLastObjects () {
	return lastObjects;
}

void CollisionController::setGameObjects (std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > gameObjects) {
	this->gameObjects = gameObjects;
}
