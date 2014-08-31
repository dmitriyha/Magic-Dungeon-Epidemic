#include "Character.h"
#include "GlobalDef.h"

/** \brief sets the stats of the Character entity
 *
 * \param healths max health
 * \param strengths the initial strength
 * \param dexteritys the initialdexterity
 * \param witss the initial wits
 * \param sanitys the initial sanity
 * \param staminas the initial stamina
 * \param charismas the initialcharisma
 * \param awarenesss the initial awareness
 * \param lucks the initial luck
 * \param ID the ID of this entity
 *
 */     


void Character::set_stats(int healths,int strengths,int dexteritys,int witss,int sanitys,int staminas,int charismas,int awarenesss,int lucks,int ID){
	health=healths;
	strength=strengths;
	dexterity=dexteritys;
	wits=witss;
	sanity=sanitys;
	stamina=staminas;
	charisma=charismas;
	awareness=awarenesss;
	luck=lucks;
	id=ID;
}

/** \brief the getter of health
 *
 * \return the current health
 *
 */     


int Character::Health(void){
	return health;
}

/** \brief the damage function
 *
 * \return if the entity is alive, returns true, if dead, returns false
 *
 */    

bool Character::Health(int damage){
	health=health-damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the Character antity
 *
 * \return the ID of the entity
 *
 */     


int Character::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
 *
 * \param the x cordinate on the map
 * \param the y coordinate on the map
 *
 */     


void Character::setCoords(int x,int y){
	coord[0]=x;
	coord[1]=y;
}

/** \brief the coordinate getter of the entity
 * 
 * \return a 2 element array with x and y coordinates
 *
 */     



int* Character::getCoords(){
	return coord;
}

/** \brief Strength getter
 *
 * \return strength attribute
 *
 */     

	
int Character::Strength(){
	return strength;
}

/** \brief dexterity getter
 *
 * \return dexterity attribute
 *
 */     


int Character::Dexterity(){
	return dexterity;
}

/** \brief Wits getter
 *
 * \return Wits attribute
 *
 */  

int Character::Wits(){
	return wits;
}

/** \brief Sanity getter
 *
 * \return Sanity attribute
 *
 */  

int Character::Sanity(){
	return sanity;
}

/** \brief Stamina getter
 *
 * \return Stamina attribute
 *
 */

int Character::Stamina(){
	return stamina;
}

/** \brief Charisma getter
 *
 * \return Charisma attribute
 *
 */

int Character::Charisma(){
	return charisma;
}

/** \brief Awareness getter
 *
 * \return Awareness attribute
 *
 */
 
int Character::Awareness(){
	return awareness;
}

/** \brief Luck getter
 *
 * \return Luck attribute
 *
 */

int Character::Luck(){
	return luck;
}

Character::~Character(){
}
