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

public:

	MainGame();

	void GameLoop();

	
};




#endif // GAME_MAINGAME_H_