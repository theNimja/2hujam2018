#include "EnemyCombatant.h"



EnemyCombatant::EnemyCombatant(SpriteHolder* sprites, float a, float v) :Combatant(sprites,a,v) {
}


EnemyCombatant::~EnemyCombatant() {
}


void EnemyCombatant::Tick(float deltaTime, SpriteHolder* sprites) {
	__super::Tick(deltaTime, sprites);
	__super::DampenVelocity(deltaTime);
}