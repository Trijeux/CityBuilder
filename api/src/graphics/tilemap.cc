// ReSharper disable IdentifierTypo
#include <iostream>
#include <graphics/Tilemap.h>

Tilemap::Tilemap()
{
	sprites_.reserve(TILEMAP_WIDTH * TILEMAP_HEIGHT);
	sprite_.setTexture(texture_);
	texture_.loadFromFile("ressources/tile/Wood.png");
	InitMap();
}


void Tilemap::InitMap()
{
	sprites_.clear();
	for (int x = 0; x < TILEMAP_WIDTH; x++)
	{
		for (int y = 0; y < TILEMAP_HEIGHT; y++)
		{
			const int idx = x * TILEMAP_HEIGHT + y;
			sprites_.emplace_back();
			sprites_[idx].setTexture(texture_);
			sprites_[idx].setPosition(x * sprite_.getTexture()->getSize().x, y * sprite_.getTexture()->getSize().y);
			sprites_[idx].setScale(1.0f, 1.0f);
		}
	}
}

void Tilemap::DrawMap(sf::RenderWindow& window)
{
	for (auto truc : sprites_)
		window.draw(truc);
}

sf::Vector2u Tilemap::SizeSprite()
{
	return sprite_.getTexture()->getSize();
}
