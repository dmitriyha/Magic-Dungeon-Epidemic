#ifndef TEXTTEXTURE_H
#define TEXTTEXTURE_H

#include <Texture.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>




class TextTexture : public Texture{
	
	public:
		TextTexture(string path,SDL_Color textColor,int fontSize,SDL_Renderer* screen);
		void setText(string text);
		~TextTexture();
	protected:
		
	private:
		///The font file used to create the texture.
		TTF_Font * font;
		///The color of the texture.
		SDL_Color textColor;
		///path to the texture
		string path;
};

#endif // TEXTTEXTURE_H
