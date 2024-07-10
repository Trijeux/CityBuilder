#ifndef API_IA_TREE_H
#define API_IA_TREE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "graphics/RessourceManager.h"

class Tile : public sf::Drawable
{
public:
	enum class TileType
	{
		kGround,
		kWood,
		kStone,
		kHome,
		kGroundOcup
	};


	Tile(TileType type_, float x, float y, bool is_walkable);

	bool Walkable() const { return isWalkable_; }
	sf::Vector2f Position() const { return sprite_.getPosition(); }
	TileType Type() const { return type_; }

	void Select();
	void Unselect();
	sf::Texture& GetFromType();

	void set_TileType(TileType);
	TileType type() const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:
	sf::Sprite sprite_;
	sf::RectangleShape outline;

	bool isWalkable_;
	bool isSelected_ = false;

	TileType type_;
};



#endif // API_IA_TREE_H
