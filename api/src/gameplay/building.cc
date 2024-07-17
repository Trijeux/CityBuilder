#include "gameplay/building.h"


#include "graphics/ressource_manager.h"


Building::Building(const float x, const float y, const Build build)
{
	switch (build)
	{
	case Build::kHome:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kHome));
	}
	break;
	case Build::kMine:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kMine));
	}
	break;
	case Build::kOrchard:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kOrchard));
	}
	break;
	case Build::kFarm:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kFarm));
	}
	break;
	case Build::kCastle:
	{
		shape_.setTexture(ResourceManager::Get().GetTexture(ResourceManager::Texture::kCastle));
	}
	break;
	}

	position_ = sf::Vector2f(x, y);

	shape_.setPosition(x, y);
}

void Building::draw(sf::RenderTarget& target, const sf::RenderStates states) const
{
	target.draw(shape_, states);
}