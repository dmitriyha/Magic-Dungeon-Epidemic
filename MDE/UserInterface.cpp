#include "UserInterface.h"


UserInterface::UserInterface(){
}

void UserInterface::initialize(CameraStruct* _camData, Texture* _backgroundTexture, Texture* _itemTexture){
	backroundTexture = _backgroundTexture;
	itemTexture = _itemTexture;
	camData = _camData;


	carbon18 = new TextTexture();
	carbon18->setRenderer(backroundTexture->getRenderer());
	SDL_Color col = { 0, 0, 0, 0 };
	carbon18->initialise("img\\carbon.ttf",col,18);

	level_bar = new Texture;
	level_bar->setRenderer(backroundTexture->getRenderer());
	level_bar->makeTexture("img\\level_bar.png");

	inventoryBackground = new Texture();
	inventoryBackground->setRenderer(backroundTexture->getRenderer());
	inventoryBackground->makeTexture("img\\inventory.png");

	curs = new Texture();
	curs->setRenderer(backroundTexture->getRenderer());
	curs->makeTexture("img\\cursor.png");
}

void UserInterface::render(){

	if (camData->inventoryStruct.inventoryMode){//if in inventory mode
		inventory();//render the inventory
	}
	
	background();//render the bacground of the user interface
	text();//render the text of the user interface

	SDL_RenderPresent(backroundTexture->getRenderer()); //finally show everything
	
}

void UserInterface::background(){
	SDL_RenderCopy(backroundTexture->getRenderer(), backroundTexture->getTexture(), NULL, &backroundTexture->getSize());
	
}

void UserInterface::text(){

	SDL_Rect offset = { 0, 0, 0,0};
	SDL_Rect textSize;

	offset.x = 707;
	offset.y = 0;
	carbon18->setText("Magic Dungeon");
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize,&offset );



	offset.x = 737;
	offset.y = 20;
	carbon18->setText("Epidemic");
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	offset.x = 707;

	string converted_int;

	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Strength()))->str();
	string strength = "Strength:..." + converted_int;
	offset.y = 50;
	carbon18->setText(strength);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Dexterity()))->str();
	string dexterity = "Dexterity:.." + converted_int;
	offset.y = 70;
	carbon18->setText(dexterity);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Wits()))->str();
	string wits = "Wits:......." + converted_int;
	offset.y = 90;
	carbon18->setText(wits);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Sanity()))->str();
	string sanity = "Sanity:....." + converted_int;
	offset.y = 110;
	carbon18->setText(sanity);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Stamina()))->str();
	string stamina = "Stamina:...." + converted_int;
	offset.y = 130;
	carbon18->setText(stamina);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Charisma()))->str();
	string charisma = "Charisma:..." + converted_int;
	offset.y = 150;
	carbon18->setText(charisma);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Awareness()))->str();
	string awareness = "Awareness:.." + converted_int;
	offset.y = 170;
	carbon18->setText(awareness);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Luck()))->str();
	string luck = "Luck:......." + converted_int;
	offset.y = 190;
	carbon18->setText(luck);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	//make function in this class for this

	offset.x = 704;
	offset.y = 225;


	carbon18->setText("Level Progress");
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

	offset.x = 707;
	offset.y = 245;
	offset.h = 30;
	offset.w = 110;

	SDL_Rect levelbar;
	levelbar.x = 0;
	levelbar.y = 0;
	levelbar.h = 30;
	levelbar.w = 110;

	//level_bar->renderTile(levelbar, offset);
	SDL_RenderCopy(level_bar->getRenderer(), level_bar->getTexture(), &levelbar, &offset);

	offset.x = 712;
	offset.y = 250;
	offset.h = 20;
	offset.w = camData->userInterfaceStruct.player->get_level_progress();

	SDL_Rect levelbar_progress;
	levelbar_progress.x = 0;
	levelbar_progress.y = 30;
	levelbar_progress.h = 20;
	levelbar_progress.w = 100;

	SDL_RenderCopy(level_bar->getRenderer(), level_bar->getTexture(), &levelbar_progress, &offset);
	offset.h = 0;
	offset.w = 0;
	// end function


	string health = "Health: " + (static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Health())))->str();
	offset.x = 707;
	offset.y = 275;
	carbon18->setText(health);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);


	offset.x = 10;
	offset.y = 530;

	if (camData->inventoryStruct.inventoryMode == false){
		carbon18->setText("Arrow keys to move.");
		textSize = carbon18->getSize();
		offset.h = textSize.h;
		offset.w = textSize.w;
		SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

		offset.y = 550;
		carbon18->setText("I - Inventory.");
		textSize = carbon18->getSize();
		offset.h = textSize.h;
		offset.w = textSize.w;
		SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

		offset.y = 570;
		carbon18->setText("[SPACE] - Wait one turn");
		textSize = carbon18->getSize();
		offset.h = textSize.h;
		offset.w = textSize.w;
		SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);
	}
	else{
		carbon18->setText("W - Equip item.");
		textSize = carbon18->getSize();
		offset.h = textSize.h;
		offset.w = textSize.w;
		SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

		offset.y = 550;
		carbon18->setText("R - Remove secondary weapon.");
		textSize = carbon18->getSize();
		offset.h = textSize.h;
		offset.w = textSize.w;
		SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

		offset.y = 570;
		carbon18->setText("D - Drop item.");
		textSize = carbon18->getSize();
		offset.h = textSize.h;
		offset.w = textSize.w;
		SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

		offset.y = 590;
		carbon18->setText("ESC/I - Back to game.");
		textSize = carbon18->getSize();
		offset.h = textSize.h;
		offset.w = textSize.w;
		SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);
	}
}

void UserInterface::inventory(){
	SDL_RenderCopy(inventoryBackground->getRenderer(), inventoryBackground->getTexture(), NULL, &inventoryBackground->getSize());


	int place = 0;
	int invRow = 0;
	SDL_Rect offset = { 0, 0, 64, 48 };

	offset.x = 0;		//places the picture in the right place
	offset.y = 0;

	//SDL_BlitSurface(UI,NULL,screen,NULL);


	offset.x = 425;		//places the picture in the right place
	offset.y = 173;
	while (camData->inventoryStruct.inventory.size()>place){
		camData->inventoryStruct.inventory[place].render(offset) ;

		place++;
		invRow++;
		offset.x = offset.x + 80;
		if (invRow == 3){
			offset.x = 425;
			offset.y = offset.y + 58;
			invRow = 0;
		}

	}


	//cursor offset and placement
	if (camData->inventoryStruct.inventory.size() > 0){
		offset.x = 425 + (((camData->inventoryStruct.inventory_cursor - 1) % 3) * 80);
		offset.y = 173 + (((camData->inventoryStruct.inventory_cursor - 1) / 3) * 58);
		SDL_RenderCopy(curs->getRenderer(), curs->getTexture(), NULL, &offset);

		/*SDL_Rect message_offset;
		message_offset.x=10;
		message_offset.y=10;*/
		offset.x = 400;
		offset.y = 690;
		//description=IMG_Load("img\\description.png");
		carbon18->setText(camData->inventoryStruct.inventory[camData->inventoryStruct.inventory_cursor - 1].Descriprion());
		//SDL_BlitSurface(message,NULL,description,&message_offset);
		//carbon18->render(offset);
		//SDL_FreeSurface(description);
	}

	//places equipped items
	if (camData->inventoryStruct.equippedItems[0].getID() != 0){
		offset.x = 143;
		offset.y = 186;
		camData->inventoryStruct.equippedItems[0].render(offset);
	}

	if (camData->inventoryStruct.equippedItems[1].getID() != 0){
		offset.x = 31;
		offset.y = 186;
		camData->inventoryStruct.equippedItems[1].render(offset);
	}

	if (camData->inventoryStruct.equippedItems[2].getID() != 0){
		offset.x = 256;
		offset.y = 186;
		camData->inventoryStruct.equippedItems[2].render(offset);
	}

	
}

UserInterface::~UserInterface()
{
}
