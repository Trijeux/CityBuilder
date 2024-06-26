#include <chrono>
#include <main_game.h>
#include <iostream>


void mainCallBack()
{
	std::cout << "Callback" << std::endl;
}

MainGame::MainGame()
{
	window_.create(sf::VideoMode(1600, 900), "SFML works!");

	sceneBounds = sf::FloatRect(0.f, 0.f, gridWidth * spriteSizeX, gridHeight * spriteSizeY);

	cursor_.BasicCursor(window_);

	tilemap_.Setup(sf::Vector2u(800 / tilemap_.SpritSize().x, 600 / tilemap_.SpritSize().y));

	tilemap_.InitMap(building_manager_);

	tilemap_.ClickedTile_ = std::bind(&BuildingManager::AddBuilding, &building_manager_, std::placeholders::_1);

	
	btn_generate.CreatButton(sf::Vector2f(50, 710), "Generate", 20, sf::Color::Yellow);
	btn_generate.setScale(0.5f, 0.5f);
	btn_generate.call_back_ = [this]()
		{
			tilemap_.InitMap(building_manager_);
		};

	btn_activate_building.CreatButton(sf::Vector2f(200, 710), "Build", 20, sf::Color::Yellow);
	btn_activate_building.setScale(0.5f, 0.5f);
	btn_activate_building.call_back_ = [this]()
		{
			building_manager_.build(window_);
		};

	//building_manager_.build(window_);

}

//void MainGame::Zoom(sf::Event event)
//{
//	if (event.type == sf::Event::MouseWheelScrolled)
//	{
//		if (event.mouseWheelScroll.delta > 0 /*&& zoomFactor >= 0.5f*/)
//		{
//			zoomFactor *= 0.95f; // Zoom avant
//		}
//		else if (event.mouseWheelScroll.delta < 0 /*&& zoomFactor <= 1.0f*/)
//		{
//			zoomFactor *= 1.05f; // Zoom arrière
//		}
//
//		view.setSize(window_.getDefaultView().getSize());
//		view.zoom(zoomFactor);
//	}
//}

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
			view.move(deltaPos);
			oldPos = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));
		}
	}
}

void MainGame::ContrainteView()
{
	sf::Vector2f viewSize = view.getSize();
	sf::Vector2f viewCenter = view.getCenter();

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

	view.setCenter(viewCenter);
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

			btn_generate.HandleEvent(event);
			btn_activate_building.HandleEvent(event);
			//tilemap_.Size_Offset(zoomFactor);
			tilemap_.HandleEvent(event);

			//Zoom(event);

			//MoveCame(event);

			//ContrainteView();
		}


		//window_.setView(view);
		window_.clear();
		window_.draw(tilemap_);
		window_.draw(building_manager_);
		window_.draw(btn_generate);
		window_.draw(btn_activate_building);
		window_.display();

		//auto end = std::chrono::high_resolution_clock::now();
		//std::chrono::duration<double> totalDuration = end - start;
	}
}
