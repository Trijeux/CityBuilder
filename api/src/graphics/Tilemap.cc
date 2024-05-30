#include <graphics/Tilemap.h>


void Tilemap::DrawMap(sf::RenderWindow& window)
{
	for (int y = 0; y < TILEMAP_HEIGHT; y++)
	{
		for (int x = 0; x < TILEMAP_WIDTH; x++)
		{
			test.setSize(sf::Vector2f(50, 50));
			test.setFillColor(sf::Color::White);
			test.setOutlineThickness(1);
			test.setOutlineColor(sf::Color::Black);
			test.setPosition(x * 50, y * 50);
			window.draw(test);
		}
	}
}