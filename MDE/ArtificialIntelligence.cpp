#include "ArtificialIntelligence.h"

ArtificialIntelligence::ArtificialIntelligence(){
}

/** \brief Returns a calculated direction for the enemy to take
 *
 * \param playerLoc The array of the player location
 * \param coord The array of the enemy's location
 * \param liveEntities EntityData struct for the current dungeon level to ensure 2 entities don't overlap
 * \param mapLayer MapData struct of the current dungeon so that NPCs can see the map
 * \return returns the direction code as defined on the num pad, 0 for attack, -1 for do nothing
 *
 */     


int ArtificialIntelligence::direction(LocationCoordinates  playerLoc, LocationCoordinates coord, EntityData liveEntities, MapData mapLayer, CameraStruct* dataForManaging){
	if(abs(playerLoc.x-coord.x) + abs(playerLoc.y-coord.y)<=7){//controls player visibility

		int choice=rand.generate(1,2);
		if (playerLoc.x<coord.x&&playerLoc.y<coord.y ){ //move diagonally towards palyer up and left

			if (liveEntities.live[coord.x - 1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x - 1][coord.y] != '#' &&
				choice == 1 &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x-1][coord.y] == 0){
				//move left
				return 4;
			}
			else if(liveEntities.live[coord.x][coord.y-1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y-1]!='#' &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y-1] == 0){
				//move up
				return 8;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc.x>coord.x&&playerLoc.y>coord.y ){//move diagonally towards palyer down and right
		
			if(liveEntities.live[coord.x][coord.y+1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y+1]!='#' &&
				choice == 1 &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y+1] == 0){ //toimii
				//move down
				return 2;
			}
			else if(liveEntities.live[coord.x+1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x+1][coord.y]!='#' &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x+1][coord.y] == 0){
				//move right
				return 6;
			}	
			else{
				return -1;
			}
		}
		else if (playerLoc.x>coord.x&&playerLoc.y<coord.y ){//move diagonally towards palyer up and right
			if(liveEntities.live[coord.x][coord.y-1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y-1]!='#' &&
				choice == 1 &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y-1] == 0){
				//move up
				return 8;
			}
			else if(liveEntities.live[coord.x+1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x+1][coord.y]!='#' &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x+1][coord.y] == 0){
				//move right
				return 6;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc.x<coord.x&&playerLoc.y>coord.y ){//move diagonally towards palyer down and left
			if(liveEntities.live[coord.x][coord.y+1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y+1]!='#' &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y+1] == 0){
				//move down
				return 2;
			}
			else if(liveEntities.live[coord.x-1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x-1][coord.y]!='#' && 
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x-1][coord.y] == 0){
				//move left
				return 4;
			}	
			else{
				return -1;
			}
		}
		else if(playerLoc.x==coord.x&&playerLoc.y<coord.y ){//move up
			if (liveEntities.live[coord.x][coord.y-1] == 1){
				//combat
				return 0;
			}
			else if(liveEntities.live[coord.x][coord.y-1] > 1 || mapLayer.mapDim[coord.x][coord.y-1]=='#'){//up
				if(liveEntities.live[coord.x-1][coord.y] == 0 &&
					mapLayer.mapDim[coord.x-1][coord.y]!='#'  &&
					choice == 1 &&
					dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x-1][coord.y] == 0){
					//move left
					return 4;
				}
				else if(liveEntities.live[coord.x+1][coord.y] == 0 &&
					mapLayer.mapDim[coord.x+1][coord.y]!='#' &&
					dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x+1][coord.y] == 0){
					//move right
					return 6;
				}
				else{
					return -1;
				}
			}
			else if(liveEntities.live[coord.x][coord.y-1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y-1]!='#' &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y-1] == 0){
				return 8;
			}
			else{
				return -1;
			}
		}
		else if(playerLoc.x==coord.x&&playerLoc.y>coord.y ){//move down
			if(liveEntities.live[coord.x][coord.y+1] == 1){
				//Combat
				return 0;
			}
			else if(liveEntities.live[coord.x][coord.y+1] > 1 || mapLayer.mapDim[coord.x][coord.y+1]=='#'){//down
				if(liveEntities.live[coord.x-1][coord.y] == 0 &&
					mapLayer.mapDim[coord.x-1][coord.y]!='#'  &&
					choice == 1 &&
					dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x-1][coord.y] == 0){
					//move left
					return 4;
				}
				else if(liveEntities.live[coord.x+1][coord.y] == 0 &&
					mapLayer.mapDim[coord.x+1][coord.y]!='#' &&
					dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x+1][coord.y] == 0){
					//move right
					return 6;
				}
				else{
					return -1;
				}
			}
			else if(liveEntities.live[coord.x][coord.y+1] == 0 &&
				mapLayer.mapDim[coord.x][coord.y+1]!='#' &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y+1] == 0){
				return 2;
			}
			else{
				return -1;
			}
		}
		else if(playerLoc.x<coord.x&&playerLoc.y==coord.y){//move left
			if (liveEntities.live[coord.x-1][coord.y] == 1){
				//Combat
				return 0;
			}
			else if(liveEntities.live[coord.x-1][coord.y] > 1 || mapLayer.mapDim[coord.x-1][coord.y]=='#'){//left
				if( liveEntities.live[coord.x][coord.y-1] == 0 &&
					mapLayer.mapDim[coord.x][coord.y-1]!='#'  &&
					choice == 1 &&
					dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y-1] == 0){
					//move up
					return 8;
				}
				else if( liveEntities.live[coord.x][coord.y+1] == 0 &&
					mapLayer.mapDim[coord.x][coord.y+1]!='#' &&
					dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y+1] == 0){
					//move down
					return 2;
				}
				else{
					return -1;
				}
			}
			else if( liveEntities.live[coord.x-1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x-1][coord.y]!='#' &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x-1][coord.y] == 0){
				return 4;
			}
			else{
				return -1;
			}
		}
		else if(playerLoc.x>coord.x&&playerLoc.y==coord.y){//move right
			if(liveEntities.live[coord.x+1][coord.y] == 1){
				//combat
				return 0;
			}
			else if(liveEntities.live[coord.x+1][coord.y] > 1 || mapLayer.mapDim[coord.x+1][coord.y]=='#'){//right
				if(liveEntities.live[coord.x][coord.y+1] == 0 &&
					mapLayer.mapDim[coord.x][coord.y+1]!='#' &&
					choice == 1 &&
					dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y+1] == 0){
					//move down
					return 2;
				}
				else if(liveEntities.live[coord.x][coord.y-1] == 0 &&
					mapLayer.mapDim[coord.x][coord.y-1]!='#' &&
					dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x][coord.y-1] == 0){
					//move up
					return 8;
				}
				else{
					return -1;
				}
			}
			else if(liveEntities.live[coord.x+1][coord.y] == 0 &&
				mapLayer.mapDim[coord.x+1][coord.y]!='#' &&
				dataForManaging->mapStruct[dataForManaging->currentLevel].entityDataBuildings.live[coord.x+1][coord.y] == 0){
				return 6;
			}
			else{
				return -1;
			}
		}
		else{
			return -1;
		}
	}
	else{
		return -1;
	}
}

ArtificialIntelligence::~ArtificialIntelligence(){
}
