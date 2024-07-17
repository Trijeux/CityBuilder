#ifndef API_IA_TREE_H
#define API_IA_TREE_H

#include <SFML/Graphics.hpp>



class Tile final : public sf::Drawable
{
public:
	enum class TileType
	{
		kGround,
		kWood,
		kStone,
		kHome,
		kFarm,
		kOrchard,
		kMine,
		kCastle,
	};


	Tile(TileType type, float x, float y, bool is_walkable);

	bool Walkable() const { return is_walkable_; }
	sf::Vector2f Position() const { return sprite_.getPosition(); }
	TileType Type() const { return type_; }

	void Select();
	void Unselect();
	sf::Texture& GetFromType() const;

	void SetTileType(TileType);
	void SetTileSprite();
	TileType type() const;

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:
	sf::Sprite sprite_;
	sf::RectangleShape outline_;

	bool is_walkable_;
	bool is_selected_ = false;

	TileType type_;
};



#endif // API_IA_TREE_H
