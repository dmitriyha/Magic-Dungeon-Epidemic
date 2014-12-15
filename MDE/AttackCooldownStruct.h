#pragma once
#include <iostream>
#include <vector>
#include "Building.h"

using namespace std;

/** \brief contains the data required to render the map
*/


struct AttackCooldownStruct{
	//Lista sis‰lt‰‰ rakennuksien id:t mill‰ on attackcooldown.
	vector<Building*> attackCooldowns;
};
