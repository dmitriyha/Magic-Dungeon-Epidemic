#pragma once
#include "Manager.h"
#include "sound_play.h"
#include "player.h"
#include "ArtificialIntelligence.h"
#include "AttackCooldownStruct.h"

class EnemyManager :
	public Manager
{
	Player* player;
	sound_play * play = new sound_play("music\\hit.wav");
	ArtificialIntelligence *npc = new ArtificialIntelligence();
public:
	EnemyManager();
	void setPlayerPointer(Player* _player);
	int move(AttackCooldownStruct* attackCooldownStruct);
	bool IsTrapBelowTheEnemy(int coordX, int coordY);
	void TrapTriggered(int currentdepth, int coordX, int coordY, AttackCooldownStruct* attackCooldownStruct);
	void renderEnemy();
	~EnemyManager();
};

