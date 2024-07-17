#include <SFML/Graphics/Texture.hpp>  // Include SFML's Texture header
#include "graphics/ressource_manager.h"  // Include your ResourceManager header

void ResourceManager::LoadAllTextures()
{
    blank_texture_ = sf::Texture();  // Create a blank texture

    // Load textures for different game elements using their respective file paths
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
    // Load cursor images for different cursor states using their respective file paths
    cursor_images_.at(static_cast<int>(CursorImage::kBasic)).loadFromFile("ressources/cursore/PNG/Outline/Default/pointer_toon_b.png");
    cursor_images_.at(static_cast<int>(CursorImage::kBuild)).loadFromFile("ressources/cursore/PNG/Outline/Default/tool_hammer.png");
}

ResourceManager::ResourceManager()
{
    LoadAllTextures();  // Load all textures upon ResourceManager creation
    LoadCursors();      // Load all cursors upon ResourceManager creation
}

ResourceManager& ResourceManager::Get()
{
    // Implement Singleton pattern: return the static instance of ResourceManager
    static ResourceManager instance;
    return instance;
}

sf::Texture& ResourceManager::GetTexture(Texture resource_id)
{
    // Retrieve a texture based on the provided resource_id, or return blank_texture_ if out of bounds
    if (static_cast<int>(resource_id) < textures_.size()) {
        return textures_.at(static_cast<int>(resource_id));
    }
    else {
        return blank_texture_;
    }
}

sf::Image& ResourceManager::GetCursor(CursorImage cursor_id)
{
    // Retrieve a cursor image based on the provided cursor_id, or return blank_cursor_image_ if out of bounds
    if (static_cast<int>(cursor_id) < cursor_images_.size()) {
        return cursor_images_.at(static_cast<int>(cursor_id));
    }
    else {
        return blank_cursor_image_;
    }
}
