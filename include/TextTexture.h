#ifndef TEXTTEXTURE_H
#define TEXTTEXTURE_H

#include <Texture.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class TextTexture : public Texture{
	TTF_Font * font;
	SDL_Color textColor;
	string path;
	public:
		TextTexture(string path,SDL_Color textColor,int fontSize,SDL_Renderer* screen);
		void setText(string text);
		~TextTexture();
	protected:
	private:
};

#endif // TEXTTEXTURE_H
