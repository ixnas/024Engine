#include "../include/Bullet.h"
#include <iostream>

void Bullet::destroyTargets () {
	auto objects = collisionController->getLastObjects ();
	for (int i = 0; i < objects->size (); i++) {
		(*objects) [i]->setRemove ();
	}
}

Bullet::Bullet (std::shared_ptr <CollisionController> collisionController, int x, int y, int acceleration)
: GameObject (AssetLoader::instance ()->getMushroomAsset (), 60, x, y, 2, 2, 0, 0, false)
, collisionController (collisionController)
, acceleration (acceleration)
{
	//debuggers.push_back (Debugger (GraphicsEngine::instance (), "aX", &this->acceleration, -acceleration, acceleration));
}

void Bullet::prepareFrame () {
	for (int i = 0; i < acceleration; i++) {
		collisionController->checkCollisions (this, x, y, w, h);
		if (collisionController->playerCollide ()) {
			destroyTargets ();
			setRemove ();
			i = acceleration;
		}
		x++;
	}
}

bool Bullet::canReincarnate () {
	return true;
}

std::shared_ptr <GameObject> Bullet::getReincarnation () {
	return std::make_shared <Explosion> (x/GraphicsEngine::instance ()->getBlockSizeX (), y/GraphicsEngine::instance ()->getBlockSizeY (), 2, 2);
}

Bullet::~Bullet () {
}

bool Bullet::reincarnateIntoForeground () {
	return true;
}
