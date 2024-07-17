#ifndef BUILDING_H
#define BUILDING_H
#include <SFML/Graphics.hpp>

enum class Build
{
	kHome,
	kMine,
	kOrchard,
	kFarm,
	kCastle
}; 

class Building final : public sf::Drawable{

public:
	Building(float x, float y, Build build);
	sf::Vector2f Position() const { return position_; }

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite shape_;
	sf::Vector2f position_;

};


#endif // BUILDING_H
