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
	EnemyGen( CameraStruct* cam);
	
	~EnemyGen();
};
#endif
