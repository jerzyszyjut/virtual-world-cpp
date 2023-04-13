#pragma once
#include "Organism.hpp"

class World
{
public:
	World();
	~World();
	void nextTurn();
	void print();
	int getTurn();
	int getOrganismsSize();
	Organism* getOrganisms();
	int getWidth();
	int getHeight();

private:
	int m_turn, m_organisms_size, m_world_width, m_world_height;
	Organism* m_organisms;
};

