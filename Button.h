#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <functional>
#include "GameFuncDef.h"

enum buttonStatus {
	BUTTON_OUT = 1,
	BUTTON_IN = 2,
	BUTTON_PRESSED = 3,
};

class Button {
public:
	BuyScreenReturnValues statusFlag;

	bool isStartGameButton;

	// showing area of button
	SDL_Rect buttonArea;
	
	bool isShow;
	

	bool isListen;
	
	int buttonId;

	std::function<void(BuyScreenReturnValues)> funcPtr;
	std::function<void()> nfuncPtr;

	Button(std::function<void(BuyScreenReturnValues)> fp);
	Button(std::function<void()> nfp);
	~Button();

	void setTexture(SDL_Texture* effectIn, SDL_Texture* effectOut, SDL_Texture* effectPressed);
	

	bool handleEvent(SDL_Event *stEvent);

	

	void operator() () const;

	//void setFuncPressed(void(*funcPressed)(const Button *));

	void setRect(const SDL_Rect &rect);

	SDL_Rect getRect();

	void setRenderer(SDL_Renderer* renderer);

	void render(int x, int y);

	SDL_Texture *getShowTexture();

private:
	
	SDL_Texture *textureIn;
	
	SDL_Texture *textureOut;
	
	SDL_Texture *texturePressed;
	
	buttonStatus status;

	SDL_Renderer* renderer;


	bool pointIn(int x, int y);

	// callback function
	typedef void(*funcPressed)(const Button * pButton);

	
};

