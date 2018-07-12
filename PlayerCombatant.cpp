#include "PlayerCombatant.h"

#include "PlayerData.h"


PlayerCombatant::PlayerCombatant() {
}


PlayerCombatant::~PlayerCombatant() {
}

int PlayerCombatant::GetMaxHealth() const {
	return myData->GetMaxHealth();;
}

int PlayerCombatant::GetMaxFuel() const {
	return myData->GetMaxFuel();
}

float PlayerCombatant::GetFuel() const {
	return myData->GetFuel();
}

int PlayerCombatant::GetHealth() const {
	return myData->GetHealth();
}
