#include "SpriteHolder.h"
#include "GameFuncDef.h"
#include <SDL_image.h>
#include <map>


SpriteHolder::SpriteHolder() {
}


SpriteHolder::~SpriteHolder() {
}

SDL_Texture* SpriteHolder::GetTexture(Sprites request) {
	return spriteMap[request];
}



bool SpriteHolder::LoadGameSprites(SDL_Renderer* renderer) {
	//load player sprite
	SDL_Texture* current = loadTexture("cirnoF.png", renderer);
	if (!current) {
		printf("Failed to load!! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	spriteMap[Sprites::PLAYER] = current;

	return true;
}



