
#include <iostream>
#include <random>

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

void BuildingManager::CreatFirstBuildingHome(const std::vector<Tile>& tiles)
{

	std::random_device r;
	std::default_random_engine e1(r());
	int mean;
	do
	{
		std::uniform_int_distribution<int> uniform_dist(tiles.size() / 4, tiles.size() / 1.2);
		mean = uniform_dist(e1);

		if (tiles[mean].type() == Tile::TileType::kGround)
		{
			buildings_.emplace_back(tiles[mean].Position().x, tiles[mean].Position().y, Build::kHome);
		}
	} while (tiles[mean].type() != Tile::TileType::kGround);
}

void BuildingManager::AddBuilding(const Tile& tile, Build building)
{
	if (!is_active_)
	{
		return;
	}

	std::cout << "Tile clicked, can we finally add a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;

	if (tile.Type() == Tile::TileType::kGround)
	{
		switch (building)
		{
		case Build::kHome:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kHome);
		}
			break;
		case Build::kFerme:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kFerme);
		}
		break;
		case Build::kCarriere:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kCarriere);
		}
		break;
		case Build::kMenuiserie:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kMenuiserie);
		}
		break;
		}
	}
}

void BuildingManager::ClearMap()
{
	buildings_.clear();
}

