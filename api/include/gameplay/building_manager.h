#ifndef BUILDING_MANAGER_H
#define BUILDING_MANAGER_H

#include <vector>
#include "game_ressource.h"
#include "graphics/tile.h"
#include "building.h" // Assuming Building class is defined in "building.h"

class BuildingManager final : public sf::Drawable
{
private:
    bool is_active_ = false; // Flag indicating if the building manager is active

    std::vector<Building> buildings_; // Vector to store instances of Building

    // Private methods
    void SetActive(bool active); // Method to set the activity status of the manager
    [[nodiscard]] bool GetActive() const; // Method to retrieve the activity status of the manager

public:
    // Public methods

    // Method to add a new building to a tile using game resources
    void AddBuilding(Tile& tile, Build build, GameResource& resource);

    // Method to remove a building from a tile using game resources
    void SubBuilding(Tile& tile, GameResource& resource);

    // Method to clear all buildings from the manager
    void ClearMap();

    // Method to create the first building (presumably a home) on a vector of tiles using game resources
    void CreateFirstBuildingHome(std::vector<Tile>& tiles, GameResource* resource);

    // Method to build/render all buildings managed by this manager
    void build(sf::RenderWindow& window);

protected:
    // Overridden method from sf::Drawable to draw all buildings managed by this manager
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // BUILDING_MANAGER_H
