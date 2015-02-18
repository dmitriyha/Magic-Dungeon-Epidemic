#ifndef ENEMYGEN_H
#define ENEMYGEN_H

#include <iostream>
#include <deque>
#include "Character.h"
#include "enemy.h"
#include <string>
#include <vector>
#include "EnemyFactory.h"
#include "CameraStruct.h"
using namespace std;

/** \brief generates a list of enemies
 *
 */     


class EnemyGen{
	vector<string> getEnemyListForGeneration(int depth);
public:
	deque<Enemy*> enemy;
	EnemyGen( CameraStruct* cam,Texture* texture);
	int GenerateNormalEnemys(int numberOfEnemies, int id, bool firstEnemy, int currentLevel, Texture* texture);
	void GenerateBosses(int numberOfBosses, int id, int currentLevel, Texture* texture);
	
	~EnemyGen();
};
#endif
