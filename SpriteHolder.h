#pragma once
#include <SDL_image.h>
#include <map>

class SpriteHolder {
public:
	
	enum Sprites {
		PLAYER
	};

	bool LoadGameSprites(SDL_Renderer* renderer);

	SDL_Texture*  GetTexture(Sprites request);



	SpriteHolder();
	~SpriteHolder();
private:
	std::map<Sprites, SDL_Texture*>  spriteMap;

};

