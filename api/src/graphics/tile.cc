#include "graphics/tile.h"

#include "graphics/ressource_manager.h"


Tile::Tile(const TileType type, const float x = 0, const float y = 0, const bool is_walkable = true)
{

	type_ = type;

	sprite_.setTexture(GetFromType());
	sprite_.setPosition(x, y);

	outline_.setSize(sf::Vector2f(sprite_.getTexture()->getSize()));
	outline_.setPosition(x, y);
	outline_.setFillColor(sf::Color(255, 255, 255, 0));
	outline_.setOutlineColor(sf::Color::White);
	outline_.setOutlineThickness(-1);

	is_walkable_ = is_walkable;
}

void Tile::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	target.draw(sprite_, states);

	if (is_selected_) {
		//std::cout << "draw selected tile [" << outline_.getPosition().x << ":" << outline_.getPosition().y << "]" << std::endl;
		target.draw(outline_, states);
	}
}

void Tile::Select()
{
	is_selected_ = true;
}
void Tile::Unselect()
{
	is_selected_ = false;
}

sf::Texture& Tile::GetFromType() const
{
	switch (type_)
	{
	case TileType::kWood:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kWood);
		break;

	case TileType::kGround:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGround);
		break;

	case TileType::kStone:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kStone);
		break;

	case TileType::kHome:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundToOccupy);
		break;

	case TileType::kFarm:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundToOccupy);
		break;

	case TileType::kOrchard:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundToOccupy);
		break;

	case TileType::kMine:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundToOccupy);
		break;
	case TileType::kCastle:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundToOccupy);
		break;
	default: 
		return { ResourceManager::Get().GetTexture(ResourceManager::Texture::kMax) };
		break;
	}
}


void Tile::SetTileType(const TileType type)
{
	type_ = type;
}

void Tile::SetTileSprite()
{
	sprite_.setTexture(GetFromType());
}

Tile::TileType Tile::type() const
{
	return type_;
}
