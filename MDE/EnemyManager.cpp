#include "EnemyManager.h"


EnemyManager::EnemyManager()
{
}

void EnemyManager::renderEnemy(){
	int size = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.size();
	int cursor = 2;
	while (cursor - 2 < size - 2){
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(cursor)->render();
		cursor++;
	}
}

int EnemyManager::move(int direction){
	LocationCoordinates playerLoc = player->getCoords();
	int size = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.size();
	int cursor = 2;
	LocationCoordinates coord;
	while (cursor - 2 < size - 2){
		coord = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getCoords();
		if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->Health(0)){

			int directionAI = npc->direction(playerLoc, coord, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData, dataForManaging->mapStruct[dataForManaging->currentLevel].mapData);
			if (directionAI == 8){//move up
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
				coord.y--;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getID();
			}
			else if (directionAI == 2){//move down
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
				coord.y++;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getID();
			}
			else if (directionAI == 4){//move left
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
				coord.x--;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getID();
			}
			else if (directionAI == 6){//move right
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
				coord.x++;
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getID();
			}
			else if (directionAI == 0){
				play->play();
				dataForManaging->userInterfaceStruct.enemyDamage = Battle::Sword(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->Strength(), dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->Dexterity(), dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->Stamina(), 1, player->getInventory()->equippedList().at(0).getItemStat());
				player->Health(dataForManaging->userInterfaceStruct.enemyDamage);
			}
			else if (directionAI == -1){
			}
		}
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->setCoords(coord.x, coord.y);
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
