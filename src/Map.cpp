#include "Map.h"

Map::Map(int depth){
	int x=0,y=0;//map coordinates
	int maxRoom=0;//maximum desired rooms
	bool keep=true;//whether a room is kept, or a new one is generated
	int pass=0;//the time-to-live of a room generator
	int roomNO=0;//the number of generated rooms
	int cursor=0;//used for path generation
	bool pathGen=true;
	RoomDimension RoomD; //definition of struct
	deque<RoomDimension> rooms;//deque list creation for dimension storage
	RNG random;
	
	
	while(y<GRID_HEIGHT){
		if(x<GRID_WIDTH){
			map.mapDim[x][y]='#';
			x++;
		}
		else if(x==GRID_WIDTH){
			y++;
			x=0;
		}
	}
	x=0;
	y=0;
	
	while (maxRoom<MAX_ROOMS){//room generation
		keep=true;
		int i;
		for(i=0;i<50000;i++);
		RoomD.locx=random.generate(0,GRID_WIDTH); //generates the x coordinate
		
		RoomD.locy=random.generate(0,GRID_HEIGHT);//generates the y coordinate
		
		RoomD.roomx=1+(2*(random.generate(2,4)));//generates the x dimension of the room
		
		RoomD.roomy=1+(2*(random.generate(2,4)));//generates the y dimension of the room
		
		//the check to make sure the room does not overflow outside of the map
		if (RoomD.locx+RoomD.roomx>GRID_WIDTH-1){
			RoomD.locx=RoomD.locx-((RoomD.locx+RoomD.roomx)-(GRID_WIDTH));
		}
		if (RoomD.locy+RoomD.roomy>GRID_HEIGHT-1){
			RoomD.locy=RoomD.locy-((RoomD.locy+RoomD.roomy)-(GRID_HEIGHT));
		}
		
		RoomD.midx=RoomD.locx+(RoomD.roomx/2)-1;
		RoomD.midy=RoomD.locy+(RoomD.roomy/2)-1;
		
		while(y<RoomD.roomy&&keep){//checks whether the space to be occupied by the room is free or not
			if(x<RoomD.roomx){
				if(map.mapDim[RoomD.locx+x][RoomD.locy+y]=='#'){
					x++;
				}
				else if(map.mapDim[RoomD.locx+x][RoomD.locy+y]=='.'){
					keep=false; //sets the throw away flag
				}
			}
			else if(x==RoomD.roomx){
				y++;
				x=0;
			}
			
		}
		
		x=0;
		y=0;
		if(keep){//if the room was kept, room is created on the map
			while(y<RoomD.roomy){
				if(x<RoomD.roomx){
					if (x==0||x==RoomD.roomx-1){
						map.mapDim[RoomD.locx+x][RoomD.locy+y]='#';
						x++;
					}
					else if (y==0||y==RoomD.roomy-1){
						map.mapDim[RoomD.locx+x][RoomD.locy+y]='#';
						x++;
					}
					else{
						map.mapDim[RoomD.locx+x][RoomD.locy+y]='.';
						x++;
					}
				}
				else if(x==RoomD.roomx){
					y++;
					x=0;
				}
			}//end while(y<RoomD.roomy)
			rooms.emplace(rooms.begin()+roomNO, RoomD);//store the location and dimensions of the kept room for path generation
			
			roomNO++;
			maxRoom++;
			pass=0;
		}//end if(keep)
		x=0;
		y=0;
		
		if (pass==10){//if there were 10 unsuccessful passes, the room is "skipped"
			maxRoom++;
		}
		pass++;
	}//end while (maxRoom<MAX_ROOMS)
	
	while(cursor<rooms.size()-1){//path generationn between rooms
		x=rooms[cursor].midx+1;
		y=rooms[cursor].midy+1;
		while(pathGen){
			//these move towards the room center
			if (x<rooms[cursor+1].midx+1){
				x++;
			}
			else if (x>rooms[cursor+1].midx+1){
				x--;
			}
			else if (y<rooms[cursor+1].midy+1){
				y++;
			}
			else if (y>rooms[cursor+1].midy+1){
				y--;
			}
			else if (x==rooms[cursor+1].midx+1 && y==rooms[cursor+1].midy+1){
				pathGen=false;
			}
			map.mapDim[x][y]='.';
		}//end while(pathGen)
		cursor++;//cursor is the room number in the list
		pathGen=true;
	}//end while(cursor<rooms.size()-1)
	x=0;
	y=0;
	int placed=0;
	int stairways_placed=0;
	
	//stairway generating code
	while (!placed){
		x=random.generate(0,GRID_WIDTH); //generates the x coordinate
		y=random.generate(0,GRID_HEIGHT);//generates the y coordinate
		if (depth == 0){
			if(map.mapDim[x][y] == '.'){
				stairs_up[0]=x;
				stairs_up[1]=y;
				map.mapDim[x][y]='u';
				placed = 1;
			}
		}
		else if(depth == 1){
			if(stairways_placed == 0 && map.mapDim[x][y] == '.'){
				stairs_up[0]=x;
				stairs_up[1]=y;
				map.mapDim[x][y]='u';
				stairways_placed ++;
			}
			else if(stairways_placed == 1 && map.mapDim[x][y] == '.'){
				stairs_down[0]=x;
				stairs_down[1]=y;
				map.mapDim[x][y]='d';
				placed ++;
			}
		}
		else if (depth == 2){
			if(map.mapDim[x][y] == '.'){
				stairs_down[0]=x;
				stairs_down[1]=y;
				map.mapDim[x][y]='d';
				placed = 1;
			}
		}
	}
}

MapData Map::getMap (){;
	return map;
}

int * Map::get_stairs_up(){
	return stairs_up;
}

int * Map::get_stairs_down(){
	return stairs_down;
}

Map::~Map(){
}
