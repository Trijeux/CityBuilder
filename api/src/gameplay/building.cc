
#include <SFML/Graphics/RenderTarget.hpp>

#include "gameplay/Building.h"
#include "graphics/RessourceManager.h"

Building::Building(float x, float y, Build build)
{
	switch (build)
	{
	case Build::kHome:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kHome));
	}
	break;
	case Build::kCarriere:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kCarriere));
	}
	break;
	case Build::kVerger:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kVerger));
	}
	break;
	case Build::kFerme:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kFerme));
	}
	break;
	case Build::kChateau:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kChateau));
	}
	break;
	}

	position_ = sf::Vector2f(x, y);

	shape_.setPosition(x, y);
}

void Building::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape_, states);
}