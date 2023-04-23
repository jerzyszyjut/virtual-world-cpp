#pragma once
#include "Animal.hpp"

class Sheep :
    public Animal
{
public:
    virtual Organism& clone() override;
    using Animal::Animal;

    protected:
        Species m_species = SHEEP;
		int m_strength = 4, m_initiative = 4;
};

