#ifndef MOVABLEPLAYER_H
#define MOVABLEPLAYER_H

#include "../include/Character.h"

class MovableCharacter : public Character {
	protected:
		std::shared_ptr <CollisionController> collisionController;
		int accelerationX, accelerationY;
		const int maxWalkingSpeed, maxAccelerationUp, maxAccelerationDown, maxJumpFrames;
		int passedJumpFrames;
		bool jumping;
		virtual bool keyLeftPressed ();
		virtual bool keyRightPressed ();
		virtual bool keyJumpPressed ();
		bool isMovingLeft ();
		bool isMovingRight ();
		bool maxSpeedX ();
		bool jumpStateLeft ();
		bool jumpStateRight ();
		bool walkStateLeft ();
		bool walkStateRight ();
		bool isFalling ();
		void accelerateLeft ();
		void accelerateRight ();
		void accelerateTop ();
		void accelerateBottom ();
		void setCollision ();
		void prepareWalking ();
		void walkLeft ();
		void walkRight ();
		void stand ();
		void prepareJumping ();
		void restrictFall ();
		bool checkHeadButt ();
		void setJumpTexture ();
		void resetJumpState ();
		void jumpHandler ();
		void jumpCycle ();
		void fall ();
		void decelerate ();
	public:
		MovableCharacter (std::shared_ptr <CollisionController> collisionController,
		               int maxSpriteFrames, int maxJumpFrames, int maxWalkingSpeed, int maxJumpingSpeed,
		               int maxFallingSpeed, int x, int y, int w, int h, float stretchW, float stretchH);
		void prepareFrame ();
};

#endif
