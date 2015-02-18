#include "WoodBarricade.h"


WoodBarricade::WoodBarricade(){
	charSprite = { 37, 240, 52, 61 };
}


/** \brief Sets WoodBarricades stats
*
* \param health WoodBarricade's health
* \param strength WoodBarricade's strength
* \param damage WoodBarricade's damage
* \param accuracy WoodBarricade's accuracy
* \param luck WoodBarricade's luck
* \param ID WoodBarricade's ID
*
* \return the current health
*
*/
void  WoodBarricade::set_stats(int healths, int strengths, int damages, int accuracys, int lucks, int attackCooldowns){
	health = healths;
	strength = strengths;
	damage = damages;
	accuracy = accuracys;
	luck = lucks;
	attackCooldown = attackCooldowns;
}





/** \brief the getter of health
*
* \return the current health
*
*/
int  WoodBarricade::Health(void){
	return health;
}

/** \brief the damage function
*
* \return if the entity is alive, returns true, if dead, returns false
*
*/
bool  WoodBarricade::Health(int damage){
	health = health - damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the WoodBarricade entity
*
* \return the ID of the entity
*
*/
int  WoodBarricade::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/
void  WoodBarricade::setCoords(int x, int y){
	coord.x = x;
	coord.y = y;
}

//Sets id
void WoodBarricade::set_Id(int _id){
	id = _id;
}

/** \brief the coordinate getter of the entity
*
* \return a 2 element array with x and y coordinates
*
*/

LocationCoordinates  WoodBarricade::getCoords(){

	return coord;
}





/** \brief Strength getter
*
* \return strength attribute
*
*/
int  WoodBarricade::Strength(){
	return strength;
}


/** \brief The Enemy level setter
*
*
*/
void WoodBarricade::set_level(int lvl){
	level = lvl;
}

/** \brief the level getter
*
* \return the level of Enemy
*
*/
int WoodBarricade::get_level(){
	return level;
}



WoodBarricade::~WoodBarricade()
{
}