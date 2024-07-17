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
	BuildingManager building_manager_;

	ChangeCursor cursor_;

	Tilemap tilemap_;

	UiButton btn_generate_;

	UiButton btn_activate_building_;

	UiButton btn_activate_destroyer_;

	UiButton btn_building_home_;

	UiButton btn_building_orchard_;

	UiButton btn_building_farm_;

	UiButton btn_building_mine_;

	UiButton btn_building_castle_;

	UiButton btn_quit_;

	sf::RenderWindow window_;

	GameResource resource_;

	sf::View view_;
	sf::View view_ui_;

	float zoom_factor_ = 1.0f;
	bool is_panning_ = false;
	sf::Vector2f old_pos_;
	sf::Vector2f new_pos_;
	Build build_ = Build::kFarm;
	bool build_active_ = false;
	bool destroy_active_ = false;
	bool mouse_on_btn_ = false;
	bool full_resource_for_home_ = false;
	bool full_resource_for_farm_ = false;
	bool full_resource_for_orchard_ = false;
	bool full_resource_for_mine_ = false;
	bool full_resource_for_castle_ = false;

	const int grid_width_ = tilemap_.playground_size_u_.x;
	const int grid_height_ = tilemap_.playground_size_u_.y;
	const int sprite_size_x_ = tilemap_.SpritSize().x;
	const int sprite_size_y_ = tilemap_.SpritSize().y;

	sf::FloatRect scene_bounds_;

	sf::Vector2f min_view_size_ = {
		std::min(window_.getDefaultView().getSize().x, scene_bounds_.width),
		std::min(window_.getDefaultView().getSize().y, scene_bounds_.height) };

public:

	MainGame();
	void Zoom(const sf::Event& event);
	void MoveCame(const sf::Event& event);
	void ConstraintsView();

	void GameLoop();
};




#endif // GAME_MAIN_GAME_H