#include "Plant.hpp"

void Plant::action()
{
	bool willSeed = (rand() % 100) < 10;
	if (willSeed)
	{
		int direction = rand() % 4;
		COORD newPosition = m_coordinates;
		switch (direction)
		{
		case 0:
			newPosition.X--;
			break;
		case 1:
			newPosition.X++;
			break;
		case 2:
			newPosition.Y--;
			break;
		case 3:
			newPosition.Y++;
			break;
		}
	}
}

bool Plant::collision(COORD newCoordinates)
{
	return false;
}

FightResult Plant::attack(Organism& other, bool isAttacked)
{
	return FightResult();
}
