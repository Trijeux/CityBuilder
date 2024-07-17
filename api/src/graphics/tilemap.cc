#include "graphics/tilemap.h"

#include <iostream>
#include <random>
#include <SFML/Graphics/Sprite.hpp>

#include "FastNoiseLite.h"
#include "graphics/ressource_manager.h"


Tilemap::Tilemap(): tile_selected_(nullptr)
{
	size_sprit_ = ResourceManager::Get().GetTexture(ResourceManager::Texture::kGround).getSize();
}

void Tilemap::Setup(const sf::Vector2u playground_size_u)
{
	playground_size_u_ = playground_size_u;
	//sprites_.reserve(playground_size_u_.x * playground_size_u_.y);
	playground_tile_offset_u_.x = size_sprit_.x;
	playground_tile_offset_u_.y = size_sprit_.y;
}

//void Tilemap::Size_Offset(float size_zoom)
//{
//	//playground_tile_offset_u_.x = playground_size_u_.x / (size_sprit_.x * size_zoom);
//	//playground_tile_offset_u_.y = playground_size_u_.y / (size_sprit_.y * size_zoom);
//}

void Tilemap::HandleEvent(const sf::Event& event, const sf::RenderWindow& window, const sf::View& view)
{
	if (event.type == sf::Event::MouseMoved)
	{
		// Convertir la position de la souris en coordonnées du monde
		const sf::Vector2f mouse_world_position = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);

		// Ajuster la position de la souris en fonction de la taille des tuiles
		auto adjusted_mouse_position = sf::Vector2f(
			std::round(mouse_world_position.x / playground_tile_offset_u_.x) * playground_tile_offset_u_.x,
			std::round(mouse_world_position.y / playground_tile_offset_u_.y) * playground_tile_offset_u_.y
		);

		/*std::cout << "Mouse Window Position: (" << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << ")\n";
		std::cout << "Mouse World Position: (" << mouseWorldPosition.x << ", " << mouseWorldPosition.y << ")\n";
		std::cout << "Adjusted Mouse Position: (" << adjustedMousePosition.x << ", " << adjustedMousePosition.y << ")\n";*/

		if (tile_selected_ != nullptr)
		{
			tile_selected_->Unselect();
		}

		if (const auto tile_found = std::ranges::find_if(tiles_, [&adjusted_mouse_position](const Tile& t) {
			return t.Position() == adjusted_mouse_position;
		}); tile_found != tiles_.end())
		{
			tile_selected_ = &(*tile_found);
			tile_selected_->Select();
		}
	}


	if (event.type == sf::Event::MouseButtonReleased)
	{

		if (event.mouseButton.button == sf::Mouse::Left) {

			if (clicked_tile_ && tile_selected_ != nullptr) {
				clicked_tile_(*tile_selected_);
			}
			else
			{
				std::cout << "No callback defined...";
			}
		}
	}
}


void Tilemap::InitMap()
{
	tiles_.clear();

	// FastNoiseLite noise generator
	FastNoiseLite noise;
	noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

	// Noise scales

	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(8.0f, 20.0f);
	const int mean = uniform_dist(e1);
	std::uniform_int_distribution<int> uniform_dist2(8.0f, 20.0f);
	const int mean2 = uniform_dist2(e1);
	

	const float scale_x = mean;
	const float scale_y = mean2;

	for (int x = 0; x < playground_size_u_.x; x++)
	{
		for (int y = 0; y < playground_size_u_.y; y++)
		{
			const int idx = x * playground_size_u_.y + y;

			// Generate a noise value
			
			const float noise_value = noise.GetNoise(x * scale_x, y * scale_y);

			sf::Sprite sprite;
			ResourceManager::Texture resource;

			// Use noise value to decide sprite type
			if (noise_value > 0.3f)
			{
				if (noise_value > 0.6f)
				{
					tiles_.emplace_back(Tile::TileType::kStone,
						x * SpritSize().x, y * SpritSize().y, false);

				}
				else
				{
					tiles_.emplace_back(Tile::TileType::kWood,
						x * SpritSize().x, y * SpritSize().y, false);

				}
			}
			else
			{
				tiles_.emplace_back(Tile::TileType::kGround,
					x * SpritSize().x, y * SpritSize().y, true);
			}
		}
	}

	//std::cout << sprites_.size() / 4 << " /// " << sprites_.size() / 1.2 << std::endl;


	tile_selected_ = nullptr;

}

sf::Vector2u Tilemap::SpritSize() const
{
	return size_sprit_;
}

std::vector<Tile>& Tilemap::tiles()
{
	return tiles_;
}


void Tilemap::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	//std::cout << tiles_.size() << "//" << tiles_.capacity() << std::endl;
	for (const auto& tile : tiles_)
	{
		target.draw(tile, states);
	}
}
