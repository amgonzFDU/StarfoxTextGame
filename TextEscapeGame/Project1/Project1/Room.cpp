#include "Room.h"
#include "Items.h"
#include <iostream>
#include <string>
#include <fstream>
//#include "Main.cpp"

enum RoomNames {
	player, Dungeon, lockedcell, cellblocka765, cellblock6mk5, cellblock88f7,CellBlockCrossRoads,cellblock25k6, BrokenStairway, BoneFilledDungeon
	, BallRoom, Armory ,SouthCourtYard, NorthCourtYard, Bedroom, AlchemistsLab, WineCellar, StorageRoom, DirtPassageway, DirtTunnel
	, UnderGroundChamber, YouHaveEscaped,numberofrooms
};
enum directions {north,south,east,west};
const int NONE = -1;
//Added MAYBE to give players a hint that it's a potential exit
const int MAYBE = -2;
char a = 1;
int rockThrowCount = 0;


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
	room[Dungeon].roomDiscription.assign("You are in a cold, damp cell with stone walls. The room is dark with the exception of dim moonlight bleeding through a small window to the south opposite a heavy Iron door. The room seems barren except for a few items.\n");
	room[Dungeon].RoomExit[north] = NONE;
	room[Dungeon].RoomExit[south] = NONE;
	room[Dungeon].RoomExit[east] = NONE;
	//room[Dungeon].RoomExit[west] = lockedcell;
	room[Dungeon].RoomExit[west] = MAYBE;

	room[lockedcell].name.assign("Locked Cell");
	room[lockedcell].roomNumber = lockedcell;
	room[lockedcell].roomDiscription.assign("You are in a small, stone walled cell. Through the dim moonlight you can see tally marks etched into the mossy stone wall, seemingly 88 in total. The north side is barred with a heavy iron door. There is a withered skeleton hanging from the ceiling and a hole in the wall to the east.\n");
	//Commenting out as initially this path is unavailable until the lock is unlocked.
	//room[lockedcell].RoomExit[north] = cellblocka765;
	room[lockedcell].RoomExit[north] = MAYBE;
	room[lockedcell].RoomExit[south] = NONE;
	room[lockedcell].RoomExit[east] = Dungeon;
	room[lockedcell].RoomExit[west] = NONE;

	room[cellblocka765].name.assign("Cell Block A765");
	room[cellblocka765].roomNumber = cellblocka765;
	room[cellblocka765].roomDiscription.assign("You are in a Long, narrow hallway lined with locked cells, though only on the south side. It is awfully dark, but in the faint light you can make out the silhouettes of bones and skulls scattered along the ground. There is a dim light at the far end of the eastern passage. To the west, the hallway is pitch black and an unsettling groan can be heard, muffled by the stiff atmosphere.\n");
	room[cellblocka765].RoomExit[north] = NONE;
	room[cellblocka765].RoomExit[south] = lockedcell;
	room[cellblocka765].RoomExit[east] = cellblock25k6;
	room[cellblocka765].RoomExit[west] = cellblock6mk5;
	
	room[cellblock6mk5].name.assign("Cell Block 6mk5");
	room[cellblock6mk5].roomNumber = cellblock6mk5;
	room[cellblock6mk5].roomDiscription.assign("You are in a Long, narrow hallway lined with locked cells, though only on the south side. It is awfully dark, but in the faint light you can make out the silhouettes of bones and skulls scattered along the ground. There is a dim light at the far end of the eastern passage. To the west, the hallway is pitch black and an unsettling groan can be heard, muffled by the stiff atmosphere.\n");
	room[cellblock6mk5].RoomExit[north] = NONE;
	room[cellblock6mk5].RoomExit[south] = NONE;
	room[cellblock6mk5].RoomExit[east] = cellblocka765;
	room[cellblock6mk5].RoomExit[west] = cellblock88f7;

	room[cellblock88f7].name.assign("Cell Block 88f7");
	room[cellblock88f7].roomNumber = cellblock88f7;
	room[cellblock88f7].roomDiscription.assign("You are in a Long, narrow hallway lined with locked cells, though only on the south side. It is awfully dark, but in the faint light you can make out the silhouettes of bones and skulls scattered along the ground. There is a dim light at the far end of the eastern passage. To the west, the hallway is pitch black and an unsettling groan can be heard, muffled by the stiff atmosphere.\n");
	room[cellblock88f7].RoomExit[north] = NONE;
	room[cellblock88f7].RoomExit[south] = NONE;
	room[cellblock88f7].RoomExit[east] = cellblock6mk5;
	room[cellblock88f7].RoomExit[west] = CellBlockCrossRoads;

	room[CellBlockCrossRoads].name.assign("Cell Block Cross Roads");
	room[CellBlockCrossRoads].roomNumber = CellBlockCrossRoads;
	room[CellBlockCrossRoads].roomDiscription.assign("You are at a T-intersection of two hallways. The southern hall is blocked by fallen debris. Within the pile of dirt and stone, long pieces of wood burn steadily. To the north, a steep stairway leads upward. The westward passage heads back into the long hall of cells.\n");
	room[CellBlockCrossRoads].RoomExit[north] = BallRoom;
	room[CellBlockCrossRoads].RoomExit[south] = NONE;
	room[CellBlockCrossRoads].RoomExit[east] = cellblock88f7;
	room[CellBlockCrossRoads].RoomExit[west] = NONE;

	room[cellblock25k6].name.assign("Cell Block 25k6");
	room[cellblock25k6].roomNumber = cellblock25k6;
	room[cellblock25k6].roomDiscription.assign("You are in a Long, narrow hallway lined with locked cells, though only on the south side. It is awfully dark, but in the faint light you can make out the silhouettes of bones and skulls scattered along the ground. There is a dim light at the far end of the eastern passage. To the west, the hallway is pitch black and an unsettling groan can be heard, muffled by the stiff atmosphere.");
	room[cellblock25k6].RoomExit[north] = NONE;
	room[cellblock25k6].RoomExit[south] = NONE;
	room[cellblock25k6].RoomExit[east] = BrokenStairway;
	room[cellblock25k6].RoomExit[west] = cellblocka765;
	
	room[BrokenStairway].name.assign("Broken Stairway");
	room[BrokenStairway].roomNumber = BrokenStairway;
	room[BrokenStairway].roomDiscription.assign("It is too dark to see further, proceeding would be unwise...\n");
	//room[BrokenStairway].RoomExit[north] = WineCellar;
	room[BrokenStairway].RoomExit[north] = MAYBE;
	room[BrokenStairway].RoomExit[south] = NONE;
	room[BrokenStairway].RoomExit[east] = BoneFilledDungeon;
	room[BrokenStairway].RoomExit[west] = cellblock25k6;

	room[BoneFilledDungeon].name.assign("Bone Filled Dungeon");
	room[BoneFilledDungeon].roomNumber = BoneFilledDungeon; 
	room[BoneFilledDungeon].roomDiscription.assign("You are in a filthy dungeon lit by burning torches along the moldy stone walls. The ground is littered with bones and a thin layer of reddish brown liquid. An enormous grotesque creature lurks towards the far wall of the room holding modest wooden chest. A stairway leads upwards behind you to the west.");
	room[BoneFilledDungeon].RoomExit[north] = NONE;
	room[BoneFilledDungeon].RoomExit[south] = NONE;
	room[BoneFilledDungeon].RoomExit[east] = NONE;
	room[BoneFilledDungeon].RoomExit[west] = BrokenStairway;
	
	room[BallRoom].name.assign("Ballroom");
	room[BallRoom].roomNumber = BallRoom;
	room[BallRoom].roomDiscription.assign("You are in a Large open room lit by a chandelier hung from the tall ceiling. The room is circular with a marble floor and stone walls. 6 thin marble pillars surround the room and stretch to the ceiling. To the east, a tall heavy Iron door is open just a crack. To the north are wooden double doors leading outside. A stairway heads downward to the south.");
	room[BallRoom].RoomExit[north] = SouthCourtYard;
	room[BallRoom].RoomExit[south] = CellBlockCrossRoads;
	room[BallRoom].RoomExit[east] = Armory;
	room[BallRoom].RoomExit[west] = NONE;

	room[Armory].name.assign("Armory");
	room[Armory].roomNumber = Armory;
	room[Armory].roomDiscription.assign("You are in a Spacious, dim room, with wooden barrels, shelves, and stands. Clearly appears to be an armory, although seems rather empty with the exception of broken weapon and armor fragments scattered about the room. Maybe something is still intact in the room.");
	room[Armory].RoomExit[north] = NONE;
	room[Armory].RoomExit[south] = NONE;
	room[Armory].RoomExit[east] = NONE;
	room[Armory].RoomExit[west] = BallRoom;

	room[SouthCourtYard].name.assign("South Court Yard");
	room[SouthCourtYard].roomNumber = SouthCourtYard;
	room[SouthCourtYard].roomDiscription.assign("You are in a large outdoor courtyard enclosed by tall Stone walls. Wilted flower beds and rugged hedges populate the nearby terrain. A short, winding cobblestone path leads to a bridge in the middle of the courtyard spanning a dark abyss. A knight in black armor stands motionless by the bridge to the north. To the south are open double doors heading back into the Ballroom.");
	room[SouthCourtYard].RoomExit[north] = NorthCourtYard;
	room[SouthCourtYard].RoomExit[south] = BallRoom;
	room[SouthCourtYard].RoomExit[east] = NONE;
	room[SouthCourtYard].RoomExit[west] = NONE;

	room[NorthCourtYard].name.assign("North Court Yard");
	room[NorthCourtYard].roomDiscription.assign("You are in the north side of the outdoor courtyard, to the west 3 tall fir trees cast long shadows in the moonlight over the courtyard. Ahead to the north is a large wooden door. To the east, curtains blow about in the wind from a balcony that has a hook extended from the bottom.");
	room[NorthCourtYard].roomNumber = NorthCourtYard;
	room[NorthCourtYard].RoomExit[north] = AlchemistsLab;
	room[NorthCourtYard].RoomExit[south] = SouthCourtYard;
	room[NorthCourtYard].RoomExit[east] = Bedroom;
	room[NorthCourtYard].RoomExit[west] = NONE;

	room[Bedroom].name.assign("Bedroom");
	room[Bedroom].roomNumber = Bedroom;
	room[Bedroom].roomDiscription.assign("You are in a spacious bedroom, furnished quite lavishly. On the dresser there are various objects and trinkets There is a door at the opposite end of the room but upon further investigation, you can figure that door is barricaded shut from the other side.");
	room[Bedroom].RoomExit[north] = NONE;
	room[Bedroom].RoomExit[south] = NONE;
	room[Bedroom].RoomExit[east] = NONE;
	room[Bedroom].RoomExit[west] = SouthCourtYard;

	room[AlchemistsLab].name.assign("AlchemistsLab");
	room[AlchemistsLab].roomNumber = AlchemistsLab;
	room[AlchemistsLab].roomDiscription.assign("You are in a cold, misty room with many barrels, a large cauldron, and a sort of brewing configuration supporting a multitude of  flasks of strange, unknown substances. Much of the ground is covered in a thin layer of rubble and broken glass. Some parts of the wall seem to be scorched and cracked. 14 hollowed bones hang from above rattling like wind chimes.");
	room[AlchemistsLab].RoomExit[north] = NONE;
	room[AlchemistsLab].RoomExit[south] = NorthCourtYard;
	room[AlchemistsLab].RoomExit[east] = NONE;
	room[AlchemistsLab].RoomExit[west] = NONE;

	room[WineCellar].name.assign("Wine Cellar");
	room[WineCellar].roomNumber = WineCellar;
	room[WineCellar].roomDiscription.assign("You are in a dusty and dark wine cellar. The room is thick with tough webs, especially at the mouth of a door to the east, where the webs forge a resilient obstruction. Next to one of the wine barrels, the remains of a skeleton sitting up against the wall, holding an empty porcelain mug.");
	room[WineCellar].RoomExit[north] = NONE;
	room[WineCellar].RoomExit[south] = BrokenStairway;
	room[WineCellar].RoomExit[east] = NONE;
	room[WineCellar].RoomExit[west] = NONE;

	room[StorageRoom].name.assign("Storage Room");
	room[StorageRoom].roomNumber = StorageRoom;
	room[StorageRoom].roomDiscription.assign("You are in a  small, dark room adjacent to the wine cellar. There are many boxes and barrels stacked about the room. One box seems to be blocking a hole in the wall, however it is too heavy to move with your bare hands.");
	room[StorageRoom].RoomExit[north] = NONE;
	room[StorageRoom].RoomExit[south] = NONE;
	room[StorageRoom].RoomExit[east] = NONE;
	room[StorageRoom].RoomExit[west] = WineCellar;

	room[DirtPassageway].name.assign("Dirt Passageway");
	room[DirtPassageway].roomNumber = DirtPassageway;
	room[DirtPassageway].RoomExit[north] = NONE;
	room[DirtPassageway].roomDiscription.assign("You are in a narrow dirt passage, too short to stand in. There is a faint light ahead to the east.");
	room[DirtPassageway].RoomExit[south] = NONE;
	room[DirtPassageway].RoomExit[east] = DirtTunnel;
	room[DirtPassageway].RoomExit[west] = StorageRoom;

	room[DirtTunnel].name.assign("Dirt Tunnel");
	room[DirtTunnel].roomNumber = DirtTunnel;
	room[DirtTunnel].roomDiscription.assign("You are in a narrow dirt tunnel, too short to stand or crouch through. There is a faint light ahead to the east.");
	room[DirtTunnel].RoomExit[north] = NONE;
	room[DirtTunnel].RoomExit[south] = NONE;
	room[DirtTunnel].RoomExit[east] = UnderGroundChamber;
	room[DirtTunnel].RoomExit[west] = DirtPassageway;

	room[UnderGroundChamber].name.assign("Under Ground Chamber");
	room[UnderGroundChamber].roomNumber = UnderGroundChamber;
	room[UnderGroundChamber].roomDiscription.assign("You are in a small empty dirt room with a ladder to the south. There is a faint light peeking through a grate at the top of the ladder to the south. On the grate is a complex iron lock with four dials. Around the dials, the numbers one through one-hundred are etched into the iron. The grate is locked, but could possibly be opened with the right combination.");
	room[UnderGroundChamber].RoomExit[north] = NONE;
	room[UnderGroundChamber].RoomExit[south] = NONE;
	room[UnderGroundChamber].RoomExit[east] = NONE;
	room[UnderGroundChamber].RoomExit[west] = DirtTunnel;

	room[YouHaveEscaped].name.assign("You Have Escaped");
	room[YouHaveEscaped].roomNumber = YouHaveEscaped;
	room[YouHaveEscaped].roomDiscription.assign("You are beside a long dirt road running east and west. It is daytime now but there doesn’t seem to be anyone else nearby. You decide to follow the road away from the castle into the forest. You seem to have escaped for now...");
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

		std::cout << "The room is " << getCurrentRoomName() << std::endl;
		std::cout << getRoomDiscription(room, getCurrentRoomNumber())<<std::endl;
		Items item;
		item.outputRoomItems(items, getCurrentRoomNumber());
		return;
	}		
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
		std::cout << "There is no room that way try a different direction \n";
		return false;
	}
	else if (roomnum == -2) {
		std::cout << "Seems like a potential exit. Might have to do something first. \n";
		return false;
	}
	else {
		return true;
	}
}

/*Gets called when proper item is used to solve puzzle to go to next room for room : Locked Cell*/
bool Room::SolvePuzzle(Room* room, Items* item, std::string currentRoomName, std::string itemName) {	
	if (itemName == "SCROLL") {
		std::cout << "In the cell you wake, filled with dismay. Navigate thy labyrinth, finding thou way. Observations thou make are a blessing to thee. The numbers beware as they hold the key.";
	}
	if (currentRoomName == "Dungeon") {
		if (itemName == "ROCK") {
			rockThrowCount++;
			if (rockThrowCount == 1) {
				std::cout << "You threw the rock at the feeble part of the wall and you can see more of the next room... \n";
			}
			else if (rockThrowCount == 2) {
				std::cout << "You threw the rock at the hole you made in the wall so now you can almost fit through the hole... \n";
			}
			else if (rockThrowCount == 3) {
				std::cout << "The rock breaks open a hole in the wall big enough to crawl through.\n";
				room[Dungeon].RoomExit[west] = lockedcell;
				room[Dungeon].roomDiscription.assign("You are in a cold, damp cell with stone walls. The room is dark with the exception of dim moonlight bleeding through a small window to the south opposite a heavy Iron door. The room seems barren except for a few items. The wall to the west has a hole big enough to crawl through.\n");
				
			}
		}
		else {
			std::cout << "Cant use that item here. \n";
		}
	}
	else if(currentRoomName == "Locked Cell") {
		if (itemName == "KEY") {
			std::cout << "The door unlocks.\n";
			room[lockedcell].RoomExit[north] = cellblocka765;
			room[lockedcell].roomDiscription.assign("You are in a small, stone walled cell. Through the dim moonlight you can see tally marks etched into the mossy stone wall, seemingly 88 in total. The north side has an open heavy iron door. There is a withered skeleton hanging from the ceiling and a hole in the wall to the east.\n");

			return true;
		}	
		else {
			std::cout << "Cant use that item here. \n";
		}
	}
	else if (currentRoomName == "Cell Block Cross Roads") {
		if (itemName == "CANDLE") {
			std::cout << "You lit the candle, this will help in dark paths.";
			room[cellblock88f7].roomDiscription.assign("You are in a Long, narrow hallway lined with locked cells, though only on the south side. Bones and skulls are scattered along the ground. There is a dim light at the far end of the eastern passage. To the west, the hallway seems to go down.\n");
			room[cellblock6mk5].roomDiscription.assign("You are in a Long, narrow hallway lined with locked cells, though only on the south side. Bones and skulls are scattered along the ground. There is a dim light at the far end of the eastern passage. To the west, the hallway seems to go down.\n");
			room[cellblocka765].roomDiscription.assign("You are in a Long, narrow hallway lined with locked cells, though only on the south side. Bones and skulls are scattered along the ground. There is a dim light at the far end of the eastern passage. To the west, the hallway seems to go down.\n");
			room[cellblock25k6].roomDiscription.assign("You are in a Long, narrow hallway lined with locked cells, though only on the south side. Bones and skulls are scattered along the ground. There is a dim light at the far end of the eastern passage. To the west, the hallway seems to go down.\n");
			room[BrokenStairway].roomDiscription.assign("There is a partially broken staircase leading downward. There are several deep holes throughout the staircase. The bottoms are too far to see with only the candle light, nonetheless it is sufficient enough to navigate the stairs safely. The eastward passage heads back into the long hall of cells. Something is strangely off about the wall to the north.\n");
		}
		else {
			std::cout << "Cant use that item here. \n";
		}
	}
	else if (currentRoomName == "Broken Stairway") {
		if (itemName == "FLASK") {
			std::cout << "You threw the flask. The stone wall suddenly crumbles, evaporating into a thick mist. It fades quickly revealing a passage where the wall once was.\n";
			room[BrokenStairway].RoomExit[north] = WineCellar;
			room[BrokenStairway].roomDiscription.assign("There is a partially broken staircase leading downward. There are several deep holes throughout the staircase. The bottoms are too far to see with only the candle light, nonetheless it is sufficient enough to navigate the stairs safely. The eastward passage heads back into the long hall of cells. There is a doorway in the northern wall.\n");
		}
	}
	else if (currentRoomName == "Bone Filled Dungeon") {
		if (itemName == "SPEAR") {
			std::cout << "The creature dies dropping the chest breaking it and revealing a shiny golden ring.\n";
			room[BoneFilledDungeon].roomDiscription.assign("You are in a filthy dungeon lit by burning torches along the moldy stone walls. The ground is littered with bones and a thin layer of reddish brown liquid. An enormous grotesque creature lays dead on the ground. A stairway leads upwards behind you to the west.\n`");
			//need to have the items not show in this room until the spear is used
			Items items;
			items.ChangeRoomLocation(item);
		}
	}
	else if (currentRoomName == "North Court Yard") {
		if (itemName == "ROPE") {
			std::cout << "You are able to lasso the hook with the rope and create a way up to the balcony. ";
			room[NorthCourtYard].roomDiscription.assign("You are in the north side of the outdoor courtyard, to the west 3 tall fir trees cast long shadows in the moonlight over the courtyard. Ahead to the north is a large wooden door. To the east, curtains blow about in the wind from a balcony that has a rope extending to the ground.\n");
		}
	}
	else if (currentRoomName == "Wine Cellar") {
		if (itemName == "KNIFE") {
			std::cout << "You cut through the webs clearing a path to the door to the east.\n";
			room[WineCellar].RoomExit[east] = StorageRoom;
			room[WineCellar].roomDiscription.assign("You are in a dusty and dark wine cellar. The room is thick with tough webs, but the door to the east is clear. Next to one of the wine barrels, the remains of a skeleton sitting up against the wall, holding an empty porcelain mug.\n");
		}
	}
	else if (currentRoomName == "Storage Room") {
		if (itemName == "BAR") {
			std::cout << "The you moved the box revieling a hole in the wall to the east.\n";
			room[StorageRoom].RoomExit[east] = DirtPassageway;
			room[StorageRoom].roomDiscription.assign("You are in a  small, dark room adjacent to the wine cellar. There are many boxes and barrels stacked about the room. Beside one box is a hole in the eastern wall just big enough to squeeze through.\n");
		}
	}
	else if (currentRoomName == "Under Ground Chamber") {
		if (itemName == "886314") {
			std::cout << "The lock releases and you are able to push up the grate.\n";
			room[UnderGroundChamber].RoomExit[south] = YouHaveEscaped;
			room[UnderGroundChamber].roomDiscription.assign("You are in a small empty dirt room with a ladder to the south. There is a faint light peeking through the open grate at the top of the ladder to the south.\n");
		}
	}
	
	else {
		if (itemName == "") {
			std::cout << "Specify an item to use. \n";
		}
		else {
			std::cout << "Cant use that item here. \n";
		}
		
	}
}
