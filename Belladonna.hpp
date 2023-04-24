#pragma once
#include "Plant.hpp"
#define BELLADONNA_STRENGTH 99

class Belladonna :
    public Plant
{
    public:
        using Plant::Plant;
        Belladonna(COORD coordinates, World& world) : Plant(BELLADONNA_STRENGTH, coordinates, world, Species::BELLADONNA) {}

        virtual Organism& clone() override;
        virtual FightResult attack(Organism& other, bool isAttacked) override;
};

