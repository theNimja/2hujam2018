#pragma once
#include <SDL.h>
#include <SDL_image.h>

enum buttonStatus {
	BUTTON_OUT = 1,
	BUTTON_IN = 2,
	BUTTON_PRESSED = 3,
};

class Button {
public:
	
	// showing area of button
	SDL_Rect buttonArea;
	
	bool isShow;
	

	bool isListen;
	
	int buttonId;

	Button();
	~Button();

	void setTexture(SDL_Texture* effectIn, SDL_Texture* effectOut, SDL_Texture* effectPressed);
	

	bool handleEvent(SDL_Event *stEvent);
	

	void setFuncPressed(void(*funcPressed)(const Button *));

	void setRect(const SDL_Rect &rect);

	SDL_Rect getRect();

	void setRenderer(SDL_Renderer* renderer);

	void render();

	SDL_Texture *getShowTexture();

private:
	
	SDL_Texture *textureIn;
	
	SDL_Texture *textureOut;
	
	SDL_Texture *texturePressed;
	
	buttonStatus status;

	SDL_Renderer* renderer;


	bool pointIn(int x, int y);

	// callback function
	void(*funcPressed)(const Button * pButton);

	
};

