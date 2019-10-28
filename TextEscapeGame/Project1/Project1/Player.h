#include <string>
#include "Room.h"

class Player
{
private:
	std::string name;
	Room* location;
public:
	Player(std::string name);
	~Player();
	Room* getCurrentRoom();
	void setCurrentRoom(Room& newRoom);
	std::string getName();
};

