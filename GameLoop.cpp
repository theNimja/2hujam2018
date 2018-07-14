#include "GameFuncDef.h"

#include <list>

#include "Combatant.h"
#include "PlayerData.h"
#include "Combatant.h"
#include "PlayerCombatant.h"
#include "EnemyCombatant.h"
#include "Bullet.h"

#include "PlayerCombatant.h"


void gameLoop() {
	// init the window, render, loader, playerData here


	bool go = true;
	uint8_t gameState = 1;
	while (go) {

		// maybe main menu or splashscreen or whatever something
		if (gameState == 1) {

			//mainMenu();
			gameState = 2;
		}

		// upgrade menu
		if (gameState == 2) {

			//upgradeMenu(renderer, playerData);
			gameState = 3;
		}

		if (gameState == 3) {
			//playLevel(renderer, playerData);

		}
	}

}





//takes pointers to the screen and player data,and the level to play, plays that level in that screen with tha player, returns if the player is advancing to the next level or failed/quitted
PlayLevelReturnValues PlayLevel(SDL_Renderer* window, PlayerData* playerData, SpriteHolder* sprites, int level) {

	//TODO initialise player combat object from playerData
	//TODO if first level, give the player some initial fuel

	//play area might vary between levels
	int playAreaX = 1024;
	int playAreaY = 762;


	//TODO place player at starting location
	PlayerCombatant player = PlayerCombatant(sprites, 0, 0,
		playerData);
	player.Move(playAreaX / 2 - player.GetXPosition(), playAreaY / 2 - player.GetYPosition());

	//create list of combatants
	std::list<Combatant*> combatants = std::list<Combatant*>();
	//TODO add player to combatants
	combatants.push_back(&player);
	//start timer

	float deltaTime = SDL_GetTicks() / 1000000.0;
	while (true) {
		//get delta time
		deltaTime = SDL_GetTicks() / 1000000.0 - deltaTime;

		//get input events

		bool pressW = false;
		bool pressS = false;
		bool pressA = false;
		bool pressD = false;
		bool pressQ = false;
		bool pressE = false;
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				return PlayLevelReturnValues::QUIT;
			}

		}

		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		if (currentKeyStates[SDL_SCANCODE_W]) {
			pressW = true;
		}
		if (currentKeyStates[SDL_SCANCODE_A]) {
			pressA = true;
		}
		if (currentKeyStates[SDL_SCANCODE_S]) {
			pressS = true;
		}
		if (currentKeyStates[SDL_SCANCODE_D]) {
			pressD = true;
		}
		if (currentKeyStates[SDL_SCANCODE_Q]) {
			pressQ = true;
		}
		if (currentKeyStates[SDL_SCANCODE_E]) {
			pressE = true;
		}

		//TODO check if player has just finished death animation
		//return PlayLevelReturnValues::FAILED, or spawn a new player

		//TODO check if player has just finished level warp animation
		//deconstruct all objects being used
		//return PlayLevelReturnValues::NEXTLEVEL

		//process inputs (clicks on buttons, closing game)

		//for controls, pass these along to player, they will convert this to thrust and vectoring

		//TODO get inputs this turn for enemies
		for (Combatant* i : combatants) {
			//get input and apply thrust

			PlayerCombatant* player = dynamic_cast<PlayerCombatant*>(i);
			//TODO: reduce fuel, launch jets
			if (player) {
				float rotateThrust = 40.0;
				float verticalThrust = 50.0;
				float lateralThrust = 30.0;

				Bullet* newBullet = nullptr;

				if (pressQ) {
					player->ThrustClockwise(-rotateThrust * deltaTime);
				}
				if (pressE) {
					player->ThrustClockwise(rotateThrust * deltaTime);
				}
				if (pressW) {
					player->ThrustForwards(verticalThrust * deltaTime);
					newBullet = player->Fire(0, sprites);
				}
				if (pressS) {
					player->ThrustForwards(-verticalThrust * deltaTime);
					newBullet = player->Fire(180, sprites);
				}
				if (pressA) {
					player->ThrustRight(-lateralThrust * deltaTime);
					newBullet = player->Fire(90, sprites);
				}
				if (pressD) {
					player->ThrustRight(lateralThrust * deltaTime);
					newBullet = player->Fire(90, sprites);
				}


				if (newBullet) {
					combatants.push_back(newBullet);
				}
			}

		}



		//TODO process movement for all combatants
		for (Combatant* i : combatants) {
			//move combatant
			i->Move(i->GetXVelocity()*deltaTime, i->GetYVelocity()*deltaTime);

			i->Rotate(i->GetRotationalVelocity()*deltaTime);

			//printf("Speed:%f,%f,%f\n", i->GetXVelocity(), i->GetYVelocity(), i->GetRotationalVelocity());
			//TODO check for collisions, process damage as appropriate

			//differnt collision checks for different types

			PlayerCombatant* player = dynamic_cast<PlayerCombatant*>(i);
			if (player) {

				//bump back into bounds
				if (i->GetXPosition() > playAreaX) {
					i->Move(-(playAreaX - i->GetXPosition()) - 1, 0);
				}
				if (i->GetYPosition() > playAreaY) {
					i->Move(0, -(playAreaY - (i->GetYPosition())) - 1);
				}
				if (i->GetXPosition() < 0) {
					i->Move(-(i->GetXPosition()) + 1, 0);
				}
				if (i->GetYPosition() < 0) {
					i->Move(0, -(i->GetYPosition()) + 1);
				}

				//loop through other objects


				for (Combatant* j : combatants) {
					if (j != player) {
						if (player->DistanceTo(j) < (player->GetHitBoxRadius() + j->GetHitBoxRadius())) {
							Bullet* b = static_cast<Bullet*>(j);
							EnemyCombatant* e = static_cast<EnemyCombatant*>(j);
							//if we hit an enemy, or a bullet that was not fired by us
							bool doWeDie = false;
							if (e != nullptr) {
								doWeDie = true;
								if (b != nullptr) {
									if (b->shooter != player) {
										doWeDie = true;
									}
								}
								if (doWeDie) {

									//we've been hit by a bullet or enemy
									//TODO we're hit, drop the death explosion object, destroy the player object, wait for a new one to be spawned, loase fuel, lose a life
								}
							}

						}
					}
				}


				//TODO Enemy:
				EnemyCombatant* enemy = dynamic_cast<EnemyCombatant*>(i);
				if (enemy) {

					//bump back into bounds
					if (i->GetXPosition() > playAreaX) {
						i->Move(-(playAreaX - i->GetXPosition()) - 1, 0);
					}
					if (i->GetYPosition() > playAreaY) {
						i->Move(0, -(playAreaY - (i->GetYPosition())) - 1);
					}
					if (i->GetXPosition() < 0) {
						i->Move(-(i->GetXPosition()) + 1, 0);
					}
					if (i->GetYPosition() < 0) {
						i->Move(0, -(i->GetYPosition()) + 1);
					}
					//TODO check for collision with other enemy, if so, move away from them
					//check for collision with jet, it so, drop explosion and die
					for (Combatant* j : combatants) {
						if (j != i) {
							if (i->DistanceTo(j) < (i->GetHitBoxRadius() + j->GetHitBoxRadius())) {
								Bullet* b = static_cast<Bullet*>(j);
								if (b != nullptr) {
									if (b->shooter == player) {
										//TODO if we're hit, drop the death explosion object, destroy yourself
									}
								}
							}

						}
					}


				}


				//Projectile 

				Bullet* bullet = dynamic_cast<Bullet*>(i);
				if (bullet) {
					//destroy bullet
					if (i->GetXPosition() > playAreaX || i->GetYPosition() > playAreaY || i->GetXPosition() < 0 || i->GetXPosition() > playAreaY) {
						combatants.remove(bullet);
						delete bullet;
					} else {
						for (Combatant* j : combatants) {
							if (j != i) {
								if (i->DistanceTo(j) < (i->GetHitBoxRadius() + j->GetHitBoxRadius())) {
									Combatant* c = static_cast<Combatant*>(j);
									if (c != nullptr) {
										if (bullet->shooter == c) {
											//we touched our own shooter,dissapear
											combatants.remove(bullet);
											delete bullet;
										}
									}
								}

							}
						}
					}

				}
				i->Tick(deltaTime, sprites);
			}
			//TODO level specific effects, i.e, spawn enemies

			//render screen
			RenderGameScreen(window, &combatants);


		}

		//we should never exit the loop
	}
}



void RenderGameScreen(SDL_Renderer * window, std::list<Combatant*>* combatants) {
	//clear screen
	SDL_RenderClear(window);
	//TODO draw background

	//loop through combatants
	for (Combatant* i : *combatants) {
		//draw combatant
		SDL_Texture* textureToDraw = i->GetTexture();
		if (textureToDraw) {
			SDL_Rect destRect = SDL_Rect();
			//set destination rectangle parameters
			//TODO: account for screen size =/= play area
			SDL_QueryTexture(textureToDraw, NULL, NULL, &destRect.w, &destRect.h);
			destRect.x = i->GetXPosition() - destRect.w / 2;
			destRect.y = i->GetYPosition() - destRect.h / 2;
			SDL_RenderCopyEx(window, textureToDraw, NULL, &destRect, i->GetRotation(), NULL, SDL_FLIP_NONE);
		} else {
			printf("Found no texture to draw");
		}

	}



	//TODO draw other data like fuel


	//update screen
	SDL_RenderPresent(window);

}
