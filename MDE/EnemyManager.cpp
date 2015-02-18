#include "EnemyManager.h"
using namespace std;

EnemyManager::EnemyManager()
{
}
/** \brief Renders all enemy's
*
*/
void EnemyManager::renderEnemy(){
	int size = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.size();
	int cursor = 2;
	while (cursor - 2 < size - 2){
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.at(cursor)->render();
		cursor++;
	}
}

int EnemyManager::move(AttackCooldownStruct* attackCooldownStruct){
	int combatXorYCoordinate;
	LocationCoordinates playerLoc = player->getCoords();
	int size = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy.size();
	int cursor = 2;
	LocationCoordinates coord;
	Enemy* enemy = new Enemy();
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
				//Gets the enemy at coordinates x and y
				enemy = GetEnemy(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y);

				dataForManaging->userInterfaceStruct.enemyDamage = Battle::Sword(enemy->Strength(), enemy->Dexterity(), enemy->Stamina(), 1, player->getInventory()->equippedList().at(0).getItemStat());
				player->Health(dataForManaging->userInterfaceStruct.enemyDamage);
			}
			else if (directionAI == -1){

			}
			//Enemy attacks building X check
			else if (directionAI == 10){ //battle building up
				EnemyAttacksBuilding(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y - 1, coord.x, coord.y);
			}
			else if (directionAI == 11){ //battle building down
				EnemyAttacksBuilding(dataForManaging, dataForManaging->currentLevel, coord.x, coord.y + 1, coord.x, coord.y);
			}
			else if (directionAI == 12){ //battle building left
				EnemyAttacksBuilding(dataForManaging, dataForManaging->currentLevel, coord.x - 1, coord.y, coord.x, coord.y);
			}
			else if (directionAI == 13){ //battle building right
				EnemyAttacksBuilding(dataForManaging, dataForManaging->currentLevel, coord.x + 1, coord.y, coord.x, coord.y);
			}
			
			
		}
		
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[cursor]->setCoords(coord.x, coord.y);
		cursor++;
		if (IsTrapBelowTheEnemy(coord.x, coord.y) == true){
			//vihollinen j�i ansaan
			TrapTriggered(dataForManaging->currentLevel, coord.x, coord.y, attackCooldownStruct);
			cout << "Vihollinen j�i ansaan" << endl;
		}
		//BladeTrapCheck(dataForManaging, coord.x, coord.y, attackCooldownStruct);

	}
	return 0;
}

void EnemyManager::BladeTrapCheck(CameraStruct* dataForManaging, int EnemyCoordX, int EnemyCoordY, AttackCooldownStruct* attackCooldownStruct){
	int buildingID = 0;
	int CoordX, CoordY;
	trapCoord[17] = {};
	IsTrapNextToEnemy(EnemyCoordX, EnemyCoordY);
		  if (trapCoord[0] != 0 && trapCoord[1] != 0){
			 
			  for (int i = 0; i < 17; i++){

				  if (trapCoord[i]!=0){
					  CoordX = trapCoord[i];
					  CoordY = trapCoord[i+1];

					  Building* building = new Building();
					  buildingID = dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[CoordX][CoordY];
					  building = dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.building.at(buildingID - 1);

					  BladeTrapHitsEnemy(dataForManaging, EnemyCoordX, EnemyCoordY, attackCooldownStruct, building);
					  trapCoord[16] -= 1;
				  }
				  i++;
				  if (trapCoord[16] == 0){
					  break;
				  }
			  }

		  }
	
}

void EnemyManager::BladeTrapHitsEnemy(CameraStruct* dataForManaging, int EnemyCoordX, int EnemyCoordY, AttackCooldownStruct* attackCooldownStruct, Building* building){

	if (building->getType() == 1){

		//Jos rakennuksen cooldown on enemm�n kuin 0 tai sit� ei l�ydy attackCooldowns  vectorista, niin sitten saadaan iske� vihollista
		if (CooldownCheck(attackCooldownStruct, building) == true){
			if (building->GetCooldown() == 0){
				building->SetCooldown(-4);
			}
			attackCooldownStruct->attackCooldowns.push_back(building);

			dataForManaging->userInterfaceStruct.buildingDamage = building->Damage();
			bool enemyAlive = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[EnemyCoordX][EnemyCoordY]]->Health(dataForManaging->userInterfaceStruct.buildingDamage);

			if (!enemyAlive){
				KillEnemy(EnemyCoordX, EnemyCoordY, dataForManaging);
				cout << "Vihollinen kuoli" << endl;
			}
			cout << "Ansan damage on " << building->Damage() << endl;
		}
	}
}


void EnemyManager::IsTrapNextToEnemy(int EnemyCoordX, int EnemyCoordY){
	int numberOfBladeTraps=0;

	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[EnemyCoordX + 1][EnemyCoordY]>0){
		trapCoord[0] = (EnemyCoordX + 1);
		trapCoord[1] = EnemyCoordY;
		trapCoord[16] = numberOfBladeTraps++;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[EnemyCoordX - 1][EnemyCoordY]>0){
		trapCoord[2] = (EnemyCoordX - 1);
		trapCoord[3] = EnemyCoordY;
		trapCoord[16] = numberOfBladeTraps++;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[EnemyCoordX][EnemyCoordY+1]>0){
		trapCoord[4] = EnemyCoordX;
		trapCoord[5] = (EnemyCoordY + 1);
		trapCoord[16] = numberOfBladeTraps++;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[EnemyCoordX][EnemyCoordY - 1]>0){
		trapCoord[6] = EnemyCoordX;
		trapCoord[7] = (EnemyCoordY - 1);
		trapCoord[16] = numberOfBladeTraps++;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[EnemyCoordX + 1][EnemyCoordY +1]>0){
		trapCoord[8] = (EnemyCoordX + 1);
		trapCoord[9] = (EnemyCoordY + 1);
		trapCoord[16] = numberOfBladeTraps++;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[EnemyCoordX + 1][EnemyCoordY -1]>0){
		trapCoord[10] = (EnemyCoordX + 1);
		trapCoord[11] = (EnemyCoordY - 1);
		trapCoord[16] = numberOfBladeTraps++;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[EnemyCoordX - 1][EnemyCoordY - 1]>0){
		trapCoord[12] = (EnemyCoordX - 1);
		trapCoord[13] = (EnemyCoordY - 1);
		trapCoord[16] = numberOfBladeTraps++;
	}
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[EnemyCoordX - 1][EnemyCoordY + 1]>0){
		trapCoord[14] = (EnemyCoordX - 1);
		trapCoord[15] = (EnemyCoordY + 1);
		trapCoord[16] = numberOfBladeTraps++;
	}


}




/** \brief gets enemy at coordinates EnemyCoordX and EnemyCoordY
*
* \param dataForManaging is CameraStruct object
* \param currentdepth is the current depth/level
* \param EnemyCoordX is the enemy coordinate x
* \param EnemyCoordY is the enemy coordinate y
*
* \return enemy object which is at coordinates EnemyCoordX and EnemyCoordY
*/
Enemy* EnemyManager::GetEnemy(CameraStruct* dataForManaging, int currentdepth, int EnemyCoordX, int EnemyCoordY){
	int enemyID;
	Enemy* enemy = new Enemy();
	enemyID = dataForManaging->mapStruct[currentdepth].entityData.live[EnemyCoordX][EnemyCoordY];
	enemy = dataForManaging->mapStruct[currentdepth].entityData.enemy.at(enemyID - 1);
	return enemy;
}

/** \brief sets the stats of the  Goblin entity
*
* \param dataForManaging is CameraStruct object
* \param currentdepth is the current depth/level
* \param BuildingCoordX is the building coordinate x
* \param BuildingCoordY is the building coordinate y
* \param EnemyCoordX is the enemy coordinate x
* \param EnemyCoordY is the enemy coordinate y
*
*/
void EnemyManager::EnemyAttacksBuilding(CameraStruct* dataForManaging, int currentdepth, int BuildingCoordX, int BuildingCoordY, int EnemyCoordX, int EnemyCoordY){
	int enemyID, buildingID;
	bool buildingAlive = true;

	Enemy* enemy = new Enemy();
	enemyID = dataForManaging->mapStruct[currentdepth].entityData.live[EnemyCoordX][EnemyCoordY];
	enemy = dataForManaging->mapStruct[currentdepth].entityData.enemy.at(enemyID - 1);

	Building* building = new Building();
	buildingID = dataForManaging->mapStruct[currentdepth].entityDataBuildings.live[BuildingCoordX][BuildingCoordY];
	building = dataForManaging->mapStruct[currentdepth].entityDataBuildings.building.at(buildingID - 1);
	

	dataForManaging->userInterfaceStruct.enemyDamage = Battle::Sword(enemy->Strength(), enemy->Dexterity(), enemy->Stamina(), 0, 0);
	cout << "Vihollinen " << buildingID << " iskee " << dataForManaging->userInterfaceStruct.enemyDamage << " damagea" << endl;
	cout << "Rakennuksen  health on ennen taistelua : " << dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.building[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[BuildingCoordX][BuildingCoordY]]->Health() << endl;
	buildingAlive = dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.building[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[BuildingCoordX][BuildingCoordY]]->Health(dataForManaging->userInterfaceStruct.enemyDamage);
	cout << "Rakennuksen health on taistelun j�lkeen : " << dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.building[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[BuildingCoordX][BuildingCoordY]]->Health() << endl;
	if (!buildingAlive){
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.dead[BuildingCoordX][BuildingCoordY] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[BuildingCoordX][BuildingCoordX];
		dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[BuildingCoordX][BuildingCoordY] = 0;
	}
}

/** \brief Checks if trap is below the enemy
*
* \param coordX is the building and enemy coordinates x
* \param coordY is the building and enemy coordinates y
*
* \return true if trap is below enemy. Returns false if trap is not below enemy.
*/
bool EnemyManager::IsTrapBelowTheEnemy(int coordX, int coordY){
	bool trapIsHere = false;
	bool enemyIsHere = false;
	if (dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coordX][coordY]>1){
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

/** \brief Checks if trap is below the enemy
*
* \param currentdepth is the curent level/depth
* \param coordX is the building and enemy coordinates x
* \param coordY is the building and enemy coordinates y
* \param attackCooldownStruct handels traps attack cooldown
*
*/
void EnemyManager::TrapTriggered(int currentdepth, int coordX, int coordY, AttackCooldownStruct* attackCooldownStruct){
	int buildingID = 0;
	int enemyID = 0;
	Building* building = new Building();
	if (dataForManaging->mapStruct[currentdepth].entityDataBuildings.live[coordX][coordY] > 0){
		buildingID = dataForManaging->mapStruct[currentdepth].entityDataBuildings.live[coordX][coordY];
		building = dataForManaging->mapStruct[currentdepth].entityDataBuildings.building.at(buildingID - 1);
	}
	
	//Jos rakennuksen cooldown on enemm�n kuin 0 tai sit� ei l�ydy attackCooldowns  vectorista, niin sitten saadaan iske� vihollista
	if (CooldownCheck(attackCooldownStruct, building) == true){
		if (building->GetCooldown() == 0){
			building->SetCooldown(-4);
		}
		attackCooldownStruct->attackCooldowns.push_back(building);
		
		dataForManaging->userInterfaceStruct.buildingDamage = building->Damage();
		bool enemyAlive=dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.enemy[dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coordX][coordY]]->Health(dataForManaging->userInterfaceStruct.buildingDamage);

		if (!enemyAlive){
			KillEnemy(coordX, coordY, dataForManaging);
			cout << "Vihollinen kuoli" << endl;
		}
		cout << "Ansan damage on " << building->Damage() << endl;
	}
}

/** \brief Kills the enemy. Removes enemy from the alive array to dead array.
*
* \param coordX is the enemy coordinates x
* \param coordY is the enemy coordinates y
*
* \return True if cooldown is 0. Returns false is cooldown is more than 0.
*/
void EnemyManager::KillEnemy(int coordX, int coordY, CameraStruct *dataForManaging){
	dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.dead[coordX][coordY] = dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coordX][coordY];
	dataForManaging->mapStruct[dataForManaging->currentLevel].entityData.live[coordX][coordY] = 0;
}



/** \brief Checks if trap has a cooldown still
*
* \param attackCooldownStruct handels traps attack cooldown
* \param building which cooldown we want to check
*
* \return True if cooldown is 0. Returns false is cooldown is more than 0.
*/
bool EnemyManager::CooldownCheck(AttackCooldownStruct* attackCooldownStruct, Building* building){
	int i;
	int size = attackCooldownStruct->attackCooldowns.size();
	int cooldown;

	for (i = 0; i < size; i++){
		if (building == attackCooldownStruct->attackCooldowns.at(i)){
			if (building->GetCooldown() > 0){
				return false;
			}
			else{
				return true;
			}
		}
	}
	return true;
}

void EnemyManager::setPlayerPointer(Player* _player){
	player = _player;
}

EnemyManager::~EnemyManager()
{
	
	delete npc;
}
