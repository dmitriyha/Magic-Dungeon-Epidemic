#include "Building.h"

Building::Building(){

}
/** \brief Sets building stats
*
* \return the current health
*
*/
void  Building::set_stats(int healths, int strengths, int damages, int accuracys, int lucks, int ID){
	health = healths;
	strength = strengths;
	damage = damages;
	accuracy = accuracys;
	luck = lucks;
	id = ID;
}


void Building::render(){

	SDL_Rect charLoc = { coord[0] * TILE_WIDTH, ((coord[1] - 1) * TILE_HEIGHT), TILE_WIDTH, TILE_HEIGHT * 2 };

	SDL_RenderCopy(texture->getRenderer(), texture->getTexture(), &charSprite, &charLoc);
}

void Building::setTexture(Texture* _texture){
	texture = _texture;
}
/** \brief the getter of health
*
* \return the current health
*
*/
int  Building::Health(void){
	return health;
}

/** \brief the damage function
*
* \return if the building is alive, returns true, if dead, returns false
*
*/

bool  Building::Health(int damage){
	health = health - damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the building
*
* \return the ID of the entity
*
*/


int  Building::getID(){
	return id;
}

/** \brief lets the building know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/


void  Building::setCoords(int x, int y){
	coord[0] = x;
	coord[1] = y;
}

/** \brief the coordinate getter of the building
*
* \return a 2 element array with x and y coordinates
*
*/



int*  Building::getCoords(){
	return coord;
}





/** \brief Strength getter
*
* \return strength attribute
*
*/
int  Building::Strength(){
	return strength;
}


/** \brief Strength getter
*
* \return strength attribute
*
*/
int  Building::Damage(){
	return damage;
}

/** \brief accuracy getter
*
* \return accuracy attribute
*
*/


int  Building::Accuracy(){
	return accuracy;
}







/** \brief Luck getter
*
* \return Luck attribute
*
*/

int  Building::Luck(){
	return luck;
}

/** \brief The Enemy level setter
*
*
*/

void Building::set_level(int lvl){
	level = lvl;
}

/** \brief the level getter
*
* \return the level of Enemy
*
*/


int Building::get_level(){
	return level;
}


Building::~Building()
{
}
