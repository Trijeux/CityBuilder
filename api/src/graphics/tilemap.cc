#include "graphics/tilemap.h"  // Include the Tilemap header file

#include <random>  // Include for random number generation
#include <SFML/Graphics/Sprite.hpp>  // Include for SFML Sprite
#include "FastNoiseLite.h"  // Include for FastNoiseLite noise generation
#include "graphics/ressource_manager.h"  // Include the ResourceManager header file


// Constructor for Tilemap class
Tilemap::Tilemap() : tile_selected_(nullptr)
{
    size_sprit_ = ResourceManager::Get().GetTexture(ResourceManager::Texture::kGround).getSize();  // Get size of ground texture from ResourceManager
}

// Setup function to initialize the Tilemap
void Tilemap::Setup(const sf::Vector2u playground_size_u)
{
    playground_size_u_ = playground_size_u;  // Set the size of the playground
    playground_tile_offset_u_.x = size_sprit_.x;  // Set the tile offset in x direction based on sprite size
    playground_tile_offset_u_.y = size_sprit_.y;  // Set the tile offset in y direction based on sprite size
}

// Event handling function for Tilemap
void Tilemap::HandleEvent(const sf::Event& event, const sf::RenderWindow& window, const sf::View& view)
{
    if (event.type == sf::Event::MouseMoved)
    {
        // Convert mouse position to world coordinates
        const sf::Vector2f mouse_world_position = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);

        // Adjust mouse position based on tile size
        auto adjusted_mouse_position = sf::Vector2f(
            std::round(mouse_world_position.x / playground_tile_offset_u_.x) * playground_tile_offset_u_.x,
            std::round(mouse_world_position.y / playground_tile_offset_u_.y) * playground_tile_offset_u_.y
        );

        // Unselect previously selected tile
        if (tile_selected_ != nullptr)
        {
            tile_selected_->Unselect();
        }

        // Find the tile under the adjusted mouse position
        if (const auto tile_found = std::ranges::find_if(tiles_, [&adjusted_mouse_position](const Tile& t) {
            return t.Position() == adjusted_mouse_position;
            }); tile_found != tiles_.end())
        {
            tile_selected_ = &(*tile_found);  // Select the found tile
            tile_selected_->Select();
        }
    }

    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (clicked_tile_ && tile_selected_ != nullptr)
            {
                clicked_tile_(*tile_selected_);  // Handle click on the selected tile
            }
        }
    }
}

// Function to initialize the map based on noise generation
void Tilemap::InitMap()
{
    tiles_.clear();  // Clear existing tiles

    // FastNoiseLite noise generator
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

    // Random number generation for noise scales
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(8.0f, 20.0f);
    const int mean = uniform_dist(e1);
    std::uniform_int_distribution<int> uniform_dist2(8.0f, 20.0f);
    const int mean2 = uniform_dist2(e1);

    const float scale_x = mean;
    const float scale_y = mean2;

    // Loop through the playground size to create tiles based on noise values
    for (int x = 0; x < playground_size_u_.x; x++)
    {
        for (int y = 0; y < playground_size_u_.y; y++)
        {
            // Generate a noise value
            const float noise_value = noise.GetNoise(x * scale_x, y * scale_y);

            // Create tiles based on noise value
            if (noise_value > 0.3f)
            {
                if (noise_value > 0.6f)
                {
                    tiles_.emplace_back(Tile::TileType::kStone,
                        x * SpritSize().x, y * SpritSize().y, false);  // Create stone tile
                }
                else
                {
                    tiles_.emplace_back(Tile::TileType::kWood,
                        x * SpritSize().x, y * SpritSize().y, false);  // Create wood tile
                }
            }
            else
            {
                tiles_.emplace_back(Tile::TileType::kGround,
                    x * SpritSize().x, y * SpritSize().y, true);  // Create ground tile
            }
        }
    }

    tile_selected_ = nullptr;  // Reset selected tile pointer
}

// Get the sprite size of the tiles
sf::Vector2u Tilemap::SpritSize() const
{
    return size_sprit_;
}

// Get a reference to the vector of tiles
std::vector<Tile>& Tilemap::tiles()
{
    return tiles_;
}

// Draw function to render the Tilemap
void Tilemap::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
    for (const auto& tile : tiles_)
    {
        target.draw(tile, states);  // Draw each tile
    }
}
