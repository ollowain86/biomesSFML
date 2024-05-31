#pragma once
#include "helpers.h"
#include <vector>
#include <array>
#include "SFML/Graphics.hpp"

class perlinClass
{
public:
	perlinClass(uInt32 i_worldWidth, uInt32 i_worldHeight, uInt32 i_cellSize) :m_worldWidth(i_worldWidth), m_worldHeight(i_worldHeight), m_cellSize(i_cellSize), m_physicalMap(i_worldHeight, std::vector<float>(i_worldWidth)) {};
	// this methods calls all functions to create the perlin map and returns the map to the main
	void createMap(std::vector<sf::RectangleShape>& map);
private:
	// variables and parameters
	uInt32 m_worldWidth{ 0U }; // x-coordinate
	uInt32 m_worldHeight{ 0U }; // y-coordinate
	std::vector<std::vector<float>> m_physicalMap;
	uInt32 m_cellSize{ 0U }; // cell sidelength
	uInt32 m_numOfWidthDivisions{ 0U }; // number of divisions for width
	uInt32 m_numOfHeightDivisions{ 0U }; // number of divisions for height
	// methods
};

