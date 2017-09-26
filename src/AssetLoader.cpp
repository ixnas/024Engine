#include "../include/AssetLoader.h"
#include <iostream>

AssetLoader::AssetLoader ()
	: loadedAssets (std::vector <std::shared_ptr <Asset> > ())
{
	std::cout << "[AssetLoader] Initialized" << std::endl;
}

AssetLoader::~AssetLoader () {
	std::cout << "[AssetLoader] Clearing assets..." << std::endl;
	for (int i = 0; i < loadedAssets.size (); i++) {
		std::cout << "[AssetLoader]   [" << i << "] " << loadedAssets [i]->getName () << std::endl;
	}
	loadedAssets.clear ();
	std::cout << "[AssetLoader] Stopped" << std::endl;
}

std::vector <int> AssetLoader::getAsset (const std::string name) {
	for (auto &loadedAsset : loadedAssets) {
		if (loadedAsset->getName () == name) {
			return loadedAsset->getTextures ();
		}
	}
	return std::vector <int> ();
}
