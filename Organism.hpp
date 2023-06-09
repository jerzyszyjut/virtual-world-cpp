#pragma once
#include "World.hpp"
#include <Windows.h>

#define DIRECTION_COUNT 4
#define DEFAULT_AGE 0

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

enum FightResult
{
	DEFEAT,
	VICTORY,
	DRAW
};

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
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

	virtual void action(Direction direction) = 0;
	virtual bool collision(COORD newCoordinates) = 0;
	void draw();

	virtual FightResult attack(Organism& other, bool isAttacked);
	virtual Organism& clone() = 0;
	int getStrength();
	void setStrength(int strength);
	int getInitiative();
	int getAge();
	void setAge(int age);
	void die();
	bool isAlive();
	Species getSpecies();
	COORD getCoordinates();
	COORD findClosestFreeSpace(int distance);
	COORD findClosestFreeSpace(int distance, COORD coordinates);
	void setCoordinates(COORD newCoordinates);
	struct OrganismComparator {
		bool operator()(Organism* first, Organism* second) const;
	};

	struct InitiativeOrganismComparator {
		bool operator()(Organism* first, Organism* second) const;
	};

protected:
	int m_strength, m_initiative, m_age;
	bool m_isAlive = true;
	COORD m_coordinates;
	World& m_world;
	Species m_species;
};
