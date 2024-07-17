#include "gameplay/game_ressource.h"


GameResource::GameResource()
{
	if (!font_.loadFromFile("ressources/fonts/kenvector_future.ttf")) {
		// Handle error: Unable to load font
	}

	text_gold_.setFont(font_);
	text_food_.setFont(font_);
	text_wood_.setFont(font_);
	text_stone_.setFont(font_);
	text_tax_.setFont(font_);
	text_gold_.setString(std::to_string(gold_));
	text_food_.setString(std::to_string(food_));
	text_wood_.setString(std::to_string(wood_));
	text_stone_.setString(std::to_string(stone_));
	text_tax_.setString(std::to_string(tax_));

	text_gold_.setColor(sf::Color::Black);
	text_food_.setColor(sf::Color::Black);
	text_wood_.setColor(sf::Color::Black);
	text_stone_.setColor(sf::Color::Black);
	text_tax_.setColor(sf::Color::Black);

	text_gold_.setOrigin(text_gold_.getGlobalBounds().width / 2.0f, text_gold_.getGlobalBounds().height / 2.0f);
	text_food_.setOrigin(text_food_.getGlobalBounds().width / 2.0f, text_food_.getGlobalBounds().height / 2.0f);
	text_wood_.setOrigin(text_wood_.getGlobalBounds().width / 2.0f, text_wood_.getGlobalBounds().height / 2.0f);
	text_stone_.setOrigin(text_stone_.getGlobalBounds().width / 2.0f, text_stone_.getGlobalBounds().height / 2.0f);
	text_tax_.setOrigin(text_tax_.getGlobalBounds().width / 2.0f, text_tax_.getGlobalBounds().height / 2.0f);

	texture_gold_.loadFromFile("ressources/tile/Ressource_Or.png");
	sprite_gold_.setTexture(texture_gold_);
	sprite_gold_.setOrigin(sprite_gold_.getGlobalBounds().width / 2.0f, sprite_gold_.getGlobalBounds().height / 2.0f);
	sprite_gold_.setColor(sf::Color::White);
	sprite_gold_.setScale(2, 2);

	texture_food_.loadFromFile("ressources/tile/Resource_nouriture.png");
	sprite_food_.setTexture(texture_food_);
	sprite_food_.setOrigin(sprite_food_.getGlobalBounds().width / 2.0f, sprite_food_.getGlobalBounds().height / 2.0f);
	sprite_food_.setColor(sf::Color::White);
	sprite_food_.setScale(2, 2);

	texture_wood_.loadFromFile("ressources/tile/Resource_boit.png");
	sprite_wood_.setTexture(texture_wood_);
	sprite_wood_.setOrigin(sprite_wood_.getGlobalBounds().width / 2.0f, sprite_wood_.getGlobalBounds().height / 2.0f);
	sprite_wood_.setColor(sf::Color::White);
	sprite_wood_.setScale(2, 2);

	texture_stone_.loadFromFile("ressources/tile/Resource_pierre.png");
	sprite_stone_.setTexture(texture_stone_);
	sprite_stone_.setOrigin(sprite_stone_.getGlobalBounds().width / 2.0f, sprite_stone_.getGlobalBounds().height / 2.0f);
	sprite_stone_.setColor(sf::Color::White);
	sprite_stone_.setScale(2, 2);

	texture_tax_.loadFromFile("ressources/tile/Taxe.png");
	sprite_tax_.setTexture(texture_tax_);
	sprite_tax_.setOrigin(sprite_tax_.getGlobalBounds().width / 2.0f, sprite_tax_.getGlobalBounds().height / 2.0f);
	sprite_tax_.setColor(sf::Color::White);
	sprite_tax_.setScale(4, 4);

	one_second_last_ = std::chrono::high_resolution_clock::now();
	tax_second_last_ = one_second_last_;
}

void GameResource::SetUiPosition(const sf::RenderWindow& window)
{
	sprite_tax_.setPosition(100, 50);
	sprite_gold_.setPosition(window.getSize().x - 600, 50);
	sprite_food_.setPosition(window.getSize().x - 450, 50);
	sprite_wood_.setPosition(window.getSize().x - 300, 50);
	sprite_stone_.setPosition(window.getSize().x - 150, 50);

	text_tax_.setPosition(sprite_tax_.getPosition().x + 50, 50);
	text_gold_.setPosition(sprite_gold_.getPosition().x + 50, 50);
	text_food_.setPosition(sprite_food_.getPosition().x + 50, 50);
	text_wood_.setPosition(sprite_wood_.getPosition().x + 50, 50);
	text_stone_.setPosition(sprite_stone_.getPosition().x + 50, 50);
}

void GameResource::AddBuilding(const Build type)
{
	switch (type)
	{
	case Build::kHome:
	{
		home_++;
	}
	break;
	case Build::kFarm:
	{
		farm_++;
	}
	break;
	case Build::kOrchard:
	{
		orchard_++;
	}
	break;
	case Build::kMine:
	{
		mine_++;
	}
	break;
	case Build::kCastle:
	{
		castle_++;
	}
	break;
	default:;
	}

}

void GameResource::SubBuilding(const Tile::TileType type)
{
	switch (type)
	{
	case Tile::TileType::kHome:
	{
		home_--;
	}
	break;
	case Tile::TileType::kFarm:
	{
		farm_--;
	}
	break;
	case Tile::TileType::kOrchard:
	{
		orchard_--;
	}
	break;
	case Tile::TileType::kMine:
	{
		mine_--;
	}
	break;

	case Tile::TileType::kCastle:
	break;
	default:;
	}
}

void GameResource::AddResource()
{
	const auto current_time = std::chrono::high_resolution_clock::now();

	if (const std::chrono::duration<double> one_second = current_time - one_second_last_; one_second.count() >= 1.0)
	{

		one_second_last_ = current_time;

		gold_ += home_;
		food_ += farm_;
		wood_ += orchard_;
		stone_ += mine_;

		text_gold_.setString(std::to_string(gold_));
		text_food_.setString(std::to_string(food_));
		text_wood_.setString(std::to_string(wood_));
		text_stone_.setString(std::to_string(stone_));
	}
}

void GameResource::PayBuilding(const Build type)
{
	switch (type)
	{
	case Build::kHome:
	{
		gold_ -= 200;
		food_ -= 100;
	}
	break;
	case Build::kFarm:
	{
		gold_ -= 100;
	}
	break;
	case Build::kOrchard:
	{
		gold_ -= 300;
		food_ -= 200;
	}
	break;
	case Build::kMine:
	{
		gold_ -= 400;
		wood_ -= 200;
		food_ -= 300;
	}
	break;
	case Build::kCastle:
	{
		gold_ -= 50000;
		wood_ -= 12500;
		food_ -= 25000;
		stone_ -= 10000;
	}
	break;
	default:;
	}
}

void GameResource::PayTax()
{
	tax_ = (mine_ * 4 + orchard_ * 3 + farm_ * 2 + home_) * 15;
	text_tax_.setString(std::to_string(tax_));

	const auto current_time = std::chrono::high_resolution_clock::now();

	if (const std::chrono::duration<double> tax_second = current_time - tax_second_last_; tax_second.count() >= 300.0)
	{
		tax_second_last_ = current_time;
		gold_ -= tax_;
	}
}

void GameResource::GameEnd()
{
	if (castle_ >= 1)
	{
		game_ = false;
	}
}


void GameResource::Draw(sf::RenderWindow& window) const
{
	window.draw(sprite_gold_);
	window.draw(text_gold_);
	window.draw(sprite_food_);
	window.draw(text_food_);
	window.draw(sprite_wood_);
	window.draw(text_wood_);
	window.draw(sprite_stone_);
	window.draw(text_stone_);
	window.draw(sprite_tax_);
	window.draw(text_tax_);
}
