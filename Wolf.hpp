#pragma once
#include "Animal.hpp"

class Wolf :
	public Animal
{
public:
	virtual Organism& clone() override;
	using Animal::Animal;

protected:
	Species m_species = WOLF;
	int m_strength = 9, m_initiative = 5;
};

