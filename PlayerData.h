#pragma once
class PlayerData {
public:
	PlayerData();
	~PlayerData();

	//uses number of hp upgrades to calculate max HP
	int GetMaxHealth() const;

	//uses number of fuel tank upgrades to calculate max fuel
	int GetMaxFuel() const;

	//tries to spend money to upgrade the healthBonus, return if it had enough money to do so
	bool TryUpgradeHealth();

	//tries to spend money to upgrade the fuelBonus, return if it had enough money to do so
	bool TryUpgradeFuelTank();

	//tries to spend money to upgrade the speedBonus, return if it had enough money to do so
	bool TryUpgradeSpeed();

	//tries to spend money to upgrade the efficiencyBonus, return if it had enough money to do so
	bool TryUpgradeEfficiency();

	//returns available credits
	int GetCredits() const;

	//returns available fuel
	float GetFuel() const;

	//returns current health
	int GetHealth() const;

private:
	int credits;
	float fuel;
	int health;


	int healthBonus;
	int fuelBonus;
	int speedBonus;
	int efficiencyBonus;

};

