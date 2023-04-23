#pragma once
#include "Organism.hpp"

class Animal : public Organism
{
public:
	using Organism::Organism;

	virtual std::string action() override;
	bool collision(COORD newCoordinates) override;
	virtual Organism& clone() = 0;
	void reproduce(Organism& other);
	bool move(COORD newPosition);
	bool attack(Organism& other, bool isAttacked);
};