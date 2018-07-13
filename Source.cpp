#include <iostream>
#include <list>
#include <map>
#include <SDL.h>

#include "GameFuncDef.h"
#include "SpriteHolder.h"

#include "PlayerData.h"
#include "Combatant.h"
#include "PlayerCombatant.h"
#include "EnemyCombatant.h"
#include "Bullet.h"

#include "PlayerCombatant.h"


const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 762;

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
		SDL_Renderer*
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (gRenderer == NULL) {
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
			return 0;
		}

		SpriteHolder sprites = SpriteHolder();
		if (!sprites.LoadGameSprites(gRenderer)) {
			printf("images could not be loaded!");
		}

		PlayerData player = PlayerData();

		while (true) {

			BuyScreenReturnValues buyResult = upgradeMenu(gRenderer, &player);
			if (buyResult == BuyScreenReturnValues::QUITGAME) { return 0; }
			PlayLevelReturnValues playResult = PlayLevelReturnValues::NEXTLEVEL;

			int currentLevel = 0;
			// play the first level

			while (playResult == PlayLevelReturnValues::NEXTLEVEL) {
				currentLevel++;
				playResult = PlayLevel(gRenderer, &player, &sprites, currentLevel);
			}

			//player failed or quit
			if (playResult == PlayLevelReturnValues::QUIT) { return 0; }
			// if failed, will loop round to the buy screen
		}
	}


	return 0;
}



