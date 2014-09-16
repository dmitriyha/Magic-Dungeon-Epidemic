#include "ActorManager.h"
#include "CameraStruct.h"

/** \brief The constructor for the class that controls all the actors in the game
 *
 *
 */     


ActorManager::ActorManager(){
	//play->new sound_play ("music\\hit.wav");
	player->set_stats(100,5,5,5,5,5,5,5,5,1);
	this->level_generator();
	int x=0,y=0;
	int placed=0;
	while(!placed){
		//generates random location for the player
		x=random.generate(0,GRID_WIDTH);
		y=random.generate(0,GRID_HEIGHT);
		if(entityData[dungeon_depth].live[x][y]==0 && mapLayer[dungeon_depth].mapDim[x][y]=='.'){
			player->setCoords(x,y);
			placed=1;
			entityData[dungeon_depth].live[x][y]=1;
		}
	}
	
}

/** \brief Based on the direction selected, the player is moved to a new square, unless enemy encountered.
 * 
 * \param direction The integer number of the direction based on the num key pad
 * \return Returns 1 if movement action was successful, 0 if that direction does not exist in the definition of the controls 
 *
 */     


int ActorManager::playerMovement(int direction){
	int *coord=player->getCoords();
	switch(direction){
		case 2://down               
			if (coord[1]<GRID_HEIGHT-1 && entityData[dungeon_depth].live[coord[0]][coord[1]+1] == 0 && mapLayer[dungeon_depth].mapDim[coord[0]][coord[1]+1]!='#'){
				entityData[dungeon_depth].live[coord[0]][coord[1]]=0;
				coord[1]=coord[1]+1;
				entityData[dungeon_depth].live[coord[0]][coord[1]]=1;
			}
			else if(entityData[dungeon_depth].live[coord[0]][coord[1]+1]>0){
				coord[1]=coord[1]+1;
				this->fightAndKillEnemy(coord);
				coord[1]=coord[1]-1;
			}
			break;
		case 4://left        
			if (coord[0]>0 && entityData[dungeon_depth].live[coord[0]-1][coord[1]] == 0 && mapLayer[dungeon_depth].mapDim[coord[0]-1][coord[1]]!='#'){
				entityData[dungeon_depth].live[coord[0]][coord[1]]=0;
				coord[0]=coord[0]-1;
				entityData[dungeon_depth].live[coord[0]][coord[1]]=1;
			}
			else if(entityData[dungeon_depth].live[coord[0]-1][coord[1]]>0){
				coord[0]=coord[0]-1;
				this->fightAndKillEnemy(coord);
				coord[0]=coord[0]+1;
			}
			break;
		case 6: //right
			if (coord[0]<GRID_WIDTH-1 && entityData[dungeon_depth].live[coord[0]+1][coord[1]] == 0 && mapLayer[dungeon_depth].mapDim[coord[0]+1][coord[1]]!='#'){
				entityData[dungeon_depth].live[coord[0]][coord[1]]=0;
				coord[0]=coord[0]+1;
				entityData[dungeon_depth].live[coord[0]][coord[1]]=1;
			}
			else if(entityData[dungeon_depth].live[coord[0]+1][coord[1]]>0){
				coord[0]=coord[0]+1;
				this->fightAndKillEnemy(coord);
				coord[0]=coord[0]-1;
			}
			break;
		case 8://up 
			if (coord[1]>0 && entityData[dungeon_depth].live[coord[0]][coord[1]-1] == 0 && mapLayer[dungeon_depth].mapDim[coord[0]][coord[1]-1]!='#'){
				entityData[dungeon_depth].live[coord[0]][coord[1]]=0;
				coord[1]=coord[1]-1;
				entityData[dungeon_depth].live[coord[0]][coord[1]]=1;
			}
			else if(entityData[dungeon_depth].live[coord[0]][coord[1]-1]>0){
				coord[1]=coord[1]-1;
				this->fightAndKillEnemy(coord);
				coord[1]=coord[1]+1;
			}
			break;
		default:
			return 0;
			break;
	}//end switch(event.key.keysym.sym)
	this->checkTileForItems();
	// checks for stariways up or down
	if(mapLayer[dungeon_depth].mapDim[coord[0]][coord[1]] == 'u') {
		dungeon_depth++;
		if(dungeon_depth > max_achieved_depth){
			max_achieved_depth++;
			this->level_generator();
		}
		player->setCoords(stairs_down[dungeon_depth][0],stairs_down[dungeon_depth][1]);
	}
	else if(mapLayer[dungeon_depth].mapDim[coord[0]][coord[1]] == 'd'){
		dungeon_depth--;
		player->setCoords(stairs_up[dungeon_depth][0],stairs_up[dungeon_depth][1]);
	}
	return 1;
}

/** \brief Fights the enemy at given coordinates
 *
 * \param coord A 2 dimensional coordinate of which enemy to attack
 *
 */     


void ActorManager::fightAndKillEnemy(int* coord){//player attack calculation function
	player_damage = battle.Sword(player->Strength(),player->Dexterity(),player->Stamina(),inv->equippedList()[1].getItemStat()+inv->equippedList()[2].getItemStat(),0);
	bool enemyAlive=enemy[dungeon_depth][entityData[dungeon_depth].live[coord[0]][coord[1]]]->Health(player_damage);
				
	if (!enemyAlive){
		entityData[dungeon_depth].dead[coord[0]][coord[1]]=entityData[dungeon_depth].live[coord[0]][coord[1]];
		entityData[dungeon_depth].live[coord[0]][coord[1]]=0;
		player->set_xp(enemy[dungeon_depth][entityData[dungeon_depth].dead[coord[0]][coord[1]]]->get_level());
		if (dungeon_depth == 2){
			kills++;
		}
	}
}

/** \brief Checks tile for items and puts it in the inventory
 * 
 *
 */     


void ActorManager::checkTileForItems(){//checks tile for items and picks up, if inventory not full
	int *coord=player->getCoords();
	while(!itemLayer[dungeon_depth].itemDataMap[coord[0]][coord[1]].empty()){
		if(inv->storeItem(itemLayer[dungeon_depth].itemDataMap[coord[0]][coord[1]].front())==1){
			itemLayer[dungeon_depth].itemDataMap[coord[0]][coord[1]].pop_front();
		}
		else{
			break;
		}
	}
}

/** \brief Controls the AI movement
 * 
 *
 */   

void ActorManager::AI(){//ai controller
	int *playerLoc=player->getCoords();
	int size=enemy[dungeon_depth].size();
	int cursor=2;
	int* coord;
	while (cursor-2 < size-2){
		coord=enemy[dungeon_depth][cursor]->getCoords();
		if (enemy[dungeon_depth][cursor]->Health(0)){
			
			int direction = npc -> direction( playerLoc, coord,entityData[dungeon_depth], mapLayer[dungeon_depth]);
			if(direction==8){//move up
				entityData[dungeon_depth].live[coord[0]][coord[1]]=0;
				coord[1]--;
				entityData[dungeon_depth].live[coord[0]][coord[1]]=enemy[dungeon_depth][cursor]->getID();
			}
			else if(direction==2){//move down
				entityData[dungeon_depth].live[coord[0]][coord[1]]=0;
				coord[1]++;
				entityData[dungeon_depth].live[coord[0]][coord[1]]=enemy[dungeon_depth][cursor]->getID();
			}
			else if(direction==4){//move left
				entityData[dungeon_depth].live[coord[0]][coord[1]]=0;
				coord[0]--;
				entityData[dungeon_depth].live[coord[0]][coord[1]]=enemy[dungeon_depth][cursor]->getID();
			}
			else if(direction==6){//move right
				entityData[dungeon_depth].live[coord[0]][coord[1]]=0;
				coord[0]++;
				entityData[dungeon_depth].live[coord[0]][coord[1]]=enemy[dungeon_depth][cursor]->getID();
			}
			else if(direction==0){
				play->play();
				enemy_damage = battle.Sword(enemy[dungeon_depth][cursor]->Strength(),enemy[dungeon_depth][cursor]->Dexterity(),enemy[dungeon_depth][cursor]->Stamina(),1,inv->equippedList()[0].getItemStat());
				player->Health(enemy_damage);
			}
			else if(direction==-1){
			}
		}
		cursor++;
	}
}

/** \brief Getter of the current inventory size
 * 
 * \return the size of the inventory
 *
 */     


int ActorManager::get_inventory_size(){
	return inv->getList().size();
}

/** \brief Removes an item from the inventory and places it on the current location of the player
 *
 * \param inventory_cursor the current cursor
 * \return the new cursor, should there have been any change to it
 *
 */     


int ActorManager::dropItem(int inventory_cursor){
	int *coord=player->getCoords();
	inventory_cursor=inv->inventory_control(1,inventory_cursor);
	if (inv->dropped_item().getID() != 0){
		itemLayer[dungeon_depth].itemDataMap[coord[0]][coord[1]].push_front(inv->dropped_item());
	}
	return inventory_cursor;
}

/** \brief Takes the selected item and equips it
 *
 * \param inventory_cursor the current selection
 * \return returns the new cursor number
 *
 */     


int ActorManager::equipItem(int inventory_cursor){
	inventory_cursor=inv->inventory_control(2,inventory_cursor);
	return inventory_cursor;
}



/** \brief Removes secondary weapon and puts it int the place of the inventory_cursor
 * 
 * \param inventory_cursor the current selection
 * \return returns the new cursor number
 *
 */     


int ActorManager::remove_secondary_weapon(int inventory_cursor){
	inventory_cursor=inv->inventory_control(3,inventory_cursor);
	return inventory_cursor;
}

/** \brief Generates a level.
 * 
 */     

void ActorManager::level_generator(){
	int x=0,y=0;
	Map map(dungeon_depth);
	EnemyGen gen;
	
	stairs_down[dungeon_depth][0]=map.get_stairs_down()[0];
	stairs_down[dungeon_depth][1]=map.get_stairs_down()[1];
	
	stairs_up[dungeon_depth][0]=map.get_stairs_up()[0];
	stairs_up[dungeon_depth][1]=map.get_stairs_up()[1];
	
	enemy[dungeon_depth]=gen.Generate(50,dungeon_depth+1);//generate the specified number of enemies
	while(y<GRID_HEIGHT){
		if(x<GRID_WIDTH){
			entityData[dungeon_depth].dead[x][y]=0;
			
			x++;
		}
		if(x==GRID_WIDTH){
			y++;
			x=0;
		}
	}
	x=0;
	y=0;
	
	mapLayer[dungeon_depth]=map.getMap();
	PlaceItemsAndEnemies place(mapLayer[dungeon_depth],enemy[dungeon_depth],dungeon_depth);//places generated enemies on the map
	enemy[dungeon_depth]=place.getEnemyList();//returns the list
	entityData[dungeon_depth]=place.getLiveEnemies();
	itemLayer[dungeon_depth]=place.getItems();
	
	mapTosend.mapData=mapLayer[dungeon_depth];
	mapTosend.entityData=entityData[dungeon_depth];
	mapTosend.itemData=itemLayer[dungeon_depth];
	mapTosend.stairsDown=stairs_down[dungeon_depth];
	mapTosend.stairsUp=stairs_up[dungeon_depth];
}

/** \brief Checks whether the player is alive
 *
 * 
 * \return the boolean value of players state
 *
 */     


bool ActorManager::check_player_death(){
	if(kills == 50){
		return false;
	}
	return player->Health(0);
	
}

/** \brief Sets up and sends camera data pointers
 *
 * \return CameraStruct pointer object
 *
 */     


CameraStruct* ActorManager::getData(){
	mapTosend.entityData=entityData[dungeon_depth];
	mapTosend.itemData=itemLayer[dungeon_depth];
	mapTosend.playerLoc=player->getCoords();
	
	UIDataToSend.player=player;
	UIDataToSend.enemyDamage=enemy_damage;
	UIDataToSend.playerDamage=player_damage;
	
	inventoryToSend.equippedItems=inv->equippedList();
	inventoryToSend.inventory=inv->getList();
	
	finalCameraData.mapStruct=mapTosend;
	finalCameraData.inventoryStruct=inventoryToSend;
	finalCameraData.userInterfaceStruct=UIDataToSend;
	
	CameraStruct* camPointer = &finalCameraData;
	return camPointer;
}

ActorManager::~ActorManager(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < enemy[i].size(); j++){
			delete enemy[i].at(j); //release memory used by these objects
			
		}
	}

	delete player;
	delete inv;
	delete npc;
}
