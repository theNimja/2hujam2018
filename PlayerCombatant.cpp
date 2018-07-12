#include "PlayerCombatant.h"

#include "PlayerData.h"


PlayerCombatant::PlayerCombatant() {
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
