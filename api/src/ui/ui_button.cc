#include "ui/ui_button.h"

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

bool UiButton::HandleEvent(const sf::Event& event)
{
	// Check for mouse button pressed event
	if (event.type == sf::Event::MouseButtonReleased) {

		if (ContainsMouse(event))
		{
			setScale(getScale().x / 0.9f, getScale().y / 0.9f);

			// Check if the left mouse button is pressed
			if (event.mouseButton.button == sf::Mouse::Left) 
			{
				if (call_back_)
				{
					call_back_();
				}
				else
				{
					
				}

			}
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (ContainsMouse(event))
		{
			setScale(0.9f * getScale().x, 0.9f * getScale().y);
			build_on_ = true;
		}
	}

	if (ContainsMouse(event))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UiButton::CreateButton(const sf::Vector2f pos, const std::string& text, const int character_size, const sf::Color color_text)
{
	if (!font_.loadFromFile("ressources/fonts/kenvector_future.ttf")) {
		// Handle error: Unable to load font
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

	build_on_ = false;
}





