#include "Player.h"
/*
Defult player constructor
*/
Player::Player(std::string name)
{
	this->location = nullptr;
	this->name = name;
}

/*
Defult player destructor
*/
Player::~Player()
{
}

/*
Returns the name varuable in the player class.
*/
std::string Player::getName()
{
	return this->name;
}

/*
Returns a pointer to the current location of the player.
*/
Room* Player::getCurrentRoom()
{
	return this->location;
}

/*
Sets the location of the player.
*/
void Player::setCurrentRoom(Room& newRoom)
{
	this->location = &newRoom;
}

