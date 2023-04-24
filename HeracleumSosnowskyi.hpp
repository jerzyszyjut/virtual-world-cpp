#pragma once
#include "Plant.hpp"
#define HERACLEUM_SOSNOWSKYI_STRENGTH 10

class HeracleumSosnowskyi :
    public Plant
{
public:
    using Plant::Plant;
    HeracleumSosnowskyi(COORD coordinates, World& world) : Plant(HERACLEUM_SOSNOWSKYI_STRENGTH, coordinates, world, Species::HERACLEUM_SOSNOWSKYI) {};

    virtual void action(Direction direction) override;
    virtual Organism& clone() override;
    virtual FightResult attack(Organism& other, bool isAttacked) override;
};

