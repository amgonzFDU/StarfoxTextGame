#include "Items.h"
#include "Room.h"
#include <iostream>
// constructor
// turns strings into numbers so rock is equal to 0 and key is equal to 1
enum itemsname { rock, key,scroll,candle,rope,spear,bar,chest,ring,mirror,key2,flask,sizeofitems};

enum itemslocation{
	player, cell, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9
	, cell10, cell11, cell12, cell13, cell14, cell15, cell16, cell17, cell18
	, cell19, cell20, cell21,sizeoflocatins
};
Items::Items() {

}
// destructor
Items::~Items() {

}
//sets the location of the item you want
void Items::setItemLocation(Items* item) {
	item[rock].name.assign("ROCK");
	item[rock].location = cell;
	item[rock].itemRoom.assign("cell");

	item[key].name.assign("KEY");
	item[key].location = cell;
	item[key].itemRoom.assign("cell");

	item[scroll].name.assign("SCROLL");
	item[scroll].location = cell;
	item[scroll].itemRoom.assign("cell");

	item[candle].name.assign("CANDLE");
	item[candle].location = cell;
	item[candle].itemRoom.assign("cell");

	item[rope].name.assign("ROPE");
	item[rope].location = cell2;
	item[rope].itemRoom.assign("cell2");

	item[spear].name.assign("SPEAR");
	item[spear].location = cell11;
	item[spear].itemRoom.assign("cell11");

	item[bar].name.assign("BAR");
	item[bar].location = cell11;
	item[bar].itemRoom.assign("cell11");

	item[chest].name.assign("CHEST");
	item[chest].location = cell9;
	item[chest].itemRoom.assign("cell9");

	item[ring].name.assign("RING");
	item[ring].location = cell9;
	item[ring].itemRoom.assign("cell9");

	item[mirror].name.assign("MIRROR");
	item[mirror].location = cell14;
	item[mirror].itemRoom.assign("cell14");

	item[key2].name.assign("KEY2");
	item[key2].location = cell14;
	item[key2].itemRoom.assign("cell14");

	item[flask].name.assign("FLASK");
	item[flask].location = cell15;
	item[flask].itemRoom.assign("cell15");

}
/*
gets the location of the item which it outputs as a number the computer gives it
but it will give a acctuall room when we friend the room class.
*/
void Items::PlayerPickup(Items* item, std::string userInput,int currentRoom) {
	int itemLocationEnumNumber;
	itemLocationEnumNumber = userInputToEnumItemLocation(item, userInput);
	//this next line checks to see if the player
	//is in the room that the item is in to pick it up
	if (currentRoom == itemLocationEnumNumber) {
		int itemNameEnumNumber = getItemNameEnum(item, userInput);
		item[itemNameEnumNumber].location = 0;
		item[itemNameEnumNumber].itemRoom.assign("Player");
		std::cout << "You picked up " + item[itemNameEnumNumber].name << std::endl;
	}
}
// If the player wants to drop an item then we get what room 
// they are in and set that to the item;
void Items::PlayerDrop(Items* item, std::string userInput, int currentRoomNumber,std::string currentRoomName) {
	
	int itemNameEnumNumber = getItemNameEnum(item, userInput);
	item[itemNameEnumNumber].location = currentRoomNumber;

	//don't think we need this seems useless?
	//std::string itemName = ItemEnumToString(item, itemNameEnumNumber);
	item[itemNameEnumNumber].itemRoom = currentRoomName;
}
int Items::getItemLocation(Items* item,int itmNum) {
	int temp = item[itmNum].location;
	return temp;
}

std::string Items::getItemLocationName(Items* item, int itemNum) {
	return item[itemNum].itemRoom;
}
/*
tries to find the item's number according to it's name
so if the user enters ROCK it should output a number 
acoridng to rock in the enum
input:: itemname (from user input)
output:: item's location as a number
*/

int Items::userInputToEnumItemLocation(Items* item, std::string itmname) {
	
	for (int i = 0; i < sizeoflocatins; i++) {
		if (itmname == item[i].name) {
			return getItemLocation(item, i);
		}
	}
	std::cout << "You did not spell that right or item doesn't exist \n";
	return -1;
	
}
/*
returns the item's number example key is related to 1
input:
itemname (from user input)
outputs:
The number that represents that item
*/
int Items::getItemNameEnum(Items* item, std::string itemname) {
	
	for (int i = 0; i < sizeofitems; i++) {
		if (itemname == item[i].name) {
			return i;
		}
	}
	
}
////turns the players input into a string based on it's enum number
////but I don't think we use this so it's useless
//std::string Items::ItemEnumToString(Items* item, int itemEnum) {
//	
//	for (int i = 0; i < sizeofitems; i++) {
//		if (itemEnum == item[i].location) {
//			return 0;
//		}
//	}
//	/*if (itemEnum == rock) {
//		return "Rock";
//	}
//	if (itemEnum == key) {
//		return "Key";
//	}*/
//}
//Confirms the player is able to use the item since it's in their inventory
bool Items::CheckInventory(Items* item, std::string itemName) {
	
	for (int i = 0; i <= flask; i++) {
		if (item[i].location == player) {
			return true;
		}
	}
	std::cout << itemName + " is not in your inventory. \n";
	return false;
}
/*
outputs the players inventory
Jira Issue # Fox-139
*/
void Items::outputPlayerItems(Items* item) {
	std::cout << "Your Inventory" << std::endl;
	for (int i = 0; i <= flask; i++) {
		if (item[i].location == player) {
			std::cout << item[i].name<<std::endl;
		}
	}
}
void Items::outputRoomItems(Items* item, int currentRoom) {
	std::cout << "This room contains: \n";
	int count = 0;
	for (int i = 0; i <= flask; i++) {
			if (item[i].location == currentRoom) {
				std::cout << item[i].name << std::endl;
				count++;
			}
	}
	if (count == 0) {
		std::cout << "Nothing\n";
	}
	
}