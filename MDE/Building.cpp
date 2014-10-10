#include "Building.h"

Building::Building(){

}

void  Building::set_stats(int healths, int strengths, int damages, int accuracys, int lucks, int ID){
	health = healths;
	strength = strengths;
	damage = damages;
	accuracy = accuracys;
	luck = lucks;
	id = ID;
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
* \return if the entity is alive, returns true, if dead, returns false
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

/** \brief  id getter of the  Building antity
*
* \return the ID of the entity
*
*/


int  Building::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/


void  Building::setCoords(int x, int y){
	coord[0] = x;
	coord[1] = y;
}

/** \brief the coordinate getter of the entity
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