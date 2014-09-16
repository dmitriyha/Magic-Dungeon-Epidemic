#include "Texture.h"
/** \brief used for inheritance
 *
 */    
Texture::Texture(){
}

/** \brief Creates a Texture with picture at given path.
 *
 * \param path The path of the target image to be loaded.
 * \param _screen The top level screen that has to be acquired at the beginning of the program, where the texture will be blitted.
 *
 */     

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

/** \brief Render this texture at the given location.
 *
 * \param offset The location where the texture will be blitted.
 *
 */     


void Texture::render( SDL_Rect offset){
	//Set rendering space and render to screen
	if (width > 70){
		offset.w = width;
		offset.h = height;
	}
	else{
		offset.w = TILE_WIDTH;
		offset.h = TILE_HEIGHT*2;
	}
	SDL_RenderCopy( screen, texture, NULL, &offset );
}

/** \brief Use this for sprite textures
 *
 * Render the certain sprite tile in a certain location on the screen
 *
 * \param locOnSpriteSheet The top right corner location of the wanted sprite on the sprite sheet.
 * \param location Where the sprite will be on the screen
 *
 */     


void Texture::renderTile( SDL_Rect locOnSpriteSheet,SDL_Rect location ){
	//Set rendering space and render to screen
	if(location.w==0&&location.h==0){
		location.w= TILE_WIDTH;
		location.h= TILE_HEIGHT ;
	}
	SDL_RenderCopy( screen, texture, &locOnSpriteSheet, &location );
}

/** \brief Frees the resources allocated to this Texture.
 *
 */     


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

