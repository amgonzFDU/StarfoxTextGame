#include "Items.h"
#include "Room.h"
#include <iostream>
// constructor
// turns strings into numbers so rock is equal to 0 and key is equal to 1
enum itemsname { rock, key };
enum itemslocation{player,cell,cell2};
Items::Items() {

}
// destructor
Items::~Items() {

}
//sets the location of the item you want
void Items::setItemLocation(Items* item) {
	item[rock].name.assign("ROCK");
	item[rock].location = cell;
	item[key].name.assign("KEY");
	item[key].location = cell2;
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
	}
}
// If the player wants to drop an item then we get what room they are in and set that to the item;
void Items::PlayerDrop(Items* item, std::string userInput, int currentRoom) {
	
	int itemNameEnumNumber = getItemNameEnum(item, userInput);
	item[itemNameEnumNumber].location = currentRoom;
	
}
int Items::getItemLocation(Items* item,int itmNum) {
	int temp = item[itmNum].location;
	return temp;
	
}
/*
tries to find the item's number according to it's name
so if the user enters ROCK it should output a number 
acoridng to rock in the enum
output::
enum in the itemslocation
*/

int Items::userInputToEnumItemLocation(Items* item, std::string itmname) {
	if (itmname == "ROCK") {
		return getItemLocation(item, 0);
	}
	if (itmname == "KEY") {
		return getItemLocation(item, 1);
	}
	std::cout << "You did not spell that right or item doesn't exist \n";
	return -1;

}
int Items::getItemNameEnum(Items* item, std::string itemname) {
	if (itemname == "ROCK") {
		return 0;
	}
	if (itemname == "KEY") {
		return 1;
	}
}