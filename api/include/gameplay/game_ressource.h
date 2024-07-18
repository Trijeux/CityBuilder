#ifndef GAMEPLAY_GAME_RESOURCE_H
#define GAMEPLAY_GAME_RESOURCE_H

#include <chrono> // Include for time_point and steady_clock
#include "building.h" // Include for Building class
#include "graphics/tile.h" // Include for Tile class

class GameResource
{
    // Resources represented by sprites and textures
    sf::Sprite sprite_gold_;
    sf::Sprite sprite_food_;
    sf::Sprite sprite_wood_;
    sf::Sprite sprite_stone_;
    sf::Sprite sprite_tax_;
    sf::Texture texture_gold_;
    sf::Texture texture_food_;
    sf::Texture texture_wood_;
    sf::Texture texture_stone_;
    sf::Texture texture_tax_;

    // Text objects for displaying resource amounts
    sf::Text text_gold_;
    sf::Text text_food_;
    sf::Text text_wood_;
    sf::Text text_stone_;
    sf::Text text_tax_;
    sf::Text text_temp_for_tax_;
    sf::Font font_;

    // Counts of different buildings and resources
    int home_ = 0;
    int gold_ = 0;
    int farm_ = 0;
    int food_ = 0;
    int orchard_ = 0;
    int wood_ = 0;
    int mine_ = 0;
    int stone_ = 0;
    int castle_ = 0;
    int tax_ = 0;
    int time_for_tax_ = 0;

    // Game state flags and time points
    bool game_ = true;
    std::chrono::time_point<std::chrono::steady_clock> one_second_last_;
    std::chrono::time_point<std::chrono::steady_clock> tax_second_last_;

public:
    GameResource(); // Constructor
    void SetUiPosition(const sf::RenderWindow&); // Method to set UI positions based on window

    // Getter methods for resource counts and game state
    [[nodiscard]] int gold() const { return gold_; }
    [[nodiscard]] int food() const { return food_; }
    [[nodiscard]] int wood() const { return wood_; }
    [[nodiscard]] int stone() const { return stone_; }
    [[nodiscard]] int tax() const { return tax_; }
    [[nodiscard]] bool game() const { return game_; }

    // Methods to modify resources and game state
    void AddBuilding(Build); // Add a building to the count
    void SubBuilding(Tile::TileType); // Subtract a building from the count
    void AddResource(); // Add resources
    void PayBuilding(Build); // Pay for building
    void PayTax(); // Pay tax
    void GameEnd(); // End the game

    void Draw(sf::RenderWindow&) const; // Draw method to render resource UI
};

#endif // GAMEPLAY_GAME_RESOURCE_H
