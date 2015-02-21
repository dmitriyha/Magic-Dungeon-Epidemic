#include "enemy.h"

Enemy::Enemy(){
	Character::Character();
}

/** \brief The Enemy primary weapon setter
*
*
*/
void Enemy::setPrimaryWeapon(Item* item){
	weapon = item;
}

/** \brief The Enemy level setter
*
*
*/
void Enemy::set_level(int lvl){
	level=lvl;
}

//Sets id
void Enemy::set_Id(int _id){
	id = _id;
}

/** \brief the level getter
 *
 * \return the level of Enemy
 *
 */     


int Enemy::get_level(){
	return level;
}

Enemy::~Enemy(){

}