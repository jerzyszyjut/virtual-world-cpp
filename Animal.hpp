#pragma once
#include "Organism.hpp"
#include "Coordinates.hpp"

class Animal : public Organism
{
public:
	using Organism::Organism;

	virtual void action() override;
	bool collision(Coordinates& newCoordinates) override;
	virtual Organism& clone() = 0;
	void reproduce(Organism& other);
	bool move(Coordinates& newPosition);
	bool attack(Organism& other, bool isAttacked);
};