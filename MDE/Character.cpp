#include "Character.h"
#include "GlobalDef.h"

Character::Character(){
	faceUp = { 0, 0, 64, 64 };
	faceLeft = { 64, 0, 64, 64 };
	faceRight = { 128, 0, 64, 64 };
	faceDown = { 192, 0, 64, 64 };
}

/** \brief sets the stats of the Character entity
 *
 * \param int healths: max health
 * \param int strengths: the initial strength
 * \param int dexteritys: the initialdexterity
 * \param int witss: the initial wits
 * \param int sanitys: the initial sanity
 * \param int staminas: the initial stamina
 * \param int charismas: the initialcharisma
 * \param int awarenesss: the initial awareness
 * \param int lucks: the initial luck
 * \param int ID: the ID of this entity
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

/** \brief renders the character
*
*
*/
void Character::render(){

	location = { coord.x * TILE_WIDTH, ((coord.y - 1) * TILE_HEIGHT), TILE_WIDTH, TILE_HEIGHT *2};
	if (health > 0){
		sprite = faceDown;
		Object::render();
	}
	else {
		SDL_RenderCopy(texture->getRenderer(), texture->getTexture(), &charSpriteDead, &location);
	}
}

int Character::fight(Character* character){
	return 0;
}
//
//int Character::fight(Building* building){
//	return 0;
//}

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
 * \param x the x cordinate on the map
 * \param y the y coordinate on the map
 *
 */     


void Character::setCoords(int x, int y){
	coord={ x, y };
}

/** \brief the coordinate getter of the entity
 * 
 * \return a 2 element array with x and y coordinates
 *
 */
LocationCoordinates  Character::getCoords(){
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

void Character::setPrimaryWeapon(Item item){

}

void Character::setDirection(int _direction){
	direction = _direction;
}

Character::~Character(){
}
