#include "Texture.h"
Texture::Texture(){
	texture = NULL;
	width = height = 0;
	
	free();
}

/**	\brief	creates an image from the specified file
*	\param	the file to make the texture out of
*/
void Texture::makeTexture(string path){//makes a texture from the picture
	free();
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL){
		cout << "Unable to load image " << path.c_str() << "  SDL_image Error: " << IMG_GetError() << endl;
	}
	else{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 255, 255));

		//Create texture from surface pixels
		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL){
			cout << "Unable to create texture from " << path.c_str() << " SDL Error: " << SDL_GetError() << endl;
		}
		else{
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
}

/**	\brief	make this texture objext a blank one
*	\param	the width of this texture
*	\param	the height of this texture
*/
void Texture::makeBlankTexture(int _width, int _height){//makes a canvas
	free();
	//Create uninitialized texture 
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _width, _height);
	if (texture == NULL) {
		cout << "Unable to create blank texture! SDL Error: " << SDL_GetError() << endl;
	}
	else {
		width = _width;
		height = _height;
	}
}

/**	\brief get the size of this texture
*	\return	the size in SDL_Rect form
*/
SDL_Rect Texture::getSize(){
	SDL_Rect size;
	size.x = 0;
	size.y = 0;
	size.w = width;
	size.h = height;
	return size;
}

/**	\brief	gets the SDL_Texture object of this texture
*	\return	returns the SDL_Texture
*/
SDL_Texture* Texture::getTexture(){//gets the texture object
	if (texture == NULL) {
		return NULL;
	}
	else{
		return texture;
	}
}

/**	\brief	set renderer for rendering purposes
*	\param	SDL_Renderer* object
*/
void Texture::setRenderer(SDL_Renderer* _renderer){//sets the renderer object
	renderer = _renderer;
}

/**	\brief	get renderer for rendering purposes
*	\return	SDL_Renderer* object
*/
SDL_Renderer* Texture::getRenderer(){//gets the renderer object
	return renderer;
}

/**	\brief	frees this object for deletion or reuse
*/
void Texture::free(){//frees the texture
	if (texture != NULL){
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

Texture::~Texture(){
	free();
}

