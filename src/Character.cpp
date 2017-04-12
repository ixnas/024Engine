#include "../include/Character.h"
#include <iostream>
#include <thread>

void Character::changeState (int state) {
	if (this->state != state) {
		this->state = state;
		passedSpriteFrames = 0;
		switch (state) {
			case STATE_WLEFT:
				textures = texturesWalkLeft;
				break;
			case STATE_WRIGHT:
				textures = texturesWalkRight;
				break;
			case STATE_SLEFT:
				textures = texturesStillLeft;
				break;
			case STATE_SRIGHT:
				textures = texturesStillRight;
				break;
			case STATE_FLEFT:
				textures = texturesJumpLeft;
				break;
			case STATE_FRIGHT:
				textures = texturesJumpRight;
				break;
			case STATE_JLEFT:
				textures = texturesJumpLeft;
				break;
			case STATE_JRIGHT:
				textures = texturesJumpRight;
				break;
			default:
				break;
		}
	}
}

Character::Character (int maxSpriteFrames, int x, int y, int w, int h, float stretchW, float stretchH)
: GameObject (std::vector <int> (), maxSpriteFrames, x, y, w, h, stretchW, stretchH, true)
, state (STATE_WRIGHT)
{
	texturesStillLeft = AssetLoader::instance ()->getPlayerStillLeftAsset ();
	texturesStillRight = AssetLoader::instance ()->getPlayerStillRightAsset ();
	texturesWalkLeft = AssetLoader::instance ()->getPlayerWalkLeftAsset ();
	texturesWalkRight = AssetLoader::instance ()->getPlayerWalkRightAsset ();
	textures = texturesStillRight;
	texturesJumpLeft = texturesStillLeft;
	texturesJumpRight = texturesStillRight;
	std::cout << "Character added" << std::endl;
}

Character::~Character () {
	std::cout << "Character removed" << std::endl;
}

void Character::prepareFrame () {
}
