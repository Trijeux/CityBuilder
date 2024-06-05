#include <graphics/Tilemap.h>


void Tilemap::DrawMap(sf::RenderWindow& window)
{
	for (int y = 0; y < TILEMAP_HEIGHT; y++)
	{
		for (int x = 0; x < TILEMAP_WIDTH; x++)
		{
			test_.setSize(sf::Vector2f(50, 50));
			test_.setFillColor(sf::Color::White);
			test_.setOutlineThickness(1);
			test_.setOutlineColor(sf::Color::Black);
			test_.setPosition(x * 50, y * 50);
			window.draw(test_);
		}
	}
}
