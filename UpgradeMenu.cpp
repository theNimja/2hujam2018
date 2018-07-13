#include "GameFuncDef.h"
#include "PlayerData.h"
#include "Combatant.h"
#include "PlayerCombatant.h"
#include "EnemyCombatant.h"
#include "Bullet.h"


enum BuyScreenReturnValues {
	NEWRUN,
	QUITGAME
};

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
	img::newImageLoad Title();
	img::newImageLoad playButton();
	img::newImageLoad cursor();
	img::newImageLoad squares();

	// Save to a Texture
	SDL_Texture* TitleTexture = Title.convertToTexture(renderer);
	SDL_Texture* pButtonTexture = playButton.convertToTexture(renderer);
	SDL_Texture* cursorTexture = cursor.convertToTexture(renderer);
	SDL_Texture* squareTexture = squares.convertToTexture(renderer);

	// TODO: set the rectangular for each element


	while (go){

		SDL_Event event;
		SDL_PollEvent(&event);

		// Switch the event type
		switch (event.type){

			// when the mouse is pressed then check for a collision
		case SDL_MOUSEBUTTONDOWN:
			// TODO: buttons
			break;
		case SDL_MOUSEMOTION:
			// TODO: cursor position
			break;
		case SDL_QUIT:
			return BuyScreenReturnValues::QUITGAME;
		}
		// TODO: renderer part
	}
}



