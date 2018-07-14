#include "PlayerBullet.h"
#include "SpriteHolder.h"


PlayerBullet::PlayerBullet(SpriteHolder* sprites, Combatant* firer, float a) :Bullet(sprites, firer, a, 0.0) {
	timeToNextFrame = 0.3;
	sprite = sprites->GetTexture(SpriteHolder::Sprites::FIRE1);

}


PlayerBullet::~PlayerBullet() {
}


void PlayerBullet::Tick(float deltaTime, SpriteHolder* sprites) {
	timeToNextFrame -= deltaTime;
	if (timeToNextFrame <= 0) {
		timeToNextFrame += 0.3;
		if (sprite == sprites->GetTexture(SpriteHolder::Sprites::FIRE1)) {
			sprite = sprites->GetTexture(SpriteHolder::Sprites::FIRE2);
		} else if (sprite == sprites->GetTexture(SpriteHolder::Sprites::FIRE2)) {
			sprite = sprites->GetTexture(SpriteHolder::Sprites::FIRE3);
		} else { 
			//get this deleted
			Move(10000000, 1000000);
		}

	}
}