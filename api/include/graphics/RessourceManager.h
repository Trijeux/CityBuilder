#ifndef API_GRAPHICS_RESOURCEMANAGER_H
#define API_GRAPHICS_RESOURCEMANAGER_H

#include <array>
#include <SFML/Graphics.hpp>
#include <unordered_map>

class ResourceManager {

public:
	enum class Texture
	{
		kGround,
		kStone,
		kWood,
		kHome,
		kVerger,
		kCarriere,
		kFerme,
		kGroundOcup,
		kChateau,

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

	sf::Texture blankTexture_;
	sf::Image blank_cursor_image_;

	
	void LoadCursors();
	//void LoadTexture();

public:
	ResourceManager();
	///~ResourceManager();

	void LoadAllTextures();

	static ResourceManager& Get();


	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	sf::Texture& GetTexture(Texture resource_id);
	sf::Image& GetCursor(CursorImage cursor_id);
};

#endif
