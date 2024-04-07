#pragma once
#include "helpers.h"
#include <vector>
#include "SFML/Graphics.hpp"

class perlinClass
{
public:
	perlinClass(uInt32 i_worldWidth, uInt32 i_worldHeight) :m_worldWidth(i_worldWidth), m_worldHeight(i_worldHeight) {};
	// this methods calls all functions to create the perlin map and returns the map to the main
	void createMap(sf::RenderWindow& window);
private:
	// variables and parameters
	uInt32 m_worldWidth; // x-coordinate
	uInt32 m_worldHeight; // y-coordinate
	std::vector<uInt32> m_divisionForWidth; //m_divisionForWidth[0] = largest division (half, third or fifth of total width or nest possible), m_divisionForWidth[1] = division of division (half, third or fifth of 1st division)...
	std::vector<uInt32> m_divisionForHeight; // ... and so on

	// methods

	// this method sets the m_divisionForWidth & m_divisionForHeight vectors
	void m_setDivisors();
};

