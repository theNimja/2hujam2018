#include "EnemyCombatant.h"



EnemyCombatant::EnemyCombatant() {
}


EnemyCombatant::~EnemyCombatant() {
}


EnemyCombatant::Tick(float deltaTime) {
	__super::Tick(deltaTime);
	__super::DampenVelocity(deltaTime);
}