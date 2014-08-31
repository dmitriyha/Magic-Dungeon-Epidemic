#include "TextTexture.h"

/** \brief The constructor for TextTexture class. SubClass of Texture.
 *
 * \param _path The Path of the required texture.
 *
 * \param _textColor The required color for the texture.
 *
 * \param fontSize The size of this font texture.
 *
 * \param _screen The top level screen that has to be acquired at the beginning of the program, where the texture will be blitted.
 * 
 *
 */     

TextTexture::TextTexture(string _path,SDL_Color _textColor,int fontSize,SDL_Renderer* _screen):Texture(){
	path=_path;
	screen=_screen;
	texture = NULL;
	width = height = 0;
	
	textColor=_textColor;
	
	free();
	
	font = TTF_OpenFont( path.c_str(), fontSize );
	if(font==NULL){
		cout<<"this was null"<<endl;
		
	}
	
}

/** \brief Sets the text to be used for this texture Object.
 *	
 * If file not found, prints an error message on the console
 *
 * \param text The string that will be created as a texture.
 *
 * \return void
 *
 */     

void TextTexture::setText(string text){
	free();
	if(font==NULL){
		cout<<"this was null"<<endl;
		
	}
	SDL_Surface * textSurf=TTF_RenderText_Solid( font, text.c_str(), textColor );
	
	
	
	texture = SDL_CreateTextureFromSurface( screen, textSurf );
	if( texture == NULL ){
		cout<<"Unable to create texture from "<<path.c_str()<<" SDL Error: "<< SDL_GetError() <<endl;
	}
	else{
		//Get image dimensions
		width = textSurf->w;
		height = textSurf->h;
	}

	//Get rid of old loaded surface
	SDL_FreeSurface( textSurf );
	
}

/** \brief The destructor of the class. Frees the resources used in this class
 *
 *
 */     


TextTexture::~TextTexture()
{
	free();
	font=NULL;
}
