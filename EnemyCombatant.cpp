#include "EnemyCombatant.h"



EnemyCombatant::EnemyCombatant() {
}


EnemyCombatant::~EnemyCombatant() {
}


void EnemyCombatant::Tick(float deltaTime) {
	__super::Tick(deltaTime);
	__super::DampenVelocity(deltaTime);
}