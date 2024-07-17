#include "gameplay/building_manager.h" // Include the header file for BuildingManager

#include <random> // Include for random number generation
#include "gameplay/change_cursor.h" // Include for ChangeCursor class

void BuildingManager::SetActive(const bool active)
{
    is_active_ = active; // Set the active state of the BuildingManager
}

bool BuildingManager::GetActive() const
{
    return is_active_; // Get the current active state of the BuildingManager
}

void BuildingManager::build(sf::RenderWindow& window)
{
    if (GetActive())
    {
        SetActive(false); // Deactivate building mode
        ChangeCursor::BasicCursor(window); // Change cursor to basic mode
    }
    else
    {
        SetActive(true); // Activate building mode
        ChangeCursor::BuildingCursor(window); // Change cursor to building mode
    }
}

void BuildingManager::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
    for (const auto& b : buildings_)
    {
        target.draw(b, states); // Draw each building in the BuildingManager
    }
}

void BuildingManager::CreateFirstBuildingHome(std::vector<Tile>& tiles, GameResource* resource)
{
    bool homeNotPlace = true; // Flag to control the placement loop
    std::random_device r; // Random device for seeding
    std::default_random_engine e1(r()); // Random engine using the random device

    do
    {
        std::uniform_int_distribution<int> uniform_dist(tiles.size() / 4, tiles.size() / 1.2); // Uniform distribution for selecting a tile

        if (const int mean = uniform_dist(e1); tiles[mean].type() == Tile::TileType::kGround)
        {
            // Place the first home building on a randomly selected ground tile
            buildings_.emplace_back(tiles[mean].Position().x, tiles[mean].Position().y, Build::kHome);
            resource->AddBuilding(Build::kHome);
            tiles[mean].SetTileType(Tile::TileType::kHome);
            tiles[mean].SetTileSprite();
            homeNotPlace = false; // Exit the loop after placing the home building
        }
    } while (homeNotPlace);
}

void BuildingManager::AddBuilding(Tile& tile, const Build building, GameResource& resource)
{
    if (!is_active_)
    {
        return; // Exit if building mode is not active
    }

    if (tile.Type() == Tile::TileType::kGround)
    {
        Tile::TileType type;

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

        tile.SetTileType(type); // Set the tile type to the newly added building type
        tile.SetTileSprite(); // Set the tile sprite to match the building type
    }
}

void BuildingManager::SubBuilding(Tile& tile, GameResource& resource)
{
    if (!is_active_)
    {
        return; // Exit if building mode is not active
    }

    // Check if the tile contains a building that can be removed
    if (tile.Type() == Tile::TileType::kHome || tile.Type() == Tile::TileType::kFarm || tile.Type() == Tile::TileType::kOrchard
        || tile.Type() == Tile::TileType::kMine || tile.Type() == Tile::TileType::kCastle)
    {
        // Find the building in the list of buildings and remove it
        const auto it = std::ranges::find_if(buildings_, [&tile](Building& b) {
            return b.Position() == tile.Position(); });

        buildings_.erase(it); // Erase the building from the list
        resource.SubBuilding(tile.Type()); // Subtract the building type from the resources
    }

    tile.SetTileType(Tile::TileType::kGround); // Set the tile type back to ground
    tile.SetTileSprite(); // Set the tile sprite to match the ground type
}

void BuildingManager::ClearMap()
{
    buildings_.clear(); // Clear all buildings from the map
}
