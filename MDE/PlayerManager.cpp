#include "PlayerManager.h"


PlayerManager::PlayerManager()
{
	
}

int PlayerManager::move(int direction){
	int *coord = player->getCoords();
	switch (direction){
	case 2://down               
		if (coord[1]<GRID_HEIGHT - 1 && dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1] + 1] == 0 && dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord[0]][coord[1] + 1] != '#'){
			dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 0;
			coord[1] = coord[1] + 1;
			dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 1;
		}
		else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1] + 1]>0){
			coord[1] = coord[1] + 1;
			BattleHandler::handle(player, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1] + 1]));
			coord[1] = coord[1] - 1;
		}
		break;
	case 4://left        
		if (coord[0]>0 && dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0] - 1][coord[1]] == 0 && dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord[0] - 1][coord[1]] != '#'){
			dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 0;
			coord[0] = coord[0] - 1;
			dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 1;
		}
		else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0] - 1][coord[1]]>0){
			coord[0] = coord[0] - 1;
			BattleHandler::handle(player, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1] + 1]));
			coord[0] = coord[0] + 1;
		}
		break;
	case 6: //right
		if (coord[0]<GRID_WIDTH - 1 && dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0] + 1][coord[1]] == 0 && dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord[0] + 1][coord[1]] != '#'){
			dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 0;
			coord[0] = coord[0] + 1;
			dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 1;
		}
		else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0] + 1][coord[1]]>0){
			coord[0] = coord[0] + 1;
			BattleHandler::handle(player, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1] + 1]));
			coord[0] = coord[0] - 1;
		}
		break;
	case 8://up 
		if (coord[1]>0 && dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1] - 1] == 0 && dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord[0]][coord[1] - 1] != '#'){
			dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 0;
			coord[1] = coord[1] - 1;
			dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1]] = 1;
		}
		else if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1] - 1]>0){
			coord[1] = coord[1] - 1;
			BattleHandler::handle(player, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord[0]][coord[1] + 1]));
			coord[1] = coord[1] + 1;
		}
		break;
	default:
		return 0;
		break;
	}//end switch(event.key.keysym.sym)
	checkTileForItems();
	// checks for stariways up or down
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord[0]][coord[1]] == 'u') {
		dataForManaging->currentLevel++;
		if (dataForManaging->currentLevel > max_achieved_depth){
			max_achieved_depth++;
			//TODO move the generater elsewhere
			//this->level_generator();
		}
		player->setCoords(dataForManaging->mapStruct[dataForManaging->currentLevel].stairsDown[0], dataForManaging->mapStruct[dataForManaging->currentLevel].stairsDown[1]);
	}
	else if (dataForManaging->mapStruct[dataForManaging->currentLevel].mapData.mapDim[coord[0]][coord[1]] == 'd'){
		dataForManaging->currentLevel--;
		player->setCoords(dataForManaging->mapStruct[dataForManaging->currentLevel].stairsUp[0], dataForManaging->mapStruct[dataForManaging->currentLevel].stairsUp[1]);
	}
	return 1;
}

void PlayerManager::checkTileForItems(){//checks tile for items and picks up, if inventory not full
	int *coord = player->getCoords();
	while (!dataForManaging->mapStruct[dataForManaging->currentLevel].itemData.itemDataMap[coord[0]][coord[1]].empty()){
		if (player->getInventory()->storeItem(dataForManaging->mapStruct[dataForManaging->currentLevel].itemData.itemDataMap[coord[0]][coord[1]].front()) == 1){
			dataForManaging->mapStruct[dataForManaging->currentLevel].itemData.itemDataMap[coord[0]][coord[1]].pop_front();
		}
		else{
			break;
		}
	}
}

void PlayerManager::setPlayerPointer(Player* _player){
	player = _player;
}

PlayerManager::~PlayerManager()
{
}
