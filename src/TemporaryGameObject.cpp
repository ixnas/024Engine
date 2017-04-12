#include "../include/TemporaryGameObject.h"
#include <iostream>

bool TemporaryGameObject::reachedLifeLimit () {
	return passedLifeFrames >= maxLifeFrames;
}

void TemporaryGameObject::nextLifeFrame () {
	if (!reachedLifeLimit ()) {
		passedLifeFrames++;
	} else {
		remove = true;
	}
}

TemporaryGameObject::TemporaryGameObject (std::vector <int> textures,
                                          int maxSpriteFrames, int maxLifeFrames, int x, int y, int w, int h,
                                          float stretchW, float stretchH, bool collidable)
: GameObject (textures, maxSpriteFrames, x, y, w, h, stretchW, stretchH, collidable)
, maxLifeFrames (maxLifeFrames)
, passedLifeFrames (1)
{
	//debuggers.push_back (Debugger ("lFrames", &this->passedLifeFrames, 0, maxLifeFrames));
}

TemporaryGameObject::~TemporaryGameObject () {
}

void TemporaryGameObject::prepareFrame () {
	nextLifeFrame ();
}
