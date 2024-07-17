#ifndef API_GRAPHICS_TILE_H
#define API_GRAPHICS_TILE_H

#include <SFML/Graphics.hpp> // Include SFML graphics library

class Tile final : public sf::Drawable
{
public:
    enum class TileType
    {
        kGround,
        kWood,
        kStone,
        kHome,
        kFarm,
        kOrchard,
        kMine,
        kCastle,
    };

    Tile(TileType type, float x, float y, bool is_walkable); // Constructor for Tile class

    bool Walkable() const { return is_walkable_; } // Method to check if tile is walkable
    sf::Vector2f Position() const { return sprite_.getPosition(); } // Method to get position of the tile
    TileType Type() const { return type_; } // Method to get type of the tile

    void Select(); // Method to select the tile
    void Unselect(); // Method to unselect the tile
    sf::Texture& GetFromType() const; // Method to get texture based on tile type

    void SetTileType(TileType); // Method to set the type of the tile
    void SetTileSprite(); // Method to set the sprite of the tile
    TileType type() const; // Method to get the type of the tile

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // Overridden draw method

private:
    sf::Sprite sprite_; // Sprite representing the visual aspect of the tile
    sf::RectangleShape outline_; // Outline shape for highlighting

    bool is_walkable_; // Flag indicating if the tile is walkable
    bool is_selected_ = false; // Flag indicating if the tile is selected

    TileType type_; // Type of the tile
};

#endif // API_GRAPHICS_TILE_H
