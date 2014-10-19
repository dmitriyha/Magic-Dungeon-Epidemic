#include "Map.h"

/** \brief The class that creates the map.
 *	
 *	the computation happens in the constructor
 * 
 * \param depth determines the type of stairs to put on the level
 */     


Map::Map(CameraStruct* cam){
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
	mapData = cam;
	
	while(y<GRID_HEIGHT){
		if(x<GRID_WIDTH){
			mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y]='#';
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
				if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[RoomD.locx + x][RoomD.locy + y] == '#'){
					x++;
				}
				else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[RoomD.locx + x][RoomD.locy + y] == '.'){
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
						mapData->mapStruct[mapData->currentLevel].mapData.mapDim[RoomD.locx + x][RoomD.locy + y] = '#';
						x++;
					}
					else if (y==0||y==RoomD.roomy-1){
						mapData->mapStruct[mapData->currentLevel].mapData.mapDim[RoomD.locx + x][RoomD.locy + y] = '#';
						x++;
					}
					else{
						mapData->mapStruct[mapData->currentLevel].mapData.mapDim[RoomD.locx + x][RoomD.locy + y] = '.';
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
			mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] = '.';
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
		if (mapData->currentLevel == 0){
			if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] == '.'){
				stairs_up[0]=x;
				stairs_up[1]=y;
				mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] = 'u';
				placed = 1;
			}
		}
		else if(mapData->currentLevel == 1){
			if (stairways_placed == 0 && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] == '.'){
				stairs_up[0]=x;
				stairs_up[1]=y;
				mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] = 'u';
				stairways_placed ++;
			}
			else if (stairways_placed == 1 && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] == '.'){
				stairs_down[0]=x;
				stairs_down[1]=y;
				mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] = 'd';
				placed ++;
			}
		}
		else if (mapData->currentLevel == 2){
			if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] == '.'){
				stairs_down[0]=x;
				stairs_down[1]=y;
				mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] = 'd';
				placed = 1;
			}
		}
	}

	mapData->mapStruct[mapData->currentLevel].stairsUp = stairs_up;
	mapData->mapStruct[mapData->currentLevel].stairsDown = stairs_down;

}

Texture* Map::getMapAsTexture(){
	tex = new Texture();
	tex->setRenderer(renderer);
	tex->makeBlankTexture(GRID_WIDTH*TILE_WIDTH, GRID_HEIGHT*TILE_HEIGHT);
	Texture tile_set;
	tile_set.setRenderer(renderer);
	tile_set.makeTexture("img\\wall.png");
	
	SDL_Rect offset;
	offset.h = TILE_HEIGHT;
	offset.w = TILE_WIDTH;


	SDL_Rect floor;
	SDL_Rect top_wall;
	SDL_Rect top_left_corner;
	SDL_Rect left_wall;
	SDL_Rect bottom_left_corner;
	SDL_Rect bottom_wall;
	SDL_Rect bottom_right_corner;
	SDL_Rect right_wall;
	SDL_Rect top_right_corner;
	SDL_Rect blank;
	SDL_Rect stairs_up;
	SDL_Rect stairs_down;

	//sprite rect set;
	floor.x = 64;
	floor.y = 48;
	floor.w = 64;
	floor.h = 48;

	top_wall.x = 64;
	top_wall.y = 0;
	top_wall.w = 64;
	top_wall.h = 48;

	top_left_corner.x = 0;
	top_left_corner.y = 0;
	top_left_corner.w = 64;
	top_left_corner.h = 48;

	left_wall.x = 0;
	left_wall.y = 48;
	left_wall.w = 64;
	left_wall.h = 48;

	bottom_left_corner.x = 0;
	bottom_left_corner.y = 96;
	bottom_left_corner.w = 64;
	bottom_left_corner.h = 48;

	bottom_wall.x = 64;
	bottom_wall.y = 96;
	bottom_wall.w = 64;
	bottom_wall.h = 48;

	bottom_right_corner.x = 128;
	bottom_right_corner.y = 96;
	bottom_right_corner.w = 64;
	bottom_right_corner.h = 48;

	right_wall.x = 128;
	right_wall.y = 48;
	right_wall.w = 64;
	right_wall.h = 48;

	top_right_corner.x = 128;
	top_right_corner.y = 0;
	top_right_corner.w = 64;
	top_right_corner.h = 48;

	blank.x = 192;
	blank.y = 0;
	blank.w = 64;
	blank.h = 48;

	stairs_up.x = 192;
	stairs_up.y = 48;
	stairs_up.w = 64;
	stairs_up.h = 48;

	stairs_down.x = 192;
	stairs_down.y = 96;
	stairs_down.w = 64;
	stairs_down.h = 48;


	SDL_SetRenderTarget(renderer, tex->getTexture());

	int x = 0;
	int y = 0;

	while (y<GRID_HEIGHT){
		while (x<GRID_WIDTH){
			offset.x = x * TILE_WIDTH;		//places the picture in the right place
			offset.y = y * TILE_HEIGHT;

			if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] == '.'){								//floor is rendered
				SDL_RenderCopy(renderer, tile_set.getTexture(), &floor,&offset);
			}
			else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] == 'u'){
				SDL_RenderCopy(renderer, tile_set.getTexture(),  &stairs_up,&offset);
			}
			else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] == 'd'){
				SDL_RenderCopy(renderer, tile_set.getTexture(),  &stairs_down,&offset);
			}
			else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y] == '#'){								//walls are rendered
				if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x + 1][y] == '#' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y + 1] == '#' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x + 1][y + 1] == '.'){
					SDL_RenderCopy(renderer, tile_set.getTexture(), &top_left_corner, &offset);
				}
				else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x + 1][y] == '#' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y - 1] == '#' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x + 1][y - 1] == '.'){
					SDL_RenderCopy(renderer, tile_set.getTexture(), &bottom_left_corner, &offset);
				}
				else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x - 1][y] == '#' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y - 1] == '#' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x - 1][y - 1] == '.'){
					SDL_RenderCopy(renderer, tile_set.getTexture(), &bottom_right_corner, &offset);
				}
				else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x - 1][y] == '#' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y + 1] == '#' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x - 1][y + 1] == '.'){
					SDL_RenderCopy(renderer, tile_set.getTexture(), &top_right_corner, &offset);
				}
				else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x + 1][y] == '.' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x - 1][y] == '#'){
					SDL_RenderCopy(renderer, tile_set.getTexture(), &left_wall, &offset);
				}
				else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y - 1] == '.' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y + 1] == '#'){
					SDL_RenderCopy(renderer, tile_set.getTexture(), &bottom_wall, &offset);
				}
				else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x - 1][y] == '.' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y + 1] == '#'){
					SDL_RenderCopy(renderer, tile_set.getTexture(), &right_wall, &offset);
				}
				else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y + 1] == '.' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y - 1] == '#'){
					SDL_RenderCopy(renderer, tile_set.getTexture(), &top_wall, &offset);
				}
				else if (mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y + 1] == '.' && mapData->mapStruct[mapData->currentLevel].mapData.mapDim[x][y - 1] == '.'){
					SDL_RenderCopy(renderer, tile_set.getTexture(), &top_wall, &offset);
				}
				else{
					SDL_RenderCopy(renderer, tile_set.getTexture(), &blank, &offset);
				}
			}
			//SDL_RenderPresent(renderer);
			x++;
		}
		x = 0;
		y++;
	}

	SDL_SetRenderTarget(renderer, NULL);
	return tex;
}

void Map::render(){
	SDL_RenderCopy(renderer, tex->getTexture(), NULL, NULL);
}

void Map::setRenderer(SDL_Renderer* _renderer){
	renderer = _renderer;
}

Map::~Map(){
}
