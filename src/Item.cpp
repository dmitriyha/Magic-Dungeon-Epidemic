#include"Item.h"

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

int Item::getID(){
	return ID;
}

int Item::getItemStat(){							
	return itemStat;
}

string Item::Name(){
	return name;
}

string Item::Descriprion(){
	return description;
}

string Item::getType(){
	return type;
}

Item::~Item(){
}
