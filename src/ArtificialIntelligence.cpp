#include "ArtificialIntelligence.h"

ArtificialIntelligence::ArtificialIntelligence(){
}

int ArtificialIntelligence::direction(int* playerLoc,int* coord,EntityData liveEnteties,MapData mapLayer){
	if(abs(playerLoc[0]-coord[0]) + abs(playerLoc[1]-coord[1])<=7){
		int choice=rand.generate(1,2);
		if (playerLoc[0]<coord[0]&&playerLoc[1]<coord[1] ){ //move diagonally towards palyer up and left
			if(liveEnteties.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#' && choice == 1){//move left
				return 4;
			}
			else if(liveEnteties.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#'){//move up
				return 8;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc[0]>coord[0]&&playerLoc[1]>coord[1] ){//move diagonally towards palyer down and right
		
			if(liveEnteties.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#' && choice == 1){//move down
				return 2;
			}
			else if(liveEnteties.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){//move right
				return 6;
			}	
			else{
				return -1;
			}
		}
		else if (playerLoc[0]>coord[0]&&playerLoc[1]<coord[1] ){//move diagonally towards palyer up and right
			if(liveEnteties.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#' && choice == 1){//move up
				return 8;
			}
			else if(liveEnteties.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){//move right
				return 6;
			}
			else{
				return -1;
			}
		}
		else if (playerLoc[0]<coord[0]&&playerLoc[1]>coord[1] ){//move diagonally towards palyer down and left
			if(liveEnteties.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#'){//move down
				return 2;
			}
			else if(liveEnteties.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#'){//move left
				return 4;
			}	
			else{
				return -1;
			}
		}
		else if(playerLoc[0]==coord[0]&&playerLoc[1]<coord[1] ){//move up
			if (liveEnteties.live[coord[0]][coord[1]-1] == 1){
				return 0;
			}
			else if(liveEnteties.live[coord[0]][coord[1]-1] > 1 || mapLayer.mapDim[coord[0]][coord[1]-1]=='#'){//up
				if(liveEnteties.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#'  && choice == 1){//move left
					return 4;
				}
				else if(liveEnteties.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){//move right
					return 6;
				}
				else{
					return -1;
				}
			}
			else if(liveEnteties.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#'){
				return 8;
			}
			else{
				return -1;
			}
		}
		else if(playerLoc[0]==coord[0]&&playerLoc[1]>coord[1] ){//move down
			if(liveEnteties.live[coord[0]][coord[1]+1] == 1){
				return 0;
			}
			else if(liveEnteties.live[coord[0]][coord[1]+1] > 1 || mapLayer.mapDim[coord[0]][coord[1]+1]=='#'){//down
				if(liveEnteties.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#'  && choice == 1){//move left
					return 4;
				}
				else if(liveEnteties.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){//move right
					return 6;
				}
				else{
					return -1;
				}
			}
			else if(liveEnteties.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#'){
				return 2;
			}
			else{
				return -1;
			}
		}
		else if(playerLoc[0]<coord[0]&&playerLoc[1]==coord[1]){//move left
			if (liveEnteties.live[coord[0]-1][coord[1]] == 1){
				return 0;
			}
			else if(liveEnteties.live[coord[0]-1][coord[1]] > 1 || mapLayer.mapDim[coord[0]-1][coord[1]]=='#'){//left
				if( liveEnteties.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#'  && choice == 1){//move up
					return 8;
				}
				else if( liveEnteties.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#'){//move down
					return 2;
				}
				else{
					return -1;
				}
			}
			else if( liveEnteties.live[coord[0]-1][coord[1]] == 0 && mapLayer.mapDim[coord[0]-1][coord[1]]!='#'){
				return 4;
			}
			else{
				return -1;
			}
		}
		else if(playerLoc[0]>coord[0]&&playerLoc[1]==coord[1]){//move right
			if(liveEnteties.live[coord[0]+1][coord[1]] == 1){
				return 0;
			}
			else if(liveEnteties.live[coord[0]+1][coord[1]] > 1 || mapLayer.mapDim[coord[0]+1][coord[1]]=='#'){//right
				if(liveEnteties.live[coord[0]][coord[1]+1] == 0 && mapLayer.mapDim[coord[0]][coord[1]+1]!='#' && choice == 1){//move down
					return 2;
				}
				else if(liveEnteties.live[coord[0]][coord[1]-1] == 0 && mapLayer.mapDim[coord[0]][coord[1]-1]!='#'){//move up
					return 8;
				}
				else{
					return -1;
				}
			}
			else if(liveEnteties.live[coord[0]+1][coord[1]] == 0 && mapLayer.mapDim[coord[0]+1][coord[1]]!='#'){
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
