#include "Player.h"
#include "Room.h"
#include "Input.h"
#include <iostream>
#include <algorithm>


bool validateInput(std::string userInput) {
	std::string validInputs[5] = { "GO", "USE", "THROW", "DROP", "ROOM",};
	for (int i = 0; i < sizeof(validInputs); i++) {
		if (validInputs[i] == userInput) {
			return true;
		}
	}
	return false;
}

int main(int argc, char* argv[])
{
	std::cout << "Please Enter your name.\n";
	std::string name;
	std::cin >> name;
	Player* MainPlayer = new Player(name);

	std::cout << "Hello there " + MainPlayer->getName(); +". \n";
	std::cout << "\n";

	std::string userInput;

	// Room constructor

	/*
	Was having alot of issuse linking rooms together using a seperate class file.
	But was able to get it working properly

	*/
	struct Room
	{
		std::string RoomName;
		Room* North;
		Room* South;
		Room* East;
		Room* West;
		//add an item array
		//add a lock object or something

	};
	// points to current room the player is in. 
	Room* CURRENTROOM = NULL;

	// make tests rooms
	Room* one = new Room();
	Room* two = new Room();
	Room* three = new Room();
	Room* four = new Room();
	Room* five = new Room();
	Room* six = new Room();
	Room* seven = new Room();
	Room* eight = new Room();
	Room* nine = new Room();

	/*
		N
		|
	W---|---E
		|
		S
	Test Room Layout
	| 1 | 2 | 3 |
	-------------
	| 4 | 5 | 6 |
	-------------
	| 7 | 8 | 9 |

	*directions in rooms with no conecting room should return as null ex. 'one.North' send back a null value*

	*/

	//links rooms together and sets room names	
	one->RoomName = "Room 1";
	one->East = two;
	one->South = four;
	// North And West both return null values if called

	two->RoomName = "Room 2";
	two->West = one;
	two->East = three;
	two->South = five;

	three->RoomName = "Room 3";
	three->East = two;
	three->South = six;

	four->RoomName = "Room 4";
	four->East = five;
	four->North = one;
	four->South = seven;

	five->RoomName = "Room 5"; // sets room name
	five->East = six; // sets room to the east
	five->West = four; // sets room to the west
	five->North = two; // sets room to the north
	five->South = eight; // sets room to the south

	six->RoomName = "Room 6";
	six->West = five;
	six->North = three;
	six->South = nine;

	seven->RoomName = "Room 7";
	seven->East = eight;
	seven->North = four;

	eight->RoomName = "Room 8";
	eight->East = nine;
	eight->West = seven;
	eight->North = five;

	nine->RoomName = "Room 9";
	nine->West = eight;
	nine->North = six;

	/*
	section to set the items in the item array for each room
	*/



	//sets current room to the first room, room 1
	CURRENTROOM = one;

	//Checks if the pointer works as intended
	std::cout << "The room is: " << CURRENTROOM->RoomName << "\n";
	CURRENTROOM = CURRENTROOM->East;
	std::cout << "The room is: " << CURRENTROOM->RoomName << "\n";
	CURRENTROOM = CURRENTROOM->West;

	std::cout << "The room is: " << CURRENTROOM->RoomName << "\n";
	CURRENTROOM = CURRENTROOM->South;
	std::cout << "The room is: " << CURRENTROOM->RoomName << "\n";
	CURRENTROOM = CURRENTROOM->East;
	std::cout << "The room is: " << CURRENTROOM->RoomName << "\n";
	CURRENTROOM = CURRENTROOM->North;
	std::cout << "The room is: " << CURRENTROOM->RoomName << "\n";

	//reset pointer after above test.
	CURRENTROOM = one;

	userInput.clear();
	while (userInput != "QUIT") {
		userInput.clear();
		std::cout << "What do you want to do?\n";
		std::cin >> userInput;
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
		if (!validateInput(userInput)) {
			std::cout << "Please enter a valid command...\n";
		}
		else if (userInput == "QUIT") {
			std::cout << "Quiting \n";		
		}
		else {
			if (userInput == "GO") {
				std::cout << "Where would you like to go? \n";
				userInput.clear();
				std::cin >> userInput;
				std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
				if (userInput == "EAST") {
					if (CURRENTROOM->East != NULL) {
						CURRENTROOM = CURRENTROOM->East;
						std::cout << "You are now in the next room. \nIf you want to knoww the room name type room.\n";
					}
					else {
						std::cout << "You cant go that way.\n";
					}
				}
				else if (userInput == "WEST") {
					if (CURRENTROOM->West != NULL) {
						CURRENTROOM = CURRENTROOM->West;
						std::cout << "You are now in the next room. \nIf you want to knoww the room name type room.\n";
					}
					else {
						std::cout << "You cant go that way.\n";
					}
				}
				else if (userInput == "NORTH") {
					if (CURRENTROOM->North != NULL) {
						CURRENTROOM = CURRENTROOM->North;
						std::cout << "You are now in the next room. \nIf you want to knoww the room name type room.\n";
					}
					else {
						std::cout << "You cant go that way.\n";
					}
				}
				else if (userInput == "SOUTH") {
					if (CURRENTROOM->South != NULL) {
						CURRENTROOM = CURRENTROOM->South;
						std::cout << "You are now in the next room. \nIf you want to knoww the room name type room.\n";
					}
					else {
						std::cout << "You cant go that way.\n";
					}
				}
				else {
					std::cout << "Not a valid input.\n";
				}
			}

			else if (userInput == "USE") {
				std::cout << "What would you like to use?\n";
			}
			else if (userInput == "THROW") {
				std::cout << "What would you like to throw?\n";
			}
			else if (userInput == "DROP") {
				std::cout << "What would you like to drop?\n";
			}
			else if (userInput == "ROOM") {
				std::cout << "The room is: " << CURRENTROOM->RoomName << "\n";
			}
			else {
				std::cout << "Not a valid input.\n";
			}
			userInput.clear();
		}

	}
	std::cout << "Goodbye.";
	std::cin.get();
	std::cin.get();
	return 0;
}
