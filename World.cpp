#include "World.hpp"
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include "Wolf.hpp"

World::World() : m_turn(0), m_world_width(0), m_world_height(0)
{
	m_organisms = std::vector<std::vector<Organism *>>(m_world_width, std::vector<Organism *>(m_world_height, nullptr));
}

World::World(int width, int height) : m_turn(0), m_world_width(width), m_world_height(height)
{
	m_organisms = std::vector<std::vector<Organism *>>(m_world_width, std::vector<Organism *>(m_world_height, nullptr));
	m_organisms[0][0] = new Wolf(5, 4, 0, Coordinates(0, 0), *this, Species::WOLF);
	m_organisms[0][1] = new Wolf(5, 4, 0, Coordinates(0, 1), *this, Species::WOLF);
	m_organisms[0][2] = new Wolf(5, 4, 0, Coordinates(0, 2), *this, Species::WOLF);
	m_organisms[0][3] = new Wolf(5, 4, 0, Coordinates(0, 3), *this, Species::WOLF);
}

void World::nextTurn()
{
	std::vector<Organism *> organisms;
	for (int i = 0; i < m_world_width; i++)
	{
		for (int j = 0; j < m_world_height; j++)
		{
			if (m_organisms[i][j] != nullptr)
			{
				organisms.push_back(m_organisms[i][j]);
			}
		}
	}
	std::sort(organisms.begin(), organisms.end(), Organism::OrganismComparator());
	for (Organism *organism : organisms)
	{
		organism->action();
	}
	m_turn++;
}

void World::print()
{
}

int World::getTurn()
{
	return m_turn;
}

std::vector<std::vector<Organism *>> &World::getOrganisms()
{
	return m_organisms;
}

int World::getWidth()
{
	return m_world_width;
}

int World::getHeight()
{
	return m_world_height;
}

bool World::isInWorld(Coordinates &coordinates)
{
	if (coordinates.x < 0 || coordinates.x >= m_world_width || coordinates.y < 0 || coordinates.y >= m_world_height)
	{
		return false;
	}
	return true;
}

bool World::isEmpty(Coordinates &coordinates)
{
	if (isInWorld(coordinates))
	{
		if (m_organisms[coordinates.x][coordinates.y] == nullptr)
		{
			return true;
		}
		return false;
	}
	throw std::invalid_argument("Coordinates are not in the world");
}

Organism &World::getOrganism(Coordinates &coordinates)
{
	if (isInWorld(coordinates))
	{
		if (m_organisms[coordinates.x][coordinates.y] != nullptr)
		{
			return *m_organisms[coordinates.x][coordinates.y];
		}
	}
	throw std::invalid_argument("Coordinates are not in the world");
}

void World::removeOrganism(Organism &organism)
{
	Coordinates coordinates = organism.getCoordinates();
	if (isInWorld(coordinates))
	{
		if (m_organisms[coordinates.x][coordinates.y] != nullptr)
		{
			delete m_organisms[coordinates.x][coordinates.y];
			m_organisms[coordinates.x][coordinates.y] = nullptr;
		}
	}
	else
	{
		throw std::invalid_argument("Coordinates are not in the world");
	}
}

void World::addOrganism(Coordinates &coordinates, Organism &organism)
{
	if (isInWorld(coordinates))
	{
		if (m_organisms[coordinates.x][coordinates.y] == nullptr)
		{
			m_organisms[coordinates.x][coordinates.y] = &organism;
		}
	}
	else
	{
		throw std::invalid_argument("Coordinates are not in the world");
	}
}

void World::moveOrganism(Organism &organism, Coordinates &newCoordinates)
{
	Coordinates oldCoordinates = organism.getCoordinates();
	if (isInWorld(oldCoordinates) && isInWorld(newCoordinates))
	{
		if (m_organisms[oldCoordinates.x][oldCoordinates.y] != nullptr)
		{
			m_organisms[newCoordinates.x][newCoordinates.y] = m_organisms[oldCoordinates.x][oldCoordinates.y];
			m_organisms[oldCoordinates.x][oldCoordinates.y] = nullptr;
			m_organisms[newCoordinates.x][newCoordinates.y]->setCoordinates(newCoordinates);
		}
	}
	else
	{
		throw std::invalid_argument("Coordinates are not in the world");
	}
}

void World::saveOrganismsToFile(std::string filename)
{
	std::ofstream file(filename);
	if (file.is_open())
	{
		file << m_world_width << ";" << m_world_height << std::endl;
		for (int i = 0; i < m_world_width; i++)
		{
			for (int j = 0; j < m_world_height; j++)
			{
				if (m_organisms[i][j] != nullptr)
				{
					file << m_organisms[i][j]->getSpecies() << ";";
					file << m_organisms[i][j]->getStrength() << ";";
					file << m_organisms[i][j]->getInitiative() << ";";
					file << m_organisms[i][j]->getAge() << ";";
					file << m_organisms[i][j]->getCoordinates().x << ";";
					file << m_organisms[i][j]->getCoordinates().y << std::endl;
				}
			}
		}
	}
}

void World::loadOrganismsFromFile(std::string filename)
{
	std::ifstream file(filename);
	if (file.is_open())
	{
		std::string line;
		std::getline(file, line);
		int width = std::stoi(line.substr(0, line.find(';')));
		int height = std::stoi(line.substr(line.find(';') + 1, line.length()));
		m_world_width = width;
		m_world_height = height;
		m_organisms = std::vector<std::vector<Organism *>>(m_world_width, std::vector<Organism *>(m_world_height, nullptr));
		while (std::getline(file, line))
		{
			char symbol = line[0];
			int strength = std::stoi(line.substr(line.find(';') + 1, line.length()));
			int initiative = std::stoi(line.substr(line.find(';') + 1, line.length()));
			int age = std::stoi(line.substr(line.find(';') + 1, line.length()));
			int x = std::stoi(line.substr(line.find(';') + 1, line.length()));
			int y = std::stoi(line.substr(line.find(';') + 1, line.length()));
			Coordinates coordinates(x, y);

			switch (symbol)
			{
			}
		}
	}
}
