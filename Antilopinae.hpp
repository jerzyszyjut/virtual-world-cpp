#pragma once
#include "Animal.hpp"

class Antilopinae :
    public Animal
{
public:
    using Animal::Animal;
    Antilopinae(COORD coordinates, World& world) : Animal(4, 4, 0, coordinates, world, Species::ANTILOPINAE) {};
    virtual Organism& clone() override;
    virtual void action() override;
    virtual bool collision(COORD newCoordinates) override;
};

