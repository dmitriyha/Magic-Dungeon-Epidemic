#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "GlobalDef.h"
using namespace std;

/** \brief class used for showing images on the screen
 */     


class Texture{
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int width;
	int height;
	public:
		Texture();
		Texture(string path,SDL_Renderer* screen);
		void render( SDL_Rect offset );
		void renderTile( SDL_Rect textureLoc,SDL_Rect renderQuad);
		~Texture();
	protected:
		void makeTexture(string path);
		void makeBlankTexture(int _width, int _height);
		SDL_Rect getSize();
		SDL_Texture* getTexture();
		void setRenderer(SDL_Renderer* _renderer);
		SDL_Renderer* getRenderer();
		void free();
	private:
		
};

#endif // TEXTURE_H
