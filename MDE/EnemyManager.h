#pragma once
#include "Manager.h"
#include "sound_play.h"
#include "player.h"
#include "ArtificialIntelligence.h"

class EnemyManager :
	public Manager
{
	Player* player;
	sound_play * play = new sound_play("music\\hit.wav");
	ArtificialIntelligence *npc = new ArtificialIntelligence();
public:
	EnemyManager();
	void setPlayerPointer(Player* _player);
	int move(int direction);
	void renderEnemy();
	~EnemyManager();
};

