#pragma once
#include "Organism.hpp"

enum FightResult
{
	DEFEAT,
	VICTORY,
	DRAW
};

class Animal : public Organism
{
public:
	using Organism::Organism;

	virtual void action() override;
	virtual bool collision(COORD newCoordinates) override;
	virtual Organism& clone() = 0;
	void reproduce(Organism& other);
	virtual bool move(COORD newPosition);
	virtual FightResult attack(Organism& other, bool isAttacked);
};