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
	
	
	public:
		Texture();
		void makeTexture(string path);
		void makeBlankTexture(int _width, int _height);
		SDL_Rect getSize();
		SDL_Texture* getTexture();
		void setRenderer(SDL_Renderer* _renderer);
		SDL_Renderer* getRenderer();
		
		~Texture();
	protected:
		SDL_Texture* texture;
		SDL_Renderer* renderer;
		int width;
		int height;
		
		void free();
	private:
		
};

#endif // TEXTURE_H
