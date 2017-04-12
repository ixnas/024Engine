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
		               const int maxSpriteFrames, const int maxJumpFrames, const int maxWalkingSpeed, const int maxJumpingSpeed,
		               const int maxFallingSpeed, const int x, const int y, const int w, const int h, const float stretchW, const float stretchH);
		void prepareFrame ();
};

#endif
