#include "graphics/RessourceManager.h"

void ResourceManager::LoadAllTextures()
{
	textures_.clear();
	textures_.resize(static_cast<int>(Texture::Max));

	// Textures -----------------
	blankTexture_ = sf::Texture();
	textures_.at(static_cast<int>(Texture::Ground)).loadFromFile("ressources/tile/Ground.png");
	textures_.at(static_cast<int>(Texture::Stone)).loadFromFile("ressources/tile/Stone.png");
	textures_.at(static_cast<int>(Texture::Wood)).loadFromFile("ressources/tile/Wood.png");
	textures_.at(static_cast<int>(Texture::Home)).loadFromFile("ressources/tile/home.png");

}

void ResourceManager::LoadCursors()
{

	cursor_images_.clear();
	cursor_images_.resize(static_cast<int>(CursorImage::Max));

	//cursors_.emplace_back();
	cursor_images_.at(static_cast<int>(CursorImage::Basic)).loadFromFile("ressources/cursore/PNG/Outline/Default/pointer_toon_b.png");
	cursor_images_.at(static_cast<int>(CursorImage::Build)).loadFromFile("ressources/cursore/PNG/Outline/Default/tool_hammer.png");

}

ResourceManager& ResourceManager::Get()
{

	static ResourceManager instance_;
	return instance_;

}

ResourceManager::ResourceManager()
{
	LoadAllTextures();
	LoadCursors();
}

sf::Texture& ResourceManager::GetTexture(Texture resourceId) {

	if (static_cast<int>(resourceId) < textures_.size()) {
		return textures_.at(static_cast<int>(resourceId));
	}
	else
	{
		return blankTexture_;
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
