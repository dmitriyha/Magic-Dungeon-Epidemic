#include "Controls.h"

Controls::Controls(){
	
	manage= new ActorManager();
	cameraData=manage->getData();
	cameraData->inventoryStruct.inventory_cursor=inventory_cursor;
	cameraData->inventoryStruct.inventoryMode=inventory;
}

void Controls::buttons(SDL_Event event){
	int direction=0;
	int size = manage->get_inventory_size();
	if (manage->check_player_death()  ){
		switch(event.key.keysym.sym){
			case SDLK_i:
				if(!inventory){		//sets inventory to visible
					inventory=true;
				}
				else{				//hides inventory
					inventory=false;
				}
				break;
			case SDLK_d:
				if(inventory){
					inventory_cursor=manage->dropItem(inventory_cursor);
				}
				break;
			case SDLK_w:
				if(inventory){
					inventory_cursor=manage->equipItem(inventory_cursor);
				}
				break;
			case SDLK_r:
				if (inventory){
					inventory_cursor=manage->remove_secondary_weapon(inventory_cursor);
				}
				break;
			case SDLK_DOWN: case SDLK_KP_2:
				if (inventory){
					inventory_cursor = inventory_cursor + 3;
					if(inventory_cursor > size){
						inventory_cursor = size;
					}
				}
				else{
					direction = 2;
				}
				break;
			case SDLK_UP: case SDLK_KP_8:
				if (inventory){
					inventory_cursor = inventory_cursor - 3;
					if(inventory_cursor <= 0){
						inventory_cursor = 1;
					}
				}
				else{
					direction = 8;
				}
				break;
			case SDLK_LEFT: case SDLK_KP_4:
				if (inventory){
					inventory_cursor --;
					if(inventory_cursor <= 0){
						inventory_cursor = 1;
					}
				}
				else{
					direction = 4;
				}
				break;
			case SDLK_RIGHT: case SDLK_KP_6:
				if (inventory){
					inventory_cursor ++;
					if(inventory_cursor > size){
						inventory_cursor = size;
					}
				}
				else{
					direction = 6;
				}
				break;
			case SDLK_ESCAPE://also hides inventory when escape is pressed
				if (inventory){
					inventory=false;
				}
				break;
		}//end switch(event.key.keysym.sym)
		if (size == 0){
			inventory_cursor = 1;
		}
		if(!inventory){
			if (manage->playerMovement(direction) || event.key.keysym.sym == SDLK_SPACE){//if player moved...
				manage->AI();//...move the enemies...
			}
			
		}
	}
	manage->getData();
	cameraData->inventoryStruct.inventory_cursor=inventory_cursor;
	cameraData->inventoryStruct.inventoryMode=inventory;
	
}

CameraStruct* Controls::getData(){
	return cameraData;
}

Controls::~Controls(){
	delete manage;
	//delete cameraData;
}
