#include"Item.h"

/** \brief Creates an Item of the ID specified in the item data sheet
 *
 * \param id the item that this Item object will be, as defined in the item_data.csv
 */     


Item::Item(int id){							//defines everything an item needs
	ReadFile read;
	ID=id;
	if (id != 0){
		int pass=1;
		//string filePath[]={"items\\weapon.csv","items\\armor.csv","items\\misc.csv"};
		int fileNum=0;
		while (pass<=ID){
			string check=read.readFile("item_data.csv",id,1);//looks for the specified item from the 3 different files
			if (check=="-1"){
				fileNum++;
				id=1;
			}
			pass++;
		}
		//once found,sets the relevant data
		name=read.readFile("item_data.csv",id,2);
		description=read.readFile("item_data.csv",id,3);
		string dmg =read.readFile("item_data.csv",id,4);
		itemStat= atoi(dmg.c_str());
		string stack =read.readFile("item_data.csv",id,5);
		maxStack=atoi(stack.c_str());
		type=read.readFile("item_data.csv",id,6);
	}
	else{
		itemStat=0;
	}
}

/** \brief Gets the item ID, as defined in the item_data.csv
 * 
 * \return the ID of this Item object
 */    


int Item::getID(){
	return ID;
}

/** \brief Gets the damage enhancement or armor, depending on the item type
 * 
 * \return damage enhancement or armor, depending on the item type
 */  

int Item::getItemStat(){							
	return itemStat;
}

/** \brief gets the name of the Item in string form
 * 
 * \return the name in string form
 */  

string Item::Name(){
	return name;
}

/** \brief gets the description of the Item in string form
 * 
 * \return the description in string form
 */  
string Item::Descriprion(){
	return description;
}

/** \brief gets the type(armor, sword,etc) of the Item in string form
 * 
 * \return the type in string form
 */  
string Item::getType(){
	return type;
}

Item::~Item(){
}
