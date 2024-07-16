#ifndef API_UI_UIBUTTON_H_
#define API_UI_UIBUTTON_H_

#include <functional>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>

enum class Build;

class UiButton : public sf::Drawable, public sf::Transformable
{
	sf::Font font_;
	sf::Sprite sprite_;
	sf::Text button_text_;
	sf::Texture texture_;
	

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool ContainsMouse(const sf::Event& event) const;

public:

	void Set_Color_Sprite(sf::Color color) { sprite_.setColor(color); }

	bool HandleEvent(const sf::Event& event);
	void CreatButton(sf::Vector2f pos, std::string text, int character_size, sf::Color color_text);
	

	bool build_on_;

	std::function<void()> call_back_;
};

#endif // API_UI_UIBUTTON_H_

