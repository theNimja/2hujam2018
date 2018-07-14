#include "PlayerCombatant.h"

#include "PlayerData.h"
#include <map>
#include "GameFuncDef.h"
#include "SpriteHolder.h"
#include "PlayerBullet.h"

PlayerCombatant::PlayerCombatant(SpriteHolder* sprites, float a, float v, PlayerData* data) : Combatant(sprites, a, v) {
	sprite = sprites->GetTexture(SpriteHolder::Sprites::PLAYER);
	myData = data;
	linearDragCoefficient = 0.04;
	rotationalDragCoefficent = 0.02;
	maxVelocity = 40;
	maxAngularVelocity = 120;

}


PlayerCombatant::~PlayerCombatant() {
}

int PlayerCombatant::GetMaxHealth() const {
	return myData->GetMaxHealth();
}

int PlayerCombatant::GetMaxFuel() const {
	return myData->GetMaxFuel();
}

float PlayerCombatant::GetFuel() const {
	return myData->GetFuel();
}

void PlayerCombatant::Tick(float deltaTime, SpriteHolder* sprites) {
	__super::Tick(deltaTime, sprites);
	__super::DampenVelocity(deltaTime);

	fShotTimer -= deltaTime;
	if (fShotTimer < 0) { fShotTimer = 0; }
	bShotTimer -= deltaTime;
	if (bShotTimer < 0) { bShotTimer = 0; }
	rShotTimer -= deltaTime;
	if (rShotTimer < 0) { rShotTimer = 0; }
	lShotTimer -= deltaTime;
	if (lShotTimer < 0) { lShotTimer = 0; }

}


int PlayerCombatant::GetHealth() const {
	return myData->GetHealth();
}

Bullet * PlayerCombatant::Fire(float relativeAngle, SpriteHolder* sprites) {
	if (relativeAngle > -1 && relativeAngle < 1) {
		//fire forwards
		if (fShotTimer == 0) {
			PlayerBullet* ret;
			ret = &PlayerBullet(sprites, this, relativeAngle + angle);
			float dist = GetHitBoxRadius() + ret->GetHitBoxRadius() + 1;
			ret->Move(dist * cos(ret->GetRotation() / 180 * M_PI), dist * sin(ret->GetRotation() / 180 * M_PI));
			return ret;
		}
	}
	if (relativeAngle < 91 && relativeAngle > 89) {
		//fire right
	}
	if (relativeAngle > -91 && relativeAngle < -89) {
		//fire left
	} else {
		//fire back
	}
	return nullptr;
}
