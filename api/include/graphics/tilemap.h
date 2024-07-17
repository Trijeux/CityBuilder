// ReSharper disable IdentifierTypo
#ifndef API_GRAPHICS_TILEMAP_H
#define API_GRAPHICS_TILEMAP_H

#include <functional> // Include for std::function
#include <SFML/Graphics.hpp> // Include SFML graphics library

#include "tile.h" // Include Tile class header

class Tilemap final : public sf::Drawable
{
public:
    Tilemap(); // Constructor

    sf::Vector2u playground_size_u_; // Size of the playground in unsigned integer vector
    sf::Vector2u playground_tile_offset_u_; // Offset of tiles in the playground in unsigned integer vector

    void Setup(sf::Vector2u playground_size_u); // Method to set up the playground size

    void HandleEvent(const sf::Event& event, const sf::RenderWindow& window, const sf::View& view); // Method to handle SFML events

    void InitMap(); // Method to initialize the tile map

    std::function<void(Tile&)> clicked_tile_; // Callback function for when a tile is clicked

    [[nodiscard]] sf::Vector2u SpritSize() const; // Method to retrieve the sprite size

    std::vector<Tile>& tiles(); // Method to retrieve the vector of tiles

    [[nodiscard]] sf::Vector2u SizeU() const { return playground_size_u_; } // Method to retrieve the size of the playground

private:
    std::vector<Tile> tiles_; // Vector to store tiles
    Tile* tile_selected_; // Pointer to the currently selected tile
    sf::Vector2u size_sprit_; // Size of the sprite

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // Overridden draw method from sf::Drawable
};

#endif // API_GRAPHICS_TILEMAP_H
