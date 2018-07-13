#pragma once

#include "Combatant.h"
struct SDL_Texture;


class PlayerData;

class PlayerCombatant : public Combatant{
public:
	PlayerCombatant(SpriteHolder* sprites, PlayerData* data);
	~PlayerCombatant();

	PlayerData* myData;

	//gets max health from player data
	int GetMaxHealth() const;

	//returns current health
	int GetHealth() const;

	//uses max fuel from player data
	int GetMaxFuel() const;

	//returns available fuel
	float GetFuel() const;

	void Tick(float deltaTime);

};

