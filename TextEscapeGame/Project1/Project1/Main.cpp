#include "Player.h"
#include "Room.h"
#include "Input.h"
#include "Items.h"
#include <iostream>
#include <algorithm>
#include <string>


//the number of items in the game
extern const int ITEMS = 13;
//the number of rooms in the game
extern const int ROOMS = 22;
//number of verbs in the game
extern const int VERBS = 12;
//enumerator to help with item pick up
enum itemsname { rock, key };
//count till it asks if you need help
int helpcount = 0;
//validates the input is an aproved verb
std::string validateInput(std::string userInput) {
	std::string validInputs[VERBS] = { "NORTH","EAST","SOUTH","WEST", "USE", "THROW", "DROP", "ROOM","GET","INVENTORY","HELP","QUIT", };
	//this keeps track of how many commands we print
	int count = 0;
	for (int i = 0; i < VERBS; i++) {
		
		if (validInputs[i] == userInput) {

			return validInputs[i];
		}
	}
	for(int i = 0 ; i<VERBS;i++){
		if (userInput.find(validInputs[i]) != std::string::npos) {
			std::cout << "The correct input is " << validInputs[i] <<std::endl;
			count++;
			
		}
	}
	if (count > 1)
	{
		std::cout << "Input's are one word at a time not multiple\n";
	}

	return "INVALID";
}
std::string USERINPUT() {
	std::string userInput;
	std::getline(std::cin, userInput);
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

	//these two remove white spaces and tabs from user input
	
	userInput.erase(remove(userInput.begin(), userInput.end(), ' '), userInput.end());
	userInput.erase(remove(userInput.begin(), userInput.end(), '	'), userInput.end());

	if (std::cin.eof()) {
		std::cin.clear();
		return "You did not input a correct action.\n";
	}
	return userInput;
}
int main(int argc, char *argv[])
{
	
		//Inializes an array that will hold the items with their properties
		Items item[ITEMS];
		//sets the name of the item
		item->setItemLocation(item);

		//Inializes an array that will hold the rooms with proprties
		Room room[ROOMS];
		//sets the properties of the items
		room->setRoom(room);




		std::cout << "Please Enter your name.\n";
		std::string name;
		name = USERINPUT();
		while (name  == "You did not input a correct action.\n") {
			std::cout << "You are not inputing a valid charactor\n";
			name = USERINPUT();
		}

		Player* MainPlayer = new Player(name);

		std::cout << "Hello there " + MainPlayer->getName(); +"";
		std::cout << "\n";
	std::cout << "All you need to do is try to get out, can you make it to the exit? \n";
	std::cout << "Type: 'North', 'South', 'East', or 'West' to move around the rooms\n";
	std::cout << "Type: 'Room' if you need to see what room you are in.\n";
	std::cout << "Type: 'Get' to pick up items and 'Drop' to drop them\n";
	std::cout << "Examples of valid inputs 'get' then 'rock' not 'get rock'\n";
	std::cout << "Type: 'Use' then '<item name>' to have an item interact with a room\n";
	std::cout << "Examples of valid inputs 'use' then 'rock' not 'use rock'\n";
	std::cout << "Enter actions one word at a time\n";
	std::cout << " you can type 'help' for a list of rules and commands at any time.\n";
		std::cout << "\n";

		std::string userInput;

		
		// points to current room
		Room* CURRENTROOM = new Room(room, 1);

		//sets current room to the first room 0 which is the cell
		CURRENTROOM->setCurrentRoom(room, 1);
		std::cout << CURRENTROOM->getRoomDiscription(room, 1) << std::endl;
		item->outputRoomItems(item, CURRENTROOM->getCurrentRoomNumber());
		while (userInput != "QUIT") {
			userInput.clear();
			std::cout << "What do you want to do?\n";
			userInput = USERINPUT();
			
			userInput = validateInput(userInput);
			/*if (!validateInput(userInput)) {*/
			if(userInput == "INVALID"){
				std::cout << "Enter a valid command \n"; //not working properly
				helpcount++;
				if (helpcount > 3) {
					helpcount = 0;
					std::cout <<"Type 'help' to get help with what commands you should use\n";
				}
			}
			else if (helpcount > 3) {
				helpcount = 0;
				std::cout << "Type 'help' to get help with what commands you should use\n";
			}
			else if (userInput == "QUIT") {
				std::cout << "Quiting \n";
			}
			else {
				std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
				if (userInput == "NORTH")
				{
					helpcount = 0;
					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 0, item);
					//std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";
				}
				else if (userInput == "SOUTH")
				{
					helpcount = 0;
					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 1, item);
					//std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";
				}
				else if (userInput == "EAST")
				{
					helpcount = 0;
					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 2, item);
					//std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";
				}
				else if (userInput == "WEST")
				{
					helpcount = 0;
					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 3, item);
					//std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";

				}
				else if (userInput == "INVENTORY") {
					helpcount = 0;
					item->outputPlayerItems(item);

				}
				else if (userInput == "HELP") {
					helpcount = 0;
					std::cout << "All you need to do is try to get out, can you make it to the exit? \n";
					std::cout << "Type: 'North', 'South', 'East', or 'West' to move around the rooms\n";
					std::cout << "Type: 'Room' if you need to see what room you are in.\n";
					std::cout << "Type: 'Get' to pick up items and 'Drop' to drop them\n";
					std::cout << "Examples of valid inputs 'get' then 'rock' not 'get rock'\n";
					std::cout << "Type: 'Use' then '<item name>' to have an item interact with a room\n";
					std::cout << "Examples of valid inputs 'use' then 'rock' not 'use rock'\n";
					std::cout << "Enter actions one word at a time\n";
				}
				else if (userInput == "USE") {
					helpcount = 0;
					std::cout << "What would you like to use?\n";
					/*
					userInput.clear();
					std::cin >> Item //input item being used
					std::cout << "What would you like to use" + Item + "on? \n";
					std::cin >> Lock //what the item is being used on
					// some to be made function to that inputs Item and Lock and will edit the board adn change room diolog
					Item.clear();
					Lock.clear();
					*/
					userInput.clear();
					std::string itemName = USERINPUT();									
					if (item->CheckInventory(item, itemName)) {
						std::string currentRoomName = CURRENTROOM->getCurrentRoomName();
						room->SolvePuzzle(room, currentRoomName, itemName);
						std::cout << CURRENTROOM->getRoomDiscription(room, CURRENTROOM->getCurrentRoomNumber()) << std::endl;
					}
				}
				//Team decided to just use the verb USE to make it easier for the user.
				//else if (userInput == "THROW") {
				//	std::cout << "What would you like to throw?\n";
				//	std::string itemName = USERINPUT();
				//	if (item->CheckInventory(item, itemName)) {						
				//		std::string currentRoomName = CURRENTROOM->getCurrentRoomName();
				//		room->SolvePuzzle(room, currentRoomName, itemName);
				//		std::cout << CURRENTROOM->getRoomDiscription(room, CURRENTROOM->getCurrentRoomNumber()) << std::endl;
				//	}					
				//	//will have very similar code to use referance that for details when ready.
				//}
				else if (userInput == "DROP") {
					userInput.clear();
					std::cout << "What Item do you want to drop?\n";
					userInput = USERINPUT();

					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					std::string CurrentRoomName = CURRENTROOM->getCurrentRoomName();
					item->PlayerDrop(item, userInput, currentRoomNumber, CurrentRoomName);
				}
				else if (userInput == "ROOM") {
					std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";
				}
				else if (userInput == "GET")//pick up
				{
					userInput.clear();
					std::cout << "What Item do you want to pick up?\n";
					
					userInput = USERINPUT();	
					
					/*tries to find the item according to user input
					and return as a number in the enum
					we need to know the item they want to pick up
					so if they type rock it should go in as a number*/
					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					item->PlayerPickup(item, userInput, currentRoomNumber);
				}

			}


		}
		std::cout << "Goodbye.";
		exit(0);
		return 0;
}

