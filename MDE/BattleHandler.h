#pragma once

#include "Character.h"
#include "Battle.h"
#include "Building.h"

class BattleHandler
{
public:
	BattleHandler();
	static int handle(Character* attacker, Character* defender);
	static int handleBuilding(Building* attacker, Character* defender);
	static int handleBuilding(Character* attacker, Building* defender);
	~BattleHandler();
};

