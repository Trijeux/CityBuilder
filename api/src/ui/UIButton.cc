#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <ui/UIButton.h>


UiButton::UiButton(sf::Vector2f pos, /*sf::Vector2f scale_Origin,*/ std::string text, int character_size, sf::Color color_text)
{
	if (!font_.loadFromFile("ressources/fonts/kenvector_future.ttf")) {
		// Gérer l'erreur : impossible de charger la police
	}

	buttonText_.setFont(font_);
	buttonText_.setString(text);
	setPosition(pos);
	buttonText_.setCharacterSize(character_size);
	buttonText_.setFillColor(color_text);
	sf::FloatRect textRect = buttonText_.getLocalBounds();
	sf::FloatRect shapeRect = sprite_.getGlobalBounds();
	buttonText_.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	buttonText_.setPosition(shapeRect.left + shapeRect.width / 2.0f, shapeRect.top + shapeRect.height / 2.0f);

	texture.loadFromFile("ressources/UI/blue_button00.png");

	sprite_.setTexture(texture);
	sprite_.setOrigin(sprite_.getGlobalBounds().width / 2.0f, sprite_.getGlobalBounds().height / 2.0f);
	sprite_.setColor(sf::Color::White);

	setScale(1, 1);
}


void UiButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite_, states);
	target.draw(buttonText_, states);

}

bool UiButton::ContainsMouse(const sf::Event& event)
{
	// Get the position of the mouse click
	float mouseX = static_cast<float>(event.mouseButton.x) - getPosition().x;
	float mouseY = static_cast<float>(event.mouseButton.y) - getPosition().y;

	// Check if the mouse click is inside the drawable shape
	if (sprite_.getGlobalBounds().contains(mouseX, mouseY)) {
		return true;
	}
	else
	{
		return false;
	}
}

void UiButton::HandleEvent(const sf::Event& event)
{

	// Check for mouse button pressed event
	if (event.type == sf::Event::MouseButtonReleased) {

		setScale(getScale().x / 0.9f, getScale().y / 0.9f);

		if (ContainsMouse(event))
		{
			// Check if the left mouse button is pressed
			if (event.mouseButton.button == sf::Mouse::Left) {

				//std::cout << "Start" << std::endl;
				//Code ? faire pour le boutton
				if (callback_) { callback_(); }
				else{ std::cout << "No Callback !!!" << std::endl; }

			}
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (ContainsMouse(event))
		{
			setScale(0.9f * getScale().x, 0.9f * getScale().y);
		}
	}
}

