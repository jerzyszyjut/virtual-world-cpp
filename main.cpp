#include <iostream>
#include "World.hpp"

int main() {
	World world(20, 20);
	while (1) {
		world.nextTurn();
	}

	return 0;
}