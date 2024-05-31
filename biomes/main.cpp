#include <iostream>
#include "SFML/Graphics.hpp"
#include "perlinClass.h"
#include "helpers.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(500, 500), "Test Window");
    sf::Event e;

    uInt32 worldWidth = 500;
    uInt32 worldHeright = 500;
    uInt32 cellSize = 10;
    perlinClass perlinObj(worldWidth, worldHeright, cellSize);
	std::vector<sf::RectangleShape> map;
	perlinObj.createMap(map);
	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::White);
		// Draw the stored rectangles
		for (const auto& cell : map)
		{
			window.draw(cell);
		}
		window.display();
	}

	return 0;
}