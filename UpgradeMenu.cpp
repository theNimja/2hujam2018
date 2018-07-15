#pragma once


#include "GameFuncDef.h"
#include "SDL_Operations.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "PlayerData.h"
#include "Combatant.h"
#include "PlayerCombatant.h"
#include "EnemyCombatant.h"
#include "Bullet.h"
#include "Button.h"
#include <list>


// updates all of the drawing functions
void update(SDL_Renderer * Renderer, SDL_Rect &destRect, SDL_Texture * texture){

	// set the background colour
	SDL_SetRenderDrawColor(Renderer, 0xff, 0xff, 0xff, 0xff);

	// TODO: something wrong here
	// query the width and height of texture(I am not familar with this part, possiblely wrong)
	SDL_QueryTexture(texture, NULL, NULL, &destRect.w, &destRect.h);

	// apply renderer
	SDL_RenderCopy(Renderer, texture, NULL, &destRect);
	SDL_RenderPresent(Renderer);
	SDL_RenderClear(Renderer);
}

// update witout clean screen
void updateNoClear(SDL_Renderer * Renderer, SDL_Rect &destRect, SDL_Texture * texture){

	SDL_SetRenderDrawColor(Renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_QueryTexture(texture, NULL, NULL, &destRect.w, &destRect.h);
	SDL_RenderCopy(Renderer, texture, NULL, &destRect);
}


void destroy(SDL_Texture* texture, SDL_Window* window, SDL_Renderer* renderer){

	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

//void helpScreen(SDL_Renderer * renderer)
//{
//	// TODO: might need a helpScreen
//}
//
//void splashScreen(SDL_Renderer* renderer)
//{
//	// TODO: might need a splashScreen
//}


void test(BuyScreenReturnValues x) {
	std::cout << "function ptr invoke succeeded!";
}

void openGame(BuyScreenReturnValues x) {
	x = BuyScreenReturnValues::NEWRUN;
}

void fuelDataPlus(PlayerData* player) {
	player->TryUpgradeFuelTank();
}

void fuelDataMinus(PlayerData* player) {
	player->TryDowngradeFuelTank();
}

//takes pointers to the screen and player data, the player in this function will be upgraded, returns if the player is quitting the game, starting a new run, or saving(?)
BuyScreenReturnValues upgradeMenu(SDL_Renderer* renderer, PlayerData* player){

	bool go = true;

	std::list<Button*> buttons = std::list<Button*>();


	
	Button fuelMinus(test);
	fuelMinus.buttonId = 1;
	SDL_Color textColor = { 0, 0, 0 };
	SDL_Color pressedColor = { 114, 115, 93 };
	fuelMinus.setRenderer(renderer);
	SDL_Texture *mtextTexture = loadFontTexture(renderer, "comic.ttf", 28, "-", textColor);
	SDL_Texture *mpressedTexture = loadFontTexture(renderer, "comic.ttf", 28, "-", pressedColor);
	fuelMinus.setTexture(mtextTexture, mtextTexture, mpressedTexture);

	buttons.push_back(&fuelMinus);

	Button showFuel(test);
	showFuel.buttonId = 1;
	showFuel.setRenderer(renderer);
	
	int fuelx = player->GetFuel();
	std::string fuel = "current fuel: " + std::to_string(fuelx);
	SDL_Texture *stextTexture = loadFontTexture(renderer, "comic.ttf", 28, fuel, textColor);
	SDL_Texture *spressedTexture = loadFontTexture(renderer, "comic.ttf", 28, fuel, pressedColor);
	showFuel.setTexture(stextTexture, stextTexture, spressedTexture);
	
	buttons.push_back(&showFuel);

	Button fuelPlus( test );
	fuelPlus.buttonId = 1;
	fuelPlus.setRenderer(renderer);
	SDL_Texture *ptextTexture = loadFontTexture(renderer, "comic.ttf", 28, "+", textColor);
	SDL_Texture *ppressedTexture = loadFontTexture(renderer, "comic.ttf", 28, "+", pressedColor);
	fuelPlus.setTexture(ptextTexture, ptextTexture, ppressedTexture);

	buttons.push_back(&fuelPlus);

	Button startGame(openGame);
	startGame.isStartGameButton = true;
	startGame.buttonId = 2;
	fuelPlus.setRenderer(renderer);
	SDL_Texture *gtextTexture = loadFontTexture(renderer, "comic.ttf", 28, "start game!", textColor);
	SDL_Texture *gpressedTexture = loadFontTexture(renderer, "comic.ttf", 28, "oh yeah", pressedColor);
	startGame.setTexture(gtextTexture, gtextTexture, gpressedTexture);

	buttons.push_back(&startGame);

	

	//SDL_Texture *textureIn = loadFontTexture(renderer, "comic.ttf", 28, "text", textColor);
	//SDL_Texture *textureOut = loadFontTexture(renderer, "comic.ttf", 28, "text", textColor);
	//SDL_Texture *texturePressed = loadFontTexture(renderer, "comic.ttf", 28, "text", textColor);
	//testButton.setTexture(textureIn, textureOut, texturePressed);
	
	SDL_Rect destRect = SDL_Rect();

	// TODO: set the rectangular for each element
	SDL_Texture *bgTexture = NULL;
	bgTexture = loadTexture("marisa.png", renderer);
	int buttonLength = 0;
	const int INTERVAL = 20;

	while (go){

		

		SDL_Event e;
		SDL_PollEvent(&e);

		// Switch the event type
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				go = false;
			}
		}
		showFuel.handleEvent(&e);
		fuelPlus.handleEvent(&e);
		fuelMinus.handleEvent(&e);
		startGame.handleEvent(&e);

		for (Button* b : buttons) {
			if (b->statusFlag == BuyScreenReturnValues::NEWRUN) {
				return BuyScreenReturnValues::NEWRUN;
			}
		}

		SDL_RenderClear(renderer);
		
		SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
		//SDL_Texture* textureToDraw = showFuel.getShowTexture();
		//SDL_QueryTexture(textureToDraw, NULL, NULL, &destRect.w, &destRect.h);
		//destRect.x = 500;
		//destRect.y = 200;
		//showFuel.setRect(destRect);
		//
		//SDL_RenderCopy(renderer, textureToDraw, NULL, &destRect);
		
		//fuelx = player->GetFuel();
		//fuel = "current fuel: " + std::to_string(fuelx);
		//stextTexture = loadFontTexture(renderer, "comic.ttf", 28, fuel, textColor);
		//spressedTexture = loadFontTexture(renderer, "comic.ttf", 28, fuel, pressedColor);
		//showFuel.setTexture(stextTexture, stextTexture, spressedTexture);
		

		for (Button* b : buttons) {
			SDL_Texture* textureToDraw = b->getShowTexture();
			if (textureToDraw == NULL) {
				std::cout << std::to_string(b->buttonId) + " load button show texture fail " << SDL_GetError() << std::endl;
			}
			SDL_Rect destRect = SDL_Rect();
			SDL_QueryTexture(textureToDraw, NULL, NULL, &destRect.w, &destRect.h);
			destRect.x = 380 + buttonLength;
			destRect.y = 100 * b->buttonId;
			b->setRect(destRect);
			SDL_RenderCopy(renderer, textureToDraw, NULL, &destRect);
			buttonLength += destRect.w + INTERVAL;
			
		}
		buttonLength = 0;

		//showFuel.render(400, 100);
		//fuelMinus.render(380, 100);
		//fuelPlus.render(600, 100);
		//SDL_RenderCopy(renderer, bgTexture, NULL, NULL);


		
		
		


		
		
		SDL_RenderPresent(renderer);
		// TODO: renderer part
	}
	return BuyScreenReturnValues::QUITGAME;
}



