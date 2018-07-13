#include "PlayerCombatant.h"

#include "PlayerData.h"
#include <map>
#include "GameFuncDef.h"
#include "SpriteHolder.h"


PlayerCombatant::PlayerCombatant(SpriteHolder* sprites, PlayerData* data):Combatant(sprites) {	
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

void PlayerCombatant::Tick(float deltaTime) {
	__super::Tick(deltaTime);
	__super::DampenVelocity(deltaTime);
}

int PlayerCombatant::GetHealth() const {
	return myData->GetHealth();
}
