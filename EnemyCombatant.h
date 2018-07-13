#pragma once
#include "Combatant.h"
class EnemyCombatant :
	public Combatant {
public:
	EnemyCombatant(SpriteHolder* sprites);
	~EnemyCombatant();

	void Tick(float deltaTime);
};

