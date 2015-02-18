#pragma once
#include "enemy.h"
#include "Goblin.h"
#include "GoblingKing.h"
#include "Orc.h"
#include "OrcChief.h"
class EnemyFactory
{
	public:
		static Enemy* create_enemy(string enemyType, bool firstEnemy);
};