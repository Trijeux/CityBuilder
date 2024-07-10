#ifndef BUILDING_H
#define BUILDING_H
#include <SFML/Graphics/Sprite.hpp>

enum class Build
{
	kHome,
	kCarriere,
	kMenuiserie,
	kFerme
}; 

class Building : public sf::Drawable{

public:
	Building(float x, float y, Build build);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite shape_;

};


#endif // BUILDING_H
