#include <SFML/Graphics.hpp>
#include <maths/vec2i.h>
#include <ui/UIButton.h>

int main()
{
	core::Vec2i v;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	UiButton startButton(sf::Vector2f(200, 100), "Test", 25, sf::Color::Blue);
	//startButton.setScale(0.5, 0.5);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			startButton.HandleEvent(event);
		}



		window.clear();
		window.draw(startButton);
		window.display();
	}

	return 0;
}