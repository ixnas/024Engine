//
// Created by Sjoerd Scheffer on 02-04-17.
//

#include "../include/PlayableCharacter.h"

bool PlayableCharacter::keyLeftPressed () {
	return inputController->keyPressed (keyLeft);
}

bool PlayableCharacter::keyRightPressed () {
	return inputController->keyPressed (keyRight);
}

bool PlayableCharacter::keyJumpPressed () {
	return inputController->keyPressed (keyJump);
}

PlayableCharacter::PlayableCharacter (std::shared_ptr <InputController> inputController,
                                      std::shared_ptr <CollisionController> collisionController, const int keyLeft, const int keyRight, const int keyJump,
                                      const int maxSpriteFrames, const int maxJumpFrames, const int maxWalkingSpeed, const int maxJumpingSpeed,
                                      const int maxFallingSpeed, const int x, const int y, const int w, const int h, const float stretchW, const float stretchH)
: MovableCharacter (collisionController, maxSpriteFrames, maxJumpFrames, maxWalkingSpeed, maxJumpingSpeed, maxFallingSpeed, x, y, w, h, stretchW, stretchH)
, inputController (inputController)
, keyLeft (keyLeft)
, keyRight (keyRight)
, keyJump (keyJump)
{

}

PlayableCharacter::~PlayableCharacter () {
}
