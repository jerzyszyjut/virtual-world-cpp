#include <iostream>
#include "World.hpp"

int main()
{
	World world(20, 20);
	int i = 5;
	while (i--)
	{
		world.print();
		world.nextTurn();
	}

	return 0;
}