#ifndef API_UI_UI_BUTTON_H
#define API_UI_UI_BUTTON_H

#include <functional>
#include <string>
#include <SFML/Graphics.hpp>



class UiButton final : public sf::Drawable, public sf::Transformable
{
	sf::Font font_;
	sf::Sprite sprite_;
	sf::Text button_text_;
	sf::Texture texture_;
	

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool ContainsMouse(const sf::Event& event) const;

public:

	void SetColorSprite(const sf::Color color) { sprite_.setColor(color); }

	bool HandleEvent(const sf::Event& event);
	void CreateButton(sf::Vector2f pos, const std::string& text, int character_size, sf::Color color_text);
	

	bool build_on_;

	std::function<void()> call_back_;
};

#endif // API_UI_UI_BUTTON_H

