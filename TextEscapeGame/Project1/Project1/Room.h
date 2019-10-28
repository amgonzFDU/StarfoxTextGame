#pragma once
#include <string>
class Room
{
	friend class Items;
public:
	int name;
	int currentRoom;
	int RoomExit[2];
	Room(Room* room, int);
	Room();
	~Room();
	void moveRoom(Room* room,int,int);
	void setRoom(Room* room);
	void setCurrentRoom(Room* room, int);
	int getCurrentRoom();
};

