#ifndef API_UI_UIBUTTON_H_
#define API_UI_UIBUTTON_H_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>

class UiButton : public sf::Drawable, sf::Transformable
{
	sf::Font font_;
	sf::Text buttonText_;
	sf::Color colorButton_ = sf::Color::Black;
	std::unique_ptr<sf::Shape> background_;

public:
	
	UiButton(float pos_x, float pos_y, float size_x, float size_y, sf::Color _color, std::string text, int character_size, sf::Color _color_text);
	UiButton(float pos_x, float pos_y, float radius, sf::Color _color, std::string text, int character_size, sf::Color _color_text);


	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void const handleEvent(const sf::Event& event);

};

#endif // API_UI_UIBUTTON_H_

