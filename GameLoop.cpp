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
PlayLevelReturnValues PlayLevel(SDL_Renderer* window, PlayerData* playerData, int level) {

	//TODO initialise player combat object from playerData
	//TODO if first level, give the player some initial fuel

	//play area might vary between levels
	int playAreaX = 1024;
	int playAreaY = 762;


	//TODO place player at starting location

	//create list of combatants
	std::list<Combatant*> combatants = std::list<Combatant*>();
	//TODO add player to combatants

	//start timer

	float deltaTime = SDL_GetTicks() / 1000;
	while (true) {
		//TODO get delta time
		deltaTime = SDL_GetTicks() / 1000 - deltaTime;

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
			} else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_w:
					pressW = true;
					break;
				case SDLK_a:
					pressA = true;
					break;
				case SDLK_s:
					pressS = true;
					break;
				case SDLK_d:
					pressD = true;
					break;
				case SDLK_q:
					pressQ = true;
					break;
				case SDLK_e:
					pressE = true;
					break;
				default:
					break;
				}
			
			}
		}

		//TODO check if player has just finished death animation
		//return PlayLevelReturnValues::FAILED, or spawn a new player

		//TODO check if player has just finished level warp animation
		//deconstruct all objects being used
		//return PlayLevelReturnValues::NEXTLEVEL

		//TODO process inputs (clicks on buttons, closing game)

		//TODO if quit,
		//return PlayLevelReturnValues::QUITGAME;


		//TODO for controls, pass these along to player, they will convert this to thrust and vectoring

		//TODO get inputs this turn for enemies
		for (Combatant* i : combatants) {
			//TODO get input and apply thrust
		}



		//TODO process movement for all combatants
		for (Combatant* i : combatants) {
			//move combatant
			i->Move(i->GetXVelocity()*deltaTime, i->GetYVelocity()*deltaTime);




			//TODO check for collisions, process damage as appropriate

			//differnt collision checks for different types

			PlayerCombatant* player = static_cast<PlayerCombatant*>(i);
			if (player != nullptr) {

				//bump back into bounds
				while (i->GetXPosition() > playAreaX) {
					i->Move(-0.001, 0);
				}
				while (i->GetYPosition() > playAreaY) {
					i->Move(0, -0.001);
				}
				while (i->GetXPosition() < 0) {
					i->Move(0.001, 0);
				}
				while (i->GetXPosition() > playAreaY) {
					i->Move(0, -0.001);
				}

				//loop through other objects


				for (Combatant* j : combatants) {
					if (j != player) {
						Bullet* b = static_cast<Bullet*>(j);
						EnemyCombatant* e = static_cast<EnemyCombatant*>(j);
						if (b != nullptr || e != nullptr) {
							if (player->DistanceTo(j) < (player->GetHitBoxRadius() + j->GetHitBoxRadius())) {
								//we've been hit by a bullet or enemy
								//TODO if we're hit, drop the death explosion object, destroy the player object, wait for a new one to be spawned, loase fuel, lose a life
							}
						}

					}
				}
			}


			//TODO Enemy:
			EnemyCombatant* enemy = static_cast<EnemyCombatant*>(i);
			if (enemy != nullptr) {

				//bump back into bounds
				while (i->GetXPosition() > playAreaX) {
					i->Move(-0.001, 0);
				}
				while (i->GetYPosition() > playAreaY) {
					i->Move(0, -0.001);
				}
				while (i->GetXPosition() < 0) {
					i->Move(0.001, 0);
				}
				while (i->GetXPosition() > playAreaY) {
					i->Move(0, -0.001);
				}
				//TODO check for collision with other enemy, if so, move away from them
				//TODO check for collision with jet, it so, drop explosion and die

			}

			//Projectile 

			Bullet* bullet = static_cast<Bullet*>(i);
			if (bullet != nullptr) {
				//destroy bullet
				if (i->GetXPosition() > playAreaX || i->GetYPosition() > playAreaY || i->GetXPosition() < 0 || i->GetXPosition() > playAreaY) {
					combatants.remove(bullet);
					delete bullet;
				}
			}
			i->Tick(deltaTime);
		}
		//TODO level specific effects, i.e, spawn enemies

		//render screen
		RenderGameScreen(window, &combatants);


	}

	//we should never exit the loop



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
			SDL_RenderCopyEx(window, textureToDraw, NULL, NULL, i->GetRotation(),NULL,SDL_FLIP_NONE);
		}

	}
	


	//TODO draw other data like fuel


	//update screen
	SDL_RenderPresent(window);

}