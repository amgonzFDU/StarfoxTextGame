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
	void setItemName(std::string);
	void setItemLocation(Items *item);
	int getItemLocation(Items * item,int);
};
