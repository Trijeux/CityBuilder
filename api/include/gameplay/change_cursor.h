#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics/Image.hpp>
#include <SFML/Window/Cursor.hpp>
#include <SFML/Window/Window.hpp>

#include "graphics/RessourceManager.h"

class ChangeCursor
{

public:
	static void BasicCursor(sf::Window& window)
	{
		const sf::Image image = ResourceManager::Get().GetCursor(ResourceManager::CursorImage::Basic);
		sf::Cursor cursor;
		cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0, 0));

		window.setMouseCursor(cursor);

	}

	static void BuildingCursor(sf::Window& window)
	{
		const sf::Image image = ResourceManager::Get().GetCursor(ResourceManager::CursorImage::Build);
		sf::Cursor cursor;
		cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0, 0));

		window.setMouseCursor(cursor);
	}

};
#endif // CURSOR_H
