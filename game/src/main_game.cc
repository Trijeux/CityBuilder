
#include "main_game.h"
#include "graphics/tile.h"

MainGame::MainGame()
{
	window_.create(sf::VideoMode(1600, 900), "City Builder!!!");

	scene_bounds_ = sf::FloatRect(0.f, 0.f, grid_width_ * sprite_size_x_, grid_height_ * sprite_size_y_);

	ChangeCursor::BasicCursor(window_);

	tilemap_.Setup(sf::Vector2u(window_.getSize().x / tilemap_.SpritSize().x, window_.getSize().y / tilemap_.SpritSize().y));

	tilemap_.InitMap();

	building_manager_.CreateFirstBuildingHome(tilemap_.tiles(), &resource_);

	resource_.SetUiPosition(window_);

	tilemap_.clicked_tile_ = [this](Tile& tile)
		{
			building_manager_.AddBuilding(tile, build_, resource_);
		};

	btn_generate_.CreateButton(sf::Vector2f(50, 760), "Generate", 20, sf::Color::Yellow);
	btn_generate_.setScale(0.5f, 0.5f);
	btn_generate_.call_back_ = [this]()
		{
			tilemap_.InitMap();
			building_manager_.ClearMap();
			building_manager_.CreateFirstBuildingHome(tilemap_.tiles(), &resource_);

		};

	btn_activate_building_.CreateButton(sf::Vector2f(200, 760), "Build", 20, sf::Color::Yellow);
	btn_activate_building_.setScale(0.5f, 0.5f);
	btn_activate_building_.call_back_ = [this]()
		{
			building_manager_.build(window_);
			if (build_active_ == false)
			{
				build_active_ = true;
			}
			else if (build_active_ == true)
			{
				build_active_ = false;
			}
		};

	btn_building_home_.CreateButton(sf::Vector2f(100, 810), "Home", 20, sf::Color::Yellow);
	btn_building_home_.setScale(0.5f, 0.5f);
	btn_building_home_.call_back_ = [this]()
		{
			btn_building_home_.setScale(0.8f, 0.8f);
			build_ = Build::kHome;
			btn_building_farm_.build_on_ = false;
			btn_building_farm_.setScale(0.5f, 0.5f);
			btn_building_orchard_.build_on_ = false;
			btn_building_orchard_.setScale(0.5f, 0.5f);
			btn_building_mine_.build_on_ = false;
			btn_building_mine_.setScale(0.5f, 0.5f);
			btn_building_castle_.build_on_ = false;
			btn_building_castle_.setScale(0.5f, 0.5f);
		};

	btn_building_farm_.CreateButton(sf::Vector2f(250, 810), "Farm", 20, sf::Color::Yellow);
	btn_building_farm_.setScale(0.8f, 0.8f);
	btn_building_farm_.call_back_ = [this]()
		{
			btn_building_farm_.setScale(0.8f, 0.8f);
			build_ = Build::kFarm;
			btn_building_home_.build_on_ = false;
			btn_building_home_.setScale(0.5f, 0.5f);
			btn_building_orchard_.build_on_ = false;
			btn_building_orchard_.setScale(0.5f, 0.5f);
			btn_building_mine_.build_on_ = false;
			btn_building_mine_.setScale(0.5f, 0.5f);
			btn_building_castle_.build_on_ = false;
			btn_building_castle_.setScale(0.5f, 0.5f);
		};

	btn_building_orchard_.CreateButton(sf::Vector2f(400, 810), "Orchard", 20, sf::Color::Yellow);
	btn_building_orchard_.setScale(0.5f, 0.5f);
	btn_building_orchard_.call_back_ = [this]()
		{
			btn_building_orchard_.setScale(0.8f, 0.8f);
			build_ = Build::kOrchard;
			btn_building_home_.build_on_ = false;
			btn_building_home_.setScale(0.5f, 0.5f);
			btn_building_farm_.build_on_ = false;
			btn_building_farm_.setScale(0.5f, 0.5f);
			btn_building_mine_.build_on_ = false;
			btn_building_mine_.setScale(0.5f, 0.5f);
			btn_building_castle_.build_on_ = false;
			btn_building_castle_.setScale(0.5f, 0.5f);
		};

	btn_building_mine_.CreateButton(sf::Vector2f(550, 810), "Mine", 20, sf::Color::Yellow);
	btn_building_mine_.setScale(0.5f, 0.5f);
	btn_building_mine_.call_back_ = [this]()
		{
			btn_building_mine_.setScale(0.8f, 0.8f);
			build_ = Build::kMine;
			btn_building_home_.build_on_ = false;
			btn_building_home_.setScale(0.5f, 0.5f);
			btn_building_orchard_.build_on_ = false;
			btn_building_orchard_.setScale(0.5f, 0.5f);
			btn_building_farm_.build_on_ = false;
			btn_building_farm_.setScale(0.5f, 0.5f);
			btn_building_castle_.build_on_ = false;
			btn_building_castle_.setScale(0.5f, 0.5f);
		};

	btn_building_castle_.CreateButton(sf::Vector2f(700, 810), "Castle", 20, sf::Color::Yellow);
	btn_building_castle_.setScale(0.5f, 0.5f);
	btn_building_castle_.call_back_ = [this]()
		{
			btn_building_castle_.setScale(0.8f, 0.8f);
			build_ = Build::kCastle;
			btn_building_home_.build_on_ = false;
			btn_building_home_.setScale(0.5f, 0.5f);
			btn_building_farm_.build_on_ = false;
			btn_building_farm_.setScale(0.5f, 0.5f);
			btn_building_mine_.build_on_ = false;
			btn_building_mine_.setScale(0.5f, 0.5f);
			btn_building_orchard_.build_on_ = false;
			btn_building_orchard_.setScale(0.5f, 0.5f);
		};

	btn_activate_destroyer_.CreateButton(sf::Vector2f(850, 810), "Destroy", 20, sf::Color::Yellow);
	btn_activate_destroyer_.setScale(0.5f, 0.5f);
	btn_activate_destroyer_.call_back_ = [this]()
		{
			if (destroy_active_ == false)
			{
				destroy_active_ = true;
				btn_activate_destroyer_.setScale(0.8f, 0.8f);
				btn_activate_destroyer_.SetColorSprite(sf::Color::Red);
			}
			else if (destroy_active_ == true)
			{
				destroy_active_ = false;
				btn_activate_destroyer_.setScale(0.5f, 0.5f);
				btn_activate_destroyer_.SetColorSprite(sf::Color::White);
			}
		};

	btn_quit_.CreateButton(sf::Vector2f(window_.getSize().x - 100, window_.getSize().y - 100), "Quit", 20, sf::Color::Yellow);
	btn_quit_.setScale(0.5f, 0.5f);
	btn_quit_.call_back_ = [this]()
		{
			window_.close();
		};

	view_ = window_.getDefaultView();
	view_ui_ = window_.getDefaultView();

	scene_bounds_ = sf::FloatRect(0, 0, window_.getSize().x, window_.getSize().y);

	//building_manager_.build(window_);

}

void MainGame::Zoom(const sf::Event& event)
{
	if (event.type == sf::Event::MouseWheelScrolled)
	{
		if (event.mouseWheelScroll.delta > 0)
		{
			zoom_factor_ *= 0.95f; // Zoom in
		}
		else if (event.mouseWheelScroll.delta < 0)
		{
			zoom_factor_ *= 1.05f; // Zoom out
		}

		// Clamping zoomFactor between 0.5 and 1.0
		if (zoom_factor_ > 1.0f)
		{
			zoom_factor_ = 1.0f;
		}
		else if (zoom_factor_ < 0.5f)
		{
			zoom_factor_ = 0.5f;
		}

		view_.setSize(window_.getDefaultView().getSize()); // Reset view size
		view_.zoom(zoom_factor_); // Apply zoom factor

		//// Print the zoom factor and view for debugging
		//std::cout << "Zoom Factor: " << zoomFactor << std::endl;
		//std::cout << "View Center: (" << view_.getCenter().x << ", " << view_.getCenter().y << ")\n";
		//std::cout << "View Size: (" << view_.getSize().x << ", " << view_.getSize().y << ")\n";
	}
}



void MainGame::MoveCame(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
	{
		is_panning_ = true;
		old_pos_ = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
	}

	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
	{
		is_panning_ = false;
	}

	if (event.type == sf::Event::MouseMoved)
	{
		if (is_panning_)
		{
			new_pos_ = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
			const sf::Vector2f delta_pos = old_pos_ - new_pos_;
			view_.move(delta_pos);
			old_pos_ = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
		}
	}
}

void MainGame::ConstraintsView()
{
	const sf::Vector2f view_size = view_.getSize();
	sf::Vector2f view_center = view_.getCenter();

	if (view_center.x - view_size.x / 2 < scene_bounds_.left)
	{
		view_center.x = scene_bounds_.left + view_size.x / 2;
	}
	if (view_center.y - view_size.y / 2 < scene_bounds_.top)
	{
		view_center.y = scene_bounds_.top + view_size.y / 2;
	}
	if (view_center.x + view_size.x / 2 > scene_bounds_.left + scene_bounds_.width)
	{
		view_center.x = scene_bounds_.left + scene_bounds_.width - view_size.x / 2;
	}
	if (view_center.y + view_size.y / 2 > scene_bounds_.top + scene_bounds_.height)
	{
		view_center.y = scene_bounds_.top + scene_bounds_.height - view_size.y / 2;
	}

	view_.setCenter(view_center);
}

void MainGame::GameLoop()
{
	while (window_.isOpen())
	{
		//auto start = std::chrono::high_resolution_clock::now();
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();

			mouse_on_btn_ = false;

			if (!build_active_)
			{
				//mouse_on_btn = btn_generate.HandleEvent(event);
			}

			mouse_on_btn_ = btn_activate_building_.HandleEvent(event);


			/*if (btn_activate_Destroyer.HandleEvent(event))
			{
				mouse_on_btn = true;
			}*/

			if (resource_.food() >= 100 && resource_.gold() >= 200)
			{
				if (btn_building_home_.HandleEvent(event))
				{
					mouse_on_btn_ = true;
				}
			}

			if (resource_.gold() >= 100)
			{
				if (btn_building_farm_.HandleEvent(event))
				{
					mouse_on_btn_ = true;
				}
			}

			if (resource_.food() >= 200 && resource_.gold() >= 300)
			{
				if (btn_building_orchard_.HandleEvent(event))
				{
					mouse_on_btn_ = true;
				}
			}

			if (resource_.food() >= 300 && resource_.gold() >= 400 && resource_.wood() >= 200)
			{
				if (btn_building_mine_.HandleEvent(event))
				{
					mouse_on_btn_ = true;
				}
			}

			if (resource_.food() >= 25000 && resource_.gold() >= 50000
				&& resource_.wood() >= 12500 && resource_.stone() >= 10000)
			{
				if (btn_building_castle_.HandleEvent(event))
				{
					mouse_on_btn_ = true;
				}
			}

			if (resource_.gold() >= 100)
			{
				btn_building_farm_.SetColorSprite(sf::Color::White);
				full_resource_for_farm_ = true;
			}
			else
			{
				btn_building_farm_.SetColorSprite(sf::Color::Black);
				full_resource_for_farm_ = false;
			}

			if (resource_.food() >= 100 && resource_.gold() >= 200)
			{
				btn_building_home_.SetColorSprite(sf::Color::White);
				full_resource_for_home_ = true;
			}
			else
			{
				btn_building_home_.SetColorSprite(sf::Color::Black);
				full_resource_for_home_ = false;
			}

			if (resource_.food() >= 200 && resource_.gold() >= 300)
			{
				btn_building_orchard_.SetColorSprite(sf::Color::White);
				full_resource_for_orchard_ = true;
			}
			else
			{
				btn_building_orchard_.SetColorSprite(sf::Color::Black);
				full_resource_for_orchard_ = false;
			}

			if (resource_.food() >= 300 && resource_.gold() >= 400 && resource_.wood() >= 200)
			{
				btn_building_mine_.SetColorSprite(sf::Color::White);
				full_resource_for_mine_ = true;
			}
			else
			{
				btn_building_mine_.SetColorSprite(sf::Color::Black);
				full_resource_for_mine_ = false;
			}

			if (resource_.food() >= 25000 && resource_.gold() >= 50000
				&& resource_.wood() >= 12500 && resource_.stone() >= 10000)
			{
				btn_building_castle_.SetColorSprite(sf::Color::White);
				full_resource_for_castle_ = true;
			}
			else
			{
				btn_building_castle_.SetColorSprite(sf::Color::Black);
				full_resource_for_castle_ = false;
			}


			if (destroy_active_)
			{
				tilemap_.clicked_tile_ = [this](Tile& tile)
					{
						building_manager_.SubBuilding(tile, resource_);
					};
				
			}
			else
			{
				tilemap_.clicked_tile_ = [this](Tile& tile)
					{
						building_manager_.AddBuilding(tile, build_, resource_);
					};
			}

			if (!mouse_on_btn_ && (full_resource_for_home_ || full_resource_for_farm_ || full_resource_for_orchard_ || full_resource_for_mine_ || full_resource_for_castle_))
			{
				tilemap_.HandleEvent(event, window_, view_);
			}

			if (!resource_.game())
			{
				btn_quit_.HandleEvent(event);
			}
			
			//tilemap_.Size_Offset(zoomFactor);


			Zoom(event);

			MoveCame(event);
		}

		resource_.AddResource();
		resource_.PayTax();
		resource_.GameEnd();

		ConstraintsView();

		window_.clear();
		if (resource_.game())
		{
			window_.setView(view_); // Set updated view
			window_.draw(tilemap_);
			window_.draw(building_manager_);
			//window_.draw(btn_generate);
			window_.setView(view_ui_);
			window_.draw(btn_activate_building_);
			resource_.Draw(window_);
			if (!build_active_)
			{
				//window_.draw(btn_generate);
			}
			if (build_active_)
			{
				//window_.draw(btn_activate_Destroyer);
				window_.draw(btn_building_home_);
				window_.draw(btn_building_farm_);
				window_.draw(btn_building_mine_);
				window_.draw(btn_building_orchard_);
				window_.draw(btn_building_castle_);
			}
		}


		if (!resource_.game())
		{
			sf::Font font;
			sf::Text text;
			sf::Text quit_text;

			if (!font.loadFromFile("ressources/fonts/kenvector_future.ttf")) {
				// Handle error: Unable to load font
			}

			text.setFont(font);
			quit_text.setFont(font);

			if (resource_.gold() <= -1)
			{
				text.setString("Game Over");
			}
			else
			{
				text.setString("Win");
			}

			text.setColor(sf::Color::Red);
			quit_text.setColor(sf::Color::Red);

			text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
			quit_text.setOrigin(quit_text.getGlobalBounds().width / 2.0f, quit_text.getGlobalBounds().height / 2.0f);

			quit_text.setString("Tap button to quit");

			text.setPosition(window_.getSize().x / 2, window_.getSize().y / 2);

			quit_text.setPosition((window_.getSize().x / 2) - 150, text.getPosition().y + 100);

			window_.draw(text);
			window_.draw(quit_text);
			window_.draw(btn_quit_);
		}
		window_.display();
	}
}
