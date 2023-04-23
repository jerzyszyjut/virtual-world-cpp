#pragma once
#include "Animal.hpp"

class Fox :
    public Animal
{
public:
    virtual Organism& clone() override;
    virtual void action() override;
};

