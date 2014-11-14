#include "Object.h"


Object::Object()
{
}

void Object::render(){
	SDL_RenderCopy(texture->getRenderer(), texture->getTexture(), &sprite, &location);
}

/** \brief Sets the texture to the character
*
* \param Texture* _texture: The texture which you want to set to character
*
*/
void Object::setTexture(Texture* _texture){
	texture = _texture;
}

Object::~Object()
{
}
