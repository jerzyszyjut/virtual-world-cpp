#pragma once
#include "Plant.hpp"

class Belladonna :
    public Plant
{
    public:
        using Plant::Plant;
        Belladonna(COORD coordinates, World& world) : Plant(99, coordinates, world, Species::BELLADONNA) {}

        virtual Organism& clone() override;
        virtual FightResult attack(Organism& other, bool isAttacked) override;
};

