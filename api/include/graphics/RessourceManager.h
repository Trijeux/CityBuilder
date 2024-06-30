#ifndef API_GRAPHICS_RESOURCEMANAGER_H
#define API_GRAPHICS_RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class ResourceManager {

public:
	enum class Texture
	{
		Ground,
		Stone,
		Wood,
		Home,
		Menuiserie,
		Carriere,
		Ferme,

		Max
	};

	enum class CursorImage
	{
		Basic,
		Build,

		// Last value of enum used to get the number of resources
		Max
	};

private:
	std::vector<sf::Texture> textures_;
	std::vector<sf::Image> cursor_images_;

	sf::Texture blankTexture_;
	sf::Image blank_cursor_image_;

	ResourceManager();
	void LoadAllTextures();
	void LoadCursors();

public:
	static ResourceManager& Get();


	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	sf::Texture& GetTexture(Texture resource_id);
	sf::Image& GetCursor(CursorImage cursor_id);
};

#endif
