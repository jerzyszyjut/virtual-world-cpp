#pragma once
#include "Plant.hpp"
#define GRASS_STRENGTH 0

class Grass :
    public Plant
{
public:
    using Plant::Plant;
    Grass(COORD coordinates, World& world) : Plant(GRASS_STRENGTH, coordinates, world, Species::GRASS) {};
    virtual Organism& clone() override;
};

