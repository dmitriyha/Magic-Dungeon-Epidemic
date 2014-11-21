#include "SpikeTrap.h""


SpikeTrap::SpikeTrap(){
	charSprite = { 0, 0, 120, 65 };
}





/** \brief Sets SpikeTraps stats
*
* \param health SpikeTrap's health
* \param strength SpikeTrap's strength
* \param damage SpikeTrap's damage
* \param accuracy SpikeTrap's accuracy
* \param luck SpikeTrap's luck
* \param ID SpikeTrap's ID
*
* \return the current health
*
*/
void  SpikeTrap::set_stats(int healths, int strengths, int damages, int accuracys, int lucks, int attackCooldowns){
	health = healths;
	strength = strengths;
	damage = damages;
	accuracy = accuracys;
	luck = lucks;
	attackCooldown = attackCooldowns;
}


int SpikeTrap::GetCooldown(){
	return attackCooldown;
}




/** \brief the getter of health
*
* \return the current health
*
*/
int  SpikeTrap::Health(void){
	return health;
}

/** \brief the damage function
*
* \return if the entity is alive, returns true, if dead, returns false
*
*/

bool  SpikeTrap::Health(int damage){
	health = health - damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the SpikeTrap entity
*
* \return the ID of the entity
*
*/


int  SpikeTrap::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/


void  SpikeTrap::setCoords(int x, int y){
	coord.x = x;
	coord.y = y;
}

//Sets id
void SpikeTrap::set_Id(int _id){
	id = _id;
}

/** \brief the coordinate getter of the entity
*
* \return a 2 element array with x and y coordinates
*
*/



LocationCoordinates  SpikeTrap::getCoords(){

	return coord;
}





/** \brief Strength getter
*
* \return strength attribute
*
*/
int  SpikeTrap::Strength(){
	return strength;
}


/** \brief Damage getter
*
* \return damage attribute
*
*/
int  SpikeTrap::Damage(){
	return damage;
}

/** \brief accuracy getter
*
* \return accuracy attribute
*
*/


int  SpikeTrap::Accuracy(){
	return accuracy;
}







/** \brief Luck getter
*
* \return Luck attribute
*
*/

int  SpikeTrap::Luck(){
	return luck;
}

/** \brief The Enemy level setter
*
*
*/

void SpikeTrap::set_level(int lvl){
	level = lvl;
}

/** \brief the level getter
*
* \return the level of Enemy
*
*/


int SpikeTrap::get_level(){
	return level;
}



SpikeTrap::~SpikeTrap()
{
}