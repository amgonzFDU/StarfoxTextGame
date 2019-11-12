#include "Room.h"
#include "Items.h"
#include <iostream>
#include <string>
#include <fstream>

enum RoomNames {
	player, Dungeon, lockedcell, cellblock1, cellblock2, cellblock3,CellBlockCrossRoads,CellBlock4, BrokenStairway, BoneFilledDungeon
	, BallRoom, Armory ,SouthCourtYard, NorthCourtYard, Bedroom, AlchemistsLab, WineCellar, StorageRoom, DirtTunnel1, DirtTunnel2
	, UnderGroundChamber, YouHaveEscaped,numberofrooms
};
enum directions {north,south,east,west};
const int NONE = -1;
char a = 1;
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
//tried to make the rooms discriptions easier to change by reading them from a file 
//but the file won't read and i'm too tired at the moment to try and fix it
//std::string Room::setRoomDiscription(int line) {
//	std::ifstream myfile("RoomDescription.txt");
//	
//	std::string discription;
//	
//	
//	for (int i = 0; i <= line; i++) {
//			std::getline(std::cin,discription, a);
//			if (i == line) {
//				return discription;
//			}
//		}
//	
//}
/*
Returns the width of the room.
*/
void Room::setRoom(Room* room) {
	
	//sets the name and exits of the rooms
	//all the names are equal to numbers in the enumerator
	room[Dungeon].name.assign("Dungeon");
	room[Dungeon].roomNumber = Dungeon;
	room[Dungeon].roomDiscription.assign("Cold, damp cell. The room is dark with the exception of dim moonlight bleeding through a small window to the south opposite a heavy Iron door.");
	room[Dungeon].RoomExit[north] = NONE;
	room[Dungeon].RoomExit[south] = NONE;
	room[Dungeon].RoomExit[east] = NONE;
	room[Dungeon].RoomExit[west] = lockedcell;

	room[lockedcell].name.assign("Locked Cell");
	room[lockedcell].roomNumber = lockedcell;
	room[lockedcell].roomDiscription.assign("A cell similar to starting cell. There is a human skeleton hung from the ceiling with a rope.");
	room[lockedcell].RoomExit[north] = cellblock1;
	room[lockedcell].RoomExit[south] = NONE;
	room[lockedcell].RoomExit[east] = Dungeon;
	room[lockedcell].RoomExit[west] = NONE;

	room[cellblock1].name.assign("Cell Block 1");
	room[cellblock1].roomNumber = cellblock1;
	room[cellblock1].roomDiscription.assign("Narrow hallway lined with locked cells. There is a dim light at the far end of the eastern passage. To the west, the hallway seems to go down but is too dark to see.");
	room[cellblock1].RoomExit[north] = NONE;
	room[cellblock1].RoomExit[south] = lockedcell;
	room[cellblock1].RoomExit[east] = CellBlock4;
	room[cellblock1].RoomExit[west] = cellblock2;
	
	room[cellblock2].name.assign("Cell Block 2");
	room[cellblock2].roomNumber = cellblock2;
	room[cellblock2].roomDiscription.assign("Narrow hallway lined with locked cells. There is a dim light at the far end of the eastern passage. To the west, the hallway seems to go down but is too dark to see.");
	room[cellblock2].RoomExit[north] = NONE;
	room[cellblock2].RoomExit[south] = NONE;
	room[cellblock2].RoomExit[east] = cellblock1;
	room[cellblock2].RoomExit[west] = cellblock3;

	room[cellblock3].name.assign("Cell Block 3");
	room[cellblock3].roomNumber = cellblock3;
	room[cellblock3].roomDiscription.assign("Narrow hallway lined with locked cells. There is a dim light at the far end of the eastern passage. To the west, the hallway seems to go down but is too dark to see.");
	room[cellblock3].RoomExit[north] = NONE;
	room[cellblock3].RoomExit[south] = NONE;
	room[cellblock3].RoomExit[east] = cellblock2;
	room[cellblock3].RoomExit[west] = CellBlockCrossRoads;

	room[CellBlockCrossRoads].name.assign("Cell Block Cross Roads");
	room[CellBlockCrossRoads].roomNumber = CellBlockCrossRoads;
	room[CellBlockCrossRoads].roomDiscription.assign("The narrow hallway comes to a T - intersection, with another passage running north and south. The southern hall is blocked by fallen debris that are still burning.");
	room[CellBlockCrossRoads].RoomExit[north] = BallRoom;
	room[CellBlockCrossRoads].RoomExit[south] = NONE;
	room[CellBlockCrossRoads].RoomExit[east] = cellblock3;
	room[CellBlockCrossRoads].RoomExit[west] = NONE;

	room[CellBlock4].name.assign("Cell Block 4");
	room[CellBlock4].roomNumber = CellBlock4;
	room[CellBlock4].roomDiscription.assign("Narrow hallway lined with locked cells. There is a dim light at the far end of the eastern passage. To the west, the hallway seems to go down but is too dark to see.");
	room[CellBlock4].RoomExit[north] = NONE;
	room[CellBlock4].RoomExit[south] = NONE;
	room[CellBlock4].RoomExit[east] = BrokenStairway;
	room[CellBlock4].RoomExit[west] = cellblock1;
	
	room[BrokenStairway].name.assign("Broken Stairway");
	room[BrokenStairway].roomNumber = BrokenStairway;
	room[BrokenStairway].roomDiscription.assign("It is too dark to see further, proceeding would be unwise.");
	room[BrokenStairway].RoomExit[north] = WineCellar;
	room[BrokenStairway].RoomExit[south] = NONE;
	room[BrokenStairway].RoomExit[east] = BoneFilledDungeon;
	room[BrokenStairway].RoomExit[west] = CellBlock4;

	room[BoneFilledDungeon].name.assign("Bone Filled Dungeon");
	room[BoneFilledDungeon].roomNumber = BoneFilledDungeon; 
	room[BoneFilledDungeon].roomDiscription.assign("A dirty dungeon littered with bones, there is an enormous boar guarding a chest.");
	room[BoneFilledDungeon].RoomExit[north] = NONE;
	room[BoneFilledDungeon].RoomExit[south] = NONE;
	room[BoneFilledDungeon].RoomExit[east] = NONE;
	room[BoneFilledDungeon].RoomExit[west] = BrokenStairway;
	
	room[BallRoom].name.assign("Ballroom");
	room[BallRoom].roomNumber = BallRoom;
	room[BallRoom].roomDiscription.assign("Large open room lit by a chandelier hung from the tall ceiling.");
	room[BallRoom].RoomExit[north] = SouthCourtYard;
	room[BallRoom].RoomExit[south] = CellBlockCrossRoads;
	room[BallRoom].RoomExit[east] = Armory;
	room[BallRoom].RoomExit[west] = NONE;

	room[Armory].name.assign("Armory");
	room[Armory].roomNumber = Armory;
	room[Armory].roomDiscription.assign("Room clearly appears to be an armory but seems rather empty with broken weapon and armor fragments scattered about the room. There is one spear that remains intact and an iron bar that was once part of a baton.");
	room[Armory].RoomExit[north] = NONE;
	room[Armory].RoomExit[south] = NONE;
	room[Armory].RoomExit[east] = NONE;
	room[Armory].RoomExit[west] = BallRoom;

	room[SouthCourtYard].name.assign("South Court Yard");
	room[SouthCourtYard].roomNumber = SouthCourtYard;
	room[SouthCourtYard].roomDiscription.assign("Large outdoor courtyard enclosed by tall Stone walls. There is a bridge in the middle of the courtyard that spans a strange abyss.");
	room[SouthCourtYard].RoomExit[north] = NorthCourtYard;
	room[SouthCourtYard].RoomExit[south] = BallRoom;
	room[SouthCourtYard].RoomExit[east] = NONE;
	room[SouthCourtYard].RoomExit[west] = NONE;

	room[NorthCourtYard].name.assign("North Court Yard");
	room[NorthCourtYard].roomDiscription.assign("The north side of the outdoor courtyard, there is a large wooden door ahead and a balcony up to the east with a hook extended from the bottom.");
	room[NorthCourtYard].roomNumber = NorthCourtYard;
	room[NorthCourtYard].RoomExit[north] = AlchemistsLab;
	room[NorthCourtYard].RoomExit[south] = SouthCourtYard;
	room[NorthCourtYard].RoomExit[east] = Bedroom;
	room[NorthCourtYard].RoomExit[west] = NONE;

	room[Bedroom].name.assign("Bedroom");
	room[Bedroom].roomNumber = Bedroom;
	room[Bedroom].roomDiscription.assign("A bedroom, furnished quite lavishly. On the dresser is a mirror and a large key. There is a door at the opposite end of the room (locked).");
	room[Bedroom].RoomExit[north] = NONE;
	room[Bedroom].RoomExit[south] = NONE;
	room[Bedroom].RoomExit[east] = NONE;
	room[Bedroom].RoomExit[west] = SouthCourtYard;

	room[AlchemistsLab].name.assign("cell 15");
	room[AlchemistsLab].roomNumber = AlchemistsLab;
	room[AlchemistsLab].roomDiscription.assign("Cold misty room with many barrels, a large cauldron, and a sort of brewing stand supporting a flask of a strange, unknown substance.");
	room[AlchemistsLab].RoomExit[north] = NONE;
	room[AlchemistsLab].RoomExit[south] = NorthCourtYard;
	room[AlchemistsLab].RoomExit[east] = NONE;
	room[AlchemistsLab].RoomExit[west] = NONE;

	room[WineCellar].name.assign("Wine Cellar");
	room[WineCellar].roomNumber = WineCellar;
	room[WineCellar].roomDiscription.assign("Dusty dark wine cellar. The room is thick with tough webs, especially at the mouth of a door to the east.");
	room[WineCellar].RoomExit[north] = NONE;
	room[WineCellar].RoomExit[south] = BrokenStairway;
	room[WineCellar].RoomExit[east] = StorageRoom;
	room[WineCellar].RoomExit[west] = NONE;

	room[StorageRoom].name.assign("Storage Room");
	room[StorageRoom].roomNumber = StorageRoom;
	room[StorageRoom].roomDiscription.assign(" small dark room adjacent to the wine cellar. There are many boxes and barrels stacked about the room. One box seems to be blocking a hole in the wall, however it is too heavy to move with your bare hands.");
	room[StorageRoom].RoomExit[north] = NONE;
	room[StorageRoom].RoomExit[south] = NONE;
	room[StorageRoom].RoomExit[east] = DirtTunnel1;
	room[StorageRoom].RoomExit[west] = WineCellar;

	room[DirtTunnel1].name.assign("Dirt Tunnel Entrance");
	room[DirtTunnel1].roomNumber = DirtTunnel1;
	room[DirtTunnel1].RoomExit[north] = NONE;
	room[DirtTunnel1].roomDiscription.assign(" Dirt tunnel, too short to stand or crouch through. There is a faint light ahead.");
	room[DirtTunnel1].RoomExit[south] = NONE;
	room[DirtTunnel1].RoomExit[east] = DirtTunnel1;
	room[DirtTunnel1].RoomExit[west] = StorageRoom;

	room[DirtTunnel2].name.assign("Dirt Tunnel Exit");
	room[DirtTunnel2].roomNumber = DirtTunnel2;
	room[DirtTunnel2].roomDiscription.assign(" Dirt tunnel, too short to stand or crouch through. There is a faint light ahead.");
	room[DirtTunnel2].RoomExit[north] = NONE;
	room[DirtTunnel2].RoomExit[south] = NONE;
	room[DirtTunnel2].RoomExit[east] = UnderGroundChamber;
	room[DirtTunnel2].RoomExit[west] = DirtTunnel1;

	room[UnderGroundChamber].name.assign("Under Ground Chamber");
	room[UnderGroundChamber].roomNumber = UnderGroundChamber;
	room[UnderGroundChamber].roomDiscription.assign("small empty dirt room with a ladder to the south. There is a faint light peeking through a grate at the top of the ladder.");
	room[UnderGroundChamber].RoomExit[north] = NONE;
	room[UnderGroundChamber].RoomExit[south] = YouHaveEscaped;
	room[UnderGroundChamber].RoomExit[east] = NONE;
	room[UnderGroundChamber].RoomExit[west] = DirtTunnel2;

	room[YouHaveEscaped].name.assign("You Have Escaped");
	room[YouHaveEscaped].roomNumber = YouHaveEscaped;
	room[YouHaveEscaped].roomDiscription.assign("You Win");
	room[YouHaveEscaped].RoomExit[north] = UnderGroundChamber;
	room[YouHaveEscaped].RoomExit[south] = NONE;
	room[YouHaveEscaped].RoomExit[east] = NONE;
	room[YouHaveEscaped].RoomExit[west] = NONE;


}
void Room::moveRoom(Room* room, int roomName,int direction,Items* items){
	//lets us use functions from item class 
	
	int roomnum;
	roomnum = room[roomName].RoomExit[direction];
	//checks to see if there is a room where the player want to go
	if (exists(room,roomName,direction)) {
		setCurrentRoom(room, roomnum);

		std::cout << getRoomDiscription(room, getCurrentRoomNumber()) <<std::endl;
		Items item;
		item.outputRoomItems(items, getCurrentRoomNumber());
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
