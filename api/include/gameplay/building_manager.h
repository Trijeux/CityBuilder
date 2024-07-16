#ifndef BUILDING_MANAGER_H_
#define BUILDING_MANAGER_H_

#include <graphics/Tile.h>
#include "Building.h"
#include "game_ressource.h"


class Tilemap;

class BuildingManager : public sf::Drawable
{
private:
	bool is_active_ = false;

	std::vector<Building> buildings_;

	void SetActive(bool active);
	bool GetActive() const;

public :
	void AddBuilding (Tile& tile, Build build, ResourceGame* resource_);
	void SubBuilding(Tile& tile, ResourceGame* resource_);

	void ClearMap();

	void CreatFirstBuildingHome(std::vector<Tile>& tiles, ResourceGame* resource_);

	void build(sf::RenderWindow& window);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif // BUILDING_MANAGER_H_
