#ifndef PLAYER_H
#define PLAYER_H

#include "../include/GameObject.h"
#include "../include/GraphicsEngine.h"
#include "KeyboardController.h"
#include "../include/CollisionController.h"
#include <vector>

class Character : public GameObject {
	protected:
		int state;
		enum {
			STATE_WLEFT,
			STATE_WRIGHT,
			STATE_SLEFT,
			STATE_SRIGHT,
			STATE_JLEFT,
			STATE_JRIGHT,
			STATE_FLEFT,
			STATE_FRIGHT
		};
		std::vector <int> texturesStillLeft;
		std::vector <int> texturesStillRight;
		std::vector <int> texturesWalkLeft;
		std::vector <int> texturesWalkRight;
		std::vector <int> texturesJumpLeft;
		std::vector <int> texturesJumpRight;
		void changeState (const int state);
	public:
		Character (const int maxSpriteFrames, const int x, const int y, const int w, const int h, const float stretchW, const float stretchH);
		virtual ~Character ();
		virtual void prepareFrame ();
};

#endif
