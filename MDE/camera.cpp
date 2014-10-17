#include "camera.h"

/** \brief Camera class constructor.
 *
 * This class is responsible for showing stuff on the screen
 *
 * \param _camData Pointer to CameraStruct, which holds all of the data of the logic
 * \param _screen The surface where we will be blitting.
 * 
 *
 */     


Camera::Camera(CameraStruct* _camData,SDL_Renderer* _screen){
	screen=_screen;
	camData=_camData;
	
	//player=new Texture ("img\\char.png",screen);
	player=new Texture("img\\player0.png", screen);
	enemy =new Texture("img\\goblinsword.png",screen);
	tile_set = new Texture("img\\wall.png", screen);
	//tile_set =new Texture("img\\tile_set.png",screen);
	inventoryBMP =new Texture("img\\inventory.png",screen);
	curs = new Texture("img\\cursor.png",screen);
	item_surface = new Texture("img\\items.png",screen);
	UI = new Texture("img\\userinterface.png",screen);
	level_bar = new Texture("img\\level_bar.png",screen);
	stoneTower = new Texture("img\\TowerStone.png", screen);
	
	
	SDL_Color color={0,0,0};
	carbon18=new TextTexture ("img\\carbon.ttf",color,18,screen);//message
	
	//sprite rect set;
	floor.x=64;
	floor.y=48;
	floor.w=64;
	floor.h=48;
	
	top_wall.x=64;
	top_wall.y=0;
	top_wall.w=64;
	top_wall.h=48;
	
	top_left_corner.x=0;
	top_left_corner.y=0;
	top_left_corner.w=64;
	top_left_corner.h=48;
	
	left_wall.x=0;
	left_wall.y=48;
	left_wall.w=64;
	left_wall.h=48;
	
	bottom_left_corner.x=0;
	bottom_left_corner.y=96;
	bottom_left_corner.w=64;
	bottom_left_corner.h=48;
	
	bottom_wall.x=64;
	bottom_wall.y=96;
	bottom_wall.w=64;
	bottom_wall.h=48;
	
	bottom_right_corner.x=128;
	bottom_right_corner.y=96;
	bottom_right_corner.w=64;
	bottom_right_corner.h=48;
	
	right_wall.x=128;
	right_wall.y=48;
	right_wall.w=64;
	right_wall.h=48;
	
	top_right_corner.x=128;
	top_right_corner.y=0;
	top_right_corner.w=64;
	top_right_corner.h=48;
	
	blank.x=192;
	blank.y=0;
	blank.w=64;
	blank.h=48;
	
	stairs_up.x=192;
	stairs_up.y=48;
	stairs_up.w=64;
	stairs_up.h=48;
	
	stairs_down.x=192;
	stairs_down.y=96;
	stairs_down.w=64;
	stairs_down.h=48;


	//EnemyLocation
	enemylocation.x = 0;
	enemylocation.y = 0;
	enemylocation.w = 40;
	enemylocation.h = 57;

	//Player
	playerlocation.x = 0;
	playerlocation.y = 0;
	playerlocation.w = 48;
	playerlocation.h = 58;

	//Stonetower location
	towerstonelocation.x = 0;
	towerstonelocation.y = 0;
	towerstonelocation.w = 115;
	towerstonelocation.h = 177;




	//load all item textures
	
	ReadFile read;
	int cursor=1;
	int pass=0;
	//string filePath[]={"items\\weapon.csv","items\\armor.csv","items\\misc.csv"};
	while(pass!=1){											//while not end of file...
		string check_for_eof=read.readFile("item_data.csv",cursor,7);
		if(check_for_eof=="-1"){
			cursor=1;
			pass++;
		}
		else{
			SDL_Rect temp_rect;
			temp_rect.x = atoi(read.readFile("item_data.csv",cursor,7).c_str());
			temp_rect.y = atoi(read.readFile("item_data.csv",cursor,8).c_str());
			temp_rect.w = 64;
			temp_rect.h = 48;
			itemTextures.push_back(temp_rect);		//...load the pictures specified and put them into a list for easy access
			
			cursor++;
			
		}
		
	}
	//prepare the cursor with color keying
	//end preperation
}

/** \brief Shows the screen
 *
 *
 */     


void Camera::renderScreen(){
	
	
	if ( camData->inventoryStruct.inventoryMode == true){
		inventoryRender();
	}
	else{renderAll();}
	
	user_interface();
	print_dmg();
	if(camData->userInterfaceStruct.player->Health()<=0){
		game_over();
	}
}

/** \brief the screen where enemies and the player is.
 *
 *
 */     


void Camera::renderAll(){
	int x = camData->mapStruct[camData->currentLevel].playerLoc[0] - (CAMERA_GRID_WIDTH / 2);
	int y = camData->mapStruct[camData->currentLevel].playerLoc[1] - (CAMERA_GRID_HEIGHT / 2);
	SDL_Rect offset={0,0,0,0};
	deque<Item> item;
	
	//cout << x << " " << y << endl;
	
	//the fillowing ifs keep the camera from going out of bounds
	if (camData->mapStruct[camData->currentLevel].playerLoc[0]<((CAMERA_GRID_WIDTH / 2))){
		x=0;
	}

	else if (camData->mapStruct[camData->currentLevel].playerLoc[0] + ((CAMERA_GRID_WIDTH / 2) + 1) > GRID_WIDTH){
		x = GRID_WIDTH - CAMERA_GRID_WIDTH;
	}
	
	if (camData->mapStruct[camData->currentLevel].playerLoc[1]<((CAMERA_GRID_HEIGHT / 2))){
		y=0;
	}
	
	
	
	else if (camData->mapStruct[camData->currentLevel].playerLoc[1] + ((CAMERA_GRID_HEIGHT / 2) + 1) > GRID_HEIGHT){
		y = GRID_HEIGHT - CAMERA_GRID_HEIGHT;
	}
	
	int xCorner=x;
	int yCorner=y;
	
	camData->leftCornerX = xCorner;
	camData->leftCornerY = yCorner;

	while(y<yCorner+CAMERA_GRID_HEIGHT){		//this renders onlt what is needed to be visible
		offset.x = (x-xCorner)* TILE_WIDTH;		//places the picture in the right place
		offset.y = (y-yCorner)* TILE_HEIGHT;
		
		item = camData->mapStruct[camData->currentLevel].itemData.itemDataMap[x][y];						//the deque at (x,y) is accessed
		
		if(x<xCorner+CAMERA_GRID_WIDTH){
			if (camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y]=='.'){								//floor is rendered
				tile_set->renderTile(floor,offset);
			}
			else if (camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y]=='u'){								//stairs are rendered
				tile_set->renderTile(stairs_up,offset);
			}
			else if (camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y]=='d'){								//stairs are is rendered
				tile_set->renderTile(stairs_down,offset);
			}
			else if(camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y]=='#'){								//walls are rendered
				if(camData->mapStruct[camData->currentLevel].mapData.mapDim[x + 1][y] == '#' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y + 1] == '#' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x + 1][y + 1] == '.'){
					tile_set->renderTile(top_left_corner,offset);
				}
				else if(camData->mapStruct[camData->currentLevel].mapData.mapDim[x + 1][y] == '#' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y - 1] == '#' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x + 1][y - 1] == '.'){
					tile_set->renderTile(bottom_left_corner,offset);
				}
				else if(camData->mapStruct[camData->currentLevel].mapData.mapDim[x - 1][y] == '#' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y - 1] == '#' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x - 1][y - 1] == '.'){
					tile_set->renderTile(bottom_right_corner,offset);
				}
				else if(camData->mapStruct[camData->currentLevel].mapData.mapDim[x - 1][y] == '#' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y + 1] == '#' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x - 1][y + 1] == '.'){
					tile_set->renderTile(top_right_corner,offset);
				}
				else if (camData->mapStruct[camData->currentLevel].mapData.mapDim[x + 1][y] == '.' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x - 1][y] == '#'){
					tile_set->renderTile(left_wall,offset);
				}
				else if (camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y - 1] == '.' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y + 1] == '#'){
					tile_set->renderTile(bottom_wall,offset);
				}
				else if (camData->mapStruct[camData->currentLevel].mapData.mapDim[x - 1][y] == '.' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y + 1] == '#'){
					tile_set->renderTile(right_wall,offset);
				}
				else if(camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y + 1] == '.' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y - 1] == '#'){
					tile_set->renderTile(top_wall,offset);
				}
				else if(camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y + 1] == '.' && camData->mapStruct[camData->currentLevel].mapData.mapDim[x][y - 1] == '.'){
					tile_set->renderTile(top_wall,offset);
				}
				else{
					tile_set->renderTile(blank,offset);
				}
			}
			if (camData->mapStruct[camData->currentLevel].entityData.dead[x][y]>0){											//dead enteties are rendered
				enemy->renderTile(enemylocation,offset);
			}
			offset.w = TILE_WIDTH;
			offset.h = TILE_HEIGHT;
			if(!item.empty()){											//checks for whether the list is empty...
				int cursor=item.size()-1;
				while(cursor>=0){
					
					item_surface->renderTile((itemTextures[item[cursor].getID()-1]),offset);
					cursor--;
					
				}
			}
			
			offset.w = TILE_WIDTH;
			offset.h = TILE_HEIGHT * 2;
			if (camData->mapStruct[camData->currentLevel].entityData.live[x][y]>1){											//renders live enteties
				offset.y=offset.y-TILE_HEIGHT;
				enemy->renderTile(enemylocation,offset);
			}
			else if (camData->mapStruct[camData->currentLevel].entityData.live[x][y]==1){								//renders player
				offset.y = offset.y - TILE_HEIGHT;
				player->renderTile(playerlocation,offset);
			}

			int coord1[2] = {0,0};
			if (buildData->building-> != NULL){
				//if (buildData->building->getCoords() != NULL){
				if (x == coord1[0] && y == coord1[1]){											//renders live enteties
					offset.y = offset.y - TILE_HEIGHT;
					stoneTower->renderTile(towerstonelocation, offset);
				}
			}
			//Tee tähän tower renderointi
			
			x++;

		}//end if(x<xCorner+CAMERA_GRID_WIDTH)
		if(x==xCorner+CAMERA_GRID_WIDTH){
			y++;
			x=xCorner;
		}
	}//end while(y<yCorner+CAMERA_GRID_HEIGHT)
	
	
}

/** \brief Renders the inventory screen
 *
 */     


void Camera::inventoryRender(){
	int place=0;
	int invRow=0;
	SDL_Rect offset={0,0,0,0};
	
	offset.x = 0;		//places the picture in the right place
	offset.y = 0;
	
	//SDL_BlitSurface(UI,NULL,screen,NULL);
	inventoryBMP->render (offset);
	
	offset.x = 425;		//places the picture in the right place
	offset.y = 173;
	while(camData->inventoryStruct.inventory.size()>place){
		item_surface->renderTile((itemTextures[camData->inventoryStruct.inventory[place].getID()-1]),offset);
		
		place++;
		invRow++;
		offset.x = offset.x ;
		if (invRow==3){
			offset.x = 425;
			offset.y = offset.y ;
			invRow=0;
		}
		
	}
	
	//cursor offset and placement
	if(camData->inventoryStruct.inventory.size() > 0){
		offset.x = 425 + (((camData->inventoryStruct.inventory_cursor - 1) % 3) * 80);
		offset.y = 173 + (((camData->inventoryStruct.inventory_cursor -1) / 3) * 58);
		curs->render(offset);
		
		/*SDL_Rect message_offset;
		message_offset.x=10;
		message_offset.y=10;*/
		offset.x= 400;
		offset.y = 690;
		//description=IMG_Load("img\\description.png");
		carbon18->setText(camData->inventoryStruct.inventory[camData->inventoryStruct.inventory_cursor-1].Descriprion() );
		//SDL_BlitSurface(message,NULL,description,&message_offset);
		carbon18->render(offset);
		//SDL_FreeSurface(description);
	}
	
	//places equipped items
	if (camData->inventoryStruct.equippedItems[0].getID() != 0){
		offset.x = 143;
		offset.y = 186;
		item_surface->renderTile((itemTextures[camData->inventoryStruct.equippedItems[0].getID()-1]),offset);
	}
	
	if (camData->inventoryStruct.equippedItems[1].getID() != 0){
		offset.x = 31;
		offset.y = 186;
		item_surface->renderTile((itemTextures[camData->inventoryStruct.equippedItems[1].getID()-1]),offset);
	}
	
	if (camData->inventoryStruct.equippedItems[2].getID() != 0){
		offset.x = 256;
		offset.y = 186;
		item_surface->renderTile((itemTextures[camData->inventoryStruct.equippedItems[2].getID()-1]),offset);
	}
	
	
}

/** \brief Renders the user interface (the stuff around the main screen and inventory
 *
 *
 */     


void Camera:: user_interface(){
	SDL_Rect offset1={0,0,0,0};
	
	UI->render(offset1);
	
	offset1.x=707;
	offset1.y=0;
	carbon18->setText("Magic Dungeon" );
	carbon18->render(offset1);
	
	
	
	offset1.x=737;
	offset1.y=20;
	carbon18->setText("Epidemic" );
	carbon18->render(offset1);
	
	offset1.x=707;
	
	string converted_int;
	
	converted_int=static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.player->Strength()) )->str();
	string strength = 	"Strength:..."+converted_int ;
	offset1.y=50;
	carbon18->setText( strength );
	carbon18->render(offset1);
	
	converted_int=static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.player->Dexterity()) )->str();
	string dexterity = 	"Dexterity:.."+converted_int;
	offset1.y=70;
	carbon18->setText( dexterity );
	carbon18->render(offset1);
	
	converted_int=static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.player->Wits()) )->str();
	string wits = 		"Wits:......."+converted_int;
	offset1.y=90;
	carbon18->setText( wits );
	carbon18->render(offset1);
	
	converted_int=static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.player->Sanity()) )->str();
	string sanity = 	"Sanity:....."+converted_int;
	offset1.y=110;
	carbon18->setText( sanity );
	carbon18->render(offset1);
	
	converted_int=static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.player->Stamina()) )->str();
	string stamina = 	"Stamina:...."+converted_int;
	offset1.y=130;
	carbon18->setText( stamina );
	carbon18->render(offset1);
	
	converted_int=static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.player->Charisma()) )->str();
	string charisma = 	"Charisma:..."+converted_int;
	offset1.y=150;
	carbon18->setText( charisma );
	carbon18->render(offset1);
	
	converted_int=static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.player->Awareness()) )->str();
	string awareness = 	"Awareness:.."+converted_int;
	offset1.y=170;
	carbon18->setText( awareness );
	carbon18->render(offset1);
	
	converted_int=static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.player->Luck()) )->str();
	string luck = 		"Luck:......."+converted_int;
	offset1.y=190;
	carbon18->setText( luck );
	carbon18->render(offset1);
	
	//make function in this class for this
	
	offset1.x = 704;
	offset1.y = 225;
	
	
	carbon18->setText( "Level Progress" );
	carbon18->render(offset1);
	
	offset1.x = 707;
	offset1.y = 245;
	offset1.h = 30;
	offset1.w = 110;
	
	SDL_Rect levelbar;
	levelbar.x = 0;
	levelbar.y = 0;
	levelbar.h = 30;
	levelbar.w = 110;
	
	level_bar->renderTile(levelbar,offset1);
	
	offset1.x = 712;
	offset1.y = 250;
	offset1.h = 20;
	offset1.w = camData->userInterfaceStruct.player->get_level_progress();
	
	SDL_Rect levelbar_progress;
	levelbar_progress.x = 0;
	levelbar_progress.y = 30;
	levelbar_progress.h = 20;
	levelbar_progress.w = camData->userInterfaceStruct.player->get_level_progress();
	
	level_bar->renderTile(levelbar_progress,offset1);
	offset1.h = 0;
	offset1.w = 0;
	// end function
	
	
	string health = "Health: " + (static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.player->Health())) )->str();
	offset1.x = 707;
	offset1.y = 275;
	carbon18->setText( health );
	carbon18->render(offset1);
	
	
	offset1.x=10;
	offset1.y=530;
	
	if ( camData->inventoryStruct.inventoryMode == false){
		carbon18->setText( "Arrow keys to move." );
		carbon18->render(offset1);
		
		offset1.y=550;
		carbon18->setText( "I - Inventory.");
		carbon18->render(offset1);
		
		offset1.y=570;
		carbon18->setText("[SPACE] - Wait one turn" );
		carbon18->render(offset1);
	}
	else{
		carbon18->setText( "W - Equip item.");
		carbon18->render(offset1);
		
		offset1.y=550;
		carbon18->setText( "R - Remove secondary weapon.");
		carbon18->render(offset1);
		
		offset1.y=570;
		carbon18->setText( "D - Drop item.");
		carbon18->render(offset1);
		
		offset1.y=590;
		carbon18->setText( "ESC/I - Back to game.");
		carbon18->render(offset1);
	}
}

/** \brief Prints the damage dealt on the screen.
 * 
 *
 */     


void Camera::print_dmg(){
	string damage_text;
	
	SDL_Rect offset1;
	
	offset1.x = 650;
	offset1.y = 550;
	
	if (camData->userInterfaceStruct.playerDamage>0){
		damage_text= "You dealt " + static_cast<ostringstream*>( &(ostringstream() << camData->userInterfaceStruct.playerDamage) )->str();
		carbon18->setText( damage_text);
		carbon18->render(offset1);
		camData->userInterfaceStruct.playerDamage = 0;
	}
	
	offset1.x = 650;
	offset1.y = 570;
	
	if (camData->userInterfaceStruct.enemyDamage>0){
		damage_text = "Enemy dealt " + static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.enemyDamage))->str();
		carbon18->setText( damage_text);
		carbon18->render(offset1);
		camData->userInterfaceStruct.enemyDamage = 0;
	}
	
}

/** \brief Called, should a game over state be reached
 *
 * 
 *
 */     

void Camera::game_over(){
	Texture t("img\\game_over.png",screen);
	SDL_Rect rect = {0,0,0,0};
	t.render(rect);
}

/** \brief clears screen in preparation for next frame
 */     


void Camera::clear_screen(){
	SDL_SetRenderDrawColor( screen, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( screen );
}

Camera::~Camera(){
	delete player;
	delete enemy;
	delete tile_set;
	delete inventoryBMP ;
	delete curs;
	delete item_surface;
	delete UI;
	delete level_bar ;
	delete carbon18;
	delete stoneTower;
}
