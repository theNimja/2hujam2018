#include <iostream>
#include <SDL.h>


#include "PlayerData.h"

using namespace std;


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




int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL initialization failed. Error: " << SDL_GetError();
		return 0;
	} else {
		cout << "SDL initialization succeeded!";
	}
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 0;
	} else {

		PlayerData player = PlayerData();

		ShowBuyScreen(gWindow, &player);

		// play the first level
		PlayLevel(gWindow, &player, 1);
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
	//get  window surface from window


	//initialise player combat object from playerData
	//if first level, give the player some initial fuel




	while (true) {
		

		//check if player has just finished death animation
			//return PlayLevelReturnValues::FAILED

		//check if player has just finished level warp animation
			//deconstruct all objects being used
			//return PlayLevelReturnValues::NEXTLEVEL

		//process inputs (clicks on buttons, closing game)

		//if quit,
			//return PlayLevelReturnValues::QUITGAME;


		//for controls, pass these along to player, they will convert this to thrust and vectoring

		//get inputs this turn for enemies

		//process movement for all combatants

		//check for collisions, process damage as appropriate

		//level specific effects, i.e, spawn enemies

		//render screen

	
	}



}


