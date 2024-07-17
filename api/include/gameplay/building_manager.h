#ifndef BUILDING_MANAGER_H
#define BUILDING_MANAGER_H

#include <vector>
#include "game_ressource.h"
#include "graphics/tile.h"


class BuildingManager final : public sf::Drawable
{
private:
	bool is_active_ = false;

	std::vector<Building> buildings_;

	void SetActive(bool active);
	[[nodiscard]] bool GetActive() const;

public :
	void AddBuilding (Tile& tile, Build build, GameResource& resource);
	void SubBuilding(Tile& tile, GameResource& resource);

	void ClearMap();

	void CreateFirstBuildingHome(std::vector<Tile>& tiles, GameResource* resource);

	void build(sf::RenderWindow& window);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif // BUILDING_MANAGER_H
