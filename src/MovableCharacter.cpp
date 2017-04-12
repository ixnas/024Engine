#include "../include/MovableCharacter.h"

bool MovableCharacter::keyLeftPressed () {
	return false;
}

bool MovableCharacter::keyRightPressed () {
	return false;
}

bool MovableCharacter::keyJumpPressed () {
	return false;
}

bool MovableCharacter::isMovingLeft () {
	return accelerationX < 0;
}

bool MovableCharacter::isMovingRight () {
	return accelerationX > 0;
}

bool MovableCharacter::maxSpeedX () {
	return accelerationX == -maxWalkingSpeed || accelerationX == maxWalkingSpeed;
}

bool MovableCharacter::jumpStateLeft () {
	return state == STATE_JLEFT && !collisionController->playerCollideBottom ();
}

bool MovableCharacter::jumpStateRight () {
	return state == STATE_JRIGHT && !collisionController->playerCollideBottom ();
}

bool MovableCharacter::walkStateLeft () {
	return state == STATE_WLEFT;
}

bool MovableCharacter::walkStateRight () {
	return state == STATE_WRIGHT;
}

bool MovableCharacter::isFalling () {
	return accelerationY < maxAccelerationDown && !jumping && !collisionController->playerCollideBottom ();
}

bool MovableCharacter::checkHeadButt () {
	collisionController->checkCollisions (this, x, y-1, w, h);
	auto headButt = collisionController->playerCollideTop ();
	setCollision ();
	return headButt;
}

void MovableCharacter::accelerateLeft () {
	auto isInWorld = x > 0;
	if (isMovingLeft () && isInWorld) {
		for (int i = 0; i > accelerationX; i--) {
			collisionController->checkCollisions (this, x-1, y, w, h);

			if (!collisionController->playerCollideLeft ()) {
				x--;
			}
		}
	}
}

void MovableCharacter::accelerateRight () {
	if (isMovingRight ()) {
		for (int i = 0; i < accelerationX; i++) {
			collisionController->checkCollisions (this, x+1, y, w, h);

			if (!collisionController->playerCollideRight ()) {
				x++;
			}
		}
	}
}

void MovableCharacter::accelerateTop () {
	auto isMovingUp = accelerationY < 0;

	if (isMovingUp) {
		for (int i = 0; i > accelerationY; i--) {
			collisionController->checkCollisions (this, x, y-1, w, h);

			if (!collisionController->playerCollideTop ()) {
				y--;
			} else {
				accelerationY++;
				jumping = false;
			}
		}
	}
}

void MovableCharacter::accelerateBottom () {
	auto isMovingDown = accelerationY > 0;

	if (isMovingDown) {
		for (int i = 0; i < accelerationY; i++) {
			collisionController->checkCollisions (this, x, y+1, w, h);

			if (!collisionController->playerCollideBottom ()) {
				y++;
			}
		}
	}
}

void MovableCharacter::setCollision () {
	collisionController->checkCollisions (this, x, y+1, w, h);
}

void MovableCharacter::prepareWalking () {
	auto bothKeysPressed = keyLeftPressed () && keyRightPressed ();

	if (!bothKeysPressed ) {
		if (keyLeftPressed ()) {
			walkLeft ();
		}
		else if (keyRightPressed ()) {
			walkRight ();
		}
		else if (!keyLeftPressed () && !keyRightPressed ()) {
			stand ();
		}
	} else {
		decelerate ();
	}
}

void MovableCharacter::walkLeft () {
	if (!jumpStateLeft ()) {
		changeState (STATE_WLEFT);
	}
	if (!maxSpeedX () || (maxSpeedX () && isMovingRight ())) {
		accelerationX = accelerationX - GraphicsEngine::instance ()->getFrameWidth ()/640;
	}
}

void MovableCharacter::walkRight () {
	if (!jumpStateRight ()) {
		changeState (STATE_WRIGHT);
	}
	if (!maxSpeedX () || (maxSpeedX () && isMovingLeft ())) {
		accelerationX = accelerationX + GraphicsEngine::instance ()->getFrameWidth ()/640;
	}
}

void MovableCharacter::stand () {
	if (walkStateLeft ()) {
		changeState (STATE_SLEFT);
	} else if (walkStateRight ()) {
		changeState (STATE_SRIGHT);
	}
	decelerate ();
}

void MovableCharacter::prepareJumping () {
	auto isStanding = collisionController->playerCollideBottom ();
	auto allowedToJump = keyJumpPressed () && !jumping && collisionController->playerCollideBottom ();
	auto jumpReleased = !keyJumpPressed () && jumping;

	if (allowedToJump && !checkHeadButt ()) {
		jumping = true;
	} else if (isFalling ()) {
		accelerationY = accelerationY + GraphicsEngine::instance ()->getFrameHeight ()/360;
	} else if (isStanding ) {
		accelerationY = 0;
	}

	if (jumpReleased) {
		passedJumpFrames = 0;
		jumping = false;
	}

	jumpCycle ();
}

void MovableCharacter::restrictFall () {
	auto isBelowFrame = y > GraphicsEngine::instance ()->getFrameHeight ();

	if (isBelowFrame ) {
		x = GraphicsEngine::instance ()->getFrameWidth ()/32*2;
		y = GraphicsEngine::instance ()->getFrameHeight ()/18*13;
	}
}

void MovableCharacter::setJumpTexture () {
	auto stopStateLeft = state == STATE_SLEFT;
	auto stopStateRight = state == STATE_SRIGHT;

	if (walkStateLeft () || stopStateLeft) {
		changeState (STATE_JLEFT);
	} else if (walkStateRight () || stopStateRight) {
		changeState (STATE_JRIGHT);
	}
}

void MovableCharacter::resetJumpState () {
	if (jumpStateLeft ()) {
		changeState (STATE_SLEFT);
	} else if (jumpStateRight ()) {
		changeState (STATE_SRIGHT);
	}
	passedJumpFrames = 0;
}

void MovableCharacter::jumpHandler () {
	auto maxSpeedUp = accelerationY == -maxAccelerationUp;

	if (!maxSpeedUp) {
		if (isFalling ()) {
			accelerationY = 0;
		}
		accelerationY = accelerationY - GraphicsEngine::instance ()->getFrameHeight ()/360;
	}
	passedJumpFrames++;
}

void MovableCharacter::jumpCycle () {
	auto jumpFinished = passedJumpFrames == maxJumpFrames;

	if (jumping) {
		setJumpTexture ();
		if (!jumpFinished) {
			jumpHandler ();
		} else {
			fall ();
		}
	} else if (!isFalling ()) {
		resetJumpState ();
	}
}

void MovableCharacter::fall () {
	jumping = false;
}

void MovableCharacter::decelerate () {
	if (isMovingLeft ()) {
		accelerationX = accelerationX + GraphicsEngine::instance ()->getFrameWidth ()/640;
	} else if (isMovingRight ()) {
		accelerationX = accelerationX - GraphicsEngine::instance ()->getFrameWidth ()/640;
	}
}


MovableCharacter::MovableCharacter (std::shared_ptr <CollisionController> collisionController, const int maxSpriteFrames, const int maxJumpFrames, const int maxWalkingSpeed, const int maxJumpingSpeed, const int maxFallingSpeed, const int x, const int y, const int w, const int h, const float stretchW, const float stretchH)
: Character (maxSpriteFrames, x, y, w, h, stretchW, stretchH)
, collisionController (collisionController)
, accelerationX (0)
, accelerationY (0)
, maxWalkingSpeed (maxWalkingSpeed)
, maxAccelerationUp (maxJumpingSpeed)
, maxAccelerationDown (maxFallingSpeed)
, maxJumpFrames (maxJumpFrames)
, passedJumpFrames (0)
, jumping (false)
{
	//debuggers.push_back (Debugger ("aX", &accelerationX, -maxWalkingSpeed, maxWalkingSpeed));
	//debuggers.push_back (Debugger ("aY", &accelerationY, -maxJumpingSpeed, maxFallingSpeed));
	//debuggers.push_back (Debugger ("jFrames", &passedJumpFrames, 0, maxJumpFrames));
}

void MovableCharacter::prepareFrame () {
	setCollision ();
	prepareWalking ();
	prepareJumping ();
	restrictFall ();
	accelerateLeft ();
	accelerateRight ();
	accelerateTop ();
	accelerateBottom ();
}
