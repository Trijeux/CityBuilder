#include "gameplay/game_ressource.h"

#include <iostream>


GameRessource::GameRessource()
{
	if (!font_.loadFromFile("ressources/fonts/kenvector_future.ttf")) {
		// Gérer l'erreur : impossible de charger la police
	}

	text_Gold_.setFont(font_);
	text_Food_.setFont(font_);
	text_Wood_.setFont(font_);
	text_Stone_.setFont(font_);
	text_Taxe_.setFont(font_);
	text_Gold_.setString(std::to_string(Gold));
	text_Food_.setString(std::to_string(Food));
	text_Wood_.setString(std::to_string(Wood));
	text_Stone_.setString(std::to_string(Stone));
	text_Taxe_.setString(std::to_string(Taxe));

	text_Gold_.setColor(sf::Color::Black);
	text_Food_.setColor(sf::Color::Black);
	text_Wood_.setColor(sf::Color::Black);
	text_Stone_.setColor(sf::Color::Black);
	text_Taxe_.setColor(sf::Color::Black);

	text_Gold_.setOrigin(text_Gold_.getGlobalBounds().width / 2.0f, text_Gold_.getGlobalBounds().height / 2.0f);
	text_Food_.setOrigin(text_Food_.getGlobalBounds().width / 2.0f, text_Food_.getGlobalBounds().height / 2.0f);
	text_Wood_.setOrigin(text_Wood_.getGlobalBounds().width / 2.0f, text_Wood_.getGlobalBounds().height / 2.0f);
	text_Stone_.setOrigin(text_Stone_.getGlobalBounds().width / 2.0f, text_Stone_.getGlobalBounds().height / 2.0f);
	text_Taxe_.setOrigin(text_Taxe_.getGlobalBounds().width / 2.0f, text_Taxe_.getGlobalBounds().height / 2.0f);

	texture_Gold_.loadFromFile("ressources/tile/Ressource_Or.png");
	sprite_Gold_.setTexture(texture_Gold_);
	sprite_Gold_.setOrigin(sprite_Gold_.getGlobalBounds().width / 2.0f, sprite_Gold_.getGlobalBounds().height / 2.0f);
	sprite_Gold_.setColor(sf::Color::White);
	sprite_Gold_.setScale(2, 2);

	texture_Food_.loadFromFile("ressources/tile/Resource_nouriture.png");
	sprite_Food_.setTexture(texture_Food_);
	sprite_Food_.setOrigin(sprite_Food_.getGlobalBounds().width / 2.0f, sprite_Food_.getGlobalBounds().height / 2.0f);
	sprite_Food_.setColor(sf::Color::White);
	sprite_Food_.setScale(2, 2);

	texture_Wood_.loadFromFile("ressources/tile/Resource_boit.png");
	sprite_Wood_.setTexture(texture_Wood_);
	sprite_Wood_.setOrigin(sprite_Wood_.getGlobalBounds().width / 2.0f, sprite_Wood_.getGlobalBounds().height / 2.0f);
	sprite_Wood_.setColor(sf::Color::White);
	sprite_Wood_.setScale(2, 2);

	texture_Stone_.loadFromFile("ressources/tile/Resource_pierre.png");
	sprite_Stone_.setTexture(texture_Stone_);
	sprite_Stone_.setOrigin(sprite_Stone_.getGlobalBounds().width / 2.0f, sprite_Stone_.getGlobalBounds().height / 2.0f);
	sprite_Stone_.setColor(sf::Color::White);
	sprite_Stone_.setScale(2, 2);

	texture_Taxe_.loadFromFile("ressources/tile/Taxe.png");
	sprite_Taxe_.setTexture(texture_Taxe_);
	sprite_Taxe_.setOrigin(sprite_Taxe_.getGlobalBounds().width / 2.0f, sprite_Taxe_.getGlobalBounds().height / 2.0f);
	sprite_Taxe_.setColor(sf::Color::White);
	sprite_Taxe_.setScale(4, 4);

	OneSecondLast = std::chrono::high_resolution_clock::now();
	TaxeSecondLast = OneSecondLast;
}

void GameRessource::setUiPosistion(sf::RenderWindow& window)
{
	sprite_Taxe_.setPosition(100, 50);
	sprite_Gold_.setPosition(window.getSize().x - 600, 50);
	sprite_Food_.setPosition(window.getSize().x - 450, 50);
	sprite_Wood_.setPosition(window.getSize().x - 300, 50);
	sprite_Stone_.setPosition(window.getSize().x - 150, 50);

	text_Taxe_.setPosition(sprite_Taxe_.getPosition().x + 50, 50);
	text_Gold_.setPosition(sprite_Gold_.getPosition().x + 50, 50);
	text_Food_.setPosition(sprite_Food_.getPosition().x + 50, 50);
	text_Wood_.setPosition(sprite_Wood_.getPosition().x + 50, 50);
	text_Stone_.setPosition(sprite_Stone_.getPosition().x + 50, 50);
}

void GameRessource::AddBatiment(const Build type)
{
	switch (type)
	{
	case Build::kHome:
	{
		Home++;
	}
	break;
	case Build::kFerme:
	{
		Ferme++;
	}
	break;
	case Build::kVerger:
	{
		Verger++;
	}
	break;
	case Build::kCarriere:
	{
		Carriere++;
	}
	break;
	case Build::kChateau:
	{
		Chateau++;
	}
	break;
	default:;
	}

}

void GameRessource::SubBatiment(Tile::TileType type)
{
	switch (type)
	{
	case Tile::TileType::kHome:
	{
		Home--;
	}
	break;
	case Tile::TileType::kFerme:
	{
		Ferme--;
	}
	break;
	case Tile::TileType::kVerger:
	{
		Verger--;
	}
	break;
	case Tile::TileType::kCarriere:
	{
		Carriere--;
	}
	break;

	case Tile::TileType::kChateau:
	{
		std::cout << "Error" << std::endl;
	}
	break;
	default:;
	}
}

void GameRessource::AddRessource()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> OneSecond = currentTime - OneSecondLast;

	//std::cout << OneSecond  << " " << Home << std::endl;

	if (OneSecond.count() >= 1.0)
	{

		OneSecondLast = currentTime;

		Gold += Home;
		Food += Ferme;
		Wood += Verger;
		Stone += Carriere;

		text_Gold_.setString(std::to_string(Gold));
		text_Food_.setString(std::to_string(Food));
		text_Wood_.setString(std::to_string(Wood));
		text_Stone_.setString(std::to_string(Stone));
	}
}

void GameRessource::PayBatiment(Build type)
{
	switch (type)
	{
	case Build::kHome:
	{
		Gold -= 200;
		Food -= 100;
	}
	break;
	case Build::kFerme:
	{
		Gold -= 100;
	}
	break;
	case Build::kVerger:
	{
		Gold -= 300;
		Food -= 200;
	}
	break;
	case Build::kCarriere:
	{
		Gold -= 400;
		Wood -= 200;
		Food -= 300;
	}
	break;
	case Build::kChateau:
	{
		Gold -= 50000;
		Wood -= 12500;
		Food -= 25000;
		Stone -= 10000;
	}
	break;
	default:;
	}
}

void GameRessource::PayTaxe()
{
	Taxe = (Carriere * 4 + Verger * 3 + Ferme * 2 + Home) * 15;
	text_Taxe_.setString(std::to_string(Taxe));
	auto currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> TaxeSecond = currentTime - TaxeSecondLast;
	if (TaxeSecond.count() >= 300.0)
	{
		TaxeSecondLast = currentTime;
		Gold -= Taxe;
	}
}

void GameRessource::GameEnd()
{
	if (Chateau >= 1)
	{
		Game = false;
	}
}


void GameRessource::Draw(sf::RenderWindow& window)
{
	window.draw(sprite_Gold_);
	window.draw(text_Gold_);
	window.draw(sprite_Food_);
	window.draw(text_Food_);
	window.draw(sprite_Wood_);
	window.draw(text_Wood_);
	window.draw(sprite_Stone_);
	window.draw(text_Stone_);
	window.draw(sprite_Taxe_);
	window.draw(text_Taxe_);
}
