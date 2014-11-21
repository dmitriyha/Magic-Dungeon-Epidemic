#pragma once

#include <SDL.h>
#include "Texture.h"
#include "TextTexture.h"
#include "CameraStruct.h"
#include "Button.h";

class UserInterface{
	//the texture in the backgtound of t
	Texture* backroundTexture;

	//the level bar texture
	Texture* level_bar;

	//the skin of the inventory
	Texture* inventoryBackground;

	//the inventory cursor texture
	Texture* curs;

	//the item textures;
	Texture* itemTexture;

	//the thepointer to the game-wide data
	CameraStruct* camData;

	//the texture used for text rendering
	TextTexture* carbon18;

	Button stoneTower;
	Button spikeTrap;

public:
	UserInterface();
	void initialize(CameraStruct* _camData, Texture* _backgroundTexture, Texture* _itemTexture);
	string eventHandler(SDL_Event event);
	void render();
	~UserInterface();
private:
	void background();
	void text();
	void inventory();

	void setText(string text, SDL_Rect offset);
};

