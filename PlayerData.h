#pragma once
class PlayerData {
public:
	PlayerData();
	~PlayerData();

	//uses number of hp upgrades to calculate max HP
	int GetMaxHealth();

	//uses number of fuel tank upgrades to calculate max fuel
	int GetMaxFuel();
private:
	int credits;
	float fuel;
	int health;


	int healthBonus;
	int fuelBonus;
	int speedBonus;
	int efficiencyBonus;

};

