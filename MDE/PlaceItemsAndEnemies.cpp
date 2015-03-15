#include "PlaceItemsAndEnemies.h"

/** \brief Places the items and enemies on the map
 *
 * \param CameraStruct 
 * \param Texture Item texture
 */     
PlaceItemsAndEnemies::PlaceItemsAndEnemies(CameraStruct* cam, Texture* texture, Map* map){
	RNG random;
	LocationCoordinates upstairs = { 0, 0 };
	entityData = cam;
	int cursor=0,x=0,y=0;
	upstairs = map->GetStairsUpCoord();
	cout << " Portaitten koordinaatti on " << upstairs.x << " ja " << upstairs.y << endl;
	while(y<GRID_HEIGHT){//initialises entityData to 0
		if(x<GRID_WIDTH){
			entityData->mapStruct[entityData->currentLevel].entityData.live[x][y] = 0;
			entityData->mapStruct[entityData->currentLevel].entityData.dead[x][y] = 0;
			x++;
		}
		if(x==GRID_WIDTH){
			y++;
			x=0;
		}
	}
	//Create all enemys created in EnemyGen class
	while (cursor < entityData->mapStruct[entityData->currentLevel].entityData.enemy.size() - 2){
		int i;
		for(i=0;i<50000;i++)
		x=random.generate(0,GRID_WIDTH); //generates the x coordinate
		y=random.generate(0,GRID_HEIGHT);//generates the y coordinate
		
		if (entityData->mapStruct[entityData->currentLevel].mapData.mapDim[x][y] == '.' && entityData->mapStruct[entityData->currentLevel].entityData.live[x][y] == 0){//sets enemies to random locations
			if (entityData->mapStruct[entityData->currentLevel].entityData.enemy[cursor + 2]->GetType()=="bossmelee"){
				PlaceBossesToTheMap(cam, texture, map,cursor,upstairs);
				cursor++;
			}
			else{
			entityData->mapStruct[entityData->currentLevel].entityData.enemy[cursor + 2]->setCoords(x, y);
			entityData->mapStruct[entityData->currentLevel].entityData.live[x][y] = entityData->mapStruct[entityData->currentLevel].entityData.enemy[cursor + 2]->getID();
			cursor++;
			}
		}
	}
	cursor=0;
	while (cursor<50){
		int i;
		for(i=0;i<50000;i++)
		x=random.generate(0,GRID_WIDTH); //generates the x coordinate
		y=random.generate(0,GRID_HEIGHT);//generates the y coordinate
		LocationCoordinates coord = {x,y};

		if (entityData->mapStruct[entityData->currentLevel].mapData.mapDim[x][y] == '.'){//generates and places 50 random items to 50 random locations
			int rand;
			if (entityData->currentLevel == 0){
				rand=random.generate(1,4);
				if (rand == 3){
					rand=7;
				}
				if (rand == 4){
					rand = 12;
				}
				Item it(rand);
				it.setTexture(texture);
				it.setAsUnequipped(coord);
				entityData->mapStruct[entityData->currentLevel].itemData.itemDataMap[x][y].push_back(it);
			}
			else if (entityData->currentLevel == 1){
				rand=random.generate(1,6);
				if (rand > 4){
					rand=rand+2;
				}
				if (rand == 4){
					rand = 12;
				}
				Item it(rand);
				it.setTexture(texture);
				it.setAsUnequipped(coord);
				entityData->mapStruct[entityData->currentLevel].itemData.itemDataMap[x][y].push_back(it);
			}
			else if (entityData->currentLevel == 2){
				rand=random.generate(1,9);
				Item it(rand);
				it.setTexture(texture);
				it.setAsUnequipped(coord);
				entityData->mapStruct[entityData->currentLevel].itemData.itemDataMap[x][y].push_back(it);
			}
			cursor++;
		}
	}
}

void PlaceItemsAndEnemies::PlaceBossesToTheMap(CameraStruct* cam, Texture* texture, Map* map, int cursor, LocationCoordinates upstairs){

	LocationCoordinates availablePlaceCoord = { 0, 0 };

	availablePlaceCoord = PlaceBossesToTheMapCheck(cam, map,upstairs);
	if (availablePlaceCoord.x > -1 && availablePlaceCoord.y > -1){
		entityData->mapStruct[entityData->currentLevel].entityData.enemy[cursor + 2]->setCoords(availablePlaceCoord.x, availablePlaceCoord.y);
		entityData->mapStruct[entityData->currentLevel].entityData.live[availablePlaceCoord.x][availablePlaceCoord.y] = entityData->mapStruct[entityData->currentLevel].entityData.enemy[cursor + 2]->getID();
		cout << "Pomo laitettu karttaan"<<endl;
	}
}

LocationCoordinates PlaceItemsAndEnemies::PlaceBossesToTheMapCheck(CameraStruct* cam, Map* map, LocationCoordinates upstairs){
	LocationCoordinates availablePlace = { 0, 0 };;
	int x = upstairs.x;
	int y = upstairs.y;
	if (cam->mapStruct[cam->currentLevel].mapData.mapDim[x + 1][y] == '.'&& cam->mapStruct[cam->currentLevel].entityData.live[x + 1][y]<=0){
		availablePlace.x = x + 1;
		availablePlace.y = y;
		return availablePlace;
	}
	else if (cam->mapStruct[cam->currentLevel].mapData.mapDim[x - 1][y] == '.' && cam->mapStruct[cam->currentLevel].entityData.live[x - 1][y] <= 0){
		availablePlace.x = x - 1;
		availablePlace.y = y;
		return availablePlace;
	}
	else if (cam->mapStruct[cam->currentLevel].mapData.mapDim[x][y + 1] == '.' && cam->mapStruct[cam->currentLevel].entityData.live[x][y + 1] <= 0){
		availablePlace.x = x;
		availablePlace.y = y + 1;
		return availablePlace;
	}
	else if (cam->mapStruct[cam->currentLevel].mapData.mapDim[x][y - 1] == '.' && cam->mapStruct[cam->currentLevel].entityData.live[x][y - 1] <= 0){
		availablePlace.x = x;
		availablePlace.y = y - 1;
		return availablePlace;
	}
	else if (cam->mapStruct[cam->currentLevel].mapData.mapDim[x + 1][y + 1] == '.' && cam->mapStruct[cam->currentLevel].entityData.live[x + 1][y + 1] <= 0){
		availablePlace.x = x + 1;
		availablePlace.y = y + 1;
		return availablePlace;
	}
	else if (cam->mapStruct[cam->currentLevel].mapData.mapDim[x + 1][y - 1] == '.' && cam->mapStruct[cam->currentLevel].entityData.live[x + 1][y - 1] <= 0){
		availablePlace.x = x + 1;
		availablePlace.y = y - 1;
		return availablePlace;
	}
	else if (cam->mapStruct[cam->currentLevel].mapData.mapDim[x - 1][y - 1] == '.' && cam->mapStruct[cam->currentLevel].entityData.live[x - 1][y - 1] <= 0){
		availablePlace.x = x - 1;
		availablePlace.y = y - 1;
		return availablePlace;
	}
	else if (cam->mapStruct[cam->currentLevel].mapData.mapDim[x - 1][y + 1] == '.' && cam->mapStruct[cam->currentLevel].entityData.live[x - 1][y + 1] <= 0){
		availablePlace.x = x - 1;
		availablePlace.y = y + 1;
		return availablePlace;
	}
	availablePlace.x = -1;
	availablePlace.y = -1;
	return availablePlace;
}

PlaceItemsAndEnemies::~PlaceItemsAndEnemies(){
}
