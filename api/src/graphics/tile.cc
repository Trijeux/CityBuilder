#include "graphics/tile.h"  // Include the Tile header file

#include "graphics/ressource_manager.h"  // Include the ResourceManager header file


// Constructor for Tile class
Tile::Tile(const TileType type, const float x /*= 0*/, const float y /*= 0*/, const bool is_walkable /*= true*/)
{
    type_ = type;  // Initialize the Tile type

    sprite_.setTexture(GetFromType());  // Set the sprite's texture based on the Tile type
    sprite_.setPosition(x, y);  // Set the position of the sprite

    // Set up the outline of the tile
    outline_.setSize(sf::Vector2f(sprite_.getTexture()->getSize()));
    outline_.setPosition(x, y);
    outline_.setFillColor(sf::Color(255, 255, 255, 0));  // Transparent fill color
    outline_.setOutlineColor(sf::Color::White);  // White outline color
    outline_.setOutlineThickness(-1);  // Outline thickness

    is_walkable_ = is_walkable;  // Set whether the tile is walkable or not
}

// Function to draw the Tile on the render target
void Tile::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
    target.draw(sprite_, states);  // Draw the main sprite

    if (is_selected_) {
        target.draw(outline_, states);  // Draw the outline if the tile is selected
    }
}

// Select the tile (show outline)
void Tile::Select()
{
    is_selected_ = true;
}

// Unselect the tile (hide outline)
void Tile::Unselect()
{
    is_selected_ = false;
}

// Get the texture based on the TileType
sf::Texture& Tile::GetFromType() const
{
    switch (type_)
    {
    case TileType::kWood:
        return ResourceManager::Get().GetTexture(ResourceManager::Texture::kWood);
    case TileType::kGround:
        return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGround);
    case TileType::kStone:
        return ResourceManager::Get().GetTexture(ResourceManager::Texture::kStone);
    case TileType::kHome:
    case TileType::kFarm:
    case TileType::kOrchard:
    case TileType::kMine:
    case TileType::kCastle:
        return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundToOccupy);
    default:
        return ResourceManager::Get().GetTexture(ResourceManager::Texture::kMax);  // Return default texture for unknown types
    }
}

// Set the TileType of the tile
void Tile::SetTileType(const TileType type)
{
    type_ = type;
}

// Update the sprite's texture based on the TileType
void Tile::SetTileSprite()
{
    sprite_.setTexture(GetFromType());
}

// Get the current TileType of the tile
Tile::TileType Tile::type() const
{
    return type_;
}
