#pragma once
#include "Combatant.h"
class EnemyCombatant :
	public Combatant {
public:
	EnemyCombatant(SpriteHolder* sprites, float a, float v);
	~EnemyCombatant();

	void Tick(float deltaTime, SpriteHolder* sprites);
};

