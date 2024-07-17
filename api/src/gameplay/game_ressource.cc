#include "gameplay/game_ressource.h" // Include the header file for GameResource

GameResource::GameResource()
{
    // Load font file and handle error if not loaded
    if (!font_.loadFromFile("ressources/fonts/kenvector_future.ttf")) {
        // Handle error: Unable to load font
    }

    // Set fonts for text elements
    text_gold_.setFont(font_);
    text_food_.setFont(font_);
    text_wood_.setFont(font_);
    text_stone_.setFont(font_);
    text_tax_.setFont(font_);

    // Initialize text values with initial resource counts
    text_gold_.setString(std::to_string(gold_));
    text_food_.setString(std::to_string(food_));
    text_wood_.setString(std::to_string(wood_));
    text_stone_.setString(std::to_string(stone_));
    text_tax_.setString(std::to_string(tax_));

    // Set text colors to black
    text_gold_.setColor(sf::Color::Black);
    text_food_.setColor(sf::Color::Black);
    text_wood_.setColor(sf::Color::Black);
    text_stone_.setColor(sf::Color::Black);
    text_tax_.setColor(sf::Color::Black);

    // Set origins for text elements to center them properly
    text_gold_.setOrigin(text_gold_.getGlobalBounds().width / 2.0f, text_gold_.getGlobalBounds().height / 2.0f);
    text_food_.setOrigin(text_food_.getGlobalBounds().width / 2.0f, text_food_.getGlobalBounds().height / 2.0f);
    text_wood_.setOrigin(text_wood_.getGlobalBounds().width / 2.0f, text_wood_.getGlobalBounds().height / 2.0f);
    text_stone_.setOrigin(text_stone_.getGlobalBounds().width / 2.0f, text_stone_.getGlobalBounds().height / 2.0f);
    text_tax_.setOrigin(text_tax_.getGlobalBounds().width / 2.0f, text_tax_.getGlobalBounds().height / 2.0f);

    // Load textures for resource sprites
    texture_gold_.loadFromFile("ressources/tile/Ressource_Or.png");
    texture_food_.loadFromFile("ressources/tile/Resource_nouriture.png");
    texture_wood_.loadFromFile("ressources/tile/Resource_boit.png");
    texture_stone_.loadFromFile("ressources/tile/Resource_pierre.png");
    texture_tax_.loadFromFile("ressources/tile/Taxe.png");

    // Set textures for resource sprites
    sprite_gold_.setTexture(texture_gold_);
    sprite_food_.setTexture(texture_food_);
    sprite_wood_.setTexture(texture_wood_);
    sprite_stone_.setTexture(texture_stone_);
    sprite_tax_.setTexture(texture_tax_);

    // Set origins for sprite elements to center them properly
    sprite_gold_.setOrigin(sprite_gold_.getGlobalBounds().width / 2.0f, sprite_gold_.getGlobalBounds().height / 2.0f);
    sprite_food_.setOrigin(sprite_food_.getGlobalBounds().width / 2.0f, sprite_food_.getGlobalBounds().height / 2.0f);
    sprite_wood_.setOrigin(sprite_wood_.getGlobalBounds().width / 2.0f, sprite_wood_.getGlobalBounds().height / 2.0f);
    sprite_stone_.setOrigin(sprite_stone_.getGlobalBounds().width / 2.0f, sprite_stone_.getGlobalBounds().height / 2.0f);
    sprite_tax_.setOrigin(sprite_tax_.getGlobalBounds().width / 2.0f, sprite_tax_.getGlobalBounds().height / 2.0f);

    // Set initial scale and color for sprite elements
    sprite_gold_.setColor(sf::Color::White);
    sprite_gold_.setScale(2, 2);
    sprite_food_.setColor(sf::Color::White);
    sprite_food_.setScale(2, 2);
    sprite_wood_.setColor(sf::Color::White);
    sprite_wood_.setScale(2, 2);
    sprite_stone_.setColor(sf::Color::White);
    sprite_stone_.setScale(2, 2);
    sprite_tax_.setColor(sf::Color::White);
    sprite_tax_.setScale(4, 4);

    // Initialize time points for resource update intervals
    one_second_last_ = std::chrono::high_resolution_clock::now();
    tax_second_last_ = one_second_last_;
}

void GameResource::SetUiPosition(const sf::RenderWindow& window)
{
    // Set positions for sprite elements
    sprite_tax_.setPosition(100, 50);
    sprite_gold_.setPosition(window.getSize().x - 600, 50);
    sprite_food_.setPosition(window.getSize().x - 450, 50);
    sprite_wood_.setPosition(window.getSize().x - 300, 50);
    sprite_stone_.setPosition(window.getSize().x - 150, 50);

    // Set positions for text elements relative to their corresponding sprites
    text_tax_.setPosition(sprite_tax_.getPosition().x + 50, 50);
    text_gold_.setPosition(sprite_gold_.getPosition().x + 50, 50);
    text_food_.setPosition(sprite_food_.getPosition().x + 50, 50);
    text_wood_.setPosition(sprite_wood_.getPosition().x + 50, 50);
    text_stone_.setPosition(sprite_stone_.getPosition().x + 50, 50);
}

void GameResource::AddBuilding(const Build type)
{
    // Increase the count of the specified building type
    switch (type)
    {
    case Build::kHome:
        home_++;
        break;
    case Build::kFarm:
        farm_++;
        break;
    case Build::kOrchard:
        orchard_++;
        break;
    case Build::kMine:
        mine_++;
        break;
    case Build::kCastle:
        castle_++;
        break;
    default:
        break;
    }
}

void GameResource::SubBuilding(const Tile::TileType type)
{
    // Decrease the count of the specified building type
    switch (type)
    {
    case Tile::TileType::kHome:
        home_--;
        break;
    case Tile::TileType::kFarm:
        farm_--;
        break;
    case Tile::TileType::kOrchard:
        orchard_--;
        break;
    case Tile::TileType::kMine:
        mine_--;
        break;
    case Tile::TileType::kCastle:
        break;
    default:
        break;
    }
}

void GameResource::AddResource()
{
    // Calculate elapsed time since last resource update
    const auto current_time = std::chrono::high_resolution_clock::now();
    if (const std::chrono::duration<double> one_second = current_time - one_second_last_; one_second.count() >= 1.0)
    {
        // Update resource counts and text strings every second
        one_second_last_ = current_time;
        gold_ += home_;
        food_ += farm_;
        wood_ += orchard_;
        stone_ += mine_;

        // Update text strings with new resource counts
        text_gold_.setString(std::to_string(gold_));
        text_food_.setString(std::to_string(food_));
        text_wood_.setString(std::to_string(wood_));
        text_stone_.setString(std::to_string(stone_));
    }
}

void GameResource::PayBuilding(const Build type)
{
    // Subtract resources based on the cost of the specified building type
    switch (type)
    {
    case Build::kHome:
        gold_ -= 200;
        food_ -= 100;
        break;
    case Build::kFarm:
        gold_ -= 100;
        break;
    case Build::kOrchard:
        gold_ -= 300;
        food_ -= 200;
        break;
    case Build::kMine:
        gold_ -= 400;
        wood_ -= 200;
        food_ -= 300;
        break;
    case Build::kCastle:
        gold_ -= 50000;
        wood_ -= 12500;
        food_ -= 25000;
        stone_ -= 10000;
        break;
    default:
        break;
    }
}

void GameResource::PayTax()
{
    // Calculate tax based on the number of each type of building
    tax_ = (mine_ * 4 + orchard_ * 3 + farm_ * 2 + home_) * 15;
    text_tax_.setString(std::to_string(tax_)); // Update tax text string

    // Calculate elapsed time since last tax payment
    const auto current_time = std::chrono::high_resolution_clock::now();
    if (const std::chrono::duration<double> tax_second = current_time - tax_second_last_; tax_second.count() >= 300.0)
    {
        // Pay tax every 300 seconds
        tax_second_last_ = current_time;
        gold_ -= tax_;
    }
}

void GameResource::GameEnd()
{
    // End the game if at least one castle has been built
    if (castle_ >= 1)
    {
        game_ = false;
    }
}

void GameResource::Draw(sf::RenderWindow& window) const
{
    // Draw all sprites and corresponding text elements to the window
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
