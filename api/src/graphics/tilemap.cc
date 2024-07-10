// ReSharper disable IdentifierTypo
#include <iostream>
#include <random>

#include "FastNoiseLite.h"
#include "graphics/Tilemap.h"
#include "graphics/RessourceManager.h"


Tilemap::Tilemap()
{
	size_sprit_ = ResourceManager::Get().GetTexture(ResourceManager::Texture::kGround).getSize();
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

void Tilemap::HandleEvent(const sf::Event& event, const sf::RenderWindow& window, sf::View& view)
{
	if (event.type == sf::Event::MouseMoved)
	{
		// Convertir la position de la souris en coordonnées du monde
		sf::Vector2f mouseWorldPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);

		// Ajuster la position de la souris en fonction de la taille des tuiles
		sf::Vector2f adjustedMousePosition = sf::Vector2f(
			std::round(mouseWorldPosition.x / playground_tile_offset_u_.x) * playground_tile_offset_u_.x,
			std::round(mouseWorldPosition.y / playground_tile_offset_u_.y) * playground_tile_offset_u_.y
		);

		/*std::cout << "Mouse Window Position: (" << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << ")\n";
		std::cout << "Mouse World Position: (" << mouseWorldPosition.x << ", " << mouseWorldPosition.y << ")\n";
		std::cout << "Adjusted Mouse Position: (" << adjustedMousePosition.x << ", " << adjustedMousePosition.y << ")\n";*/

		if (tileSelected_ != nullptr)
		{
			tileSelected_->Unselect();
		}

		auto tileFound = std::find_if(tiles_.begin(), tiles_.end(), [&adjustedMousePosition](Tile& t) {
			return t.Position() == adjustedMousePosition;
			});
		if (tileFound != tiles_.end())
		{
			tileSelected_ = &(*tileFound);
			tileSelected_->Select();
		}
	}


	if (event.type == sf::Event::MouseButtonReleased)
	{

		if (event.mouseButton.button == sf::Mouse::Left) {

			if (ClickedTile_ && tileSelected_ != nullptr) {
				ClickedTile_(*tileSelected_);
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

	// Générateur de bruit FastNoiseLite
	FastNoiseLite noise;
	noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

	// Échelles pour le bruit
	
	int mean;
	int mean2;

	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(8.0f, 20.0f);
	mean = uniform_dist(e1);
	std::uniform_int_distribution<int> uniform_dist2(8.0f, 20.0f);
	mean2 = uniform_dist2(e1);
	

	const float scaleX = mean;
	const float scaleY = mean2;

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


	tileSelected_ = nullptr;

}

sf::Vector2u Tilemap::SpritSize()
{
	return size_sprit_;
}

const std::vector<Tile>& Tilemap::tiles()
{
	return tiles_;
}


void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//std::cout << tiles_.size() << "//" << tiles_.capacity() << std::endl;
	for (const auto& tile : tiles_)
	{
		target.draw(tile, states);
	}

	//for (auto& tile : tiles_)
	//{
	//	target.draw(tile, states);

	//	// Dessiner les positions de débogage
	//	sf::RectangleShape debugRect;
	//	debugRect.setSize(sf::Vector2f(playground_tile_offset_u_.x, playground_tile_offset_u_.y));
	//	debugRect.setPosition(tile.Position());
	//	debugRect.setFillColor(sf::Color::Transparent);
	//	debugRect.setOutlineColor(sf::Color::Red);
	//	debugRect.setOutlineThickness(1.0f);

	//	target.draw(debugRect, states);
	//}
}
