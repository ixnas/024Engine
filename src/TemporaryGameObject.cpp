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
                                          const int maxSpriteFrames, const int maxLifeFrames, const int x, const int y, const int w, const int h,
                                          const float stretchW, const float stretchH, const bool collidable)
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
