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
extern const int VERBS = 11;
//enumerator to help with item pick up
enum itemsname { rock, key };
//validates the input is an aproved verb
bool validateInput(std::string userInput) {
	std::string validInputs[VERBS] = { "NORTH","EAST","SOUTH","WEST", "USE", "THROW", "DROP", "ROOM","GET","INVENTORY","HELP" };
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

	std::cout << "Hello there " + MainPlayer->getName(); + "";
	std::cout << " you can type 'help' for a list of rules and commands.\n";
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
	std::cout << CURRENTROOM->getRoomDiscription(room,1) << std::endl;
	
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
			std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
			if (userInput == "NORTH")
			{
				int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
				CURRENTROOM->moveRoom(room, currentRoomNumber, 0);
				std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";
			}
			else if (userInput == "SOUTH")
			{
				int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
				CURRENTROOM->moveRoom(room, currentRoomNumber, 1);
				std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";
			}
			else if (userInput == "EAST")
			{
				int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
				CURRENTROOM->moveRoom(room, currentRoomNumber, 2);
				std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";
			}
			else if (userInput == "WEST")
			{
				int currentRoomNumber = CURRENTROOM->getCurrentRoomNumber();
				CURRENTROOM->moveRoom(room, currentRoomNumber, 3);
				std::cout << "The room is: " << CURRENTROOM->getCurrentRoomName() << "\n";
			}
			else if (userInput == "INVENTORY") {

				item->outputPlayerItems(item);

			}
			else if (userInput == "HELP") {
				std::cout << "All you need to do is try to get out, can you make it to the exit? \n";
				std::cout << "Type: 'North', 'South', 'East', or 'West' to move around the rooms\n";
				std::cout << "Type: 'Room' if you need to see what room you are in.\n";
				std::cout << "Type: 'item' to pick up items and 'drop' to drop them\n";
			}	
			else if (userInput == "USE") {
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
				
			}
			else if (userInput == "THROW") {
				std::cout << "What would you like to throw?\n";
				
				//will have very similar code to use referance that for details when ready.
				
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
			else if (userInput == "GET")//pick up
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
			}
			
		}
		
				
	}
	
	
	
	std::cout << "Goodbye.";
	std::cin.get();
	std::cin.get();
	return 0;
}
