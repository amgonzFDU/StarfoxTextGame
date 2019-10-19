#pragma once
#include <string>
class Room
{
public:
	std::string name;
	std::string currentRoom;
	int RoomExit[2];
	Room(Room* room, int);
	Room();
	~Room();
	void setRoom(Room* room);
	void setCurrentRoom(Room* room, int);
	std::string getCurrentRoom();
};

