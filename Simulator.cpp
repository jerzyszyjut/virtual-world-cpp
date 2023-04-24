#include "Simulator.hpp"
#include <iostream>
#include <string>
#include <conio.h>

#define KEY_START_SYMBOL 224
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 224
#define ESCAPE 27
#define KEY_S 115
#define KEY_L 108


void Simulator::loadFromFile()
{
	system("cls");
	std::cout << "Loading save from file" << std::endl;
	do 
	{
		std::string filename;
		std::cout << "Input correct filename: " << std::endl;
		std::cin >> filename;
		world.loadOrganismsFromFile(filename);
	} while (world.getWidth() == 0 || world.getHeight() == 0);
}

void Simulator::saveToFile()
{
	system("cls");
	std::string filename;
	std::cout << "Saving to file" << std::endl;
	std::cout << "Input filename: " << std::endl;
	std::cin >> filename;
	world.saveOrganismsToFile(filename);
}

Simulator::Simulator()
{
	int userInput;
	std::cout << "Virtual world simulator" << std::endl;
	std::cout << "1. Load world from file" << std::endl;
	std::cout << "2. Generate new world" << std::endl;
	std::cin >> userInput;
	switch (userInput)
	{
	case 1: {
		loadFromFile();
		break;

	}
	case 2: {
		int width, height;
		std::cout << "Input map width:" << std::endl;
		std::cin >> width;
		std::cout << "Input map height:" << std::endl;
		std::cin >> height;
		world = World(width, height);
		break;
	}
	default:
		break;
	}
}

void Simulator::run()
{
	int character;
	bool isRunning = true;
	while (isRunning)
	{
		world.print();

		character = 0;
		character = _getch();
		if (character == KEY_START_SYMBOL) {
			character = _getch();
			switch (character)
			{
			case KEY_UP:
				break;
			case KEY_DOWN:
				break;
			case KEY_LEFT:
				break;
			case KEY_RIGHT:
				break;
			default:
				break;
			}
			world.nextTurn();
		}
		else
		{
			switch (character)
			{
			case ESCAPE:
				isRunning = false;
				break;
			case KEY_L:
				loadFromFile();
				break;
			case KEY_S:
				saveToFile();
				break;
			default:
				break;
			}
		}
	}
}
