#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <ui/UIButton.h>


UiButton::UiButton(float pos_x, float pos_y, float size_x, float size_y, sf::Color _color, std::string text, int character_size, sf::Color _color_text)
{
	background_ = std::make_unique<sf::RectangleShape>(sf::Vector2f(size_x, size_y));
	background_->setFillColor(_color);
	background_->setPosition(pos_x, pos_y);

	if (!font_.loadFromFile("C:/Users/Anthony Barman/Desktop/Jeux en dev/VirtualStudio/C++/CityBuilder/font/light-arial.ttf")) {
		// Gérer l'erreur : impossible de charger la police
	}

	buttonText_.setFont(font_);
	buttonText_.setString(text);
	buttonText_.setCharacterSize(character_size);
	buttonText_.setFillColor(_color_text);
	sf::FloatRect textRect = buttonText_.getLocalBounds();
	sf::FloatRect shapeRect = background_->getGlobalBounds();
	buttonText_.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	buttonText_.setPosition(shapeRect.left + shapeRect.width / 2.0f, shapeRect.top + shapeRect.height / 2.0f);
}

UiButton::UiButton(float pos_x, float pos_y, float radius, sf::Color _color, std::string text, int character_size, sf::Color _color_text)
{
	background_ = std::make_unique<sf::CircleShape>(radius);
	background_->setFillColor(_color);
	background_->setPosition(pos_x, pos_y);

	if (!font_.loadFromFile("C:/Users/Anthony Barman/Desktop/Jeux en dev/VirtualStudio/C++/CityBuilder/font/light-arial.ttf")) {
		// Gérer l'erreur : impossible de charger la police
	}

	buttonText_.setFont(font_);
	buttonText_.setString(text);
	buttonText_.setCharacterSize(character_size);
	buttonText_.setFillColor(_color_text);
	sf::FloatRect textRect = buttonText_.getLocalBounds();
	sf::FloatRect shapeRect = background_->getGlobalBounds();
	buttonText_.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	buttonText_.setPosition(shapeRect.left + shapeRect.width / 2.0f, shapeRect.top + shapeRect.height / 2.0f);
}

void UiButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(*background_, states);
	target.draw(buttonText_, states);

}

void const UiButton::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			float mouseX = static_cast<float>(event.mouseButton.x);
			float mouseY = static_cast<float>(event.mouseButton.y);

			if (background_->getGlobalBounds().contains(mouseX, mouseY))
			{
				std::cout << "Start" << std::endl;
			}
		}
	}
}

