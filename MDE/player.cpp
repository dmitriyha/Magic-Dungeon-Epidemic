#include "player.h"

Player::Player(){
	sprite.x = 0;
	sprite.y = 0;
	sprite.w = 48;
	sprite.h = 58;

	charSpriteDead = { 0, 0, 0, 0 };
}

/** \brief sets the stats of the  Player entity
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


void  Player::set_stats(int healths, int strengths, int dexteritys, int witss, int sanitys, int staminas, int charismas, int awarenesss, int lucks, int ID){
	health = healths;
	strength = strengths;
	dexterity = dexteritys;
	wits = witss;
	sanity = sanitys;
	stamina = staminas;
	charisma = charismas;
	awareness = awarenesss;
	luck = lucks;
	id = ID;
}


/** \brief handels the fighting
*
* \param Character* character: The defending character. The one who is receiving damage
*
*/
int Player::fight(Character* character){
	//damage to be inflicted
	int damage = 0;
	if (inventory->equippedList().at(1).getType() == "sword"){
		damage = Battle::Sword(strength, dexterity, stamina, (inventory->equippedList().at(1).getItemStat() + inventory->equippedList().at(2).getItemStat()), 0);
		character->Health(damage);
	}

	else if (inventory->equippedList().at(1).getType() == "bow") {
		damage = Battle::Bow(dexterity, awareness, luck, inventory->equippedList().at(1).getItemStat());
		character->Health(damage);
	}
	else{
		damage = Battle::Sword(strength, dexterity, stamina, 0, 0);
		character->Health(damage);
	}
	return damage;
}

Inventory* Player::getInventory(){
	return inventory;
}

/** \brief sets the primary weapon
*
* \param Item item: The item which you want to set as primary weapon
*
*/
void Player::setPrimaryWeapon(Item item){
	inventory->setPrimaryWeapon(item);
}

/** \brief the getter of health
*
* \return the current health
*
*/
int  Player::Health(void){
	return health;
}

/** \brief the damage function
*
* \return if the entity is alive, returns true, if dead, returns false
*
*/
bool  Player::Health(int damage){
	health = health - damage;
	if (health>0){
		return true;
	}
	else{
		return false;
	}
}

/** \brief  id getter of the  Player antity
*
* \return the ID of the entity
*
*/
int  Player::getID(){
	return id;
}

/** \brief lets the entity know where it is on the map
*
* \param x the x cordinate on the map
* \param y the y coordinate on the map
*
*/
void  Player::setCoords(int x, int y){
	coord={ x, y };
}

/** \brief the coordinate getter of the entity
*
* \return a 2 element array with x and y coordinates
*
*/
LocationCoordinates Player::getCoords(){
	return coord;
}


/** \brief Strength getter
*
* \return strength attribute
*
*/
int  Player::Strength(){
	return strength;
}

/** \brief dexterity getter
*
* \return dexterity attribute
*
*/
int  Player::Dexterity(){
	return dexterity;
}

/** \brief Wits getter
*
* \return Wits attribute
*
*/
int  Player::Wits(){
	return wits;
}

/** \brief Sanity getter
*
* \return Sanity attribute
*
*/
int  Player::Sanity(){
	return sanity;
}

/** \brief Stamina getter
*
* \return Stamina attribute
*
*/
int  Player::Stamina(){
	return stamina;
}

/** \brief Charisma getter
*
* \return Charisma attribute
*
*/
int  Player::Charisma(){
	return charisma;
}

/** \brief Awareness getter
*
* \return Awareness attribute
*
*/
int  Player::Awareness(){
	return awareness;
}

/** \brief Luck getter
*
* \return Luck attribute
*
*/
int  Player::Luck(){
	return luck;
}


 Player::~ Player(){
	 delete inventory;
}


/** \brief called on a death of a creature to calculate new xp
 *
 * \param creature_level the level of the creature that was killed
 *
 */     
void Player::set_xp(int creature_level){
	if (level == creature_level){
		xp=xp+(10*level);
	}
	else if(level > creature_level){
		xp=xp+((10 * level)*(0.6/(level - creature_level)));
	}
	else {
		xp=xp+((10 * level)*(1 + (0.4*(creature_level - level))));
	}
	if (xp >= next_level){
		level++;
		lvl_points=2;
		xp=xp - next_level;
		//next_level = next_level + (10 * level *40); //next level xp calculated as previous requirement added to the product of this level's xp gained per kill multiplied by the amount bad guys to kill
		next_level= (10 * level *40);
	}
	//cout<<"Level: "<<level<<endl<<"xp: "<<xp<<endl;
}

/** \brief returns the lvl progress in integer form
 *
 * \return the lvl progress in integer form
 *
 */     
int Player::get_level_progress(){
	float prog = ((float)xp / (float)next_level)*100;
	int progress = prog;
	return progress;
}

/** \brief returns the lvl of the player
 *
 * \return the lvl of the player
 *
 */   

int Player::get_level(){
	return level;
}
