//
// Created by Sjoerd Scheffer on 02-04-17.
//

#ifndef CLION_SDL_EXPLOSION_H
#define CLION_SDL_EXPLOSION_H

#include "../include/TemporaryGameObject.h"

class Explosion : public TemporaryGameObject {
	public:
		Explosion (const int x, const int y, const int w, const int h);
		virtual ~Explosion ();
};


#endif
