#include"Inventory.h"

Inventory::Inventory(){
	inventory.push_back(Item(1));
	inventory.push_back(Item(1));
	inventory.push_back(Item(1));
}

/** \brief Stores the specified Item
 *
 * \param item the Item to be stored
 * \return returns 1 if successful store, else returns 0
 *
 */     

int Inventory::storeItem(Item item){//inventosy store function
	if (inventory.size()<15){
		inventory.push_back(item);//store items at the back of the list
		return 1;
	}
	else{
		return 0;
	}
}

/** \brief Controls the inventory based on the specified mode at the specified cursor
 *
 * \param mode Mode 1 drops item, mode 2 equips and unequips items that are on, mode 3 uequips off hand weapon
 * \param inventory_cursor the current cursor in the inventory
 * \return returns new inventory cursor
 *
 */     


int Inventory::inventory_control(int mode, int inventory_cursor){
	int size=inventory.size();
	if (mode == 1){ // drop items
		if(size != 0){
			dropped_Item=inventory[inventory_cursor-1];
			this->removeItem(inventory_cursor);
		}
		else{
			dropped_Item= Item(0);
		}
		if(size <= inventory_cursor){
			inventory_cursor--;
		}
	}//end if (mode == 1)
	else if(mode == 2){//equip and unequip items
		if(size != 0){
			if(inventory[inventory_cursor-1].getType() == "chest"){//equip any chest armor
				if (chest.getID() == 0){
					chest = inventory[inventory_cursor - 1];
					this->removeItem(inventory_cursor);
					if(size < inventory_cursor){
						inventory_cursor--;
					}
				}
				else{
					Item temp = chest;
					chest = inventory[inventory_cursor - 1];
					inventory[inventory_cursor - 1]= temp;
				}
			}//end if(inventory[inventory_cursor-1].getType() == "chest")
			if(inventory[inventory_cursor-1].getType() == "sword" || inventory[inventory_cursor-1].getType() == "mace" || inventory[inventory_cursor-1].getType() == "bow" || inventory[inventory_cursor-1].getType() == "crossbow" || inventory[inventory_cursor-1].getType() == "staff"){
				//equip any weapon
				if (main_hand.getID() == 0){  
					main_hand = inventory[inventory_cursor - 1];
					this->removeItem(inventory_cursor);
					if(size <= inventory_cursor){
						inventory_cursor--;
					}
				}//end if (main_hand.getID() == 0)
				else if(main_hand.getType() != "bow" && main_hand.getType() != "crossbow" && main_hand.getType() != "staff" && inventory[inventory_cursor-1].getType() != "bow" && inventory[inventory_cursor-1].getType() != "crossbow" && inventory[inventory_cursor-1].getType() != "staff"){
					//should you be wearing a 1-handed weapon, equip another in the off hand
					if (off_hand.getID() == 0 ){
						off_hand = inventory[inventory_cursor - 1];
						this->removeItem(inventory_cursor);
						if(size <= inventory_cursor){
							inventory_cursor--;
						}
					}
					else{
						if (main_hand.getID() != 0){
							Item temp = main_hand;
							main_hand = inventory[inventory_cursor - 1];
							//this->removeItem(inventory_cursor);
							inventory[inventory_cursor - 1]=temp;
						}
						else{
							main_hand = inventory[inventory_cursor - 1];
							this->removeItem(inventory_cursor);
						}
						if(size <= inventory_cursor){
							inventory_cursor--;
						}
					}
				}//end else if(main_hand.getType() != "bow" && main_hand.getType() !=...
				else{
					Item temp = main_hand;
					main_hand = inventory[inventory_cursor - 1];
					inventory[inventory_cursor - 1]= temp;
					if (off_hand.getID() > 0 ){  //takes the secondaty weapon off should the equipped weapon be 2 handed
						temp = off_hand;		//should the equipped weapon be 2 handed
						off_hand=Item(0);
						inventory.push_back(temp);
					}
				}//end else
			}//end if(inventory[inventory_cursor-1].getType() == "sword" || ...
		}//end if(size != 0)
	}//end else if(mode == 2)
	else if (mode == 3){
		if (off_hand.getID() > 0 ){
			Item temp = off_hand;
			off_hand=Item(0);
			inventory.push_back(temp);
		}
	}
	return inventory_cursor;
}

/** \brief Removes the item in the specified slot
 *
 * \param remove the item in this slot
 *
 */     

void Inventory::removeItem(int rmItem){
	if(rmItem>0){
		inventory.erase(inventory.begin()+(rmItem-1));//remove the specified item
	}
}

/** \brief Returns the dropped Item.
 * 
 * \return the dropped item to put on the ground
 *
 */     

Item Inventory::dropped_item(){
	return dropped_Item;
}

/** \brief Returns the inventory list.
 * 
 * \return the inventory list.
 *
 */   
deque<Item> Inventory::getList(){//returns list
	return inventory;
}

/** \brief Returns the a list of equipped items.
 * 
 * \return list of equipped items.
 *
 */   
deque<Item> Inventory::equippedList(){
	deque<Item> list;
	list.push_back(chest);
	list.push_back(main_hand);
	list.push_back(off_hand);
	return list;
}


void Inventory::setPrimaryWeapon(Item item){
	main_hand = item;
}

Inventory::~Inventory(){
}
