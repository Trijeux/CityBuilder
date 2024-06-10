#include <chrono>
#include <main_game.h>
#include <iostream>


void mainCallBack()
{
	std::cout << "Callback" << std::endl;
}

MainGame::MainGame()
{
	window_.create(sf::VideoMode(800, 600), "SFML works!");

	sceneBounds = sf::FloatRect(0.f, 0.f, gridWidth * spriteSizeX, gridHeight * spriteSizeY);

	//button_.CreatButton(sf::Vector2f(200, 100), "Test", 25, sf::Color::Blue);
	//button_.setScale(0.8f, 0.8f);

	//First Exemple
	//button_.call_back_ = mainCallBack;

	//Second Exemple
	//button_.callBack_ = [] { std::cout << "Callback" << std::endl; };
}

//void MainGame::Zoom(sf::Event event)
//{
//	if (event.type == sf::Event::MouseWheelScrolled)
//	{
//		float oldZoomFactor = zoomFactor;
//
//		if (event.mouseWheelScroll.delta > 0)
//		{
//			zoomFactor *= 0.9f; // Zoom avant
//		}
//		else if (event.mouseWheelScroll.delta < 0)
//		{
//			zoomFactor *= 1.1f; // Zoom arrière
//		}
//
//		// Limiter le zoom
//		sf::Vector2f newSize = window_.getDefaultView().getSize();
//		newSize.x *= zoomFactor;
//		newSize.y *= zoomFactor;
//
//		if (newSize.x < minViewSize.x || newSize.y < minViewSize.y)
//		{
//			zoomFactor = oldZoomFactor; // Annuler le zoom s'il dépasse la limite
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
		auto start = std::chrono::high_resolution_clock::now();
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
			//button_.HandleEvent(event);
			/*Zoom(event);*/

			MoveCame(event);

			ContrainteView();
		}


		window_.setView(view);
		window_.clear();
		//window_.draw(button_);
		tilemap_.DrawMap(window_);
		window_.display();


		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> totalDuration = end - start;
		std::cout << "Temps total d'exécution : " << totalDuration.count() << " secondes." << std::endl;
	}
}

