#include <iostream>
#include "World.hpp"

int main()
{
	World world(20, 20);
	world.loadOrganismsFromFile("organisms.txt");
	int i = 1000;
	while (i--)
	{
		world.print();
		world.nextTurn();
		world.saveOrganismsToFile("organisms.txt");
	}

	return 0;
}