#include "Room.h"
#include <iostream>

enum RoomNames {
	player, cell, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9
	, cell10, cell11, cell12, cell13, cell14, cell15, cell16, cell17, cell18
	, cell19, cell20, cell21,
};
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
	room[cell].name.assign("Cell 1");
	room[cell].roomNumber = cell;
	room[cell].roomDiscription.assign("Cold and Damp");
	room[cell].RoomExit[north] = NONE;
	room[cell].RoomExit[south] = NONE;
	room[cell].RoomExit[east] = NONE;
	room[cell].RoomExit[west] = cell2;

	room[cell2].name.assign("cell 2");
	room[cell2].roomNumber = cell2;
	room[cell2].roomDiscription.assign("A cell similar to the starting cell");
	room[cell2].RoomExit[north] = cell3;
	room[cell2].RoomExit[south] = NONE;
	room[cell2].RoomExit[east] = cell;
	room[cell2].RoomExit[west] = NONE;

	room[cell3].name.assign("cell 3");
	room[cell3].roomNumber = cell3;
	room[cell3].RoomExit[north] = NONE;
	room[cell3].RoomExit[south] = cell2;
	room[cell3].RoomExit[east] = cell7;
	room[cell3].RoomExit[west] = cell4;
	
	room[cell4].name.assign("cell 4");
	room[cell4].roomNumber = cell4;
	room[cell4].RoomExit[north] = NONE;
	room[cell4].RoomExit[south] = NONE;
	room[cell4].RoomExit[east] = cell3;
	room[cell4].RoomExit[west] = cell5;

	room[cell5].name.assign("cell 5");
	room[cell5].roomNumber = cell5;
	room[cell5].RoomExit[north] = NONE;
	room[cell5].RoomExit[south] = NONE;
	room[cell5].RoomExit[east] = cell4;
	room[cell5].RoomExit[west] = cell6;

	room[cell6].name.assign("cell 6");
	room[cell6].roomNumber = cell6;
	room[cell6].RoomExit[north] = cell10;
	room[cell6].RoomExit[south] = NONE;
	room[cell6].RoomExit[east] = cell5;
	room[cell6].RoomExit[west] = NONE;

	room[cell7].name.assign("cell 7");
	room[cell7].roomNumber = cell7;
	room[cell7].RoomExit[north] = NONE;
	room[cell7].RoomExit[south] = NONE;
	room[cell7].RoomExit[east] = cell8;
	room[cell7].RoomExit[west] = cell3;
	
	room[cell8].name.assign("cell 8");
	room[cell8].roomNumber = cell8;
	room[cell8].RoomExit[north] = cell16;
	room[cell8].RoomExit[south] = NONE;
	room[cell8].RoomExit[east] = cell9;
	room[cell8].RoomExit[west] = cell7;

	room[cell9].name.assign("cell 9");
	room[cell9].roomNumber = cell9;
	room[cell9].RoomExit[north] = NONE;
	room[cell9].RoomExit[south] = NONE;
	room[cell9].RoomExit[east] = NONE;
	room[cell9].RoomExit[west] = cell8;
	
	room[cell10].name.assign("cell 10");
	room[cell10].roomNumber = cell10;
	room[cell10].RoomExit[north] = cell12;
	room[cell10].RoomExit[south] = cell6;
	room[cell10].RoomExit[east] = cell11;
	room[cell10].RoomExit[west] = NONE;

	room[cell11].name.assign("cell 11");
	room[cell11].roomNumber = cell11;
	room[cell11].RoomExit[north] = NONE;
	room[cell11].RoomExit[south] = NONE;
	room[cell11].RoomExit[east] = NONE;
	room[cell11].RoomExit[west] = cell10;

	room[cell12].name.assign("cell 12");
	room[cell12].roomNumber = cell12;
	room[cell12].RoomExit[north] = cell13;
	room[cell12].RoomExit[south] = cell10;
	room[cell12].RoomExit[east] = NONE;
	room[cell12].RoomExit[west] = NONE;

	room[cell13].name.assign("cell 13");
	room[cell13].roomNumber = cell13;
	room[cell13].RoomExit[north] = cell15;
	room[cell13].RoomExit[south] = cell12;
	room[cell13].RoomExit[east] = cell14;
	room[cell13].RoomExit[west] = NONE;

	room[cell14].name.assign("cell 14");
	room[cell14].roomNumber = cell14;
	room[cell14].RoomExit[north] = NONE;
	room[cell14].RoomExit[south] = NONE;
	room[cell14].RoomExit[east] = NONE;
	room[cell14].RoomExit[west] = cell12;

	room[cell15].name.assign("cell 15");
	room[cell15].roomNumber = cell15;
	room[cell15].RoomExit[north] = NONE;
	room[cell15].RoomExit[south] = cell13;
	room[cell15].RoomExit[east] = NONE;
	room[cell15].RoomExit[west] = NONE;

	room[cell16].name.assign("cell 16");
	room[cell16].roomNumber = cell16;
	room[cell16].RoomExit[north] = NONE;
	room[cell16].RoomExit[south] = cell8;
	room[cell16].RoomExit[east] = cell17;
	room[cell16].RoomExit[west] = NONE;

	room[cell17].name.assign("cell 17");
	room[cell17].roomNumber = cell17;
	room[cell17].RoomExit[north] = NONE;
	room[cell17].RoomExit[south] = NONE;
	room[cell17].RoomExit[east] = cell18;
	room[cell17].RoomExit[west] = cell16;

	room[cell18].name.assign("cell 18");
	room[cell18].roomNumber = cell18;
	room[cell18].RoomExit[north] = NONE;
	room[cell18].RoomExit[south] = NONE;
	room[cell18].RoomExit[east] = cell18;
	room[cell18].RoomExit[west] = cell17;

	room[cell19].name.assign("cell 19");
	room[cell19].roomNumber = cell19;
	room[cell19].RoomExit[north] = NONE;
	room[cell19].RoomExit[south] = NONE;
	room[cell19].RoomExit[east] = cell20;
	room[cell19].RoomExit[west] = cell18;

	room[cell20].name.assign("cell 20");
	room[cell20].roomNumber = cell20;
	room[cell20].RoomExit[north] = NONE;
	room[cell20].RoomExit[south] = cell21;
	room[cell20].RoomExit[east] = NONE;
	room[cell20].RoomExit[west] = cell19;

	room[cell21].name.assign("cell 21");
	room[cell21].roomNumber = cell21;
	room[cell21].RoomExit[north] = cell20;
	room[cell21].RoomExit[south] = NONE;
	room[cell21].RoomExit[east] = NONE;
	room[cell21].RoomExit[west] = NONE;


}
void Room::moveRoom(Room* room, int roomName,int direction){
	//the room number you want to move to 
	int roomnum;
	roomnum = room[roomName].RoomExit[direction];
	//checks to see if there is a room where the player want to go
	if (exists(room,roomName,direction)) {
		setCurrentRoom(room, roomnum);

		std::cout << getRoomDiscription(room, getCurrentRoomNumber()) <<std::endl;
		return;
	}	
	std::cout << "There is no room that way try a different direction \n";
}
/*
calls different function to set the roomname and number
*/
void Room::setCurrentRoom(Room* room, int roomNum) {
	setCurrentRoomName(room, roomNum);
	setCurrentRoomNumber(room, roomNum);
}
void Room::setCurrentRoomName(Room * room, int roomNum) {
	
	this->currentRoom = room[roomNum].name;
	
}
void Room::setCurrentRoomNumber(Room* room, int roomNum) {

	this->roomNumber = room[roomNum].roomNumber;

}
/*
gets the room name your currently in
*/
std::string Room::getCurrentRoomName() {
	return this->currentRoom;
}
/*
gets the room number your in*/
int Room::getCurrentRoomNumber() {
	return this->roomNumber;
}
std::string Room::getRoomDiscription(Room*room,int RoomName) {
	return room[RoomName].roomDiscription;
}
/*
checks to see if the room you are trying to go to exists
input: room number and direciton
output: true or false
*/
bool Room::exists(Room*room,int roomName,int direction) {
	int roomnum;
	roomnum = room[roomName].RoomExit[direction];
	if (roomnum == -1) {
		return false;
	}
	else {
		return true;
	}
}
