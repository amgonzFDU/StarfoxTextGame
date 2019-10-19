#include "Room.h"

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
	room[cell].name.assign("Cell");
	room[cell].RoomExit[north] = NONE;
	room[cell].RoomExit[south] = NONE;
	room[cell].RoomExit[east] = NONE;
	room[cell].RoomExit[west] = cell2;

	room[cell2].name.assign("Cell 2");
	room[cell2].RoomExit[north] = NONE;
	room[cell2].RoomExit[south] = NONE;
	room[cell2].RoomExit[east] = cell;
	room[cell2].RoomExit[west] = NONE;
	
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
std::string Room::getCurrentRoom() {
	return this->currentRoom;
}
