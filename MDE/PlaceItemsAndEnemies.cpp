#include "PlaceItemsAndEnemies.h"

/** \brief Places the items and enemies on the map
 *
 * \param mapLayer MapLayer object that contains the map data
 * \param baddies the deque with Enemy objects to be put on the map
 * \param level the current level of the dungeon to put the proper items on the ground
 */     


PlaceItemsAndEnemies::PlaceItemsAndEnemies(CameraStruct* cam, Texture* texture){
	RNG random;
	

	enemyData = cam;

	int cursor=0,x=0,y=0;
	
	while(y<GRID_HEIGHT){//initialises entityData to 0
		if(x<GRID_WIDTH){
			enemyData->mapStruct[enemyData->currentLevel].entityData.live[x][y] = 0;
			enemyData->mapStruct[enemyData->currentLevel].entityData.dead[x][y] = 0;
			x++;
		}
		if(x==GRID_WIDTH){
			y++;
			x=0;
		}
	}

	while (cursor < enemyData->mapStruct[enemyData->currentLevel].entityData.enemy.size() - 2){
		int i;
		for(i=0;i<50000;i++)
		x=random.generate(0,GRID_WIDTH); //generates the x coordinate
		y=random.generate(0,GRID_HEIGHT);//generates the y coordinate
		
		if (enemyData->mapStruct[enemyData->currentLevel].mapData.mapDim[x][y] == '.' && enemyData->mapStruct[enemyData->currentLevel].entityData.live[x][y] == 0){//sets enemies to random locations
			enemyData->mapStruct[enemyData->currentLevel].entityData.enemy[cursor + 2]->setCoords(x, y);
			enemyData->mapStruct[enemyData->currentLevel].entityData.live[x][y] = enemyData->mapStruct[enemyData->currentLevel].entityData.enemy[cursor + 2]->getID();
			cursor++;
		}
	}
	cursor=0;
	while (cursor<50){
		int i;
		for(i=0;i<50000;i++)
		x=random.generate(0,GRID_WIDTH); //generates the x coordinate
		y=random.generate(0,GRID_HEIGHT);//generates the y coordinate
		int coord[2];
		coord[0] = x;
		coord[1] = y;

		if (enemyData->mapStruct[enemyData->currentLevel].mapData.mapDim[x][y] == '.'){//generates and places 50 random items to 50 random locations
			int rand;
			if (enemyData->currentLevel == 0){
				rand=random.generate(1,3);
				if (rand == 3){
					rand=7;
				}
				Item it(rand);
				it.setTexture(texture);
				it.setAsUnequpped(coord);
				enemyData->mapStruct[enemyData->currentLevel].itemData.itemDataMap[x][y].push_back(it);
			}
			else if (enemyData->currentLevel == 1){
				rand=random.generate(1,6);
				if (rand > 4){
					rand=rand+2;
				}
				Item it(rand);
				it.setTexture(texture);
				it.setAsUnequpped(coord);
				enemyData->mapStruct[enemyData->currentLevel].itemData.itemDataMap[x][y].push_back(it);
			}
			else if (enemyData->currentLevel == 2){
				rand=random.generate(1,9);
				Item it(rand);
				it.setTexture(texture);
				it.setAsUnequpped(coord);
				enemyData->mapStruct[enemyData->currentLevel].itemData.itemDataMap[x][y].push_back(it);
			}
			cursor++;
		}
	}
}

PlaceItemsAndEnemies::~PlaceItemsAndEnemies(){
}
