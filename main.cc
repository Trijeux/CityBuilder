#include <SFML/Graphics.hpp>
#include <maths/vec2i.h>
#include <ui/UIButton.h>
#include <graphics/Tilemap.h>


void mainCallBack()
{
	std::cout << "Callback" << std::endl;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	//UiButton startButton(sf::Vector2f(200, 100), "Test", 25, sf::Color::Blue);
	//startButton.setScale(0.8f, 0.8f);
	////First Exemple
	//startButton.callBack_ = mainCallBack;

	////Second Exemple
	//startButton.callBack_ = [] { std::cout << "Callback" << std::endl; };

	Tilemap test;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//startButton.HandleEvent(event);
		}



		window.clear();
		//window.draw(startButton);
		test.DrawMap(window);
		window.display();
	}

	return 0;
}