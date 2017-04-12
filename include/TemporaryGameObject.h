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
		TemporaryGameObject (std::vector <int> textures, int maxSpriteFrames, int maxLifeFrames, int x, int y, int w, int h, float stretchW, float stretchH, bool collidable);
		virtual ~TemporaryGameObject ();
		void prepareFrame ();
};

#endif
