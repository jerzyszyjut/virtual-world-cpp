#pragma once
#include "World.hpp"
#include <Windows.h>

enum Species {
	WOLF = 'W',
	SHEEP = 'S',
	FOX = 'F',
	TURTLE = 'T',
	ANTILOPINAE = 'A',
	CYBERSHEEP = 'C',
	HUMAN = 'H',
	GRASS = 'G',
	DANDELION = 'D',
	GUARANA = 'O',
	BELLADONNA = 'B',
	HERACLEUM_SOSNOWSKYI = '@',
	NONE = ' '
};

class World;

class Organism
{
public:
	Organism(int strength, int initiative, int age, COORD coordinates, World& world, Species species);
	Organism(Organism& other);
	Organism(Organism&& other);
	Organism(Organism* other);
	~Organism();

	virtual void action() = 0;
	virtual bool collision(COORD newCoordinates) = 0;
	void draw();

	virtual Organism& clone() = 0;
	int getStrength();
	int getInitiative();
	int getAge();
	void setAge(int age);
	Species getSpecies();
	COORD getCoordinates();
	COORD findClosestFreeSpace();
	COORD findClosestFreeSpace(int distance);
	void setCoordinates(COORD newCoordinates);

	struct OrganismComparator {
		bool operator()(Organism* first, Organism* second) const;
	};

protected:
	int m_strength=0, m_initiative=0, m_age=0;
	COORD m_coordinates;
	World& m_world;
	Species m_species = NONE;
};
