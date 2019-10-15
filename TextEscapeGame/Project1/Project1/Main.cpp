#include "Player.h"
#include "Room.h"
#include "Input.h"
#include <iostream>
int main(int argc, char *argv[])
{
	std::cout << "Please Enter your name.\n";
	std::string name;
    std::cin >> name;
	Player* MainPlayer = new Player(name);

	std::cout << "Hello there " + MainPlayer->getName() + " how are you doing?\n";

	std::cin.get();
	std::cin.get();
	return 0;
}