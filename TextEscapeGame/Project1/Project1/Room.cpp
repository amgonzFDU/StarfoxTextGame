#include "Room.h"
#include <iostream>

enum RoomNames {cell,cell2};
enum directions {north,south,east,west};
const int NONE = -1;
/*
Defult Room constructor
*/
Room::Room()
{
}
Room::Room(Room* room, int RoomNum) {
	this->currentRoom = room[RoomNum].name;
}
/*
Defult Room destructor
*/
Room::~Room()
{
}
/*
Returns the width of the room.
*/
void Room::setRoom(Room* room) {
	//sets the name and exits of the rooms
	//all the names are equal to numbers in the enumerator
	room[cell].name = cell;
	room[cell].RoomExit[north] = NONE;
	room[cell].RoomExit[south] = NONE;
	room[cell].RoomExit[east] = cell2;
	room[cell].RoomExit[west] = NONE;

	room[cell2].name = cell2;
	room[cell2].RoomExit[north] = NONE;
	room[cell2].RoomExit[south] = NONE;
	room[cell2].RoomExit[east] = NONE;
	room[cell2].RoomExit[west] = cell;
	
}
void Room::moveRoom(Room* room, int roomName,int direction){
	//the room number you want to move to 
	int roomnum;
	roomnum = room[roomName].RoomExit[direction];
	//checks to see if there is a room where the player want to go
	if (roomnum == -1) {
		std::cout << "There is no room that way try again";
		return;
	}
	setCurrentRoom(room, roomnum);	
}
/*
sets the current room your in
*/
void Room::setCurrentRoom(Room * room, int roomNum) {
	
	this->currentRoom = room[roomNum].name;
	
}
/*
gets the room your currently in
*/
int Room::getCurrentRoom() {
	return this->currentRoom;
}
