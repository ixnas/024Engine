#ifndef BULLET_H
#define BULLET_H

#include "../include/GameObject.h"
#include "../include/Explosion.h"
#include "../include/CollisionController.h"

class Bullet: public GameObject {
	private:
		std::shared_ptr <CollisionController> collisionController;
		int acceleration;
		void destroyTargets ();
	public:
		Bullet (std::shared_ptr <CollisionController> collisionController, int x, int y, int acceleration);
		~Bullet ();
		void prepareFrame () override;
		bool canReincarnate () override;
		bool reincarnateIntoForeground () override;
		std::shared_ptr <GameObject> getReincarnation () override;
};

#endif
