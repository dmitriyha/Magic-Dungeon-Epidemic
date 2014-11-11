#include "StoneTower.h""


StoneTower::StoneTower(){
	charSprite = { 0, 0, 115, 177 };
}


/** \brief Sets Stonetowers stats
*
* \param health Stonetower's health
* \param strength Stonetower's strength
* \param damage Stonetower's damage
* \param accuracy Stonetower's accuracy
* \param luck Stonetower's luck
* \param ID Stonetower's ID
*
* \return the current health
*
*/
void  StoneTower::set_stats(int healths, int strengths,int damages, int accuracys, int lucks){
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


int  StoneTower::Health(void){
	return health;
}

/** \brief the damage function
*
* \return if the entity is alive, returns true, if dead, returns false
*
*/

bool  StoneTower::Health(int damage){
	health = health - damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the StoneTower entity
*
* \return the ID of the entity
*
*/


int  StoneTower::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/


void  StoneTower::setCoords(int x, int y){
	coord.x = x;
	coord.y = y;
}

//Sets id
void StoneTower::set_Id(int _id){
	id = _id;
}

/** \brief the coordinate getter of the entity
*
* \return a 2 element array with x and y coordinates
*
*/



LocationCoordinates  StoneTower::getCoords(){

	return coord;
}





/** \brief Strength getter
*
* \return strength attribute
*
*/
int  StoneTower::Strength(){
	return strength;
}


/** \brief Damage getter
*
* \return damage attribute
*
*/
int  StoneTower::Damage(){
	return damage;
}

/** \brief accuracy getter
*
* \return accuracy attribute
*
*/


int  StoneTower::Accuracy(){
	return accuracy;
}







/** \brief Luck getter
*
* \return Luck attribute
*
*/

int  StoneTower::Luck(){
	return luck;
}

/** \brief The Enemy level setter
*
*
*/

void StoneTower::set_level(int lvl){
	level = lvl;
}

/** \brief the level getter
*
* \return the level of Enemy
*
*/


int StoneTower::get_level(){
	return level;
}



StoneTower::~StoneTower()
{
}