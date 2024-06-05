#include <main_game.h>
#include <iostream>


void mainCallBack()
{
	std::cout << "Callback" << std::endl;
}

MainGame::MainGame()
{
	window_.create(sf::VideoMode(800, 600), "SFML works!");

	button_.CreatButton(sf::Vector2f(200, 100), "Test", 25, sf::Color::Blue);
	button_.setScale(0.8f, 0.8f);

	//First Exemple
	button_.call_back_ = mainCallBack;

	//Second Exemple
	//button_.callBack_ = [] { std::cout << "Callback" << std::endl; };
}

void MainGame::GameLoop()
{
	while (window_.isOpen())
	{
		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();
			button_.HandleEvent(event);
		}



		window_.clear();
		window_.draw(button_);
		//tilemap_.DrawMap(window_);
		window_.display();
	}
}

