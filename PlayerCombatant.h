#pragma once

#include "Combatant.h"
struct SDL_Texture;


class PlayerData;

class PlayerCombatant : public Combatant{
public:
	PlayerCombatant(SpriteHolder* sprites,float a,float v, PlayerData* data);
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

	void Tick(float deltaTime, SpriteHolder* sprites);

	Bullet* Fire(float relativeAngle, SpriteHolder* sprites);


private:
	float lShotTimer=0;
	float rShotTimer=0;
	float fShotTimer=0;
	float bShotTimer=0;

};

