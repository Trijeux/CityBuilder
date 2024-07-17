#ifndef GAME_MAIN_GAME_H
#define GAME_MAIN_GAME_H

#include "gameplay/building.h"
#include "gameplay/building_manager.h"
#include "gameplay/change_cursor.h"
#include "gameplay/game_ressource.h"
#include "graphics/tilemap.h"
#include "ui/ui_button.h"

class MainGame
{
	// Game components
	BuildingManager building_manager_;
	ChangeCursor cursor_;
	Tilemap tilemap_;

	// UI Buttons
	UiButton btn_generate_;
	UiButton btn_activate_building_;
	UiButton btn_activate_destroyer_;
	UiButton btn_building_home_;
	UiButton btn_building_orchard_;
	UiButton btn_building_farm_;
	UiButton btn_building_mine_;
	UiButton btn_building_castle_;
	UiButton btn_quit_;

	// SFML window and views
	sf::RenderWindow window_;
	sf::View view_;
	sf::View view_ui_;

	// Game resources
	GameResource resource_;

	// Zoom and pan variables
	float zoom_factor_ = 1.0f;
	bool is_panning_ = false;
	sf::Vector2f old_pos_;
	sf::Vector2f new_pos_;

	// Build state variables
	Build build_ = Build::kFarm;
	bool mouse_on_btn_ = false;
	bool build_active_ = false;
	bool destroy_active_ = false;

	// Resource fullness flags for different buildings
	bool full_resource_for_home_ = false;
	bool full_resource_for_farm_ = false;
	bool full_resource_for_orchard_ = false;
	bool full_resource_for_mine_ = false;
	bool full_resource_for_castle_ = false;

	// Constants based on tilemap
	const int grid_width_ = tilemap_.playground_size_u_.x;
	const int grid_height_ = tilemap_.playground_size_u_.y;
	const int sprite_size_x_ = tilemap_.SpritSize().x;
	const int sprite_size_y_ = tilemap_.SpritSize().y;

	sf::FloatRect scene_bounds_;
	sf::Vector2f min_view_size_;

public:
	
	// Constructor
	MainGame();


	// Methods for map
	void CreateTilemap();

	// Methods for create button
	void CreateButtonGenerate(int x, int y, const std::string& text, int size, sf::Color color_text);
	void CreateButtonActiveBuilding(int x, int y, const std::string& text, int size, sf::Color color_text);
	void CreateButtonBuildHome(int x, int y, const std::string& text, int size, sf::Color color_text);
	void CreateButtonBuildFarm(int x, int y, const std::string& text, int size, sf::Color color_text);
	void CreateButtonBuildOrchard(int x, int y, const std::string& text, int size, sf::Color color_text);
	void CreateButtonBuildMine(int x, int y, const std::string& text, int size, sf::Color color_text);
	void CreateButtonBuildCastle(int x, int y, const std::string& text, int size, sf::Color color_text);
	void CreateButtonActiveDestroy(int x, int y, const std::string& text, int size, sf::Color color_text);
	void CreateButtonQuit(int x, int y, const std::string& text, int size, sf::Color color_text);
	


	// Main game loop function
	void GameLoop();

	// Methods for event
	void ButtonEvent(sf::Event event);

	// Prevents the player from building if he does not have the resources
	void ConstraintsForBuild();

	// Setup code For tilemap.clicked_tile_
	void SetupCallBackForTilemapClicked();
	

	// Methods for handling zoom and camera movement
	void Zoom(const sf::Event& event);
	void MoveCame(const sf::Event& event);
	void ConstraintsView();

	//Draw all ui and map
	void Draw();

	// Check end game And Draw All Utility for end game
	void EndGame();
};

#endif // GAME_MAIN_GAME_H
