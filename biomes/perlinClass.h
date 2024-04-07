#pragma once
#include "helpers.h"

class perlinClass
{
public:
	perlinClass(uInt32 i_worldWidth, uInt32 i_worldHeight) :m_worldWidth(i_worldWidth), m_worldHeight(i_worldHeight) {};
private:
	uInt32 m_worldWidth; // x-coordinate
	uInt32 m_worldHeight; // y-coordinate
};

