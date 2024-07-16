#ifndef GAMEPLAY_GAME_RESSOURCE_H_
#define GAMEPLAY_GAME_RESSOURCE_H_

#include <chrono>
#include <SFML/Graphics.hpp>
#include "Building.h"
#include "graphics/tile.h"

class ResourceGame
{

	sf::Sprite sprite_Gold_;
	sf::Sprite sprite_Food_;
	sf::Sprite sprite_Wood_;
	sf::Sprite sprite_Stone_;
	sf::Sprite sprite_Taxe_;
	sf::Texture texture_Gold_;
	sf::Texture texture_Food_;
	sf::Texture texture_Wood_;
	sf::Texture texture_Stone_;
	sf::Texture texture_Taxe_;
	sf::Text text_Gold_;
	sf::Text text_Food_;
	sf::Text text_Wood_;
	sf::Text text_Stone_;
	sf::Text text_Taxe_;
	sf::Font font_;

	int Home = 0;
	int Gold = 0;

	int Ferme = 0;
	int Food = 0;

	int Verger = 0;
	int Wood = 0;

	int Carriere = 0;
	int Stone = 0;

	int Chateau = 0;

	int Taxe = 0;

	bool Game = true;

	std::chrono::time_point<std::chrono::steady_clock> OneSecondLast;
	std::chrono::time_point<std::chrono::steady_clock> TaxeSecondLast;

public:
	ResourceGame();
	void setUiPosistion(sf::RenderWindow&);

	[[nodiscard]] int gold() const { return Gold; }
	[[nodiscard]] int food() const { return Food; }
	[[nodiscard]] int wood() const { return Wood; }
	[[nodiscard]] int stone() const { return Stone; }
	[[nodiscard]] int taxe() const { return Taxe; }
	[[nodiscard]] bool game() const { return Game; }

	void AddBatiment(Build);
	void SubBatiment(Tile::TileType);
	void AddRessource();
	void PayBatiment(Build);
	void PayTaxe();
	void GameEnd();

	void Draw(sf::RenderWindow&);
};

#endif
