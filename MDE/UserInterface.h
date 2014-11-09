#pragma once
#include <SDL.h>
#include "Texture.h"
#include "TextTexture.h"
#include "CameraStruct.h"

class UserInterface{
	Texture* backroundTexture;
	Texture* level_bar;
	Texture* inventoryBackground;
	Texture* curs;
	Texture* itemTexture;
	CameraStruct* camData;

	TextTexture* carbon18;

	
public:
	UserInterface();
	void initialize(CameraStruct* _camData,Texture* _backgroundTexture,Texture* _itemTexture);
	void render();
	~UserInterface();
private:
	void background();
	void text();
	void inventory();
};

