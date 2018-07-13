#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_Operations.h"
#include "Bullet.h"
#include "Combatant.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include "SpriteHolder.h"
class PlayerData;

enum BuyScreenReturnValues {
	NEWRUN,
	QUITGAME
};

enum PlayLevelReturnValues {
	NEXTLEVEL,
	QUIT,
	FAILED
};



void update(SDL_Renderer * Renderer, SDL_Rect &destRect, SDL_Texture * texture);
void updateNoClear(SDL_Renderer * Renderer, SDL_Rect &destRect, SDL_Texture * texture);
void destroy(SDL_Texture* texture, SDL_Window* window, SDL_Renderer* renderer);
//void splashScreen(SDL_Renderer* renderer);
SDL_Rect initRect(int16_t x, int16_t y);
BuyScreenReturnValues upgradeMenu(SDL_Renderer* renderer, PlayerData* player);

PlayLevelReturnValues PlayLevel(SDL_Renderer* window, PlayerData* playerData,SpriteHolder* sprites, int level);
void RenderGameScreen(SDL_Renderer * window, std::list<Combatant*>* Combatants);

