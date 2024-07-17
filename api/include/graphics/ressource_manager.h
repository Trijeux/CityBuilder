#ifndef API_GRAPHICS_RESOURCE_MANAGER_H
#define API_GRAPHICS_RESOURCE_MANAGER_H
#include <array>


class ResourceManager {

public:
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

		kMax
	};

	enum class CursorImage
	{
		kBasic,
		kBuild,

		// Last value of enum used to get the number of resources
		kMax
	};

private:
	std::array<sf::Texture, static_cast<int>(Texture::kMax)> textures_;
	std::array<sf::Image, static_cast<int>(CursorImage::kMax)> cursor_images_;

	sf::Texture blank_texture_;
	sf::Image blank_cursor_image_;

	
	void LoadCursors();

public:
	ResourceManager();

	void LoadAllTextures();

	static ResourceManager& Get();


	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	sf::Texture& GetTexture(Texture resource_id);
	sf::Image& GetCursor(CursorImage cursor_id);
};

#endif //API_GRAPHICS_RESOURCE_MANAGER_H
