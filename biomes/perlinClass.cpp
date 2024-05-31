#include "perlinClass.h"
#include "SFML/Graphics.hpp"
#include <random>
#include <array>
#include <vector>
#include <cmath>

void perlinClass::createMap(std::vector<sf::RectangleShape>& map)
{
	//set number of divisions per sideLength
	m_numOfHeightDivisions = m_worldHeight / m_cellSize;
	m_numOfWidthDivisions = m_worldWidth / m_cellSize;

	// set up random uniform real distributor
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> uniformRealDistr(-1.0f, 1.0f);
	
	// set up corner vecs
	std::array<float, 2U> upLeftVec;
	std::array<float, 2U> bottomLeftVec;
	std::array<float, 2U> bottomRightVec;
	std::array<float, 2U> upRightVec;

	// Assign random float values to the array elements
	// 2 is the size of each array
	for (int i = 0; i < 2U; ++i)
	{
		upLeftVec[i] = uniformRealDistr(gen);
		bottomLeftVec[i] = uniformRealDistr(gen);
		bottomRightVec[i] = uniformRealDistr(gen);
		upRightVec[i] = uniformRealDistr(gen);
	}

	// parameters for calculate dot product
	float upLeftDotProduct{ 0.0F };
	float bottomLeftDotProduct{ 0.0F };
	float bottomRightDotProduct{ 0.0F };
	float upRightDotProduct{ 0.0F };

	// interpolation parameters
	float upperInterpolation{ 0.0F };
	float lowerInterpolation{ 0.0F };
	float middleInterpolation{ 0.0F };

	// loop through all tiles
	for (size_t i = 0; i < m_worldHeight; i++)
	{
		for (size_t j = 0; j < m_worldWidth; j++)
		{
			float x = static_cast<float>(j) + 0.5f;
			float y = static_cast<float>(i) + 0.5f;
			float height = 0;

			upLeftDotProduct = y * upLeftVec[0U] + (x) * upLeftVec[1U];
			bottomLeftDotProduct = (-static_cast<float>(m_worldHeight) + y) * bottomLeftVec[0U] + x * bottomLeftVec[1U];
			bottomRightDotProduct = (-static_cast<float>(m_worldHeight) + y) * bottomRightVec[0U] + (-static_cast<float>(m_worldWidth) + x) * bottomRightVec[1U];
			upRightDotProduct = y * upRightVec[0U] + (-static_cast<float>(m_worldWidth) + x) * upRightVec[1U];

			//upper column interpolation with smoothstep function 3x^2 - 2x^3
			upperInterpolation = upLeftDotProduct + (3.0F * std::powf(((x/ static_cast<float>(m_worldWidth)) + 0.5F), 2.0F) - 2.0F * std::powf(((x / static_cast<float>(m_worldWidth)) + 0.5F), 3.0F))*(upRightDotProduct-upLeftDotProduct);
			lowerInterpolation = bottomLeftDotProduct + (3.0F * std::powf(((x / static_cast<float>(m_worldWidth)) + 0.5F), 2.0F) - 2.0F * std::powf(((x / static_cast<float>(m_worldWidth)) + 0.5F), 3.0F)) * (bottomRightDotProduct - bottomLeftDotProduct);
			
			//bottom up interpolation
			height = upperInterpolation + (3.0F * std::powf(((x / static_cast<float>(m_worldWidth)) + 0.5F), 2.0F) - 2.0F * std::powf(((x / static_cast<float>(m_worldWidth)) + 0.5F), 3.0F)) * (lowerInterpolation-upperInterpolation);

			sf::RectangleShape cell(sf::Vector2f(1.0, 1.0)); //1.0 is cell size
			cell.setPosition(j * 1.0, i * 1.0); //1.0 is cell size
			if (height <0)
			{
				cell.setFillColor(sf::Color::Blue);
			}
			else if (height < 50)
			{
				cell.setFillColor(sf::Color::Yellow);
			}
			else if(height < 100)
			{
				cell.setFillColor(sf::Color::Green);
			}
			else
			{
				cell.setFillColor(sf::Color::Black);
			}
			map.push_back(cell);
		}
	}
}