#include "EnemyFactory.h"

/** \brief Create a Enemy factory
*
* \param string enemyType. enemyType is a type of enemy you want to create.
*
* \return If enemyType matches available enemys, it returns enemy entity you want to create.
*
*/
Enemy* EnemyFactory::create_enemy(string enemyType, bool firstEnemy){

	if (enemyType == "goblin"){
		if (firstEnemy == true){
			Goblin* goblin = new Goblin();
			goblin->set_stats(0, 0, 0, 0, 0, 0, 0, 0, 0);
			return goblin;
		}
		else{
		Goblin* goblin = new Goblin();
		goblin->set_stats(4 , 5 , 1, 1, 1, 1, 1, 1, 1);
		return goblin;
		}

	}
	
}