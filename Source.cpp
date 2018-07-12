#include <iostream>
#include <list>

#include <SDL.h>


#include "PlayerData.h"
#include "Combatant.h"

#include "PlayerCombatant.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 762;


enum BuyScreenReturnValues {
	NEWRUN,
	QUITGAME
};



enum PlayLevelReturnValues {
	NEXTLEVEL,
	QUITGAME,
	FAILED
};



//takes pointers to the screen and player data, the player in this function will be upgraded, returns if the player is quitting the game, starting a new run, or saving(?)
BuyScreenReturnValues ShowBuyScreen(SDL_Window* window, PlayerData* player);

//takes pointers to the screen and player data,and the level to play, plays that level in that screen with tha player, returns if the player is advancing to the next level or failed/quitted
PlayLevelReturnValues PlayLevel(SDL_Window* window, PlayerData* player, int level);

void RenderGameScreen(SDL_Window* window, std::list<Combatant*>* Combatants);


int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL initialization failed. Error: " << SDL_GetError();
		return 0;
	} else {
		std::cout << "SDL initialization succeeded!";
	}
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 0;
	} else {

		PlayerData player = PlayerData();
		while (true) {

			BuyScreenReturnValues buyResult = ShowBuyScreen(gWindow, &player);
			if (buyResult == BuyScreenReturnValues::QUITGAME) { return 0; }
			PlayLevelReturnValues playResult = PlayLevelReturnValues::NEXTLEVEL;

			int currentLevel = 0;
			// play the first level

			while (playResult == PlayLevelReturnValues::NEXTLEVEL) {
				currentLevel++;
				playResult = PlayLevel(gWindow, &player, currentLevel);
			}

			//player failed or quit
			if (playResult == PlayLevelReturnValues::QUITGAME) { return 0; }
			// if failed, will loop round to the buy screen
		}
	}


	return 0;
}


BuyScreenReturnValues ShowBuyScreen(SDL_Window* gWindow, PlayerData* player) {
	while (true) {
		//process inputs (clicks on buttons, closing game)


		//if quit, return that we're quitting
		//return BuyScreenReturnValues::QUITGAME;

		//if click, find position

			//if click position is on a button, attempt to buy whatever that button corresponds to

			//else if on start run button, return that we're starting a run
			//return BuyScreenReturnValues::NEWRUN;
		//render screen
	}


	//we should never exit the loop
}

PlayLevelReturnValues PlayLevel(SDL_Window* window, PlayerData* playerData, int level) {
	
	//TODO initialise player combat object from playerData
	//TODO if first level, give the player some initial fuel

	//play area might vary between levels
	int playAreaX = SCREEN_WIDTH;
	int playAreaY = SCREEN_HEIGHT;


	//TODO place player at starting location

	//create list of combatants
	std::list<Combatant*> combatants = std::list<Combatant*>();
	//TODO add player to combatants


	while (true) {
		//TODO get delta time
		float deltaTime;


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

			//bump back into bounds
			while (i->GetXPosition > playAreaX) {
				i->Move(-0.001, 0);
			}
			while (i->GetYPosition > playAreaY) {
				i->Move(0, -0.001);
			}
			while (i->GetXPosition < 0) {
				i->Move(0.001,0);
			}
			while (i->GetXPosition > playAreaY) {
				i->Move(0, -0.001);
			}


			//TODO check for collisions, process damage as appropriate


			//if we're the player and we're hit, drop the death explosion object, destroy the player object, wait for a new one to be spawned, loase fuel, lose a life



			i->Tick(deltaTime);
		}
		//TODO level specific effects, i.e, spawn enemies

		//TODO render screen

		

	
	}

	//we should never exit the loop



}

void RenderGameScreen(SDL_Window * window, std::list<Combatant*>* Combatants) {
	//TODO clear screen

	//TODO draw background

	//TODO loop through combatants
		//TODO draw combatant
	

	//TODO draw other data like fuel

	
	//update screen
	SDL_UpdateWindowSurface(window);

}


