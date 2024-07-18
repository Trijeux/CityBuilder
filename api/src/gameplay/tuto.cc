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

	text_objective_.setFont(font_);
	text_objective_.setString("Objective");
	text_objective_.setColor(sf::Color::White);
	text_objective_.setOrigin(text_objective_.getGlobalBounds().width / 2, text_objective_.getGlobalBounds().height / 2);
	tuto_objective_.setFont(font_);
	tuto_objective_.setString("Build a castle /      to win \nand manage to pay the tax");
	tuto_objective_.setColor(sf::Color::White);
	tuto_objective_.setScale(0.5f, 0.5f);
	tuto_objective_.setOrigin(tuto_objective_.getGlobalBounds().width / 2, tuto_objective_.getGlobalBounds().height / 2);
	tuto_castle_sprite_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kCastle));
	tuto_castle_sprite_.setOrigin(tuto_castle_sprite_.getGlobalBounds().width / 2, tuto_castle_sprite_.getGlobalBounds().height / 2);

	text_price_.setFont(font_);
	text_price_.setString("Price");
	text_price_.setColor(sf::Color::White);
	text_price_.setOrigin(text_price_.getGlobalBounds().width / 2, text_price_.getGlobalBounds().height / 2);

	text_home_.setFont(font_);
	text_home_.setString("Home");
	text_home_.setColor(sf::Color::White);
	text_home_.setOrigin(text_home_.getGlobalBounds().width / 2, text_home_.getGlobalBounds().height / 2);
	text_price_home_gold_.setFont(font_);
	text_price_home_gold_.setString("200 Gold");
	text_price_home_gold_.setColor(sf::Color::Yellow);
	text_price_home_gold_.setScale(0.5f, 0.5f);
	text_price_home_gold_.setOrigin(text_price_home_gold_.getGlobalBounds().width / 2, text_price_home_gold_.getGlobalBounds().height / 2);
	text_price_home_food_.setFont(font_);
	text_price_home_food_.setString("100 Food");
	text_price_home_food_.setColor(sf::Color::Green);
	text_price_home_food_.setScale(0.5f, 0.5f);
	text_price_home_food_.setOrigin(text_price_home_food_.getGlobalBounds().width / 2, text_price_home_food_.getGlobalBounds().height / 2);

	text_farm_.setFont(font_);
	text_farm_.setString("Farm");
	text_farm_.setColor(sf::Color::White);
	text_farm_.setOrigin(text_farm_.getGlobalBounds().width / 2, text_farm_.getGlobalBounds().height / 2);
	text_price_farm_gold_.setFont(font_);
	text_price_farm_gold_.setString("100 Gold");
	text_price_farm_gold_.setColor(sf::Color::Yellow);
	text_price_farm_gold_.setScale(0.5f, 0.5f);
	text_price_farm_gold_.setOrigin(text_price_farm_gold_.getGlobalBounds().width / 2, text_price_farm_gold_.getGlobalBounds().height / 2);

	text_orchard_.setFont(font_);
	text_orchard_.setString("Orchard");
	text_orchard_.setColor(sf::Color::White);
	text_orchard_.setOrigin(text_orchard_.getGlobalBounds().width / 2, text_orchard_.getGlobalBounds().height / 2);
	text_price_orchard_gold_.setFont(font_);
	text_price_orchard_gold_.setString("300 Gold");
	text_price_orchard_gold_.setColor(sf::Color::Yellow);
	text_price_orchard_gold_.setScale(0.5f, 0.5f);
	text_price_orchard_gold_.setOrigin(text_price_orchard_gold_.getGlobalBounds().width / 2, text_price_orchard_gold_.getGlobalBounds().height / 2);
	text_price_orchard_food_.setFont(font_);
	text_price_orchard_food_.setString("200 Food");
	text_price_orchard_food_.setColor(sf::Color::Green);
	text_price_orchard_food_.setScale(0.5f, 0.5f);
	text_price_orchard_food_.setOrigin(text_price_orchard_food_.getGlobalBounds().width / 2, text_price_orchard_food_.getGlobalBounds().height / 2);

	text_mine_.setFont(font_);
	text_mine_.setString("Mine");
	text_mine_.setColor(sf::Color::White);
	text_mine_.setOrigin(text_mine_.getGlobalBounds().width / 2, text_mine_.getGlobalBounds().height / 2);
	text_price_mine_gold_.setFont(font_);
	text_price_mine_gold_.setString("400 Gold");
	text_price_mine_gold_.setColor(sf::Color::Yellow);
	text_price_mine_gold_.setScale(0.5f, 0.5f);
	text_price_mine_gold_.setOrigin(text_price_mine_gold_.getGlobalBounds().width / 2, text_price_mine_gold_.getGlobalBounds().height / 2);
	text_price_mine_food_.setFont(font_);
	text_price_mine_food_.setString("300 Food");
	text_price_mine_food_.setColor(sf::Color::Green);
	text_price_mine_food_.setScale(0.5f, 0.5f);
	text_price_mine_food_.setOrigin(text_price_mine_food_.getGlobalBounds().width / 2, text_price_mine_food_.getGlobalBounds().height / 2);
	text_price_mine_wood_.setFont(font_);
	text_price_mine_wood_.setString("100 Wood");
	text_price_mine_wood_.setColor(sf::Color(222,134,17));
	text_price_mine_wood_.setScale(0.5f, 0.5f);
	text_price_mine_wood_.setOrigin(text_price_mine_wood_.getGlobalBounds().width / 2, text_price_mine_wood_.getGlobalBounds().height / 2);


	text_castle_.setFont(font_);
	text_castle_.setString("Castle");
	text_castle_.setColor(sf::Color::White);
	text_castle_.setOrigin(text_castle_.getGlobalBounds().width / 2, text_castle_.getGlobalBounds().height / 2);
	text_price_castle_gold_.setFont(font_);
	text_price_castle_gold_.setString("50'000 Gold");
	text_price_castle_gold_.setColor(sf::Color::Yellow);
	text_price_castle_gold_.setScale(0.5f, 0.5f);
	text_price_castle_gold_.setOrigin(text_price_castle_gold_.getGlobalBounds().width / 2, text_price_castle_gold_.getGlobalBounds().height / 2);
	text_price_castle_food_.setFont(font_);
	text_price_castle_food_.setString("25'000 Food");
	text_price_castle_food_.setColor(sf::Color::Green);
	text_price_castle_food_.setScale(0.5f, 0.5f);
	text_price_castle_food_.setOrigin(text_price_castle_food_.getGlobalBounds().width / 2, text_price_castle_food_.getGlobalBounds().height / 2);
	text_price_castle_wood_.setFont(font_);
	text_price_castle_wood_.setString("12'500 Wood");
	text_price_castle_wood_.setColor(sf::Color(222, 134, 17));
	text_price_castle_wood_.setScale(0.5f, 0.5f);
	text_price_castle_wood_.setOrigin(text_price_castle_wood_.getGlobalBounds().width / 2, text_price_castle_wood_.getGlobalBounds().height / 2);
	text_price_castle_stone_.setFont(font_);
	text_price_castle_stone_.setString("10'000 Stone");
	text_price_castle_stone_.setColor(sf::Color(182,182,182));
	text_price_castle_stone_.setScale(0.5f, 0.5f);
	text_price_castle_stone_.setOrigin(text_price_castle_stone_.getGlobalBounds().width / 2, text_price_castle_stone_.getGlobalBounds().height / 2);
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

	text_objective_.setPosition(window.getSize().x - (box_.getSize().x / 2), window.getSize().y - (box_.getSize().y - 300));
	tuto_objective_.setPosition(window.getSize().x - ((box_.getSize().x / 2) + 55), window.getSize().y - (box_.getSize().y - 350));
	tuto_castle_sprite_.setPosition(window.getSize().x - ((box_.getSize().x / 2 ) - 50), window.getSize().y - (box_.getSize().y - 352));

	text_price_.setPosition(window.getSize().x - (box_.getSize().x / 2), window.getSize().y - (box_.getSize().y - 20));

	text_home_.setPosition(window.getSize().x - (box_.getSize().x - 75), window.getSize().y - (box_.getSize().y - 75));
	text_price_home_gold_.setPosition(window.getSize().x - (box_.getSize().x - 54), window.getSize().y - (box_.getSize().y - 100));
	text_price_home_food_.setPosition(window.getSize().x - (box_.getSize().x - 54), window.getSize().y - (box_.getSize().y - 115));

	text_farm_.setPosition(window.getSize().x - (box_.getSize().x - 300), window.getSize().y - (box_.getSize().y - 72));
	text_price_farm_gold_.setPosition(window.getSize().x - (box_.getSize().x - 276), window.getSize().y - (box_.getSize().y - 97));

	text_orchard_.setPosition(window.getSize().x - (box_.getSize().x - 90), window.getSize().y - (box_.getSize().y - 200));
	text_price_orchard_gold_.setPosition(window.getSize().x - (box_.getSize().x - 65), window.getSize().y - (box_.getSize().y - 225));
	text_price_orchard_food_.setPosition(window.getSize().x - (box_.getSize().x - 65), window.getSize().y - (box_.getSize().y - 240));

	text_mine_.setPosition(window.getSize().x - (box_.getSize().x - 300), window.getSize().y - (box_.getSize().y - 197));
	text_price_mine_gold_.setPosition(window.getSize().x - (box_.getSize().x - 276), window.getSize().y - (box_.getSize().y - 225));
	text_price_mine_food_.setPosition(window.getSize().x - (box_.getSize().x - 276), window.getSize().y - (box_.getSize().y - 240));
	text_price_mine_wood_.setPosition(window.getSize().x - (box_.getSize().x - 276), window.getSize().y - (box_.getSize().y - 255));

	text_castle_.setPosition(window.getSize().x - ((box_.getSize().x / 2) + 5), window.getSize().y - (box_.getSize().y - 300));
	text_price_castle_gold_.setPosition(window.getSize().x - (box_.getSize().x - 60), window.getSize().y - (box_.getSize().y - 335));
	text_price_castle_food_.setPosition(window.getSize().x - (box_.getSize().x - 60), window.getSize().y - (box_.getSize().y - 355));
	text_price_castle_wood_.setPosition(window.getSize().x - (box_.getSize().x - 260), window.getSize().y - (box_.getSize().y - 335));
	text_price_castle_stone_.setPosition(window.getSize().x - (box_.getSize().x - 260), window.getSize().y - (box_.getSize().y - 355));
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

		window.draw(text_objective_);
		window.draw(tuto_objective_);
		window.draw(tuto_castle_sprite_);
	}
	break;
	case TypeTuto::kPrice:
	{
		window.draw(text_price_);

		window.draw(text_home_);
		window.draw(text_price_home_gold_);
		window.draw(text_price_home_food_);

		window.draw(text_farm_);
		window.draw(text_price_farm_gold_);

		window.draw(text_orchard_);
		window.draw(text_price_orchard_gold_);
		window.draw(text_price_orchard_food_);

		window.draw(text_mine_);
		window.draw(text_price_mine_gold_);
		window.draw(text_price_mine_food_);
		window.draw(text_price_mine_wood_);

		window.draw(text_castle_);
		window.draw(text_price_castle_gold_);
		window.draw(text_price_castle_food_);
		window.draw(text_price_castle_wood_);
		window.draw(text_price_castle_stone_);
	}
	break;
	}
	
	
}
