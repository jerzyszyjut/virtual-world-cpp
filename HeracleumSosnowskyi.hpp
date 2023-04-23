#pragma once
#include "Plant.hpp"

class HeracleumSosnowskyi :
    public Plant
{
public:
    using Plant::Plant;
    HeracleumSosnowskyi(COORD coordinates, World& world) : Plant(10, coordinates, world, Species::HERACLEUM_SOSNOWSKYI) {};

    virtual void action() override;
    virtual Organism& clone() override;
    virtual FightResult attack(Organism& other, bool isAttacked) override;
};

