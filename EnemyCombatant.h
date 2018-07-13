#pragma once
#include "Combatant.h"
class EnemyCombatant :
	public Combatant {
public:
	EnemyCombatant();
	~EnemyCombatant();

	void Tick(float deltaTime);
};

