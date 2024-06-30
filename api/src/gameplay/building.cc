
#include <SFML/Graphics/RenderTarget.hpp>

#include "gameplay/Building.h"
#include "graphics/RessourceManager.h"

Building::Building(float x, float y, Build build)
{
	switch (build)
	{
	case Build::Home:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::Home));
	}
	break;
	case Build::Carriere:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::Carriere));
	}
	break;
	case Build::Menuiserie:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::Menuiserie));
	}
	break;
	case Build::Ferme:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::Ferme));
	}
	break;
	}


	shape_.setPosition(x, y);
}

void Building::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape_, states);
}