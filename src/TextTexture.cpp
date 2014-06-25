#include "TextTexture.h"

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

TextTexture::~TextTexture()
{
	free();
	font=NULL;
}
