#include <iostream>
#include "SFML/Graphics.hpp"

const int CELL_SIZE = 50;

void drawMatrix(sf::RenderWindow& window, const std::vector<std::vector<int>>& matrix)
{
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
            cell.setOutlineColor(sf::Color::Black);
            cell.setOutlineThickness(1.f);

            switch (matrix[i][j]) {
            case 0:
                cell.setFillColor(sf::Color::White);
                break;
            case 1:
                cell.setFillColor(sf::Color::Red);
                break;
            case 2:
                cell.setFillColor(sf::Color::Green);
                break;
                // Add more cases as needed
            default:
                cell.setFillColor(sf::Color::Blue);
            }

            window.draw(cell);
        }
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 0, 0},
        {3, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

	sf::RenderWindow window(sf::VideoMode(800,600), "Test Window");
	sf::Event e;

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
        drawMatrix(window, matrix);
        window.display();
	}

	return 0;
}