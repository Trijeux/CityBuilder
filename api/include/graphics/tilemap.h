// ReSharper disable IdentifierTypo
#ifndef API_GRAPHICS_TILEMAP_H_
#define API_GRAPHICS_TILEMAP_H_

#include <functional>
#include <SFML/Graphics.hpp>

#include "gameplay/building_manager.h"
#include "graphics/tile.h"

class Player;
class GameText;

class Tilemap final : public sf::Drawable
{

public:
	Tilemap();

	sf::Vector2u playground_size_u_;
	sf::Vector2u playground_tile_offset_u_;

	void Setup(sf::Vector2u playground_size_u);

	void HandleEvent(const sf::Event& event, const sf::RenderWindow& window, sf::View& view);
	
	//void Size_Offset(float);

	void InitMap();

	std::function<void(Tile&)> ClickedTile_;

	sf::Vector2u SpritSize();

	const std::vector<Tile>& tiles();

private:
	std::vector<Tile> tiles_;
	Tile* tileSelected_;
	sf::Vector2u size_sprit_;
	

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // API_GRAPHICS_TILEMAP_H_
