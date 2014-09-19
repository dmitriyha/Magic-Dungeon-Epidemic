#pragma once

#include "Character.h"
#include "Battle.h"

class BattleHandler
{
public:
	BattleHandler();
	static int handle(Character* attacker, Character* defender);
	~BattleHandler();
};

