#include "graphics/Tile.h"
#include <iostream>

Tile::Tile(TileType type, float x = 0, float y = 0, bool is_walkable = true)
{

	type_ = type;

	sprite_.setTexture(GetFromType());
	sprite_.setPosition(x, y);

	outline.setSize(sf::Vector2f(sprite_.getTexture()->getSize()));
	outline.setPosition(x, y);
	outline.setFillColor(sf::Color(255, 255, 255, 0));
	outline.setOutlineColor(sf::Color::White);
	outline.setOutlineThickness(-1);

	isWalkable_ = is_walkable;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_, states);

	if (isSelected_) {
		//std::cout << "draw selected tile [" << outline_.getPosition().x << ":" << outline_.getPosition().y << "]" << std::endl;
		target.draw(outline, states);
	}
}

void Tile::Select()
{
	isSelected_ = true;
}
void Tile::Unselect()
{
	isSelected_ = false;
}

sf::Texture& Tile::GetFromType()
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
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundOcup);
		break;

	case TileType::kFerme:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundOcup);
		break;

	case TileType::kVerger:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundOcup);
		break;

	case TileType::kCarriere:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundOcup);
		break;
	case TileType::kChateau:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::kGroundOcup);
		break;
	}
}



void Tile::set_TileType(TileType type)
{
	type_ = type;
}

void Tile::set_TileSprite()
{
	sprite_.setTexture(GetFromType());
}

Tile::TileType Tile::type() const
{
	return type_;
}
