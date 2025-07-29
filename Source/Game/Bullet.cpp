#include "Bullet.h"

// When you get Enemy.cpp done, paste that shit here.
// check yo phone, it can possibly help you!

void Bullet::onCollision(Actor* other)
{
	if (tag != other->tag) {
		stillAlive = false;
	}
	
}
