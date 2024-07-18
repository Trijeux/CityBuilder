#include "gameplay/tuto.h"
#include "gameplay/tuto.h"

#include "graphics/ressource_manager.h"

Tuto::Tuto()
{
	// Load font file and handle error if not loaded
	if (!font_.loadFromFile("ressources/fonts/kenvector_future.ttf")) {
		// Handle error: Unable to load font
	}

	text_tuto_.setFont(font_);
	text_tuto_.setString("Tuto");
	text_tuto_.setColor(sf::Color::White);
	text_tuto_.setOrigin(text_tuto_.getGlobalBounds().width / 2, text_tuto_.getGlobalBounds().height / 2);


	tuto_resource_home_.setFont(font_);
	tuto_resource_home_.setString("1 Home /      = 1 Gold /      /s");
	tuto_resource_home_.setColor(sf::Color::White);
	tuto_resource_home_.setScale(0.5f, 0.5f);
	tuto_resource_home_.setOrigin(tuto_resource_home_.getGlobalBounds().width / 2, tuto_resource_home_.getGlobalBounds().height / 2);
	tuto_home_sprite_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kHome));
	tuto_home_sprite_.setOrigin(tuto_home_sprite_.getGlobalBounds().width / 2, tuto_home_sprite_.getGlobalBounds().height / 2);
	tuto_gold_texture_.loadFromFile("ressources/tile/Ressource_Or.png");
	tuto_gold_sprite_.setTexture(tuto_gold_texture_);
	tuto_gold_sprite_.setOrigin(tuto_gold_sprite_.getGlobalBounds().width / 2, tuto_gold_sprite_.getGlobalBounds().height / 2);


	tuto_resource_farm_.setFont(font_);
	tuto_resource_farm_.setString("1 Farm /      = 1 Food /      /s");
	tuto_resource_farm_.setColor(sf::Color::White);
	tuto_resource_farm_.setScale(0.5f, 0.5f);
	tuto_resource_farm_.setOrigin(tuto_resource_farm_.getGlobalBounds().width / 2, tuto_resource_farm_.getGlobalBounds().height / 2);
	tuto_farm_sprite_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kFarm));
	tuto_farm_sprite_.setOrigin(tuto_farm_sprite_.getGlobalBounds().width / 2, tuto_farm_sprite_.getGlobalBounds().height / 2);
	tuto_food_texture_.loadFromFile("ressources/tile/Resource_nouriture.png");
	tuto_food_sprite_.setTexture(tuto_food_texture_);
	tuto_food_sprite_.setOrigin(tuto_food_sprite_.getGlobalBounds().width / 2, tuto_food_sprite_.getGlobalBounds().height / 2);

	tuto_resource_orchard_.setFont(font_);
	tuto_resource_orchard_.setString("1 Orchard /      = 1 Wood /      /s");
	tuto_resource_orchard_.setColor(sf::Color::White);
	tuto_resource_orchard_.setScale(0.5f, 0.5f);
	tuto_resource_orchard_.setOrigin(tuto_resource_orchard_.getGlobalBounds().width / 2, tuto_resource_orchard_.getGlobalBounds().height / 2);
	tuto_orchard_sprite_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kOrchard));
	tuto_orchard_sprite_.setOrigin(tuto_orchard_sprite_.getGlobalBounds().width / 2, tuto_orchard_sprite_.getGlobalBounds().height / 2);
	tuto_wood_texture_.loadFromFile("ressources/tile/Resource_boit.png");
	tuto_wood_sprite_.setTexture(tuto_wood_texture_);
	tuto_wood_sprite_.setOrigin(tuto_wood_sprite_.getGlobalBounds().width / 2, tuto_wood_sprite_.getGlobalBounds().height / 2);

	tuto_resource_mine_.setFont(font_);
	tuto_resource_mine_.setString("1 Mine /      = 1 Stone /      /s");
	tuto_resource_mine_.setColor(sf::Color::White);
	tuto_resource_mine_.setScale(0.5f, 0.5f);
	tuto_resource_mine_.setOrigin(tuto_resource_mine_.getGlobalBounds().width / 2, tuto_resource_mine_.getGlobalBounds().height / 2);
	tuto_mine_sprite_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kMine));
	tuto_mine_sprite_.setOrigin(tuto_mine_sprite_.getGlobalBounds().width / 2, tuto_mine_sprite_.getGlobalBounds().height / 2);
	tuto_stone_texture_.loadFromFile("ressources/tile/Resource_pierre.png");
	tuto_stone_sprite_.setTexture(tuto_stone_texture_);
	tuto_stone_sprite_.setOrigin(tuto_stone_sprite_.getGlobalBounds().width / 2, tuto_stone_sprite_.getGlobalBounds().height / 2);

	tuto_tax_amount_.setFont(font_);
	tuto_tax_amount_.setString("Tax Amount = ");
	tuto_tax_amount_.setColor(sf::Color::White);
	tuto_tax_amount_.setScale(0.5f, 0.5f);
	tuto_tax_amount_.setOrigin(tuto_tax_amount_.getGlobalBounds().width / 2, tuto_tax_amount_.getGlobalBounds().height / 2);
	tuto_tax_texture_.loadFromFile("ressources/tile/Taxe.png");
	tuto_tax_sprite_.setTexture(tuto_tax_texture_);
	tuto_tax_sprite_.setScale(2, 2);
	tuto_tax_sprite_.setOrigin(tuto_tax_sprite_.getGlobalBounds().width / 2, tuto_tax_sprite_.getGlobalBounds().height / 2);

	tuto_pay_tax_time_.setFont(font_);
	tuto_pay_tax_time_.setString("Pay every 300 second");
	tuto_pay_tax_time_.setColor(sf::Color::White);
	tuto_pay_tax_time_.setScale(0.5f, 0.5f);
	tuto_pay_tax_time_.setOrigin(tuto_tax_amount_.getGlobalBounds().width / 2, tuto_tax_amount_.getGlobalBounds().height / 2);
}

void Tuto::SetupBox(const sf::RenderWindow& window)
{
	box_.setSize(sf::Vector2f(window.getSize().x / 4, window.getSize().y / 2));
	box_.setPosition(window.getSize().x, window.getSize().y);
	box_.setOrigin(box_.getGlobalBounds().width, box_.getGlobalBounds().height);
	box_.setFillColor(sf::Color::Black);
}

void Tuto::SetupTextInBox(const sf::RenderWindow& window)
{
	text_tuto_.setPosition(window.getSize().x - (box_.getSize().x / 2), window.getSize().y - (box_.getSize().y - 20));

	tuto_resource_home_.setPosition(window.getSize().x - (box_.getSize().x - 80), window.getSize().y - (box_.getSize().y - 60));
	tuto_home_sprite_.setPosition(window.getSize().x - (box_.getSize().x - 110), window.getSize().y - (box_.getSize().y - 65));
	tuto_gold_sprite_.setPosition(window.getSize().x - (box_.getSize().x - 222), window.getSize().y - (box_.getSize().y - 65));

	tuto_resource_farm_.setPosition(window.getSize().x - (box_.getSize().x - 80), window.getSize().y - (box_.getSize().y - 90));
	tuto_farm_sprite_.setPosition(window.getSize().x - (box_.getSize().x - 110), window.getSize().y - (box_.getSize().y - 95));
	tuto_food_sprite_.setPosition(window.getSize().x - (box_.getSize().x - 222), window.getSize().y - (box_.getSize().y - 95));

	tuto_resource_orchard_.setPosition(window.getSize().x - (box_.getSize().x - 90), window.getSize().y - (box_.getSize().y - 120));
	tuto_orchard_sprite_.setPosition(window.getSize().x - (box_.getSize().x - 145), window.getSize().y - (box_.getSize().y - 125));
	tuto_wood_sprite_.setPosition(window.getSize().x - (box_.getSize().x - 260), window.getSize().y - (box_.getSize().y - 125));

	tuto_resource_mine_.setPosition(window.getSize().x - (box_.getSize().x - 84), window.getSize().y - (box_.getSize().y - 150));
	tuto_mine_sprite_.setPosition(window.getSize().x - (box_.getSize().x - 105), window.getSize().y - (box_.getSize().y - 155));
	tuto_stone_sprite_.setPosition(window.getSize().x - (box_.getSize().x - 230), window.getSize().y - (box_.getSize().y - 155));

	tuto_tax_amount_.setPosition(window.getSize().x - (box_.getSize().x - 62), window.getSize().y - (box_.getSize().y - 190));
	tuto_tax_sprite_.setPosition(window.getSize().x - (box_.getSize().x - 185), window.getSize().y - (box_.getSize().y - 204));

	tuto_pay_tax_time_.setPosition(window.getSize().x - (box_.getSize().x - 62), window.getSize().y - (box_.getSize().y - 220));
}

void Tuto::Draw(sf::RenderWindow& window, const TypeTuto type) const
{
	window.draw(box_);
	switch (type)
	{
	case TypeTuto::kTuto:
	{
		window.draw(text_tuto_);

		window.draw(tuto_resource_home_);
		window.draw(tuto_home_sprite_);
		window.draw(tuto_gold_sprite_);

		window.draw(tuto_resource_farm_);
		window.draw(tuto_farm_sprite_);
		window.draw(tuto_food_sprite_);

		window.draw(tuto_resource_orchard_);
		window.draw(tuto_orchard_sprite_);
		window.draw(tuto_wood_sprite_);

		window.draw(tuto_resource_mine_);
		window.draw(tuto_mine_sprite_);
		window.draw(tuto_stone_sprite_);

		window.draw(tuto_tax_amount_);
		window.draw(tuto_tax_sprite_);

		window.draw(tuto_pay_tax_time_);
	}
	break;
	case TypeTuto::kPrice:
	{

	}
	break;
	}
	
	
}
