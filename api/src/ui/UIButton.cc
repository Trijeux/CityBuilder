#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <ui/UIButton.h>

void UiButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(sprite_, states);
	target.draw(button_text_, states);

}

bool UiButton::ContainsMouse(const sf::Event& event) const
{
	// Get the position of the mouse click
	const float mouse_x = static_cast<float>(event.mouseButton.x) - getPosition().x;
	const float mouse_y = static_cast<float>(event.mouseButton.y) - getPosition().y;

	// Check if the mouse click is inside the drawable shape
	if (sprite_.getGlobalBounds().contains(mouse_x, mouse_y)) {
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
				if (call_back_) { call_back_(); }
				else { std::cout << "No Callback !!!" << std::endl; }

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

void UiButton::CreatButton(sf::Vector2f pos, std::string text, int character_size, sf::Color color_text)
{
	if (!font_.loadFromFile("ressources/fonts/kenvector_future.ttf")) {
		// Gérer l'erreur : impossible de charger la police
	}

	button_text_.setFont(font_);
	button_text_.setString(text);
	setPosition(pos);
	button_text_.setCharacterSize(character_size);
	button_text_.setFillColor(color_text);
	const sf::FloatRect text_rect = button_text_.getLocalBounds();
	const sf::FloatRect shape_rect = sprite_.getGlobalBounds();
	button_text_.setOrigin(text_rect.left + text_rect.width / 2.0f, text_rect.top + text_rect.height / 2.0f);
	button_text_.setPosition(shape_rect.left + shape_rect.width / 2.0f, shape_rect.top + shape_rect.height / 2.0f);

	texture_.loadFromFile("ressources/UI/blue_button00.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(sprite_.getGlobalBounds().width / 2.0f, sprite_.getGlobalBounds().height / 2.0f);
	sprite_.setColor(sf::Color::White);

	setScale(1, 1);
}



