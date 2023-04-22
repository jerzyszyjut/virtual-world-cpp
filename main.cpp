#include <iostream>
#include "World.hpp"

int main() {
	World world(20, 20);
	int i = 10;
	while (i--) {
		world.nextTurn();
	}

	return 0;
}