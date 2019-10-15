#include <string>

class Player
{
private:
	std::string name;
public:
	Player(std::string name);
	~Player();
	std::string getName();
};

