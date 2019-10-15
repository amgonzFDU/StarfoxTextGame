#include "Player.h"
#include "Room.h"
#include "Input.h"
#include <iostream>
#include <algorithm>
int main(int argc, char *argv[])
{
	std::cout << "Please Enter your name.\n";
	std::string name;
    std::cin >> name;
	Player* MainPlayer = new Player(name);

	std::cout << "Hello there " + MainPlayer->getName(); + ". \n";
	std::cout << "\n";

	std::string userInput;

	while (userInput != "QUIT") {
		userInput.clear();
		std::cout << "Would you like to go to the next room?\n";		
		std::cin >> userInput;
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
		if (userInput == "YES")
		{
			std::cout << "You are now in the next room.\n";
		}
		else if (userInput == "NO")
		{
			std::cout << "You stayed in the same room.\n";
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