#include "PlaceItemsAndEnemies.h"

/** \brief Places the items and enemies on the map
 *
 * \param mapLayer MapLayer object that contains the map data
 * \param baddies the deque with Enemy objects to be put on the map
 * \param level the current level of the dungeon to put the proper items on the ground
 */     


PlaceItemsAndEnemies::PlaceItemsAndEnemies(MapData mapLayer, deque<Enemy*> baddies,int level){
	RNG random;
	enemy=baddies;
	int cursor=0,x=0,y=0;
	
	while(y<GRID_HEIGHT){//initialises entityData to 0
		if(x<GRID_WIDTH){
			entityData.live[x][y]=0;
			entityData.dead[x][y]=0;
			x++;
		}
		if(x==GRID_WIDTH){
			y++;
			x=0;
		}
	}

	while (cursor<baddies.size()-2){
		int i;
		for(i=0;i<50000;i++)
		x=random.generate(0,GRID_WIDTH); //generates the x coordinate
		y=random.generate(0,GRID_HEIGHT);//generates the y coordinate
		
		if (mapLayer.mapDim[x][y]=='.' && entityData.live[x][y]==0){//sets enemies to random locations
			enemy[cursor+2]->setCoords(x,y);
			entityData.live[x][y]=enemy[cursor+2]->getID();
			cursor++;
		}
	}
	cursor=0;
	while (cursor<50){
		int i;
		for(i=0;i<50000;i++)
		x=random.generate(0,GRID_WIDTH); //generates the x coordinate
		y=random.generate(0,GRID_HEIGHT);//generates the y coordinate
		
		if (mapLayer.mapDim[x][y]=='.'){//generates and places 50 random items to 50 random locations
			int rand;
			if (level == 0){
				rand=random.generate(1,3);
				if (rand == 3){
					rand=7;
				}
				Item it(rand);
				itemLayer.itemDataMap[x][y].push_back(it);
			}
			else if (level == 1){
				rand=random.generate(1,6);
				if (rand > 4){
					rand=rand+2;
				}
				Item it(rand);
				itemLayer.itemDataMap[x][y].push_back(it);
			}
			else if (level == 2){
				rand=random.generate(1,9);
				Item it(rand);
				itemLayer.itemDataMap[x][y].push_back(it);
			}
			cursor++;
		}
	}
}

/** \brief gets the new enemy list with the Enemy objects knowing where they are on the map
 *
 * \
 * \return the Enemy object list with each object knowing it's own location
 *
 */     


deque<Enemy*> PlaceItemsAndEnemies::getEnemyList(){
	return enemy;
}

/** \brief gets EntityData object which has the data where each enemy is
 * 
 * \return EntityData object which has the data where each enemy is
 *
 */     


EntityData PlaceItemsAndEnemies::getLiveEnemies(){
	return entityData;
}

/** \brief gets the item layer of the map
 *
 * \return the item layer of the map
 *
 */     


ItemData PlaceItemsAndEnemies::getItems(){
	return itemLayer;
}

PlaceItemsAndEnemies::~PlaceItemsAndEnemies(){
}
