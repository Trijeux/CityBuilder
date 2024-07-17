#include <chrono>
#include <iostream>
#include <main_game.h>
#include <threads.h>
#ifdef TRACY_ENABLE
#include <Tracy/Tracy.hpp>
#endif

MainGame::MainGame()
{
#ifdef TRACY_ENABLE
	ZoneScoped;
#endif
	window_.create(sf::VideoMode(1600, 900), "SFML works!");

	sceneBounds = sf::FloatRect(0.f, 0.f, gridWidth * spriteSizeX, gridHeight * spriteSizeY);

	cursor_.BasicCursor(window_);

	tilemap_.Setup(sf::Vector2u(window_.getSize().x / tilemap_.SpritSize().x, window_.getSize().y / tilemap_.SpritSize().y));

	tilemap_.InitMap();

	building_manager_.CreatFirstBuildingHome(tilemap_.tiles(), &resource_);

	resource_.setUiPosistion(window_);

	tilemap_.ClickedTile_ = [this](Tile& tile)
		{
			building_manager_.AddBuilding(tile, build_, resource_);
		};

	btn_generate.CreatButton(sf::Vector2f(50, 760), "Generate", 20, sf::Color::Yellow);
	btn_generate.setScale(0.5f, 0.5f);
	btn_generate.call_back_ = [this]()
		{
			tilemap_.InitMap();
			building_manager_.ClearMap();
			building_manager_.CreatFirstBuildingHome(tilemap_.tiles(), &resource_);

		};

	btn_activate_building.CreatButton(sf::Vector2f(200, 760), "Build", 20, sf::Color::Yellow);
	btn_activate_building.setScale(0.5f, 0.5f);
	btn_activate_building.call_back_ = [this]()
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

	btn_building_Home.CreatButton(sf::Vector2f(100, 810), "Home", 20, sf::Color::Yellow);
	btn_building_Home.setScale(0.5f, 0.5f);
	btn_building_Home.call_back_ = [this]()
		{
			btn_building_Home.setScale(0.8f, 0.8f);
			build_ = Build::kHome;
			btn_building_Ferme.build_on_ = false;
			btn_building_Ferme.setScale(0.5f, 0.5f);
			btn_building_Menuiserie.build_on_ = false;
			btn_building_Menuiserie.setScale(0.5f, 0.5f);
			btn_building_Carriere.build_on_ = false;
			btn_building_Carriere.setScale(0.5f, 0.5f);
			btn_building_Chateau.build_on_ = false;
			btn_building_Chateau.setScale(0.5f, 0.5f);
		};

	btn_building_Ferme.CreatButton(sf::Vector2f(250, 810), "Ferme", 20, sf::Color::Yellow);
	btn_building_Ferme.setScale(0.8f, 0.8f);
	btn_building_Ferme.call_back_ = [this]()
		{
			btn_building_Ferme.setScale(0.8f, 0.8f);
			build_ = Build::kFerme;
			btn_building_Home.build_on_ = false;
			btn_building_Home.setScale(0.5f, 0.5f);
			btn_building_Menuiserie.build_on_ = false;
			btn_building_Menuiserie.setScale(0.5f, 0.5f);
			btn_building_Carriere.build_on_ = false;
			btn_building_Carriere.setScale(0.5f, 0.5f);
			btn_building_Chateau.build_on_ = false;
			btn_building_Chateau.setScale(0.5f, 0.5f);
		};

	btn_building_Menuiserie.CreatButton(sf::Vector2f(400, 810), "Verger", 20, sf::Color::Yellow);
	btn_building_Menuiserie.setScale(0.5f, 0.5f);
	btn_building_Menuiserie.call_back_ = [this]()
		{
			btn_building_Menuiserie.setScale(0.8f, 0.8f);
			build_ = Build::kVerger;
			btn_building_Home.build_on_ = false;
			btn_building_Home.setScale(0.5f, 0.5f);
			btn_building_Ferme.build_on_ = false;
			btn_building_Ferme.setScale(0.5f, 0.5f);
			btn_building_Carriere.build_on_ = false;
			btn_building_Carriere.setScale(0.5f, 0.5f);
			btn_building_Chateau.build_on_ = false;
			btn_building_Chateau.setScale(0.5f, 0.5f);
		};

	btn_building_Carriere.CreatButton(sf::Vector2f(550, 810), "Carriere", 20, sf::Color::Yellow);
	btn_building_Carriere.setScale(0.5f, 0.5f);
	btn_building_Carriere.call_back_ = [this]()
		{
			btn_building_Carriere.setScale(0.8f, 0.8f);
			build_ = Build::kCarriere;
			btn_building_Home.build_on_ = false;
			btn_building_Home.setScale(0.5f, 0.5f);
			btn_building_Menuiserie.build_on_ = false;
			btn_building_Menuiserie.setScale(0.5f, 0.5f);
			btn_building_Ferme.build_on_ = false;
			btn_building_Ferme.setScale(0.5f, 0.5f);
			btn_building_Chateau.build_on_ = false;
			btn_building_Chateau.setScale(0.5f, 0.5f);
		};

	btn_building_Chateau.CreatButton(sf::Vector2f(700, 810), "Chateau", 20, sf::Color::Yellow);
	btn_building_Chateau.setScale(0.5f, 0.5f);
	btn_building_Chateau.call_back_ = [this]()
		{
			btn_building_Chateau.setScale(0.8f, 0.8f);
			build_ = Build::kChateau;
			btn_building_Home.build_on_ = false;
			btn_building_Home.setScale(0.5f, 0.5f);
			btn_building_Ferme.build_on_ = false;
			btn_building_Ferme.setScale(0.5f, 0.5f);
			btn_building_Carriere.build_on_ = false;
			btn_building_Carriere.setScale(0.5f, 0.5f);
			btn_building_Menuiserie.build_on_ = false;
			btn_building_Menuiserie.setScale(0.5f, 0.5f);
		};

	btn_activate_Destroyer.CreatButton(sf::Vector2f(850, 810), "Destroy", 20, sf::Color::Yellow);
	btn_activate_Destroyer.setScale(0.5f, 0.5f);
	btn_activate_Destroyer.call_back_ = [this]()
		{
			if (destroy_active_ == false)
			{
				destroy_active_ = true;
				btn_activate_Destroyer.setScale(0.8f, 0.8f);
				btn_activate_Destroyer.Set_Color_Sprite(sf::Color::Red);
			}
			else if (destroy_active_ == true)
			{
				destroy_active_ = false;
				btn_activate_Destroyer.setScale(0.5f, 0.5f);
				btn_activate_Destroyer.Set_Color_Sprite(sf::Color::White);
			}
		};

	btn_quit.CreatButton(sf::Vector2f(window_.getSize().x - 100, window_.getSize().y - 100), "Quit", 20, sf::Color::Yellow);
	btn_quit.setScale(0.5f, 0.5f);
	btn_quit.call_back_ = [this]()
		{
			window_.close();
		};

	view_ = window_.getDefaultView();
	viewUi_ = window_.getDefaultView();

	sceneBounds = sf::FloatRect(0, 0, window_.getSize().x, window_.getSize().y);

	//building_manager_.build(window_);

}

void MainGame::Zoom(sf::Event event)
{
	if (event.type == sf::Event::MouseWheelScrolled)
	{
		if (event.mouseWheelScroll.delta > 0)
		{
			zoomFactor *= 0.95f; // Zoom avant
		}
		else if (event.mouseWheelScroll.delta < 0)
		{
			zoomFactor *= 1.05f; // Zoom arrière
		}

		// Clamping zoomFactor between 0.5 and 1.0
		if (zoomFactor > 1.0f)
		{
			zoomFactor = 1.0f;
		}
		else if (zoomFactor < 0.5f)
		{
			zoomFactor = 0.5f;
		}

		view_.setSize(window_.getDefaultView().getSize()); // Reset view size
		view_.zoom(zoomFactor); // Apply zoom factor

		//// Print the zoom factor and view for debugging
		//std::cout << "Zoom Factor: " << zoomFactor << std::endl;
		//std::cout << "View Center: (" << view_.getCenter().x << ", " << view_.getCenter().y << ")\n";
		//std::cout << "View Size: (" << view_.getSize().x << ", " << view_.getSize().y << ")\n";
	}
}



void MainGame::MoveCame(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
	{
		isPanning = true;
		oldPos = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
	}

	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
	{
		isPanning = false;
	}

	if (event.type == sf::Event::MouseMoved)
	{
		if (isPanning)
		{
			newPos = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
			sf::Vector2f deltaPos = oldPos - newPos;
			view_.move(deltaPos);
			oldPos = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
		}
	}
}

void MainGame::ContrainteView()
{
	sf::Vector2f viewSize = view_.getSize();
	sf::Vector2f viewCenter = view_.getCenter();

	if (viewCenter.x - viewSize.x / 2 < sceneBounds.left)
	{
		viewCenter.x = sceneBounds.left + viewSize.x / 2;
	}
	if (viewCenter.y - viewSize.y / 2 < sceneBounds.top)
	{
		viewCenter.y = sceneBounds.top + viewSize.y / 2;
	}
	if (viewCenter.x + viewSize.x / 2 > sceneBounds.left + sceneBounds.width)
	{
		viewCenter.x = sceneBounds.left + sceneBounds.width - viewSize.x / 2;
	}
	if (viewCenter.y + viewSize.y / 2 > sceneBounds.top + sceneBounds.height)
	{
		viewCenter.y = sceneBounds.top + sceneBounds.height - viewSize.y / 2;
	}

	view_.setCenter(viewCenter);
}

void MainGame::GameLoop()
{
	while (window_.isOpen())
	{
#ifdef TRACY_ENABLE
		ZoneNamedN(GameLoop, "GameLoop", true);
#endif
		//auto start = std::chrono::high_resolution_clock::now();
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();

			mouse_on_btn = false;

			if (!build_active_)
			{
				//mouse_on_btn = btn_generate.HandleEvent(event);
			}

			mouse_on_btn = btn_activate_building.HandleEvent(event);


			/*if (btn_activate_Destroyer.HandleEvent(event))
			{
				mouse_on_btn = true;
			}*/

			if (resource_.food() >= 100 && resource_.gold() >= 200)
			{
				if (btn_building_Home.HandleEvent(event))
				{
					mouse_on_btn = true;
				}
			}

			if (resource_.gold() >= 100)
			{
				if (btn_building_Ferme.HandleEvent(event))
				{
					mouse_on_btn = true;
				}
			}

			if (resource_.food() >= 200 && resource_.gold() >= 300)
			{
				if (btn_building_Menuiserie.HandleEvent(event))
				{
					mouse_on_btn = true;
				}
			}

			if (resource_.food() >= 300 && resource_.gold() >= 400 && resource_.wood() >= 200)
			{
				if (btn_building_Carriere.HandleEvent(event))
				{
					mouse_on_btn = true;
				}
			}

			if (resource_.food() >= 25000 && resource_.gold() >= 50000
				&& resource_.wood() >= 12500 && resource_.stone() >= 10000)
			{
				if (btn_building_Chateau.HandleEvent(event))
				{
					mouse_on_btn = true;
				}
			}

			if (resource_.gold() >= 100)
			{
				btn_building_Ferme.Set_Color_Sprite(sf::Color::White);
				full_ressource_for_ferme_ = true;
			}
			else
			{
				btn_building_Ferme.Set_Color_Sprite(sf::Color::Black);
				full_ressource_for_ferme_ = false;
			}

			if (resource_.food() >= 100 && resource_.gold() >= 200)
			{
				btn_building_Home.Set_Color_Sprite(sf::Color::White);
				full_ressource_for_home_ = true;
			}
			else
			{
				btn_building_Home.Set_Color_Sprite(sf::Color::Black);
				full_ressource_for_home_ = false;
			}

			if (resource_.food() >= 200 && resource_.gold() >= 300)
			{
				btn_building_Menuiserie.Set_Color_Sprite(sf::Color::White);
				full_ressource_for_verger_ = true;
			}
			else
			{
				btn_building_Menuiserie.Set_Color_Sprite(sf::Color::Black);
				full_ressource_for_verger_ = false;
			}

			if (resource_.food() >= 300 && resource_.gold() >= 400 && resource_.wood() >= 200)
			{
				btn_building_Carriere.Set_Color_Sprite(sf::Color::White);
				full_ressource_for_mine_ = true;
			}
			else
			{
				btn_building_Carriere.Set_Color_Sprite(sf::Color::Black);
				full_ressource_for_mine_ = false;
			}

			if (resource_.food() >= 25000 && resource_.gold() >= 50000
				&& resource_.wood() >= 12500 && resource_.stone() >= 10000)
			{
				btn_building_Chateau.Set_Color_Sprite(sf::Color::White);
				full_ressource_for_chateau_ = true;
			}
			else
			{
				btn_building_Chateau.Set_Color_Sprite(sf::Color::Black);
				full_ressource_for_chateau_ = false;
			}


			if (destroy_active_)
			{
				tilemap_.ClickedTile_ = [this](Tile& tile)
					{
						building_manager_.SubBuilding(tile, resource_);
					};
				
			}
			else
			{
				tilemap_.ClickedTile_ = [this](Tile& tile)
					{
						building_manager_.AddBuilding(tile, build_, resource_);
					};
			}

			if (!mouse_on_btn && (full_ressource_for_home_ || full_ressource_for_ferme_ || full_ressource_for_verger_ || full_ressource_for_mine_ || full_ressource_for_chateau_))
			{
				tilemap_.HandleEvent(event, window_, view_);
			}

			if (!resource_.game())
			{
				btn_quit.HandleEvent(event);
			}
			
			//tilemap_.Size_Offset(zoomFactor);


			Zoom(event);

			MoveCame(event);
		}

		resource_.AddRessource();
		resource_.PayTaxe();
		resource_.GameEnd();

		ContrainteView();

		window_.clear();
		if (resource_.game())
		{
			window_.setView(view_); // Set updated view
			window_.draw(tilemap_);
			window_.draw(building_manager_);
			//window_.draw(btn_generate);
			window_.setView(viewUi_);
			window_.draw(btn_activate_building);
			resource_.Draw(window_);
			if (!build_active_)
			{
				//window_.draw(btn_generate);
			}
			if (build_active_)
			{
				//window_.draw(btn_activate_Destroyer);
				window_.draw(btn_building_Home);
				window_.draw(btn_building_Ferme);
				window_.draw(btn_building_Carriere);
				window_.draw(btn_building_Menuiserie);
				window_.draw(btn_building_Chateau);
			}
		}

#ifdef TRACY_ENABLE
		FrameMark;
#endif

		if (!resource_.game())
		{
			sf::Font font;
			sf::Text text;
			sf::Text quitText;

			if (!font.loadFromFile("ressources/fonts/kenvector_future.ttf")) {
				// Gérer l'erreur : impossible de charger la police
			}

			text.setFont(font);
			quitText.setFont(font);

			if (resource_.gold() <= -1)
			{
				text.setString("Game Over");
			}
			else
			{
				text.setString("Win");
			}

			text.setColor(sf::Color::Red);
			quitText.setColor(sf::Color::Red);

			text.setOrigin(text.getGlobalBounds().width / 2.0f, text.getGlobalBounds().height / 2.0f);
			quitText.setOrigin(quitText.getGlobalBounds().width / 2.0f, quitText.getGlobalBounds().height / 2.0f);

			quitText.setString("Tap button to quit");

			text.setPosition(window_.getSize().x / 2, window_.getSize().y / 2);

			quitText.setPosition((window_.getSize().x / 2) - 150, text.getPosition().y + 100);

			window_.draw(text);
			window_.draw(quitText);
			window_.draw(btn_quit);
		}
		window_.display();
	}
}
