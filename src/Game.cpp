#include "../include/Game.h"
#include <cassert>
#include <iostream>
#include <thread>
#include <functional>

void Game::setCamera () {
	auto freeCameraSpeed = 10;
	if (inputController->keyPressed (SDLK_0)) {
		if (inputController->keyPressed (SDLK_a)) {
			camera.shiftH (-freeCameraSpeed);
		} if (inputController->keyPressed (SDLK_d)) {
			camera.shiftH (freeCameraSpeed);
		} if (inputController->keyPressed (SDLK_w)) {
			camera.shiftV (-freeCameraSpeed);
		} if (inputController->keyPressed (SDLK_s)) {
			camera.shiftV (freeCameraSpeed);
		}
	} else {
		if (players->size () > 0) {
			auto x = (*players) [0]->getX ()-GraphicsEngine::instance ()->getFrameWidth ()/3;
			auto y = (*players) [0]->getY ()-GraphicsEngine::instance ()->getFrameHeight ()/20*11;
			if (x > 0) {
				camera.setPosition (x, y);
			} else {
				camera.setPosition (0, y);
			}
		}
	}
}

void Game::prepareCameraAndObjects () {
	std::thread t1 (std::bind (&Game::setCamera, this));
	std::thread t2 (std::bind (&Game::prepareObjects, this, players));
	t1.join ();
	t2.join ();
	prepareObjects (gameObjects);
	prepareObjects (gameObjectsForeground);
}

bool Game::checkObjectWithinCamera (const int objectX, const int objectY, const int objectW, const int objectH) {
	if (
		objectX + objectW > -camera.getOffsetX () &&
        objectX < -camera.getOffsetX () + GraphicsEngine::instance ()->getFrameWidth () &&
        objectY + objectH > -camera.getOffsetY () &&
        objectY < -camera.getOffsetY () + GraphicsEngine::instance ()->getFrameHeight ()) {
		return true;
	} else {
		return false;
	}
}

void Game::drawBackground () {
	auto x = camera.getOffsetX ()/2;
	auto y = camera.getOffsetY ()/2 - GraphicsEngine::instance ()->getFrameHeight ()*2;
	auto w = GraphicsEngine::instance ()->getFrameWidth ()*4;
	auto h = GraphicsEngine::instance ()->getFrameHeight ()*4;

	GraphicsEngine::instance ()->drawTexture (background, x, y, w, h);
}

void Game::drawObjects (std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > objects) {
	for (int i = 0; i < (*objects).size (); i++) {
		auto x = (*objects) [i]->getStretchedX ();
		auto y = (*objects) [i]->getStretchedY ();
		auto w = (*objects) [i]->getStretchedW ();
		auto h = (*objects) [i]->getStretchedH ();

		if (checkObjectWithinCamera (x, y, w, h)) {
			(*objects) [i]->render (camera.getOffsetX (), camera.getOffsetY ());
		}
	}
}

void Game::drawWatermark () {
	auto x = GraphicsEngine::instance ()->getFrameWidth ()/3;
	auto y = GraphicsEngine::instance ()->getFrameHeight ()/40;
	auto w = GraphicsEngine::instance ()->getFrameWidth ()/3;
	auto h = GraphicsEngine::instance ()->getFrameHeight ()/10;

	GraphicsEngine::instance ()->drawTexture (watermark, x, y, w, h);
}

void Game::prepareObjects (std::shared_ptr <std::vector <std::shared_ptr <GameObject> > > objects) {
	assert (objects != NULL);

	for (int i = 0; i < (*objects).size (); i++) {
		auto object = (*objects) [i];
		assert (object != NULL);

		if (object->toBeRemoved ()) {
			if (object->canReincarnate ()) {
				if (object->reincarnateIntoForeground ()) {
					gameObjectsForeground->push_back (std::shared_ptr <GameObject> (object->getReincarnation ()));
				} else {
					objects->push_back (object->getReincarnation ());
				}
			}
			objects->erase (objects->begin () + i);
			std::cout << "GameObject removed by flag" << std::endl;
			i--;
		} else {
			object->prepareFrame ();
		}
	}
}

Game::Game (std::shared_ptr <InputController> inputController, std::shared_ptr <CollisionController> collisionController, int background)
: inputController (inputController)
, gameObjects (std::make_shared <std::vector <std::shared_ptr <GameObject> > > ())
, gameObjectsForeground (std::make_shared <std::vector <std::shared_ptr <GameObject> > > ())
, players (std::make_shared <std::vector <std::shared_ptr <GameObject> > > ())
, camera (Camera (0, 0, 5, 5))
, collisionController (collisionController)
, blockx (GraphicsEngine::instance ()->getBlockSizeX ())
, blocky (GraphicsEngine::instance ()->getBlockSizeY ())
, background (background)
{
	assert (inputController != nullptr);
	assert (GraphicsEngine::instance () != nullptr);

	GraphicsEngine::instance ()->loadFont ("fonts/HighlandGothicLightFLF.ttf", 128);
	collisionController->setGameObjects (gameObjects);
	players->push_back (std::make_shared <PlayableCharacter> (inputController, collisionController, SDLK_LEFT, SDLK_RIGHT, SDLK_SPACE, 24, 12, blockx/4, blocky/2, blocky/2, 2, 13, 2, 4, 2, 0.4));
	watermark = GraphicsEngine::instance ()->loadText (0, "024 Engine [April]", 0, 0, 0);
}

void Game::loop () {
	prepareCameraAndObjects ();
	drawBackground ();
	drawObjects (gameObjects);
	drawObjects (players);
	drawObjects (gameObjectsForeground);
	drawWatermark ();
}

void Game::addGameObject (std::shared_ptr <GameObject> gameObject) {
	assert (gameObject != NULL);
	gameObjects->push_back (gameObject);
}

void Game::addGameObjectForeground (std::shared_ptr <GameObject> gameObject) {
	assert (gameObject != NULL);
	gameObjectsForeground->push_back (gameObject);
}

std::shared_ptr <CollisionController> Game::getCollisionController () {
	assert (collisionController != NULL);
	return collisionController;
}