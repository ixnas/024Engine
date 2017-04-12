//
// Created by Sjoerd Scheffer on 02-04-17.
//

#ifndef CLION_SDL_PLAYABLECHARACTER_H
#define CLION_SDL_PLAYABLECHARACTER_H


#include "../include/MovableCharacter.h"
#include "../include/Character.h"

class PlayableCharacter : public MovableCharacter {
	protected:
		std::shared_ptr <InputController> inputController;
		bool keyLeftPressed ();
		bool keyRightPressed ();
		bool keyJumpPressed ();
	private:
		const int keyLeft;
		const int keyRight;
		const int keyJump;
	public:
		PlayableCharacter (std::shared_ptr <InputController> inputController,
		                   std::shared_ptr <CollisionController> collisionController, const int keyLeft, const int keyRight, const int keyJump,
		                   const int maxSpriteFrames, const int maxJumpFrames, const int maxWalkingSpeed, const int maxJumpingSpeed,
		                   const int maxFallingSpeed, const int x, const int y, const int w, const int h, const float stretchW, const float stretchH);
		~PlayableCharacter ();
};


#endif //CLION_SDL_PLAYABLECHARACTER_H
