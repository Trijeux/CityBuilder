// ReSharper disable IdentifierTypo
#ifndef API_GRAPHICS_TILEMAP_H
#define API_GRAPHICS_TILEMAP_H

#include <functional>
#include <SFML/Graphics.hpp>

#include "tile.h"


class Tilemap final : public sf::Drawable
{

public:
	Tilemap();

	sf::Vector2u playground_size_u_;
	sf::Vector2u playground_tile_offset_u_;

	void Setup(sf::Vector2u playground_size_u);

	void HandleEvent(const sf::Event& event, const sf::RenderWindow& window, const sf::View& view);

	void InitMap();

	std::function<void(Tile&)> clicked_tile_;

	[[nodiscard]] sf::Vector2u SpritSize() const;

	std::vector<Tile>& tiles();

	[[nodiscard]] sf::Vector2u SizeU() const { return playground_size_u_; }

private:
	std::vector<Tile> tiles_;
	Tile* tile_selected_;
	sf::Vector2u size_sprit_;
	

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // API_GRAPHICS_TILEMAP_H
