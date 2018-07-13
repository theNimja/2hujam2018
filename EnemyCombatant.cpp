#include "EnemyCombatant.h"



EnemyCombatant::EnemyCombatant(SpriteHolder* sprites) :Combatant(sprites) {
}


EnemyCombatant::~EnemyCombatant() {
}


void EnemyCombatant::Tick(float deltaTime) {
	__super::Tick(deltaTime);
	__super::DampenVelocity(deltaTime);
}