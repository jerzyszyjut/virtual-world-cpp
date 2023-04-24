#include "World.hpp"
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include "Wolf.hpp"
#include "Turtle.hpp"
#include "Sheep.hpp"
#include "Fox.hpp"
#include "Antilopinae.hpp"
#include "Grass.hpp"
#include "Dandelion.hpp"
#include "Guarana.hpp"
#include "Belladonna.hpp"
#include "HeracleumSosnowskyi.hpp"

World::World() : m_turn(0), m_world_width(0), m_world_height(0)
{
	m_organisms = new std::vector<std::vector<Organism*>>(m_world_width, std::vector<Organism*>(m_world_height, nullptr));
	m_renderer = new Renderer(m_world_width, m_world_height);
}

World::World(int width, int height) : m_turn(0), m_world_width(width), m_world_height(height)
{
	m_organisms = new std::vector<std::vector<Organism*>>(m_world_width, std::vector<Organism*>(m_world_height, nullptr));
	m_renderer = new Renderer(m_world_width, m_world_height);
	(*m_organisms)[0][0] = new Antilopinae({ 0, 0 }, *this);
}

void World::nextTurn()
{
	std::vector<Organism*> organisms;
	for (int i = 0; i < m_world_width; i++)
	{
		for (int j = 0; j < m_world_height; j++)
		{
			if ((*m_organisms)[i][j] != nullptr)
			{
				organisms.push_back((*m_organisms)[i][j]);
			}
		}
	}
	std::sort(organisms.begin(), organisms.end(), Organism::InitiativeOrganismComparator());
	for (Organism* organism : organisms)
	{
		if (organism->isAlive())
		{
			organism->action();
		}
	}
	removeDeadOrganisms();
	m_turn++;
}

void World::print()
{
	std::vector<Organism*> organisms;
	for (int i = 0; i < m_world_width; i++)
	{
		for (int j = 0; j < m_world_height; j++)
		{
			if ((*m_organisms)[i][j] != nullptr)
			{
				organisms.push_back((*m_organisms)[i][j]);
			}
		}
	}
	for (Organism* organism : organisms)
	{
		organism->draw();
	}
	m_renderer->render();
}

int World::getTurn()
{
	return m_turn;
}

std::vector<std::vector<Organism*>>* World::getOrganisms()
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

bool World::isInWorld(COORD coordinates)
{
	if (coordinates.X < 0 || coordinates.X >= m_world_width || coordinates.Y < 0 || coordinates.Y >= m_world_height)
	{
		return false;
	}
	return true;
}

bool World::isEmpty(COORD coordinates)
{
	if (isInWorld(coordinates))
	{
		if ((*m_organisms)[coordinates.X][coordinates.Y] == nullptr || !((*m_organisms)[coordinates.X][coordinates.Y]->isAlive()))
		{
			return true;
		}
		return false;
	}
	throw std::invalid_argument("Coordinates are not in the world");
}

Organism& World::getOrganism(COORD coordinates)
{
	if (isInWorld(coordinates))
	{
		if ((*m_organisms)[coordinates.X][coordinates.Y] != nullptr && (*m_organisms)[coordinates.X][coordinates.Y]->isAlive())
		{
			return *(*m_organisms)[coordinates.X][coordinates.Y];
		}
	}
	throw std::invalid_argument("Coordinates are not in the world");
}

void World::removeOrganism(Organism& organism)
{
	COORD coordinates = organism.getCoordinates();
	if (isInWorld(coordinates))
	{
		if ((*m_organisms)[coordinates.X][coordinates.Y] != nullptr)
		{
			delete (*m_organisms)[coordinates.X][coordinates.Y];
			(*m_organisms)[coordinates.X][coordinates.Y] = nullptr;
		}
	}
	else
	{
		throw std::invalid_argument("Coordinates are not in the world");
	}
}

void World::removeDeadOrganisms()
{
	for (int i = 0; i < m_world_width; i++)
	{
		for (int j = 0; j < m_world_height; j++)
		{
			if ((*m_organisms)[i][j] != nullptr)
			{
				if (!(*m_organisms)[i][j]->isAlive())
				{
					removeOrganism(*(*m_organisms)[i][j]);
				}
			}
		}
	}
}

void World::addOrganism(Organism& organism, COORD coordinates)
{
	if (isInWorld(coordinates))
	{
		if ((*m_organisms)[coordinates.X][coordinates.Y] == nullptr)
		{
			(*m_organisms)[coordinates.X][coordinates.Y] = &organism;
		}
	}
	else
	{
		throw std::invalid_argument("Coordinates are not in the world");
	}
}

void World::moveOrganism(Organism& organism, COORD coordinates)
{
	COORD oldCoordinates = organism.getCoordinates();
	if (isInWorld(oldCoordinates) && isInWorld(coordinates))
	{
		if ((*m_organisms)[oldCoordinates.X][oldCoordinates.Y] != nullptr)
		{
			(*m_organisms)[coordinates.X][coordinates.Y] = (*m_organisms)[oldCoordinates.X][oldCoordinates.Y];
			(*m_organisms)[oldCoordinates.X][oldCoordinates.Y] = nullptr;
			(*m_organisms)[coordinates.X][coordinates.Y]->setCoordinates(coordinates);
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
				if ((*m_organisms)[i][j] != nullptr && (*m_organisms)[i][j]->isAlive())
				{
					file << (*m_organisms)[i][j]->getSpecies() << ";";
					file << (*m_organisms)[i][j]->getStrength() << ";";
					file << (*m_organisms)[i][j]->getInitiative() << ";";
					file << (*m_organisms)[i][j]->getAge() << ";";
					file << (*m_organisms)[i][j]->getCoordinates().X << ";";
					file << (*m_organisms)[i][j]->getCoordinates().Y << std::endl;
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
		delete m_organisms;
		m_organisms = new std::vector<std::vector<Organism*>>(m_world_width, std::vector<Organism*>(m_world_height, nullptr));
		delete m_renderer;
		m_renderer = new Renderer(m_world_width, m_world_height);
		while (std::getline(file, line))
		{
			char symbol = std::stoi(line.substr(0, line.find(';')));
			line = line.substr(line.find(';') + 1, line.length());
			int strength = std::stoi(line.substr(0, line.find(';')));
			line = line.substr(line.find(';') + 1, line.length());
			int initiative = std::stoi(line.substr(0, line.find(';')));
			line = line.substr(line.find(';') + 1, line.length());
			int age = std::stoi(line.substr(0, line.find(';')));
			line = line.substr(line.find(';') + 1, line.length());
			int x = std::stoi(line.substr(0, line.find(';')));
			line = line.substr(line.find(';') + 1, line.length());	
			int y = std::stoi(line.substr(0, line.find(';')));
			COORD coordinates{ x, y };

			switch (symbol)
			{
			case Species::SHEEP:
			{
				Sheep* sheep = new Sheep(strength, initiative, age, coordinates, *this, SHEEP);
				addOrganism(*sheep, coordinates);
				break;
			}
			case Species::FOX:
			{
				Fox* fox = new Fox(strength, initiative, age, coordinates, *this, FOX);
				addOrganism(*fox, coordinates);
				break;
			}
			case Species::TURTLE:
			{
				Turtle* turtle = new Turtle(strength, initiative, age, coordinates, *this, TURTLE);
				addOrganism(*turtle, coordinates);
				break;
			}
			case Species::ANTILOPINAE:
			{
				Antilopinae* antilopinae = new Antilopinae(strength, initiative, age, coordinates, *this, ANTILOPINAE);
				addOrganism(*antilopinae, coordinates);
				break;
			}
			case Species::WOLF:
			{
				Wolf* wolf = new Wolf(strength, initiative, age, coordinates, *this, WOLF);
				addOrganism(*wolf, coordinates);
				break;
			}
			case Species::GRASS:
			{
				Grass* grass = new Grass(strength, initiative, age, coordinates, *this, GRASS);
				addOrganism(*grass, coordinates);
				break;
			}
			case Species::DANDELION:
			{
				Dandelion* dandelion = new Dandelion(strength, initiative, age, coordinates, *this, DANDELION);
				addOrganism(*dandelion, coordinates);
				break;
			}
			case Species::GUARANA:
			{
				Guarana* guarana = new Guarana(strength, initiative, age, coordinates, *this, GUARANA);
				addOrganism(*guarana, coordinates);
				break;
			}
			case Species::BELLADONNA:
			{
				Belladonna* belladonna = new Belladonna(strength, initiative, age, coordinates, *this, BELLADONNA);
				addOrganism(*belladonna, coordinates);
				break;
			}
			case Species::HERACLEUM_SOSNOWSKYI:
			{
				HeracleumSosnowskyi* heracleumSosnowskyi = new HeracleumSosnowskyi(strength, initiative, age, coordinates, *this, HERACLEUM_SOSNOWSKYI);
				addOrganism(*heracleumSosnowskyi, coordinates);
				break;
			}
			}
		}

	}
}
