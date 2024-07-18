#ifndef GAMEPLAY_TUTO_H
#define GAMEPLAY_TUTO_H
#include <SFML/Graphics.hpp>



class Tuto
{
public:
	enum class TypeTuto
	{
		kTuto,
		kPrice
	};

	Tuto();

	void SetupBox(const sf::RenderWindow&);

	void SetupTextInBox(const sf::RenderWindow& window);

	void Draw(sf::RenderWindow& window, TypeTuto) const;

private:

	sf::RectangleShape box_;

	sf::Font font_;

	sf::Text text_tuto_;

	sf::Text tuto_resource_home_;
	sf::Sprite tuto_home_sprite_;
	sf::Sprite tuto_gold_sprite_;
	sf::Texture tuto_gold_texture_;

	sf::Text tuto_resource_farm_;
	sf::Sprite tuto_farm_sprite_;
	sf::Sprite tuto_food_sprite_;
	sf::Texture tuto_food_texture_;

	sf::Text tuto_resource_orchard_;
	sf::Sprite tuto_orchard_sprite_;
	sf::Sprite tuto_wood_sprite_;
	sf::Texture tuto_wood_texture_;

	sf::Text tuto_resource_mine_;
	sf::Sprite tuto_mine_sprite_;
	sf::Sprite tuto_stone_sprite_;
	sf::Texture tuto_stone_texture_;

	sf::Text tuto_tax_amount_;
	sf::Sprite tuto_tax_sprite_;
	sf::Texture tuto_tax_texture_;

	sf::Text tuto_pay_tax_time_;

	sf::Text text_objective_;
	sf::Text tuto_objective_;
	sf::Sprite tuto_castle_sprite_;

	sf::Text text_price_;

	sf::Text text_home_;
	sf::Text text_price_home_;

	sf::Text text_farm_;
	sf::Text text_price_farm_;

	sf::Text text_orchard_;
	sf::Text text_price_orchard_;

	sf::Text text_mine_;
	sf::Text text_price_mine_;

	sf::Text text_castle_;
	sf::Text text_price_castle_;
};

#endif // GAMEPLAY_TUTO_H
