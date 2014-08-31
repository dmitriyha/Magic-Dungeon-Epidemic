#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "GlobalDef.h"
using namespace std;

/** \brief class used for showing images on the screen
 */     


class Texture{
	
	public:
		Texture();
		Texture(string path,SDL_Renderer* screen);
		void render( SDL_Rect offset );
		void renderTile( SDL_Rect textureLoc,SDL_Rect renderQuad);
		~Texture();
	protected:
		///The texture that will be blitted.
		SDL_Texture* texture; 
		///The screen that the texture will be blitted to.
		SDL_Renderer* screen;
		/// the width of the input picture.
		int width;
		/// the height of the input picture.
		int height;
		void free();
	private:
		
};

#endif // TEXTURE_H
