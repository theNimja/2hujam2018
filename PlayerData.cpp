#include "PlayerData.h"


//initialise a new player with no upgrades
PlayerData::PlayerData() {
	credits = 0;
	fuel = 0;
	health = 1;

	healthBonus = 0;
	fuelBonus = 0;
	speedBonus - 0;
	efficiencyBonus = 0;
}


PlayerData::~PlayerData() {
}

int PlayerData::GetMaxHealth() const {
	return 0;
}

int PlayerData::GetMaxFuel() const {
	return 0;
}

int PlayerData::GetCredits() const {
	return credits;
}

float PlayerData::GetFuel() const {
	return fuel;
}

int PlayerData::GetHealth() const {
	return health;
}
