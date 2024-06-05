#ifndef API_GRAPHICS_TILEMAP_H_
#define API_GRAPHICS_TILEMAP_H_

#include <SFML/Graphics.hpp>

#define TILEMAP_WIDTH 5
#define TILEMAP_HEIGHT 5

class Player;
class GameText;

class Tilemap
{
public:

	sf::RectangleShape test_;

	void DrawMap(sf::RenderWindow& window);

private:
};



#endif // API_GRAPHICS_TILEMAP_H_