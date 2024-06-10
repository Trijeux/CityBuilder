#ifndef GAME_MAINGAME_H_
#define GAME_MAINGAME_H_
#include <SFML/Graphics/RenderWindow.hpp>
#include <graphics/Tilemap.h>
#include <ui/UIButton.h>

class MainGame
{
	sf::RenderWindow window_;

	Tilemap tilemap_;

	UiButton button_;

	sf::View view = window_.getDefaultView();

	float zoomFactor = 1.0f;
	bool isPanning = false;
	sf::Vector2f oldPos;
	sf::Vector2f newPos;

	const int gridWidth = TILEMAP_WIDTH;
	const int gridHeight = TILEMAP_HEIGHT;
	const int spriteSizeX = tilemap_.SizeSprite().x;
	const int spriteSizeY = tilemap_.SizeSprite().y;

	sf::FloatRect sceneBounds;

	/*sf::Vector2f minViewSize = {
		std::min(window_.getDefaultView().getSize().x, sceneBounds.width),
		std::min(window_.getDefaultView().getSize().y, sceneBounds.height) };*/

public:

	MainGame();
	//void Zoom(sf::Event event);
	void MoveCame(sf::Event event);
	void ContrainteView();

	void GameLoop();


};




#endif // GAME_MAINGAME_H_