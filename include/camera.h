#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#include "GlobalDef.h"
#include <deque>
#include "Item.h"
#include "ReadFile.h"
#include <SDL2/SDL_ttf.h>
#include "player.h"
#include "Texture.h"
#include "TextTexture.h"
#include "MapDataStructs.h"
#include "CameraStruct.h"
using namespace std;

class Camera{
	
	deque<SDL_Rect> itemTextures;
	deque<int> item_number;
	
	///the textures
	Texture* player;
	Texture* enemy;
	Texture* tile_set;
	Texture* inventoryBMP;
	Texture* curs;
	Texture* item_surface;
	Texture* UI;
	Texture* level_bar;
	
	
	TextTexture * carbon18;//message
	
	///the floor sprite data
	SDL_Rect floor;
	SDL_Rect top_wall;
	SDL_Rect top_left_corner;
	SDL_Rect left_wall;
	SDL_Rect bottom_left_corner;
	SDL_Rect bottom_wall;
	SDL_Rect bottom_right_corner;
	SDL_Rect right_wall;
	SDL_Rect top_right_corner;
	SDL_Rect blank;
	SDL_Rect stairs_up;
	SDL_Rect stairs_down;
	
	SDL_Renderer* screen;
	CameraStruct* camData;
	
	TTF_Font * airmole = TTF_OpenFont( "img\\carbon.ttf", 23 );
	TTF_Font * carbon = TTF_OpenFont( "img\\carbon.ttf", 18);
	
	SDL_Rect offset;
	
	public:
		Camera(CameraStruct* camData,SDL_Renderer* screen);
		void renderScreen();
		~Camera();
	private:
		void renderAll();
		void inventoryRender();
		void user_interface();
		void print_dmg();
		void game_over();	
};

	#endif
