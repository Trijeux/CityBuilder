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
	case TileType::Wood:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::Wood);
		break;

	case TileType::Ground:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::Ground);
		break;

	case TileType::Stone:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::Stone);
		break;

	case TileType::Home:
		return ResourceManager::Get().GetTexture(ResourceManager::Texture::Home);
		break;
	}



}

void Tile::set_TileType(TileType type)
{
	type_ = type;
}

Tile::TileType Tile::get_TileType()
{
	return type_;
}
