// image Load Class
// this class is to handle the Image Loading

#include "SDL_Operations.h"

SDL_Rect initRect(int16_t x, int16_t y){

	SDL_Rect tempRect;
	tempRect.x = x;
	tempRect.y = y;
	return tempRect;
}

SDL_Window *window(){

	// initialise the SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0){

		// error handle
		std::cout << "Whoops! Something went very wrong, cannot initialise SDL :(" << SDL_GetError();
	}

	// make a whatever window
	SDL_Window *WINDOW = SDL_CreateWindow("2hujam2018", 0, 0, 0 ,0, SDL_WINDOW_SHOWN);

	// return the window
	return WINDOW;
}

SDL_Renderer *renderer(SDL_Window *window){

	// set the renderer with v-sync
	SDL_Renderer *Render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	return Render;
}

SDL_Texture *texture(SDL_Surface* iImage, SDL_Renderer* Renderer){

	// make a texture
	SDL_Texture *Texture = SDL_CreateTextureFromSurface(Renderer, iImage);
	return Texture;
}

img::newImageLoad::newImageLoad(std::string file){

	// I only do the bmp load with native SDL lib instead of SDL_image, because of some weird linker error
	filename = file;

	surface = SDL_LoadBMP(filename.c_str());

	if (surface){

		// I set cyan color as transparent colorkey
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xff));
		return;
	}

	std::cout << "image load error: " << SDL_GetError();

	SDL_Quit();
	return;
}


SDL_Texture *img::newImageLoad::convertToTexture(SDL_Renderer* Renderer){

	// make a texture, free surface
	SDL_Texture *Texture = SDL_CreateTextureFromSurface(Renderer, surface);
	SDL_FreeSurface(surface);
	return Texture;
}