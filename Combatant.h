#pragma once

//core class that all player avatar inherits from, also AI enemies
class Combatant {
public:
	Combatant();
	~Combatant();

	//reduces velocity over time by friction
	void DampenVelocity(float deltaTime);


private:
	float xPosition;
	float yPosition;

	float xVelocity;
	float yVelocity;

	float clockwiseVelocity;

	float linearDragCoefficient;
	float rotationalDragCoefficent;
};

