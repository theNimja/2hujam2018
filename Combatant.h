#pragma once
#include <SDL_image.h>
class SpriteHolder;
class Bullet;
//core class that player avatar inherits from, also AI enemies and bullets
class Combatant {

	

public:
	Combatant(SpriteHolder* sprites,float a,float v);
	~Combatant();


	SDL_Texture* GetTexture();

	//does ticks such as dampening velocity, playing animations, updating timers, etc
	virtual void Tick(float deltaTime,SpriteHolder* sprites);

	void Move(float x, float y);
	void Rotate(float rotAngle);

	float GetXVelocity();

	float GetYVelocity();

	float GetXPosition();

	float GetYPosition();

	float GetHitBoxRadius();

	float DistanceTo(Combatant* other);

	float GetRotation();

	float GetRotationalVelocity();

	void ThrustForwards(float thrust);
	void ThrustRight(float thrust);
	void ThrustClockwise(float thrust);

	float GetMaxVelocity();
	float GetMaxAngularVelocity();

	virtual Bullet* Fire(float relativeAngle, SpriteHolder* sprites);

protected:
	float maxVelocity;
	float maxAngularVelocity;
	//reduces velocity over time by friction
	void DampenVelocity(float deltaTime);
		

	float xPosition;
	float yPosition;

	float xVelocity;
	float yVelocity;

	float angle;

	float clockwiseVelocity;

	float linearDragCoefficient;
	float rotationalDragCoefficent;

	float hitBoxRadius;

	//will be updated in tick to change sprite
	SDL_Texture* sprite;
};

