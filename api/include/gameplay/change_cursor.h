#ifndef CURSOR_H
#define CURSOR_H

#include "graphics/ressource_manager.h"


class ChangeCursor
{

public:
	static void BasicCursor(sf::Window& window)
	{
		const sf::Image image = ResourceManager::Get().GetCursor(ResourceManager::CursorImage::kBasic);
		sf::Cursor cursor;
		cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0, 0));

		window.setMouseCursor(cursor);

	}

	static void BuildingCursor(sf::Window& window)
	{
		const sf::Image image = ResourceManager::Get().GetCursor(ResourceManager::CursorImage::kBuild);
		sf::Cursor cursor;
		cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0, 0));

		window.setMouseCursor(cursor);
	}

};
#endif // CURSOR_H
