// ReSharper disable IdentifierTypo
#ifndef API_GRAPHICS_TILEMAP_H_
#define API_GRAPHICS_TILEMAP_H_

#include <SFML/Graphics.hpp>

#define TILEMAP_WIDTH 150
#define TILEMAP_HEIGHT 100

class Player;
class GameText;

class Tilemap
{
public:

	Tilemap();
	void InitMap();
	void DrawMap(sf::RenderWindow& window);
	sf::Vector2u SizeSprite();

private:

	sf::Texture texture_;
	sf::Sprite sprite_;
	sf::Sprite sprite_test_;

	std::vector<sf::Sprite> sprites_;
};



#endif // API_GRAPHICS_TILEMAP_H_
