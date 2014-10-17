#include "EnemyManager.h"


EnemyManager::EnemyManager()
{
}

int EnemyManager::move(int direction){
	int *playerLoc = player->getCoords();
	int size = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.size();
	int cursor = 2;
	int* coord;
	while (cursor - 2 < size - 2){
		coord = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getCoords();
		if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->Health(0)){

			int directionAI = npc->direction(playerLoc, coord, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData, dataForManaging->mapStruct[dataForManaging->currentLevel].mapData);
			if (directionAI == 8){//move up
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 0;
				coord[1]--;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getID();
			}
			else if (directionAI == 2){//move down
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 0;
				coord[1]++;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getID();
			}
			else if (directionAI == 4){//move left
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 0;
				coord[0]--;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getID();
			}
			else if (directionAI == 6){//move right
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 0;
				coord[0]++;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getID();
			}
			else if (directionAI == 0){
				play->play();
				dataForManaging->userInterfaceStruct.enemyDamage = Battle::Sword(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->Strength(), dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->Dexterity(), dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->Stamina(), 1, player->getInventory()->equippedList()[0].getItemStat());
				player->Health(dataForManaging->userInterfaceStruct.enemyDamage);
			}
			else if (directionAI == -1){
			}
		}
		cursor++;
	}
	return 0;
}

void EnemyManager::setPlayerPointer(Player* _player){
	player = _player;
}

EnemyManager::~EnemyManager()
{
	for (int i = 0; i < MAX_DEPTH; i++){
		for (int j = 0; j < dataForManaging->mapStruct[i].entityData.enemy.size(); j++){
			delete dataForManaging->mapStruct[i].entityData.enemy.at(j); //release memory used by these objects

		}
	}
	delete npc;
}
