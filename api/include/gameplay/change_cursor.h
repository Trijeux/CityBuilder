#ifndef CURSOR_H
#define CURSOR_H

#include "graphics/ressource_manager.h"

// Class for changing the cursor image dynamically
class ChangeCursor
{
public:
    // Method to set a basic cursor image
    static void BasicCursor(sf::Window& window)
    {
        // Get the basic cursor image from the resource manager
        const sf::Image image = ResourceManager::Get().GetCursor(ResourceManager::CursorImage::kBasic);

        // Create an SFML cursor object and load the image data
        sf::Cursor cursor;
        cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0, 0));

        // Set the mouse cursor of the window to the created cursor
        window.setMouseCursor(cursor);
    }

    // Method to set a building cursor image
    static void BuildingCursor(sf::Window& window)
    {
        // Get the building cursor image from the resource manager
        const sf::Image image = ResourceManager::Get().GetCursor(ResourceManager::CursorImage::kBuild);

        // Create an SFML cursor object and load the image data
        sf::Cursor cursor;
        cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0, 0));

        // Set the mouse cursor of the window to the created cursor
        window.setMouseCursor(cursor);
    }
};

#endif // CURSOR_H
