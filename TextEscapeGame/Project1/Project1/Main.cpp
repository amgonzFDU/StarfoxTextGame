#include "Player.h"
#include "Room.h"
#include "Input.h"
#include <iostream>
#include <algorithm>
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
		Room *North;
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
	three->North = two;
	three->RoomName = "Room 3";

	//sets current room to the first room 1
	CURRENTROOM = one;

	while (userInput != "QUIT") {
		userInput.clear();
		std::cout << "Would you like to go to the next room?\n";		
		getline(std::cin, userInput);
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
		if (userInput == "YES")
		{
			std::cout << "You are now in the next room. \nIf you want to know the room name type room.\n";
			if(CURRENTROOM->RoomName == "Room 1")
			{
				CURRENTROOM = two;
			}
			else if (CURRENTROOM->RoomName == "Room 2") {
				CURRENTROOM = one;
			}
		}
		else if (userInput == "NO")
		{
			std::cout << "You stayed in the same room.\n";
		}
		else if (userInput == "ROOM") {
			std::cout << "The room is: " << CURRENTROOM->RoomName << "\n";
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
