#pragma once
#include "Plant.hpp"

class Grass :
    public Plant
{
public:
    using Plant::Plant;
    Grass(COORD coordinates, World& world) : Plant(0, coordinates, world, Species::GRASS) {};
    virtual Organism& clone() override;
};

