#include "Player.h"
#include "Room.h"
#include "Input.h"
#include <iostream>
#include <algorithm>

bool validateInput(std::string userInput) {
	std::string validInputs[5] = { "GO", "USE", "THROW", "DROP" };
	for (int i = 0; i < sizeof(validInputs); i++) {
		if (validInputs[i].find(userInput, 0) != std::string::npos) {			
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	//Created my own Branch: AlexisChavez
	std::cout << "Please Enter your name.\n";
	std::string name;
    std::cin >> name;
	Player* MainPlayer = new Player(name);

	std::cout << "Hello there " + MainPlayer->getName(); + ". \n";
	std::cout << "\n";

	std::string userInput;
	

	// Room constructor
	struct Room
	{
		std::string RoomName;
		std::string validDirections[4] = { "NORTH", "EAST" };
		Room *NORTH;
		Room *South;
		Room *East;
		Room *West;
		
	};
	// points to current room
	Room* CURRENTROOM = NULL;
	
	// make tests rooms
	Room* one = NULL;
	Room* two = NULL;
	Room* three = NULL;
	
	one = new Room();
	two = new Room();
	three = new Room();


	//links rooms together and sets names
	one->East = two;
	one->RoomName = "Room 1";
	two->West = one;
	two->RoomName = "Room 2";
	two->South = three;
	three->NORTH = two;
	three->RoomName = "Room 3";

	//sets current room to the first room 1
	CURRENTROOM = one;

	while (userInput != "QUIT") {		
		std::cout << "What would you like to do?\n";	
		std::cin >> userInput;
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
		if (!validateInput(userInput)) {
			std::cout << "Please enter a valid command...\n";
		}
		else {
			if (userInput == "GO") {
				std::cout << "Where would you like to go? \n";
				//if(checkIfPossibleMove)
				//go to room
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
			else
			{
				std::cout << "Not a valid input.\n";
			}
		}
		userInput.clear();
	}
	
	std::cout << "Goodbye.";
	std::cin.get();
	std::cin.get();
	return 0;
}


