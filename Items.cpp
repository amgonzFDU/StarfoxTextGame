//This class will be used for the items the player will be able to pick up and use.
#include "items.h"
/*
 Create items for use
 -Key
 -Candle 
 -Anything else that comes to mind????
*/
Items::item() 
{

}
Items::~item() 
{

}
Items::setItemName(Items * item) {
	
	
	item[1]->name = "rock";
}
Items::getItemName() {
	return this->name;
}
/*
Define uses for each item
throw, unlock, eat, kick
*/