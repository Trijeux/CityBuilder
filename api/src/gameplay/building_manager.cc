
#include <iostream>

#include <gameplay/building_manager.h>

#include "gameplay/change_cursor.h"

void BuildingManager::SetActive(bool active)
{
	is_active_ = active;
}
bool BuildingManager::GetActive() const
{
	return is_active_;
}

void BuildingManager::build(sf::RenderWindow& window)
{
	if (GetActive())
	{
		SetActive(false);
		ChangeCursor::BasicCursor(window);
	}
	else
	{
		SetActive(true);
		ChangeCursor::BuildingCursor(window);
	}
}

void BuildingManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& b : buildings_)
	{
		target.draw(b, states);
	}
}

void BuildingManager::ForceBuilding(const Tile& tile)
{
	buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::Home);
}

void BuildingManager::AddBuilding(const Tile& tile, Build building)
{
	if (!is_active_)
	{
		return;
	}

	std::cout << "Tile clicked, can we finally add a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;

	if (tile.Type() == Tile::TileType::Ground)
	{
		switch (building)
		{
		case Build::Home:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::Home);
		}
			break;
		case Build::Ferme:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::Ferme);
		}
		break;
		case Build::Carriere:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::Carriere);
		}
		break;
		case Build::Menuiserie:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::Menuiserie);
		}
		break;
		}
	}
}

