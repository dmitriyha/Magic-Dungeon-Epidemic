#include "Texture.h"

Texture::Texture(){
}

Texture::Texture(string path,SDL_Renderer* _screen){
	screen=_screen;
	texture = NULL;
	width = height = 0;
	
	free();
	
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL ){
		cout<<"Unable to load image "<< path.c_str()<<"  SDL_image Error: " << IMG_GetError() <<endl;
	}
	else{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( screen, loadedSurface );
		if( texture == NULL ){
			cout<<"Unable to create texture from "<<path.c_str()<<" SDL Error: "<< SDL_GetError() <<endl;
		}
		else{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
}

void Texture::render( SDL_Rect offset){
	//Set rendering space and render to screen
	offset.w =  width;
	offset.h=height ;
	SDL_RenderCopy( screen, texture, NULL, &offset );
}

void Texture::renderTile( SDL_Rect locOnSpriteSheet,SDL_Rect location ){
	//Set rendering space and render to screen
	if(location.w==0&&location.h==0){
		location.w= TILE_WIDTH;
		location.h= TILE_HEIGHT ;
	}
	SDL_RenderCopy( screen, texture, &locOnSpriteSheet, &location );
}

void Texture::free(){
	if( texture != NULL ){
		SDL_DestroyTexture( texture );
		texture = NULL;
		width = 0;
		height = 0;
	}
}

Texture::~Texture(){
	free();
}

