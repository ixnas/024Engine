#ifndef CLION_SDL_ASSETLOADER_H
#define CLION_SDL_ASSETLOADER_H

#include <vector>
#include <string>
#include "../include/Asset.h"
#include "../include/GraphicsEngine.h"

class AssetLoader {
	private:
		std::vector <std::shared_ptr <Asset> > loadedAssets;
	public:
		AssetLoader ();
		~AssetLoader ();
		std::vector <int> getAsset (const std::string name);
};

#endif
