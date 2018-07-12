#include "Combatant.h"
#include <math.h>


Combatant::Combatant() {
}


Combatant::~Combatant() {
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

	float drag = 0.5* clockwiseVelocity* clockwiseVelocity * rotationalDragCoefficent*deltaTime;
	if (rotationalDragCoefficent > 0) {
		clockwiseVelocity -= drag;
	} else {
		clockwiseVelocity += drag;
	}

}


void Combatant::Tick(float deltaTime) {
	
}

void Combatant::Move(float x, float y) {
	xPosition += x;
	yPosition += y;
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
