#pragma once
#include "helpers.h"
#include <vector>
#include <array>
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

	// methods

	// this method sets the m_divisionForWidth & m_divisionForHeight vectors
	
};

