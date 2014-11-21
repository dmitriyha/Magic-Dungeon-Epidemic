#include "UserInterface.h"


UserInterface::UserInterface(){
}

/**	\brief	initializes the UI with the required data and textures
*	\param CameraStruct * _camData the camera data pointer that is shared with the whole program
*	\param Texture * _backgroundTexture pointer to BG texture
*	\param Texture * _itemTexture poiter to the texture that has item pictures
*/
void UserInterface::initialize(CameraStruct* _camData, Texture* _backgroundTexture, Texture* _itemTexture){
	backroundTexture = _backgroundTexture;
	itemTexture = _itemTexture;
	camData = _camData;


	carbon18 = new TextTexture();
	carbon18->setRenderer(backroundTexture->getRenderer());
	SDL_Color col = { 0, 0, 0, 0 };
	carbon18->initialise("img\\carbon.ttf", col, 18);

	level_bar = new Texture;
	level_bar->setRenderer(backroundTexture->getRenderer());
	level_bar->makeTexture("img\\level_bar.png");

	inventoryBackground = new Texture();
	inventoryBackground->setRenderer(backroundTexture->getRenderer());
	inventoryBackground->makeTexture("img\\inventory.png");

	curs = new Texture();
	curs->setRenderer(backroundTexture->getRenderer());
	curs->makeTexture("img\\cursor.png");

	Texture* t = new Texture();
	t->setRenderer(backroundTexture->getRenderer());
	t->makeTexture("img\\Building.png");

	SDL_Rect stoneTowerSprite{ 0, 65, 121, 174 };

	stoneTower.setTexture(t,stoneTowerSprite);
	stoneTower.setLocation(705, 307);

	SDL_Rect spikeTrapSprite{ 0, 0, 121, 65 };

	spikeTrap.setTexture(t, spikeTrapSprite);
	spikeTrap.setLocation(770, 307);
}

/** \brief handles the nutten events on the ui
*	\param event the SDL_Event struct
*
*	\return the detected button as string
*/
string UserInterface::eventHandler(SDL_Event event){
	if (stoneTower.isPressed(event)){
		return "stonetower";
	}
	else if (spikeTrap.isPressed(event)){
		return "spiketrap";
	}
	else{
		return "none";
	}
}

/**	\brief renders the UI to the screen, making it visible to the user
*
*/
void UserInterface::render(){

	if (camData->inventoryStruct.inventoryMode){//if in inventory mode
		inventory();//render the inventory
	}

	background();//render the bacground of the user interface
	text();//render the text of the user interface

	stoneTower.render();
	spikeTrap.render();

	SDL_RenderPresent(backroundTexture->getRenderer()); //finally show everything

}


/**	\brief	render the outer part of the whole user interface
*
*/
void UserInterface::background(){
	SDL_RenderCopy(backroundTexture->getRenderer(), backroundTexture->getTexture(), NULL, &backroundTexture->getSize());

}

/**	\brief	render all the text on the screen
*
*/
void UserInterface::text(){
	//the offset of the text to be shown on the screen
	SDL_Rect offset = { 0, 0, 0, 0 };



	//overall the pattern here is the same: set the location, se the text, se the size 


	offset.x = 707;
	offset.y = 0;

	setText("Magic Dungeon", offset);


	offset.x = 737;
	offset.y = 20;
	setText("Epidemic", offset);


	offset.x = 707;

	string converted_int;

	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Strength()))->str();
	string strength = "Strength:..." + converted_int;
	offset.y = 50;

	setText(strength, offset);


	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Dexterity()))->str();
	string dexterity = "Dexterity:.." + converted_int;
	offset.y = 70;
	setText(dexterity, offset);


	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Wits()))->str();
	string wits = "Wits:......." + converted_int;
	offset.y = 90;
	setText(wits, offset);


	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Sanity()))->str();
	string sanity = "Sanity:....." + converted_int;
	offset.y = 110;
	setText(sanity, offset);


	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Stamina()))->str();
	string stamina = "Stamina:...." + converted_int;
	offset.y = 130;
	setText(stamina, offset);


	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Charisma()))->str();
	string charisma = "Charisma:..." + converted_int;
	offset.y = 150;
	setText(charisma, offset);


	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Awareness()))->str();
	string awareness = "Awareness:.." + converted_int;
	offset.y = 170;
	setText(awareness, offset);


	converted_int = static_cast<ostringstream*>(&(ostringstream() << camData->userInterfaceStruct.player->Luck()))->str();
	string luck = "Luck:......." + converted_int;
	offset.y = 190;
	setText(luck, offset);


	//make function in this class for this

	offset.x = 704;
	offset.y = 225;


	setText("Level Progress", offset);


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
	setText(health, offset);



	offset.x = 10;
	offset.y = 530;

	if (camData->inventoryStruct.inventoryMode == false){
		setText("Arrow keys to move.", offset);

		offset.y = 550;
		setText("I - Inventory.", offset);


		offset.y = 570;
		setText("[SPACE] - Wait one turn", offset);

	}
	else{
		setText("W - Equip item.", offset);


		offset.y = 550;
		setText("R - Remove secondary weapon.", offset);


		offset.y = 570;
		setText("D - Drop item.", offset);


		offset.y = 590;
		setText("ESC/I - Back to game.", offset);

	}
}

/**	\brief	shows the inventory to the user
*
*/
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
	while (camData->inventoryStruct.inventory.size() > place){
		camData->inventoryStruct.inventory[place].render(offset);

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

/**	\brief	show the specified text at the specified location
*	\param	string text the string to be printed
*	\param	SDL_Rect offset where it will be printed on the screen
*/
void UserInterface::setText(string text, SDL_Rect offset){
	SDL_Rect textSize;

	carbon18->setText(text);
	textSize = carbon18->getSize();
	offset.h = textSize.h;
	offset.w = textSize.w;
	SDL_RenderCopy(carbon18->getRenderer(), carbon18->getTexture(), &textSize, &offset);

}


UserInterface::~UserInterface()
{
}
