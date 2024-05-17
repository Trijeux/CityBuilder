#include <SFML/Graphics.hpp>
#include <maths/vec2i.h>
#include <ui/UIButton.h>

int main()
{
    core::Vec2i v;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    UiButton startButton(50,50,100,50,sf::Color::Red,"Test",50,sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            startButton.handleEvent(event);
        }

        

        window.clear();
        window.draw(startButton);
        window.display();
    }

    return 0;
}