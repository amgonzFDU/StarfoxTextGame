#include "Room.h"
#include <iostream>

enum RoomNames {player,cell,cell2,cell3,cell4,cell5,cell6,cell7,cell8,cell9};
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
	room[cell].RoomExit[south] = cell4;
	room[cell].RoomExit[east] = cell2;
	room[cell].RoomExit[west] = NONE;

	room[cell2].name = cell2;
	room[cell2].RoomExit[north] = NONE;
	room[cell2].RoomExit[south] = cell5;
	room[cell2].RoomExit[east] = cell3;
	room[cell2].RoomExit[west] = cell;

	room[cell3].name = cell3;
	room[cell3].RoomExit[north] = NONE;
	room[cell3].RoomExit[south] = cell6;
	room[cell3].RoomExit[east] = NONE;
	room[cell3].RoomExit[west] = cell2;
	
	room[cell4].name = cell4;
	room[cell4].RoomExit[north] = cell;
	room[cell4].RoomExit[south] = cell7;
	room[cell4].RoomExit[east] = cell5;
	room[cell4].RoomExit[west] = NONE;

	room[cell5].name = cell5;
	room[cell5].RoomExit[north] = cell2;
	room[cell5].RoomExit[south] = cell8;
	room[cell5].RoomExit[east] = cell6;
	room[cell5].RoomExit[west] = cell4;

	room[cell6].name = cell6;
	room[cell6].RoomExit[north] = cell3;
	room[cell6].RoomExit[south] = cell9;
	room[cell6].RoomExit[east] = NONE;
	room[cell6].RoomExit[west] = cell5;

	room[cell7].name = cell7;
	room[cell7].RoomExit[north] = cell4;
	room[cell7].RoomExit[south] = NONE;
	room[cell7].RoomExit[east] = cell8;
	room[cell7].RoomExit[west] = NONE;
	
	room[cell8].name = cell8;
	room[cell8].RoomExit[north] = cell5;
	room[cell8].RoomExit[south] = NONE;
	room[cell8].RoomExit[east] = cell9;
	room[cell8].RoomExit[west] = cell7;

	room[cell9].name = cell9;
	room[cell9].RoomExit[north] = cell6;
	room[cell9].RoomExit[south] = NONE;
	room[cell9].RoomExit[east] = NONE;
	room[cell9].RoomExit[west] = cell8;
	
}
void Room::moveRoom(Room* room, int roomName,int direction){
	//the room number you want to move to 
	int roomnum;
	roomnum = room[roomName].RoomExit[direction];
	//checks to see if there is a room where the player want to go
	if (roomnum == -1) {
		std::cout << "There is no room that way try again \n";
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
