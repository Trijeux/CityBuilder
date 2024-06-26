// ReSharper disable IdentifierTypo
#include <iostream>
#include <random>
#include "FastNoiseLite.h"
#include "graphics/Tilemap.h"
#include "graphics/RessourceManager.h"


Tilemap::Tilemap()
{
	size_sprit_ = ResourceManager::Get().GetTexture(ResourceManager::Texture::Ground).getSize();
}

void Tilemap::Setup(sf::Vector2u playground_size_u)
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

void Tilemap::HandleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved) {

		sf::Vector2f mousePosition = sf::Vector2f(
			event.mouseMove.x - event.mouseMove.x % playground_tile_offset_u_.x,
			event.mouseMove.y - event.mouseMove.y % playground_tile_offset_u_.y 
		);


		if (tileSelected_ != nullptr) {
			tileSelected_->Unselect();
		}


		auto tileFound = std::find_if(tiles_.begin(), tiles_.end(), [&mousePosition](Tile& t) {return t.Position() == mousePosition; });
		if (tileFound != tiles_.end()) {
			tileSelected_ = &(*tileFound);
			tileSelected_->Select();
		}

	}


	if (event.type == sf::Event::MouseButtonReleased)
	{

		if (event.mouseButton.button == sf::Mouse::Left) {

			if (ClickedTile && tileSelected_ != nullptr) {
				ClickedTile(*tileSelected_);
			}
			else
			{
				std::cout << "No callback defined...";
			}
		}
	}
}


void Tilemap::InitMap(BuildingManager& building)
{
	tiles_.clear();

	// Générateur de bruit FastNoiseLite
	FastNoiseLite noise;
	noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

	// Échelles pour le bruit
	const float scaleX = 15.0f;
	const float scaleY = 15.0f;

	for (int x = 0; x < playground_size_u_.x; x++)
	{
		for (int y = 0; y < playground_size_u_.y; y++)
		{
			const int idx = x * playground_size_u_.y + y;

			// Générer une valeur de bruit
			const float noiseValue = noise.GetNoise(x * scaleX, y * scaleY);

			sf::Sprite sprite;
			ResourceManager::Texture resource;

			// Utiliser la valeur de bruit pour décider du type de sprite
			if (noiseValue > 0.3f)
			{
				if (noiseValue > 0.6f)
				{
					tiles_.emplace_back(Tile::TileType::Stone,
						x * SpritSize().x, y * SpritSize().y, false);

				}
				else
				{
					tiles_.emplace_back(Tile::TileType::Wood,
						x * SpritSize().x, y * SpritSize().y, false);

				}
			}
			else
			{
				tiles_.emplace_back(Tile::TileType::Ground,
					x * SpritSize().x, y * SpritSize().y, true);
			}
		}
	}

	//std::cout << sprites_.size() / 4 << " /// " << sprites_.size() / 1.2 << std::endl;

	std::random_device r;
	int mean;
	do
	{
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(tiles_.size() / 4, tiles_.size() / 1.2);
		mean = uniform_dist(e1);


		if (tiles_[mean].get_TileType() == Tile::TileType::Ground)
		{
			std::cout << tiles_[mean].Position().x << "//" << tiles_[mean].Position().y;
			
			building.ForceBuilding(tiles_[mean]);
		}
	} while (tiles_[mean].get_TileType() != Tile::TileType::Ground);

	tileSelected_ = nullptr;

}

sf::Vector2u Tilemap::SpritSize()
{
	return size_sprit_;
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//std::cout << tiles_.size() << "//" << tiles_.capacity() << std::endl;
	for (const auto& tile : tiles_)
	{
		target.draw(tile, states);
	}
}