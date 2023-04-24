#include "Renderer.hpp"
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdexcept>

#define MAP_START_X 1
#define MAP_START_Y 2
#define MAP_BORDER_WIDTH 1
#define MAX_MAP_SIZE 20
#define MAX_MAP_SIZE_X MAX_MAP_SIZE 
#define MAX_MAP_SIZE_Y MAX_MAP_SIZE 
#define LOGS_START_X MAP_START_X + MAX_MAP_SIZE_X + MAP_BORDER_WIDTH * 2
#define LOGS_START_Y 1
#define LEGEND_START_X 1
#define LEGEND_START_Y MAP_START_Y + MAX_MAP_SIZE_Y + MAP_BORDER_WIDTH * 2

Renderer::Renderer(int mapWidth, int mapHeight)
{
	m_mapWidth = mapWidth;
	m_mapHeight = mapHeight;
	m_map.resize(m_mapWidth);
	for (int i = 0; i < m_mapWidth; i++)
	{
		m_map[i].resize(m_mapHeight);
	}
	for (int i = 0; i < m_mapWidth; i++)
	{
		for (int j = 0; j < m_mapHeight; j++)
		{
			m_map[i][j] = ' ';
		}
	}
	m_logs = std::vector<std::string>();
}

void Renderer::render(int cooldown)
{
	system("cls");
	renderAutor();
	renderBorder();
	renderMap();
	renderLogs();
	renderLegend(cooldown);
	clearMap();
	clearLogs();
}

void Renderer::addLog(std::string log)
{
	if(log != "")
	m_logs.push_back(log);
}

void Renderer::addMapElement(int x, int y, char c)
{
	if (x < m_mapWidth && x >= 0 && y < m_mapHeight && y >= 0)
	{
		m_map[x][y] = c;
	}
	else 
	{
		throw std::exception("Out of map");
	}
}

void Renderer::clearMap()
{
	for (int i = 0; i < m_mapWidth; i++)
	{
		for (int j = 0; j < m_mapHeight; j++)
		{
			m_map[i][j] = ' ';
		}
	}
}

void Renderer::clearLogs()
{
	m_logs = std::vector<std::string>();
}

void Renderer::renderAutor()
{
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "Jerzy Szyjut 193064";
}

void Renderer::renderLogs()
{
	int startX = LOGS_START_X, startY = LOGS_START_Y;
	int maxSize = m_logs.size() > MAX_MAP_SIZE_Y ? MAX_MAP_SIZE_Y : m_logs.size();
	for (int i = 0; i < maxSize; i++)
	{
		COORD coord = { startX, startY + i };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << m_logs[i];
	}
}

void Renderer::renderMap()
{
	int startX = 0, startY = 0;
	int basicOffsetX = MAP_START_X, basicOffsetY = MAP_START_Y;
	int width = m_mapWidth > MAX_MAP_SIZE_X ? MAX_MAP_SIZE_X : m_mapWidth;
	int height = m_mapHeight > MAX_MAP_SIZE_Y ? MAX_MAP_SIZE_Y : m_mapHeight;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			startX = basicOffsetX + i;
			startY = basicOffsetY + j;
			COORD coord = { startX, startY };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << m_map[i][j];
		}
	}
}

void Renderer::renderBorder()
{
	int width = m_mapWidth > MAX_MAP_SIZE_X ? MAX_MAP_SIZE_X : m_mapWidth;
	int height = m_mapHeight > MAX_MAP_SIZE_Y ? MAX_MAP_SIZE_Y : m_mapHeight;
	for (int i = 0; i < width + 2 * MAP_BORDER_WIDTH; i++)
	{
		COORD coord = { MAP_START_X - 1 + i, MAP_START_Y - 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << "-";
	}
	for (int i = 0; i < width + 2 * MAP_BORDER_WIDTH; i++)
	{
		COORD coord = { MAP_START_X - 1 + i, MAP_START_X + m_mapHeight + 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << "-";
	}
	for (int i = 0; i < m_mapHeight + 2 * MAP_BORDER_WIDTH; i++)
	{
		COORD coord = { MAP_START_X - 1, MAP_START_Y - 1 + i };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << "|";
	}
	for (int i = 0; i < m_mapHeight + 2 * MAP_BORDER_WIDTH; i++)
	{
		COORD coord = { MAP_START_X + width, MAP_START_Y - 1 + i };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << "|";
	}
}

void Renderer::renderLegend(int cooldown)
{
	COORD coord = { LEGEND_START_X, LEGEND_START_Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "Legend:";
	coord = { LEGEND_START_X, LEGEND_START_Y + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "Arrows - movement, SPACE - ability";
	coord = { LEGEND_START_X, LEGEND_START_Y + 2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	if (cooldown == 0)
	{
		std::cout << "Ability available";
	}
	else if(cooldown > 0)
	{
		std::cout << "Ability active for: " << cooldown;
	}
	else
	{
		std::cout << "Ability on cooldown for: " << -cooldown;
	}
	coord = { LEGEND_START_X + 40, LEGEND_START_Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "H - Human";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "S - Sheep";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "W - Wolf";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 3 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "F - Fox";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "T - Turtle";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 5 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "A - Antelope";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 6 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "C - CyberSheep";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 7 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "G - Grass";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 8 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "D - Dandelion";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 9 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "O - Guarana";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 10 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "B - Belladonna";
	coord = { LEGEND_START_X + 40, LEGEND_START_Y + 11 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	std::cout << "@ - Heracleum Sosnowskyi";
}
