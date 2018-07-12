#include <iostream>
#include <SDL.h>
using namespace std;


const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 762;


//takes pointers to the screen and player data, the player in this function will be upgraded, returns if the player is quitting the game, starting a new run, or saving(?)
void ShowBuyScreen(SDL_Window* window, Player* player);

//takes pointers to the screen and player data,and the level to play, plays that level in that screen with tha player, returns if the player is advancing to the next level or failed/quitted
void PlayLevel(SDL_Window* window, Player* player,int level);




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

		ShowBuyScreen(gWindow, player);



		// play the first level
		PlayLevel(gWindow, player,1);
	}


	return 0;
}



