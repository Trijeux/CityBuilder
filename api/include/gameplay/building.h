#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>

// Enum defining different types of buildings
enum class Build
{
    kHome,
    kMine,
    kOrchard,
    kFarm,
    kCastle,
    kNothing
};

// Class representing a Building that inherits from sf::Drawable
class Building final : public sf::Drawable {
public:
    // Constructor to initialize a Building object
    Building(float x, float y, Build build);

    // Function to retrieve the position of the building
    sf::Vector2f Position() const { return position_; }

protected:
    // Overridden draw function from sf::Drawable to draw the building
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite shape_;      // Sprite representing the visual shape of the building
    sf::Vector2f position_; // Position of the building
};

#endif // BUILDING_H
