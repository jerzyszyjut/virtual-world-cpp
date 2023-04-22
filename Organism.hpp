#pragma once
#include "World.hpp"
#include "Coordinates.hpp"

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
};

class Coordinates;
class World;

class Organism
{
public:
	Organism(int strength, int initiative, int age, Coordinates coordinates, World& world, Species species);
	Organism(Organism& other);
	~Organism();

	virtual void action() = 0;
	virtual bool collision(Coordinates& newCoordinates) = 0;
	void draw();

	virtual Organism& clone() = 0;
	int getStrength();
	int getInitiative();
	int getAge();
	Species getSpecies();
	Coordinates& getCoordinates();
	Coordinates& findClosestFreeSpace();
	Coordinates& findClosestFreeSpace(int distance);
	void setCoordinates(Coordinates& newCoordinates);

	struct OrganismComparator {
		bool operator()(Organism* first, Organism* second) const;
	};

protected:
	int m_strength, m_initiative, m_age;
	Coordinates* m_coordinates;
	World& m_world;
	Species m_species;
};
