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
                                      std::shared_ptr <CollisionController> collisionController, int keyLeft, int keyRight, int keyJump,
                                      int maxSpriteFrames, int maxJumpFrames, int maxWalkingSpeed, int maxJumpingSpeed,
                                      int maxFallingSpeed, int x, int y, int w, int h, float stretchW, float stretchH)
: MovableCharacter (collisionController, maxSpriteFrames, maxJumpFrames, maxWalkingSpeed, maxJumpingSpeed, maxFallingSpeed, x, y, w, h, stretchW, stretchH)
, inputController (inputController)
, keyLeft (keyLeft)
, keyRight (keyRight)
, keyJump (keyJump)
{

}

PlayableCharacter::~PlayableCharacter () {
}
