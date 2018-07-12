#pragma once
#include "Combatant.h"
class EnemyCombatant :
	public Combatant {
public:
	EnemyCombatant();
	~EnemyCombatant();

	Tick(float deltaTime);
};

