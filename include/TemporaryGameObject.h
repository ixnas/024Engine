//
// Created by Sjoerd Scheffer on 02-04-17.
//

#ifndef CLION_SDL_TEMPORARYGAMEOBJECT_H
#define CLION_SDL_TEMPORARYGAMEOBJECT_H

#include "../include/GameObject.h"

class TemporaryGameObject : public GameObject {
	private:
		const int maxLifeFrames;
		int passedLifeFrames;
		bool reachedLifeLimit ();
		void nextLifeFrame ();
	public:
		TemporaryGameObject (std::vector <int> textures, const int maxSpriteFrames, const int maxLifeFrames, const int x, const int y, const int w, const int h, const float stretchW, const float stretchH, const bool collidable);
		virtual ~TemporaryGameObject ();
		void prepareFrame ();
};

#endif
