#include "BattleHandler.h"


BattleHandler::BattleHandler()
{
}

int BattleHandler::handle(Character* attacker, Character* defender){
	int attacker_damage = attacker->fight(defender);
	return attacker_damage;
}

BattleHandler::~BattleHandler()
{
}
