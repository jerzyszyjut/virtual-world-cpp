#pragma once
#include "Organism.hpp"
#include "Coordinates.hpp"
#include <vector>
#include <string>

class Organism;

class World
{
public:
	World();
	World(int width, int height);
	void nextTurn();
	void print();
	int getTurn();
	std::vector<std::vector<Organism*>>& getOrganisms();
	int getWidth();
	int getHeight();
	bool isInWorld(Coordinates& coordinates);
	bool isEmpty(Coordinates& coordinates);
	Organism& getOrganism(Coordinates& coordinates);
	void removeOrganism(Organism& organism);
	void addOrganism(Coordinates& coordinates, Organism& organism);
	void moveOrganism(Organism& organism, Coordinates& newCoordinates);
	
	void saveOrganismsToFile(std::string filename);
	void loadOrganismsFromFile(std::string filename);

private:
	int m_turn, m_world_width, m_world_height;
	std::vector<std::vector<Organism*>> m_organisms;
};

