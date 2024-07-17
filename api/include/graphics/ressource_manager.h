#ifndef API_GRAPHICS_RESOURCE_MANAGER_H
#define API_GRAPHICS_RESOURCE_MANAGER_H

#include <array> // Include for std::array

// Forward declaration of sf::Texture and sf::Image
namespace sf {
    class Texture;
    class Image;
}

class ResourceManager {

public:
    // Enum for different textures managed by the resource manager
    enum class Texture
    {
        kGround,
        kStone,
        kWood,
        kHome,
        kOrchard,
        kMine,
        kFarm,
        kGroundToOccupy,
        kCastle,

        kMax // Last value used to get the number of textures
    };

    // Enum for different cursor images managed by the resource manager
    enum class CursorImage
    {
        kBasic,
        kBuild,

        kMax // Last value used to get the number of cursor images
    };

private:
    // Arrays to store textures and cursor images
    std::array<sf::Texture, static_cast<int>(Texture::kMax)> textures_;
    std::array<sf::Image, static_cast<int>(CursorImage::kMax)> cursor_images_;

    // Default texture and cursor image
    sf::Texture blank_texture_;
    sf::Image blank_cursor_image_;

    // Private method to load cursor images
    void LoadCursors();

public:
    // Constructor
    ResourceManager();

    // Method to load all textures
    void LoadAllTextures();

    // Static method to get the singleton instance of ResourceManager
    static ResourceManager& Get();

    // Deleted copy constructor and assignment operator to prevent copying
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    // Method to get a texture by its ID
    sf::Texture& GetTexture(Texture resource_id);

    // Method to get a cursor image by its ID
    sf::Image& GetCursor(CursorImage cursor_id);
};

#endif //API_GRAPHICS_RESOURCE_MANAGER_H
