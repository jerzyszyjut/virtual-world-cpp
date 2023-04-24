#include "Human.hpp"

Organism& Human::clone()
{
	Human* newHuman = new Human(m_coordinates, m_world);
	return *newHuman;
}

void Human::action(Direction direction)
{
	if (m_cooldown == 1)
	{
		m_cooldown = -5;
	}
	else if (m_cooldown > 0)
	{
		m_cooldown--;
	}
	else if (m_cooldown < 0)
	{
		m_cooldown++;
	}
	Animal::action(direction);
}

bool Human::collision(COORD newCoordinates)
{
	if (m_cooldown > 0)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				COORD neighbourCoordinates = { m_coordinates.X + i, m_coordinates.Y + j };
				if (m_world.isInWorld(neighbourCoordinates))
				{
					if (!m_world.isEmpty(neighbourCoordinates))
					{
						m_world.getOrganism(neighbourCoordinates).die();
					}
				}
			}
		}
	}
	else
	{
		return Animal::collision(newCoordinates);
	}
	return true;
}

int Human::getCooldown()
{
	return m_cooldown;
}

void Human::setCooldown(int cooldown)
{
	m_cooldown = cooldown;
}

void Human::useAbility()
{
	if (m_cooldown == 0)
	{
		m_cooldown = 5;
	}
}
