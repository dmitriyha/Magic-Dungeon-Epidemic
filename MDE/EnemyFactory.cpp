#include "EnemyFactory.h"

/** \brief Create a Enemy factory
*
* \param string enemyType. enemyType is a type of enemy you want to create.
*
* \return If enemyType matches available enemys, it returns enemy entity you want to create.
*
*/
Enemy* EnemyFactory::create_enemy(string enemyType, bool firstEnemy){
	//Normal enemys
	if (enemyType == "goblin"){
		if (firstEnemy == true){
			Goblin* goblin = new Goblin();
			goblin->set_stats(0, 0, 0, 0, 0, 0, 0, 0, 0,"","");
			return goblin;
		}
		else{
		Goblin* goblin = new Goblin();
		goblin->set_stats(4, 5, 1, 1, 1, 1, 1, 1, 1, enemyType, "");
		return goblin;
		}

	}
	else if (enemyType == "orc"){
		Orc* orc = new Orc();
		orc->set_stats(20, 8, 3, 3, 3, 3, 3, 3, 1, enemyType, "normalmelee");
		return orc;
	}
	//Boses
	else if (enemyType == "goblingking"){
		GoblingKing* goblinking = new GoblingKing();
		goblinking->set_stats(25, 12, 3, 3, 3, 3, 3, 3, 1, enemyType,"bossmelee");
		return goblinking;
	}
	else if (enemyType == "orcchief"){
		OrcChief* orcChief = new OrcChief();
		orcChief->set_stats(35, 12, 3, 3, 3, 3, 3, 3, 1, enemyType,"bossmelee");
		return orcChief;
	}
	
	
}