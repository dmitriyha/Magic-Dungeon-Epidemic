#include "EnemyFactory.h"

/** \brief Create a Enemy factory
*
* \param string enemyType. enemyType is a type of enemy you want to create.
*
* \return If enemyType matches available enemys, it returns enemy entity you want to create.
*
*/
Enemy* EnemyFactory::create_enemy(string enemyType){

	if (enemyType == "goblin"){
		return new Goblin();
	}
	
}