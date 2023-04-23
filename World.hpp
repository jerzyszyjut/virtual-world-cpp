#pragma once
#include "Organism.hpp"
#include "Renderer.hpp"
#include <vector>
#include <string>
#include <Windows.h>

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
	bool isInWorld(COORD coordinates);
	bool isEmpty(COORD coordinates);
	Organism& getOrganism(COORD coordinates);
	void removeOrganism(Organism& organism);
	void addOrganism(Organism& organism, COORD coordinates);
	void moveOrganism(Organism& organism, COORD coordinates);
	
	void saveOrganismsToFile(std::string filename);
	void loadOrganismsFromFile(std::string filename);

	Renderer* m_renderer;

private:
	int m_turn, m_world_width, m_world_height;
	std::vector<std::vector<Organism*>> m_organisms;
};

