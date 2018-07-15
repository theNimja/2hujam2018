#include "Button.h"
#include <iostream>
#include <functional>
#include "PlayerData.h"
#include "GameFuncDef.h"

Button::Button(std::function<void(BuyScreenReturnValues)> fp) {
	isStartGameButton = false;
	funcPtr = fp;
	statusFlag = BuyScreenReturnValues::DONOTHING;

	isShow = true;
	isListen = true;
	status = buttonStatus::BUTTON_OUT;

	//setFuncPressed(NULL);
	buttonId = 0;
	//buttonArea = SDL_Rect();
	buttonArea.x = 0;
	buttonArea.y = 0;
	buttonArea.w = 0;
	buttonArea.h = 0;
	textureIn = NULL;
	textureOut = NULL;
	texturePressed = NULL;
	renderer = NULL;
}

Button::Button(std::function<void()> nfp) {
	isStartGameButton = false;
	nfuncPtr = nfp;
	statusFlag = BuyScreenReturnValues::DONOTHING;

	isShow = true;
	isListen = true;
	status = buttonStatus::BUTTON_OUT;

	//setFuncPressed(NULL);
	buttonId = 0;
	//buttonArea = SDL_Rect();
	buttonArea.x = 0;
	buttonArea.y = 0;
	buttonArea.w = 0;
	buttonArea.h = 0;
	textureIn = NULL;
	textureOut = NULL;
	texturePressed = NULL;
	renderer = NULL;
}

Button::~Button() {
	funcPtr = NULL;
	nfuncPtr = NULL;

	if (NULL != textureIn)
	{
		SDL_DestroyTexture(textureIn);
	}
	if (NULL != textureOut)
	{
		SDL_DestroyTexture(textureOut);
	}
	if (NULL != texturePressed)
	{
		SDL_DestroyTexture(texturePressed);
	}

}



//void Button::setFuncPressed(void(*theFuncPressed)(const Button *)) {
//	funcPressed = theFuncPressed;
//}
void Button::setTexture(SDL_Texture* surfaceIn, SDL_Texture* surfaceOut, SDL_Texture* surfacePressed) {

	textureIn = surfaceIn;
	textureOut = surfaceOut;
	texturePressed = surfacePressed;

}
bool Button::pointIn(int x, int y) {
	if (x >= buttonArea.x && x <= (buttonArea.x + buttonArea.w) && y >= buttonArea.y && y <= (buttonArea.y + buttonArea.h))
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool Button::handleEvent(SDL_Event * stEvent) {
	if (!isListen) {
		return false;
	}

	// set the action for different status
	bool bRet = false;
	if (stEvent->type == SDL_MOUSEMOTION) {
		if (status == buttonStatus::BUTTON_IN || buttonStatus::BUTTON_OUT) {
			if (pointIn(stEvent->motion.x, stEvent->motion.y)) {
				status = buttonStatus::BUTTON_IN;
				bRet = true;
			}
			else {
				status = buttonStatus::BUTTON_OUT;
			}
		}
		else if (status == buttonStatus::BUTTON_PRESSED) {
			if (!pointIn(stEvent->motion.x, stEvent->motion.y)) {
				status = buttonStatus::BUTTON_OUT;
			}
		}

	}
	else if (stEvent->type == SDL_MOUSEBUTTONDOWN) {
		if (pointIn(stEvent->button.x, stEvent->button.y)) {
			status = buttonStatus::BUTTON_PRESSED;
			bRet = true;
		}
	}
	else if (stEvent->type == SDL_MOUSEBUTTONUP) {
		buttonStatus oldStatus = status;
		if (pointIn(stEvent->button.x, stEvent->button.y)) {
			status = buttonStatus::BUTTON_IN;
			bRet = true;
		}
		else {
			status = buttonStatus::BUTTON_OUT;
		}
		if (oldStatus == buttonStatus::BUTTON_PRESSED) {
			if (isStartGameButton) {
				statusFlag = BuyScreenReturnValues::NEWRUN;
			}

			//funcPtr(statusFlag);
			//if (funcpressed != null) {
			//	funcpressed(this);
			//	bret = true;
			//}
			bRet = true;
		}
	}
	return bRet;
}

SDL_Texture * Button::getShowTexture() {
	
	if (status == buttonStatus::BUTTON_IN) {
		//std::cout << "button in" << std::endl;
		return textureIn;
	}
	else if (status == buttonStatus::BUTTON_PRESSED) {
		//std::cout << "button pressed" << std::endl;
		return texturePressed;
	}
	else {
		//std::cout << "button out" << std::endl;
		return textureOut;
	}
}

void Button::setRect(const SDL_Rect &rc)
{
	buttonArea = rc;
}

SDL_Rect Button::getRect()
{
	return buttonArea;
}

void Button::setRenderer(SDL_Renderer* renderer1)
{

	renderer = renderer1;

}

void Button::render(int x, int y)
{
	SDL_Rect xxx = SDL_Rect();
	SDL_QueryTexture(getShowTexture(), NULL, NULL, &xxx.w, &xxx.h);
	//std::cout << buttonArea.w << std::endl;
	//std::cout << buttonArea.h << std::endl;
	xxx.x = x;
	xxx.y = y;
	setRect(xxx);
	SDL_RenderCopy(renderer, getShowTexture(), NULL, &xxx);

}
