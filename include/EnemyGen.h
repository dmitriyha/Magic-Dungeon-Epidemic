#ifndef ENEMYGEN_H
#define ENEMYGEN_H

#include <iostream>
#include <deque>
#include "Character.h"
#include "enemy.h"
using namespace std;

class EnemyGen{
	
public:
	EnemyGen();
	deque<Enemy> Generate(int enemies,int level);
	~EnemyGen();
};
#endif
