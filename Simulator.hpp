#pragma once
#include "World.hpp"

class Simulator
{
private:
	World world;
	void loadFromFile();
	void saveToFile();

public:
	Simulator();
	void run();
};

