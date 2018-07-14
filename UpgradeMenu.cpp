#pragma once


#include "GameFuncDef.h"
#include "SDL_Operations.h"
#include <SDL_image.h>
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





//takes pointers to the screen and player data, the player in this function will be upgraded, returns if the player is quitting the game, starting a new run, or saving(?)
BuyScreenReturnValues upgradeMenu(SDL_Renderer* renderer, PlayerData* player){

	bool go = true;

	// set the class for the new image, I didn't add bmp material path since they are not ready, THEY WONT COMPILE
	//img::newImageLoad Title();
	//img::newImageLoad playButton();
	//img::newImageLoad cursor();
	//img::newImageLoad squares();

	//// Save to a Texture
	//SDL_Texture* TitleTexture = Title.convertToTexture(renderer);
	//SDL_Texture* pButtonTexture = playButton.convertToTexture(renderer);
	//SDL_Texture* cursorTexture = cursor.convertToTexture(renderer);
	//SDL_Texture* squareTexture = squares.convertToTexture(renderer);

	Button testButton;
	SDL_Rect destRect = SDL_Rect();
	//SDL_QueryTexture(textureToDraw, NULL, NULL, &destRect.w, &destRect.h);
	//testButton.setRect(buttonArea);
	testButton.setRenderer(renderer);

	SDL_Texture *textureIn = loadTexture("b1.png", renderer);
	SDL_Texture *textureOut = loadTexture("b1.png", renderer);
	SDL_Texture *texturePressed = loadTexture("b2.png", renderer);
	testButton.setTexture(textureIn, textureOut, texturePressed);


	// TODO: set the rectangular for each element
	SDL_Texture *bgTexture = NULL;
	bgTexture = loadTexture("usamiBG.png", renderer);

	while (go){

		

		SDL_Event e;
		SDL_PollEvent(&e);

		// Switch the event type
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				go = false;
			}
		}
		testButton.handleEvent(&e);
		SDL_RenderClear(renderer);
		SDL_Texture* textureToDraw = testButton.getShowTexture();
		SDL_QueryTexture(textureToDraw, NULL, NULL, &destRect.w, &destRect.h);
		//std::cout << destRect.w << std::endl;
		//std::cout << destRect.h << std::endl;
		destRect.x = 500;
		destRect.y = 200;
		testButton.setRect(destRect);
		SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
		SDL_RenderCopy(renderer, textureToDraw, NULL, &destRect);


		
		
		


		
		
		SDL_RenderPresent(renderer);
		// TODO: renderer part
	}
	return BuyScreenReturnValues::QUITGAME;
}



