#ifndef GAME_MAINGAME_H_
#define GAME_MAINGAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <graphics/Tilemap.h>
#include <ui/UIButton.h>

#include "gameplay/building_manager.h"
#include "gameplay/change_cursor.h"

class MainGame
{
	BuildingManager building_manager_;

	ChangeCursor cursor_;

	Tilemap tilemap_;

	UiButton btn_generate;

	UiButton btn_activate_building;

	UiButton btn_activate_Destroyer;

	UiButton btn_building_Home;

	UiButton btn_building_Menuiserie;

	UiButton btn_building_Ferme;

	UiButton btn_building_Carriere;

	UiButton btn_building_Chateau;

	UiButton btn_quit;

	sf::RenderWindow window_;

	GameRessource resource_;

	sf::View view_;
	sf::View viewUi_;

	float zoomFactor = 1.0f;
	bool isPanning = false;
	sf::Vector2f oldPos;
	sf::Vector2f newPos;
	Build build_ = Build::kFerme;
	bool build_active_ = false;
	bool destroy_active_ = false;
	bool mouse_on_btn;
	bool full_ressource_for_home_ = false;
	bool full_ressource_for_ferme_ = false;
	bool full_ressource_for_verger_ = false;
	bool full_ressource_for_mine_ = false;
	bool full_ressource_for_chateau_ = false;

	const int gridWidth = tilemap_.playground_size_u_.x;
	const int gridHeight = tilemap_.playground_size_u_.y;
	const int spriteSizeX = tilemap_.SpritSize().x;
	const int spriteSizeY = tilemap_.SpritSize().y;

	sf::FloatRect sceneBounds;

	sf::Vector2f minViewSize = {
		std::min(window_.getDefaultView().getSize().x, sceneBounds.width),
		std::min(window_.getDefaultView().getSize().y, sceneBounds.height) };

public:

	MainGame();
	void Zoom(sf::Event event);
	void MoveCame(sf::Event event);
	void ContrainteView();

	void GameLoop();

	void GameTemp();
};




#endif // GAME_MAINGAME_H_