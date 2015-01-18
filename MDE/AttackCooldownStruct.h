#pragma once
#include <iostream>
#include <vector>
#include "Building.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

/** \brief contains the data required to render the map
*/

struct AttackCooldownStruct{
	//Lista sis‰lt‰‰ rakennuksien id:t mill‰ on attackcooldown.
	vector<Building*> attackCooldowns;

	vector<Player*> playerCooldowns;

	vector<Enemy*> enemyCooldowns;//not in use
};
