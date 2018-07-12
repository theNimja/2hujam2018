#pragma once

//core class that player avatar inherits from, also AI enemies and bullets
class Combatant {
public:
	Combatant();
	~Combatant();

	//does ticks such as dampening velocity, playing animations, updating timers, etc
	void Tick(float deltaTime);

	void Move(float x, float y);

	float GetXVelocity();

	float GetYVelocity();

	float GetXPosition();

	float GetYPosition();

	float GetHitBoxRadius();

	float DistanceTo(Combatant* other);
protected:

	//reduces velocity over time by friction
	void DampenVelocity(float deltaTime);
		
private:
	

	float xPosition;
	float yPosition;

	float xVelocity;
	float yVelocity;

	float angle;

	float clockwiseVelocity;

	float linearDragCoefficient;
	float rotationalDragCoefficent;

	float hitBoxRadius;
};

