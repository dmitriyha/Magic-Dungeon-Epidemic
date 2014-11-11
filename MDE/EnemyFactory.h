#pragma once
#include "enemy.h"
#include "Goblin.h"
class EnemyFactory
{
	public:
		static Enemy* create_enemy(string enemyType, bool firstEnemy);
};