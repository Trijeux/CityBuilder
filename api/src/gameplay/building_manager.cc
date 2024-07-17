#include "gameplay/building_manager.h"

#include <iostream>
#include <random>

#include "gameplay/change_cursor.h"


void BuildingManager::SetActive(const bool active)
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


void BuildingManager::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	for (const auto& b : buildings_)
	{
		target.draw(b, states);
	}
}

void BuildingManager::CreateFirstBuildingHome(std::vector<Tile>& tiles, GameResource* resource)
{
	bool homeNotPlace = true;
	std::random_device r;
	std::default_random_engine e1(r());
	int mean = 0;
	do
	{
		std::uniform_int_distribution<int> uniform_dist(tiles.size() / 4, tiles.size() / 1.2);
		mean = uniform_dist(e1);

		if (tiles[mean].type() == Tile::TileType::kGround)
		{
			buildings_.emplace_back(tiles[mean].Position().x, tiles[mean].Position().y, Build::kHome);
			resource->AddBuilding(Build::kHome);
			tiles[mean].SetTileType(Tile::TileType::kHome);
			tiles[mean].SetTileSprite();
			homeNotPlace = false;
		}
	} while (homeNotPlace);
}

void BuildingManager::AddBuilding(Tile& tile, const Build building, GameResource& resource)
{
	if (!is_active_)
	{
		return;
	}

	std::cout << "Tile clicked, can we finally add a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;

	if (tile.Type() == Tile::TileType::kGround)
	{
		Tile::TileType type;
		//std::cout << &resource_ << std::endl;
		switch (building)
		{
		case Build::kHome:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kHome);
			resource.AddBuilding(Build::kHome);
			resource.PayBuilding(Build::kHome);
			type = Tile::TileType::kHome;
		}
		break;
		case Build::kFarm:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kFarm);
			resource.AddBuilding(Build::kFarm);
			resource.PayBuilding(Build::kFarm);
			type = Tile::TileType::kFarm;
		}
		break;
		case Build::kOrchard:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kOrchard);
			resource.AddBuilding(Build::kOrchard);
			resource.PayBuilding(Build::kOrchard);
			type = Tile::TileType::kOrchard;
		}
		break;
		case Build::kMine:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kMine);
			resource.AddBuilding(Build::kMine);
			resource.PayBuilding(Build::kMine);
			type = Tile::TileType::kMine;
		}
		break;
		case Build::kCastle:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kCastle);
			resource.AddBuilding(Build::kCastle);
			resource.PayBuilding(Build::kCastle);
			type = Tile::TileType::kCastle;
		}
		break;
		}

		tile.SetTileType(type);
		tile.SetTileSprite();
	}
}

void BuildingManager::SubBuilding(Tile& tile, GameResource& resource)
{
	if (!is_active_)
	{
		return;
	}

	std::cout << "Tile clicked, can we finally sub a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;


	if (tile.Type() == Tile::TileType::kHome || tile.Type() == Tile::TileType::kFarm || tile.Type() == Tile::TileType::kOrchard
		|| tile.Type() == Tile::TileType::kMine || tile.Type() == Tile::TileType::kCastle)
	{
		const auto it = std::ranges::find_if(buildings_, [&tile](Building& b) {
			return b.Position() == tile.Position(); });

		buildings_.erase(it);
		resource.SubBuilding(tile.Type());
	}


	tile.SetTileType(Tile::TileType::kGround);
	tile.SetTileSprite();
}

void BuildingManager::ClearMap()
{
	buildings_.clear();
}

