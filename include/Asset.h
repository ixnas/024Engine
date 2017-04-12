#ifndef CLION_SDL_ASSET_H
#define CLION_SDL_ASSET_H

#include <vector>
#include <string>

class Asset {
	private:
		std::string name;
		std::vector <int> textures;
	public:
		Asset (const char *name);
		std::string getName ();
		std::vector <int> getTextures ();
		void addTexture (const int textureNumber);
};

#endif //CLION_SDL_ASSET_H
