#include <SFML/Graphics/Texture.hpp>
#include "graphics/ressource_manager.h"



void ResourceManager::LoadAllTextures()
{
	//textures_.clear();
	//textures_.resize(static_cast<int>(Texture::kMax));

	// Textures -----------------
	blank_texture_ = sf::Texture();
	textures_.at(static_cast<int>(Texture::kGround)).loadFromFile("ressources/tile/Ground.png");
	textures_.at(static_cast<int>(Texture::kStone)).loadFromFile("ressources/tile/Stone.png");
	textures_.at(static_cast<int>(Texture::kWood)).loadFromFile("ressources/tile/Wood.png");
	textures_.at(static_cast<int>(Texture::kHome)).loadFromFile("ressources/tile/home.png");
	textures_.at(static_cast<int>(Texture::kFarm)).loadFromFile("ressources/tile/ferme.png");
	textures_.at(static_cast<int>(Texture::kMine)).loadFromFile("ressources/tile/carriere.png");
	textures_.at(static_cast<int>(Texture::kOrchard)).loadFromFile("ressources/tile/menuiserie.png");
	textures_.at(static_cast<int>(Texture::kGroundToOccupy)).loadFromFile("ressources/tile/Ground_Ocupper.png");
	textures_.at(static_cast<int>(Texture::kCastle)).loadFromFile("ressources/tile/King_Castle.png");
	
}

void ResourceManager::LoadCursors()
{

	//cursor_images_.clear();
	//cursor_images_.resize(static_cast<int>(CursorImage::kMax));

	//cursors_.emplace_back();
	cursor_images_.at(static_cast<int>(CursorImage::kBasic)).loadFromFile("ressources/cursore/PNG/Outline/Default/pointer_toon_b.png");
	cursor_images_.at(static_cast<int>(CursorImage::kBuild)).loadFromFile("ressources/cursore/PNG/Outline/Default/tool_hammer.png");

}

//void ResourceManager::LoadTexture(std::string filename, )
//{
//	sf::Image image;
//	image.loadFromFile(filename);
//	texture.loadFromImage(image, area);
//}


//static ResourceManager* instance = nullptr;
ResourceManager::ResourceManager()
{
	//instance = this;
	LoadAllTextures();
	LoadCursors();
}

//ResourceManager::~ResourceManager()
//{
//	instance = nullptr;
//}

ResourceManager& ResourceManager::Get()
{

	static ResourceManager instance;
	return instance;
	//return *instance_;

}

sf::Texture& ResourceManager::GetTexture(Texture resource_id) {

	if (static_cast<int>(resource_id) < textures_.size()) {
		return textures_.at(static_cast<int>(resource_id));
	}
	else
	{
		return blank_texture_;
	}
}

sf::Image& ResourceManager::GetCursor(CursorImage cursor_id)
{
	if (static_cast<int>(cursor_id) < cursor_images_.size()) {
		return cursor_images_.at(static_cast<int>(cursor_id));
	}
	else
	{
		return blank_cursor_image_;
	}
}
