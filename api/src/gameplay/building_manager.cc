
#include <iostream>
#include <random>

#include <gameplay/building_manager.h>

#include "gameplay/change_cursor.h"
#include "graphics/tilemap.h"

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

void BuildingManager::CreatFirstBuildingHome(std::vector<Tile>& tiles, GameRessource* resource_)
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
			resource_->AddBatiment(Build::kHome);
			tiles[mean].set_TileType(Tile::TileType::kHome);
			tiles[mean].set_TileSprite();
			homeNotPlace = false;
		}
	} while (homeNotPlace);
}

void BuildingManager::AddBuilding(Tile& tile, Build building, GameRessource& resource_)
{
	Tile::TileType type;

	if (!is_active_)
	{
		return;
	}

	std::cout << "Tile clicked, can we finally add a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;

	if (tile.Type() == Tile::TileType::kGround)
	{
		//std::cout << &resource_ << std::endl;
		switch (building)
		{
		case Build::kHome:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kHome);
			resource_.AddBatiment(Build::kHome);
			resource_.PayBatiment(Build::kHome);
			type = Tile::TileType::kHome;
		}
		break;
		case Build::kFerme:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kFerme);
			resource_.AddBatiment(Build::kFerme);
			resource_.PayBatiment(Build::kFerme);
			type = Tile::TileType::kFerme;
		}
		break;
		case Build::kVerger:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kVerger);
			resource_.AddBatiment(Build::kVerger);
			resource_.PayBatiment(Build::kVerger);
			type = Tile::TileType::kVerger;
		}
		break;
		case Build::kCarriere:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kCarriere);
			resource_.AddBatiment(Build::kCarriere);
			resource_.PayBatiment(Build::kCarriere);
			type = Tile::TileType::kCarriere;
		}
		break;
		case Build::kChateau:
		{
			buildings_.emplace_back(tile.Position().x, tile.Position().y, Build::kChateau);
			resource_.AddBatiment(Build::kChateau);
			resource_.PayBatiment(Build::kChateau);
			type = Tile::TileType::kChateau;
		}
		break;
		}

		tile.set_TileType(type);
		tile.set_TileSprite();
	}
}

void BuildingManager::SubBuilding(Tile& tile, GameRessource& resource_)
{
	if (!is_active_)
	{
		return;
	}

	std::cout << "Tile clicked, can we finally sub a house ? [" << tile.Position().x << ":" << tile.Position().y << "]" << std::endl;


	if (tile.Type() == Tile::TileType::kHome || tile.Type() == Tile::TileType::kFerme || tile.Type() == Tile::TileType::kVerger
		|| tile.Type() == Tile::TileType::kCarriere || tile.Type() == Tile::TileType::kChateau)
	{
		auto it = std::find_if(buildings_.begin(), buildings_.end(), [&tile](Building& b) {
			return b.Position() == tile.Position(); });

		buildings_.erase(it);
		resource_.SubBatiment(tile.Type());
	}


	tile.set_TileType(Tile::TileType::kGround);
	tile.set_TileSprite();
}

void BuildingManager::ClearMap()
{
	buildings_.clear();
}

