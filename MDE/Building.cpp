#include "Building.h"

Building::Building(){

}
/** \brief Sets building stats
*
* \return the current health
*
*/
void  Building::set_stats(int healths, int strengths, int damages, int accuracys, int lucks, int attackCooldowns){
	health = healths;
	strength = strengths;
	damage = damages;
	accuracy = accuracys;
	luck = lucks;
	attackCooldown = attackCooldowns;
}


int Building::GetCooldown(){
	return attackCooldown;
}


/** \brief Renders the building
*
*
*/
void Building::render(){

	SDL_Rect charLoc = { coord.x * TILE_WIDTH, ((coord.y - 1) * TILE_HEIGHT), TILE_WIDTH, TILE_HEIGHT * 2 };

	SDL_RenderCopy(texture->getRenderer(), texture->getTexture(), &charSprite, &charLoc);
}


/** \brief Renders the building
*
* \param Texture _texture: The thexture whic you want to place to the building
*/
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
* \return int damage: if the building is alive, returns true, if dead, returns false
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
/** \brief sets building id
*
* \return int id: id which you want to place to the building
*
*/
void Building::set_Id(int _id){
	id = _id;
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
* \param int x: the x cordinate on the map
* \param int y: the y coordinate on the map
*
*/
void  Building::setCoords(int x, int y){
	coord.x = x;
	coord.y = y;
}

/** \brief the gets building coordinates
*
* \return a 2 element array with x and y coordinates
*
*/
LocationCoordinates Building::getCoords(){
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
* \param int lvl: The level which you want to give your building
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

//
///** \brief handels the fighting
//*
//* \param building* building: The defending building. The one who is receiving damage
//*
//*/
//int Building::fight(Character* chracter){
//	//damage to be inflicted
//	int damage = 0;
//	
//		damage = 3;
//		chracter->Health(damage);
//
//	return damage;
//}
Building::~Building()
{
}
