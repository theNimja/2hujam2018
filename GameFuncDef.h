#pragma once
#include <SDL.h>
#include "SDL_Operations.h"
#include "Bullet.h"
#include "Combatant.h"
#include <string>
#include <vector>

void update(SDL_Renderer * Renderer, SDL_Rect &destRect, SDL_Texture * texture);
void updateNoClear(SDL_Renderer * Renderer, SDL_Rect &destRect, SDL_Texture * texture);
void destroy(SDL_Texture* texture, SDL_Window* window, SDL_Renderer* renderer);
//void splashScreen(SDL_Renderer* renderer);
SDL_Rect initRect(int16_t x, int16_t y);
void upgradeMenu(SDL_Renderer* renderer);
void gameLoop();