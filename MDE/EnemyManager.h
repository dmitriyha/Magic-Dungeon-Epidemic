#pragma once
#include "Manager.h"
class EnemyManager :
	public Manager
{
public:
	EnemyManager();
	int move(int direction);
	~EnemyManager();
};

