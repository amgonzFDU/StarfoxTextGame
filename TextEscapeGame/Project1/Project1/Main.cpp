#include "Player.h"
#include "Room.h"
#include "Input.h"
#include "Items.h"
#include <iostream>
#include <algorithm>
#include <string>

//the number of items in the game
extern const int ITEMS = 1;
//the number of rooms in the game
extern const int ROOMS = 2;
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
	
	
	// points to current room
	Room* CURRENTROOM = new Room(room , 0);
	
	//sets current room to the first room 0 which is the cell
	CURRENTROOM->setCurrentRoom(room, 0);


	while (userInput != "QUIT") {
		userInput.clear();
		std::cout << "Would you like to go to the next room?\n";		
		std::cin >> userInput;
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
		if (userInput == "YES")
		{
			std::cout << "You are now in the next room. \nIf you want to knoww the room name type room.\n";
			if(CURRENTROOM->getCurrentRoom() == "Cell")
			{
				CURRENTROOM->setCurrentRoom(room, 1);
			}
			else if (CURRENTROOM->getCurrentRoom() == "Cell 2") {
				CURRENTROOM->setCurrentRoom(room, 0);
			}
		}
		else if (userInput == "NO")
		{
			std::cout << "You stayed in the same room.\n";
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
		else if(userInput != "YES" || userInput != "NO" && userInput == "QUIT")
		{
			
		}		
		else if (userInput != "YES" || userInput != "NO") {
			std::cout << "It's a yes or question...\n";
		}
	}
	
	std::cout << "Goodbye.";
	std::cin.get();
	std::cin.get();
	return 0;
}
