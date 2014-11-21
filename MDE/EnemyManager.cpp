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

int EnemyManager::move(AttackCooldownStruct* attackCooldownStruct){
	LocationCoordinates playerLoc = player->getCoords();
	int size = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.size();
	int cursor = 2;
	LocationCoordinates coord;
	while (cursor - 2 < size - 2){
		coord = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->getCoords();
		if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->Health(0)){

			int directionAI = npc->direction(playerLoc, coord, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData, dataForManaging->mapStruct[dataForManaging->currentLevel].mapData, dataForManaging);
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

			if (IsTrapBelowTheEnemy(coord.x, coord.y) == true){
				//vihollinen jäi ansaan
				TrapTriggered(dataForManaging->currentLevel, coord.x, coord.y,attackCooldownStruct);
				cout << "Vihollinen jäi ansaan" << endl;
				
			}
		}
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->setCoords(coord.x, coord.y);
		cursor++;
	}
	return 0;
}
bool EnemyManager::IsTrapBelowTheEnemy(int coordX, int coordY){
	bool trapIsHere = false;
	bool enemyIsHere = false;
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coordX][coordY]>0){
		enemyIsHere = true;
	}

	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coordX][coordY]>0){
		trapIsHere = true;
	}
	if (enemyIsHere == true && trapIsHere == true){
		return true;
	}
	else{
		return false;
	}
}


void EnemyManager::TrapTriggered(int currentdepth, int coordX, int coordY, AttackCooldownStruct* attackCooldownStruct){
	int buildingID = 0;
	int enemyID = 0;
	Building* building = new Building();
	Enemy* enemy = new Enemy();
	if (dataForManaging->mapStruct[currentdepth].entityDataBuildings.live[coordX][coordY] > 0){
		buildingID = dataForManaging->mapStruct[currentdepth].entityDataBuildings.live[coordX][coordY];
		building = dataForManaging->mapStruct[currentdepth].entityDataBuildings.building.at(buildingID - 1);
		attackCooldownStruct->attackCooldownIDs.push_back(building);
		enemyID = dataForManaging->mapStruct[currentdepth].entityData.live[coordX][coordY];
		enemy = dataForManaging->mapStruct[currentdepth].entityData.enemy.at(enemyID - 1);
	}
	cout << "Ansan damage on " << building->Damage() << endl;

	dataForManaging->userInterfaceStruct.buildingDamage = building->Damage();
	
		//BattleHandler::handleBuilding(building, dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coordX][coordY]));
	bool enemyAlive = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coordX][coordY]]->Health(dataForManaging->userInterfaceStruct.buildingDamage);


	/*if (!enemyAlive){
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.dead[coord.x][coord.y] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y];
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coord.x][coord.y] = 0;
		player->set_xp(dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.dead[coord.x][coord.y]]->get_level());
		if (dataForManaging->currentLevel == 2){
			kills++;
		}
	}*/
}


void EnemyManager::setPlayerPointer(Player* _player){
	player = _player;
}

EnemyManager::~EnemyManager()
{
	
	delete npc;
}
