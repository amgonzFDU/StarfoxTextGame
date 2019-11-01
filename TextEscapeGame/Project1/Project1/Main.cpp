#include "Player.h"
#include "Room.h"
#include "Input.h"
#include "Items.h"
#include <iostream>
#include <algorithm>
#include <string>


//the number of items in the game
extern const int ITEMS = 2;
//the number of rooms in the game
extern const int ROOMS = 22;
//number of verbs in the game
extern const int VERBS = 6;
//enumerator to help with item pick up
enum itemsname { rock, key };
//validates the input is an aproved verb
bool validateInput(std::string userInput) {
	std::string validInputs[VERBS] = { "GO", "USE", "THROW", "DROP", "ROOM","ITEM" };
	for (int i = 0; i < VERBS; i++) {
		if (validInputs[i] == userInput) {
			return true;
		}
	}
	return false;
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
    std::cin >> name;
	Player* MainPlayer = new Player(name);

	std::cout << "Hello there " + MainPlayer->getName(); + ". \n";
	std::cout << "\n";

	std::string userInput;
	
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
	*/

	
	
	
	// points to current room
	Room* CURRENTROOM = new Room(room , 1);
	
	//sets current room to the first room 0 which is the cell
	CURRENTROOM->setCurrentRoom(room, 1);
	
	while (userInput != "QUIT") {
		userInput.clear();
		std::cout << "What do you want to do?\n";
		std::cin >> userInput;
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
		if (!validateInput(userInput)) {
			std::cout << "Enter a valid command \n"; //not working properly
		}		
		else if (userInput == "QUIT") { 
			std::cout << "Quiting \n";
		}		
		else{
			if (userInput == "GO") {
				std::cout << "Where would you like to go? \n";
				userInput.clear();
				std::cin >> userInput;
				std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
				if (userInput == "NORTH")
				{
					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 0);
				}
				if (userInput == "SOUTH")
				{
					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 1);
				}
				if (userInput == "EAST")
				{
					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 2);
				}
				if (userInput == "WEST")
				{
					int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 3);
				}
			}
			else if (userInput == "USE") {
				std::cout << "What would you like to use?\n";
			}
			else if (userInput == "THROW") {
				std::cout << "What would you like to throw?\n";
			}
			else if (userInput == "DROP") {
				userInput.clear();
				std::cout << "What Item do you want to drop?\n";
				std::cin >> userInput;//Rock
				std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
				
				int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
				std::string CurrentRoomName = CURRENTROOM->getCurrentRoomName();
				item->PlayerDrop(item,userInput, currentRoomNumber,CurrentRoomName);
			}
			else if (userInput == "ROOM") {
				std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";
			}
			else if (userInput == "ITEM")//pick up
			{
				userInput.clear();
				std::cout << "What Item do you want to pick up?\n";
				std::cin >> userInput;//Rock
				std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
	
     			/*tries to find the item according to user input 
				and return as a number in the enum	
				we need to know the item they want to pick up
				so if they type rock it should go in as a number*/
				int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
				item->PlayerPickup(item, userInput,currentRoomNumber);
				
				std::cout << "rock is in room " << item->getItemLocationName(item, 0) << "\n";
				//std::cout << "key IS in room " << item->getItemLocation(item, 1) << "\n";
			}
			
		}
		
				
	}
	
	// old input validation
	/*
				if (userInput == "NORTH")
				{
					int currentRoomNumber = CURRENTROOM->getCurrentRoom();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 0);
				}
				if (userInput == "SOUTH")
				{
					int currentRoomNumber = CURRENTROOM->getCurrentRoom();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 1);
				}
				if (userInput == "EAST")
				{
					int currentRoomNumber = CURRENTROOM->getCurrentRoom();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 2);
				}
				if(userInput == "WEST")
				{
					int currentRoomNumber = CURRENTROOM->getCurrentRoom();
					CURRENTROOM->moveRoom(room, currentRoomNumber, 3);
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
				else if (userInput == "ROOM")
				{
					std::cout << "The room is: " << CURRENTROOM->getCurrentRoom() << "\n";
				}
				else if (userInput == "ITEM")
				{
					std::cout << "rock IS in room " << item->getItemLocation(item, 0) << "\n";
					std::cout << "key IS in room " << item->getItemLocation(item, 1) << "\n";
				}

				else{
					std::cout << "Not a valid input\n";
				}
				userInput.clear();
				*/
	
	std::cout << "Goodbye.";
	std::cin.get();
	std::cin.get();
	return 0;
}
