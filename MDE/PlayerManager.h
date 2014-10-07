#pragma once
#include "Manager.h"
#include "player.h"
#include "GlobalDef.h"

class PlayerManager : public Manager
{
	Player *player;
	int max_achieved_depth = 0;
public:
	PlayerManager();
	void setPlayerPointer(Player* _player);
	int move(int direction);
	void setPlayer(Player* player);
	void checkTileForItems();

	~PlayerManager();
};

