#pragma once
#include <SDL.h> 
#include <iostream>
#include <stdint.h>

SDL_Window *window();
SDL_Renderer *renderer(SDL_Window *window);

void close();
SDL_Texture *loadTexture(std::string path, SDL_Renderer* renderer);
SDL_Texture *loadFontTexture(SDL_Renderer* renderer, std::string fontPath, int fontSize, std::string textureText, SDL_Color textColor);

namespace img{

	class newImageLoad{

	public:
		newImageLoad(std::string file);
		SDL_Texture *convertToTexture(SDL_Renderer *Renderer);
	private:
		std::string filename;
		SDL_Surface *surface;
	};
}