#ifndef BUILDING_MANAGER_H_
#define BUILDING_MANAGER_H_

#include <graphics/Tile.h>
#include "Building.h"


class BuildingManager : public sf::Drawable
{
private:
	bool is_active_ = false;

	std::vector<Building> buildings_;

	void SetActive(bool active);
	bool GetActive() const;

public :
	void AddBuilding(const Tile& tile, Build build);

	void ForceBuilding(const Tile& tile);

	void build(sf::RenderWindow& window);
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif // BUILDING_MANAGER_H_
