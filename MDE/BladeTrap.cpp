#include "BladeTrap.h""


BladeTrap::BladeTrap(){
	charSprite = { 0, 67, 115, 177 };
}


/** \brief Sets BladeTraps stats
*
* \param health BladeTrap's health
* \param strength BladeTrap's strength
* \param damage BladeTrap's damage
* \param accuracy BladeTrap's accuracy
* \param luck BladeTrap's luck
* \param ID BladeTrap's ID
*
* \return the current health
*
*/
void  BladeTrap::set_stats(int healths, int strengths, int damages, int accuracys, int lucks){
	health = healths;
	strength = strengths;
	damage = damages;
	accuracy = accuracys;
	luck = lucks;
}

/** \brief the getter of health
*
* \return the current health
*
*/


int  BladeTrap::Health(void){
	return health;
}

/** \brief the damage function
*
* \return if the entity is alive, returns true, if dead, returns false
*
*/

bool  BladeTrap::Health(int damage){
	health = health - damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the BladeTrap entity
*
* \return the ID of the entity
*
*/


int  BladeTrap::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/


void  BladeTrap::setCoords(int x, int y){
	coord.x = x;
	coord.y = y;
}

//Sets id
void BladeTrap::set_Id(int _id){
	id = _id;
}

/** \brief the coordinate getter of the entity
*
* \return a 2 element array with x and y coordinates
*
*/



LocationCoordinates  BladeTrap::getCoords(){

	return coord;
}





/** \brief Strength getter
*
* \return strength attribute
*
*/
int  BladeTrap::Strength(){
	return strength;
}


/** \brief Damage getter
*
* \return damage attribute
*
*/
int  BladeTrap::Damage(){
	return damage;
}

/** \brief accuracy getter
*
* \return accuracy attribute
*
*/


int  BladeTrap::Accuracy(){
	return accuracy;
}







/** \brief Luck getter
*
* \return Luck attribute
*
*/

int  BladeTrap::Luck(){
	return luck;
}

/** \brief The Enemy level setter
*
*
*/

void BladeTrap::set_level(int lvl){
	level = lvl;
}

/** \brief the level getter
*
* \return the level of Enemy
*
*/


int BladeTrap::get_level(){
	return level;
}



BladeTrap::~BladeTrap()
{
}