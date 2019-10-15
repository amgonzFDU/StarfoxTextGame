#include "Player.h"
/*
Defult player constructor
*/
Player::Player(std::string name)
{
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
