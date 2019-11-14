#pragma once
#include <string>
#include "Items.h"
class Room
{
	friend class Items;
public:
	Items item;
	std::string name;
	std::string roomDiscription;
	std::string currentRoom;
	int roomNumber;
	int RoomExit[2];
	Room(Room* room, int);
	Room();
	~Room();
	void moveRoom(Room* room,int,int,Items*);
	void setRoom(Room* room);
	void setCurrentRoomName(Room* room, int);
	void setCurrentRoomNumber(Room* room, int);
	void setCurrentRoom(Room* room, int);
	std::string getCurrentRoomName();
	int getCurrentRoomNumber();
	std::string getRoomDiscription(Room*, int);
	std::string setRoomDiscription(int);
	bool exists(Room*,int,int);
	bool SolvePuzzle(Room* room, std::string, std::string, std::string);
	
};

