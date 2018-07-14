#pragma once
#include "Combatant.h"
class Bullet :	public Combatant {
public:
	Bullet(SpriteHolder* sprites,Combatant* firer, float a, float v);
	~Bullet();


	Combatant* shooter=nullptr;
};

