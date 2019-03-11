#include <iostream>
#include "include/Game.h"

int main()
{
	Game game("Snake");
	game.run();

	std::cin.get();
	return 0;
}