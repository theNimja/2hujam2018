// image Load Class
// this class is to handle the Image Loading

#include "SDL_Operations.h"
#include <SDL_ttf.h>
#include <SDL_image.h>

SDL_Texture *loadTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (!loadedSurface) {

		printf("Failed to load png! IMG_Error: %s\n", IMG_GetError());
	}
	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;
}

SDL_Texture *loadFontTexture(SDL_Renderer* renderer, std::string fontPath, int fontSize, std::string textureText, SDL_Color textColor) {
	TTF_Init();
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (font == NULL) {
		std::cout << "font load error" << TTF_GetError() << std::endl;
	}
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
	if (textSurface == NULL) {
		std::cout << "textSurface render error"<< SDL_GetError() << std::endl;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (texture == NULL) {
		std::cout << "font texture create error"<< SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(textSurface);
	return texture;

}


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