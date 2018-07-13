#include "Combatant.h"
#include <math.h>
#include <SDL.h> 
#include <map>
#include "GameFuncDef.h"
#include "SpriteHolder.h"


Combatant::Combatant(SpriteHolder* sprites) {
}


Combatant::~Combatant() {
}

SDL_Texture* Combatant::GetTexture() {
	return sprite;
}


void Combatant::DampenVelocity(float deltaTime) {

	//dampen linear speed
	float slope = yVelocity / xVelocity;
	float speed = sqrtf(yVelocity*yVelocity + xVelocity * xVelocity);
	if (speed != 0) {
		//drag equation is
		//force = 1/2 * speed^2 * density of air * area * drag coefficient
		//density of air, cross sectional area and drga coeffcient are taken account of in the linearDragCoefficient variable
		//as is the implied mass of the object

		speed -= 0.5f*speed*speed*linearDragCoefficient * deltaTime;
		if (speed > GetMaxVelocity()) { speed = GetMaxVelocity(); }
		if (speed < 0) { speed = 0; }
		//now set xVelocyt and yVelocity
		// for X: speed = sqrt(xVelocity^2 + (xVelocity*slope)^2)
		//speed^2 = xVelocyt^2 + (xVelocity*slope)^2
		//speed^2 = xVelocty^2 + xVelocity^2*slope^2
		//speed^2/xVelocty^2 = 1 + slope^2
		//1/xVelocty^2 = (1 + slope^2)/speed^2
		//xVelocty^2 = speed^2/ (1 + slope^2)
		//xVelocty = sqrt(speed^2/ (1 + slope^2))
		float newXVel = sqrtf((speed * speed) / ((1 + slope * slope)));
		if (xVelocity > 0) {
			xVelocity = newXVel;
		} else {
			xVelocity = -newXVel;
		}

		//for Y: speed = sqrt(yVelocity^2 + (yVelocity/slope)^2)
		//speed^2 = yVelocity^2 + (yVelocity/slope)^2
		//speed^2 = yVelocity^2 + yVelocity^2/slope^2
		//speed^2/yVelocity^2 = 1 + 1/slope^2
		//1/yVelocity^2 = (1 + 1/slope^2)/speed^2
		//yVelocity^2 = speed^2/(1 + 1/slope^2)
		//yVelocity = sqrt(speed^2/(1 + 1/slope^2))


		float newYVel = sqrtf((speed * speed) / ((1 + 1 / (slope * slope))));
		if (yVelocity > 0) {
			yVelocity = newYVel;
		} else {
			yVelocity = -newYVel;
		}
	}



	//dampen rotational speed;
	if (abs(clockwiseVelocity) > 0) {
		float drag = 0.5* clockwiseVelocity* clockwiseVelocity * rotationalDragCoefficent*deltaTime;

		if (clockwiseVelocity > 0) {
			clockwiseVelocity -= drag;
			if (abs(clockwiseVelocity) > GetMaxAngularVelocity()) {
				clockwiseVelocity = maxAngularVelocity;
			}
		} else {
			clockwiseVelocity += drag;
			if (abs(clockwiseVelocity) > GetMaxAngularVelocity()) {
				clockwiseVelocity = -maxAngularVelocity;
			}
		}
	}

}


void Combatant::Tick(float deltaTime) {
	
}

void Combatant::Move(float x, float y) {
	xPosition += x;
	yPosition += y;
}

void Combatant::Rotate(float rotAngle) {
	angle += rotAngle;
}

float Combatant::GetXVelocity() {
	return xVelocity;
}

float Combatant::GetYVelocity() {
	return yVelocity;
}

float Combatant::GetXPosition() {
	return xPosition;
}

float Combatant::GetYPosition() {
	return yPosition;
}

float Combatant::GetHitBoxRadius() {
	return hitBoxRadius;
}

float Combatant::DistanceTo(Combatant* other) {
	float xDiff = other->GetXPosition();
	float yDiff = other->GetYPosition();

	return sqrtf(xDiff*xDiff + yDiff * yDiff);
}

float Combatant::GetRotation() {
	return angle-90;
}

float Combatant::GetRotationalVelocity() {
	return clockwiseVelocity;
}

void Combatant::ThrustForwards(float thrust) {
	xVelocity += thrust * cos(GetRotation() /180 * M_PI); 
	yVelocity += thrust * sin(GetRotation() / 180 * M_PI);
}

void Combatant::ThrustRight(float thrust) {
	xVelocity += thrust * cos((GetRotation()+90) / 180 * M_PI);
	yVelocity += thrust * sin((GetRotation()+90) / 180 * M_PI);
}

void Combatant::ThrustClockwise(float thrust) {
	clockwiseVelocity += thrust;
}

float Combatant::GetMaxVelocity() {
	return maxVelocity;
}


float Combatant::GetMaxAngularVelocity() {
	return maxAngularVelocity;
}
