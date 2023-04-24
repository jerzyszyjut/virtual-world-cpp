#pragma once
#include <conio.h>
#include <vector>
#include <string>

class Renderer
{
public:
	Renderer(int mapWidth, int mapHeight);

	void render(int cooldown, int cameraPositionX, int cameraPositionY);
	void addLog(std::string log);
	void addMapElement(int x, int y, char c);
	void clearMap();
	void clearLogs();

private:
	void renderAutor();
	void renderLogs();
	void renderMap(int cameraPositionX, int cameraPositionY);
	void renderBorder();
	void renderLegend(int cooldown);

	int m_mapWidth, m_mapHeight;
	std::vector<std::vector<char>> m_map;
	std::vector<std::string> m_logs;
};

