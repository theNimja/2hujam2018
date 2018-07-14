#include "Bullet.h"



Bullet::Bullet(SpriteHolder* sprites,Combatant* firer, float a,float v) :Combatant(sprites,a,v) {
	shooter = firer;
}


Bullet::~Bullet() {
}
