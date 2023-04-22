#include <iostream>
#include "World.hpp"

int main()
{
	World world(20, 20);
	int i = 10000;
	while (i--)
	{
		world.nextTurn();
	}

	return 0;
}