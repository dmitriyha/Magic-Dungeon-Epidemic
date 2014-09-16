#include "EnemyFactory.h"


Enemy* EnemyFactory::create_enemy(string enemyType){

	if (enemyType == "goblin"){
		return new Goblin;
	}
	
}