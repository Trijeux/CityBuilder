#include "gameplay/building.h" // Include header file for Building class
#include "graphics/ressource_manager.h" // Include header file for ResourceManager class

Building::Building(const float x, const float y, const Build build)
{
    // Constructor: Initializes a Building object with specified position (x, y) and type (build)

    switch (build)
    {
    case Build::kHome:
        // If building type is home, set its texture to the corresponding texture from ResourceManager
        shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kHome));
        break;
    case Build::kMine:
        // If building type is mine, set its texture to the corresponding texture from ResourceManager
        shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kMine));
        break;
    case Build::kOrchard:
        // If building type is orchard, set its texture to the corresponding texture from ResourceManager
        shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kOrchard));
        break;
    case Build::kFarm:
        // If building type is farm, set its texture to the corresponding texture from ResourceManager
        shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kFarm));
        break;
    case Build::kCastle:
        // If building type is castle, set its texture to the corresponding texture from ResourceManager
        shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kCastle));
        break;
    }

    // Set the position of the building
    position_ = sf::Vector2f(x, y);
    shape_.setPosition(x, y); // Set position of the sprite shape
}

void Building::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
    // Draw method: Renders the building on the specified render target

    target.draw(shape_, states); // Draw the building's sprite shape on the render target
}
