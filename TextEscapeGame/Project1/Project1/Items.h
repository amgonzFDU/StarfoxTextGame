#pragma once
#include <string>
//see if this can be a friend of the room class -jeremy

class Items
{
	friend class Room;
public:
	std::string name;
	int location;
	Items();
	~Items();
	int userInputToEnumItemLocation(Items* item, std::string);
	int getItemNameEnum(Items*, std::string);
	void setItemLocation(Items *item);
	int getItemLocation(Items * item,int);
	void PlayerPickup(Items* item, std::string,int);
	void PlayerDrop(Items* item, std::string,int);

};