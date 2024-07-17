#ifndef GAMEPLAY_GAME_RESOURCE_H
#define GAMEPLAY_GAME_RESOURCE_H

#include <chrono>

#include "building.h"
#include "graphics/tile.h"


class GameResource
{

	sf::Sprite sprite_gold_;
	sf::Sprite sprite_food_;
	sf::Sprite sprite_wood_;
	sf::Sprite sprite_stone_;
	sf::Sprite sprite_tax_;
	sf::Texture texture_gold_;
	sf::Texture texture_food_;
	sf::Texture texture_wood_;
	sf::Texture texture_stone_;
	sf::Texture texture_tax_;
	sf::Text text_gold_;
	sf::Text text_food_;
	sf::Text text_wood_;
	sf::Text text_stone_;
	sf::Text text_tax_;
	sf::Font font_;

	int home_ = 0;
	int gold_ = 0;

	int farm_ = 0;
	int food_ = 0;

	int orchard_ = 0;
	int wood_ = 0;

	int mine_ = 0;
	int stone_ = 0;

	int castle_ = 0;

	int tax_ = 0;

	bool game_ = true;

	std::chrono::time_point<std::chrono::steady_clock> one_second_last_;
	std::chrono::time_point<std::chrono::steady_clock> tax_second_last_;

public:
	GameResource();
	void SetUiPosition(const sf::RenderWindow&);

	[[nodiscard]] int gold() const { return gold_; }
	[[nodiscard]] int food() const { return food_; }
	[[nodiscard]] int wood() const { return wood_; }
	[[nodiscard]] int stone() const { return stone_; }
	[[nodiscard]] int tax() const { return tax_; }
	[[nodiscard]] bool game() const { return game_; }

	void AddBuilding(Build);
	void SubBuilding(Tile::TileType);
	void AddResource();
	void PayBuilding(Build);
	void PayTax();
	void GameEnd();

	void Draw(sf::RenderWindow&) const;
};

#endif
