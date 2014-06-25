#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "GlobalDef.h"
using namespace std;

class Texture{
	
	public:
		Texture();
		Texture(string path,SDL_Renderer* screen);
		void render( SDL_Rect offset );
		void renderTile( SDL_Rect textureLoc,SDL_Rect renderQuad);
		~Texture();
	protected:
		SDL_Texture* texture;
		SDL_Renderer* screen;
		int width,height;
		void free();
	private:
		
};

#endif // TEXTURE_H
