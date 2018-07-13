// TODO: might we can put playLevel part here? it would be better to work together in source.cpp

#include "GameFuncDef.h"

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