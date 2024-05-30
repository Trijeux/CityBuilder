#ifndef API_UI_UIBUTTON_H_
#define API_UI_UIBUTTON_H_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>

class UiButton : public sf::Drawable, public sf::Transformable
{
	sf::Font font_;
	sf::Sprite sprite_;
	sf::Text buttonText_;
	sf::Texture texture;
	//sf::Vector2f initialScale_;
	bool ContainsMouse(const sf::Event& event);

public:

	UiButton(sf::Vector2f pos, /*sf::Vector2f scale_Origin,*/ std::string text, int character_size, sf::Color color_text);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void HandleEvent(const sf::Event& event);

};

#endif // API_UI_UIBUTTON_H_

