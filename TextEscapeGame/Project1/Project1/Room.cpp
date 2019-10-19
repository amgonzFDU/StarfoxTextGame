#include "Room.h"


/*
Defult Room constructor
*/
Room::Room()
{
}
/*
Defult Room destructor
*/
Room::~Room()
{
}
/*
Returns the width of the room.
*/
double Room::getWidth()
{
	return this->width;
}

/*
Returns the length of the room.
*/
double Room::getLength()
{
	return this->length;
}

/*
Returns the height of the room.
*/
double Room::getHeight()
{
	return this->height;
}