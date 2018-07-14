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
	if (!LoadSprite(renderer, "cirnoF.png", Sprites::PLAYER)) { return false; }
	if (!LoadSprite(renderer, "flames1.png", Sprites::FIRE1)) { return false; }
	if (!LoadSprite(renderer, "flames2.png", Sprites::FIRE2)) { return false; }
	if (!LoadSprite(renderer, "flames3.png", Sprites::FIRE3)) { return false; }
	return true;
}

bool SpriteHolder::LoadSprite(SDL_Renderer* renderer, std::string path, Sprites id) {

	SDL_Texture* current = loadTexture(path, renderer);
	if (!current) {
		printf("Failed to load!! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	spriteMap[id] = current;
	return true;
}

