#include "Items.h"
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
	item[rock].name.assign("rock");
	item[rock].location = cell;
	item[key].location = cell2;
}
/*
gets the location of the item which it outputs as a number the computer gives it
but it will give a acctuall room when we friend the room class.
*/

int Items::getItemLocation(Items* item,int itmNum) {
	int temp = item[itmNum].location;
	return temp;
	
}