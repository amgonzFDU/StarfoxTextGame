#pragma once
#include <string>
class Room
{
	friend class Items;
public:
	std::string name;
	std::string roomDiscription;
	std::string currentRoom;
	int roomNumber;
	int RoomExit[2];
	Room(Room* room, int);
	Room();
	~Room();
	void moveRoom(Room* room,int,int);
	void setRoom(Room* room);
	void setCurrentRoomName(Room* room, int);
	void setCurrentRoomNumber(Room* room, int);
	void setCurrentRoom(Room* room, int);
	std::string getCurrentRoomName();
	int getCurrentRoomNumber();
	
};

