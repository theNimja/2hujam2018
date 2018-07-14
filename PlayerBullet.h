#pragma once
#include "Bullet.h"
class PlayerBullet :
	public Bullet {
public:
	PlayerBullet(SpriteHolder* sprites, Combatant* firer, float a);
	~PlayerBullet();

	void Tick(float deltaTime, SpriteHolder* sprites);

private:
	float timeToNextFrame;
};

