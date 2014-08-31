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


int ArtificialIntelligence::direction(int* playerLoc,int* coord,EntityData liveEntities,MapData mapLayer){
	if(abs(playerLoc[0]-coord[0]) + abs(playerLoc[1]-coord[1])<=7){//controls player visibility
		int choice=rand.generate(1,2);
		if (playerLoc[0]<coord[0]&&playerLoc[1]<coord[1] ){ //move diagonally towards palyer up and left
			if(liveEntities.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#' && choice == 1){//move left
				return 4;
			}
			else if(liveEntities.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#'){//move up
				return 8;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc[0]>coord[0]&&playerLoc[1]>coord[1] ){//move diagonally towards palyer down and right
		
			if(liveEntities.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#' && choice == 1){//move down
				return 2;
			}
			else if(liveEntities.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){//move right
				return 6;
			}	
			else{
				return -1;
			}
		}
		else if (playerLoc[0]>coord[0]&&playerLoc[1]<coord[1] ){//move diagonally towards palyer up and right
			if(liveEntities.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#' && choice == 1){//move up
				return 8;
			}
			else if(liveEntities.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){//move right
				return 6;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc[0]<coord[0]&&playerLoc[1]>coord[1] ){//move diagonally towards palyer down and left
			if(liveEntities.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#'){//move down
				return 2;
			}
			else if(liveEntities.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#'){//move left
				return 4;
			}	
			else{
				return -1;
			}
		}
		else if(playerLoc[0]==coord[0]&&playerLoc[1]<coord[1] ){//move up
			if (liveEntities.live[coord[0]][coord[1]-1] == 1){
				return 0;
			}
			else if(liveEntities.live[coord[0]][coord[1]-1] > 1 || mapLayer.mapDim[coord[0]][coord[1]-1]=='#'){//up
				if(liveEntities.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#'  && choice == 1){//move left
					return 4;
				}
				else if(liveEntities.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){//move right
					return 6;
				}
				else{
					return -1;
				}
			}
			else if(liveEntities.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#'){
				return 8;
			}
			else{
				return -1;
			}
		}
		else if(playerLoc[0]==coord[0]&&playerLoc[1]>coord[1] ){//move down
			if(liveEntities.live[coord[0]][coord[1]+1] == 1){
				return 0;
			}
			else if(liveEntities.live[coord[0]][coord[1]+1] > 1 || mapLayer.mapDim[coord[0]][coord[1]+1]=='#'){//down
				if(liveEntities.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#'  && choice == 1){//move left
					return 4;
				}
				else if(liveEntities.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){//move right
					return 6;
				}
				else{
					return -1;
				}
			}
			else if(liveEntities.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#'){
				return 2;
			}
			else{
				return -1;
			}
		}
		else if(playerLoc[0]<coord[0]&&playerLoc[1]==coord[1]){//move left
			if (liveEntities.live[coord[0]-1][coord[1]] == 1){
				return 0;
			}
			else if(liveEntities.live[coord[0]-1][coord[1]] > 1 || mapLayer.mapDim[coord[0]-1][coord[1]]=='#'){//left
				if( liveEntities.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#'  && choice == 1){//move up
					return 8;
				}
				else if( liveEntities.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#'){//move down
					return 2;
				}
				else{
					return -1;
				}
			}
			else if( liveEntities.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#'){
				return 4;
			}
			else{
				return -1;
			}
		}
		else if(playerLoc[0]>coord[0]&&playerLoc[1]==coord[1]){//move right
			if(liveEntities.live[coord[0]+1][coord[1]] == 1){
				return 0;
			}
			else if(liveEntities.live[coord[0]+1][coord[1]] > 1 || mapLayer.mapDim[coord[0]+1][coord[1]]=='#'){//right
				if(liveEntities.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#' && choice == 1){//move down
					return 2;
				}
				else if(liveEntities.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#'){//move up
					return 8;
				}
				else{
					return -1;
				}
			}
			else if(liveEntities.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){
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
