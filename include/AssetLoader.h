//
// Created by Sjoerd Scheffer on 02-04-17.
//

#ifndef CLION_SDL_ASSETLOADER_H
#define CLION_SDL_ASSETLOADER_H

#include <vector>
#include "../include/Asset.h"
#include "../include/GraphicsEngine.h"

class AssetLoader {
	private:
		static AssetLoader *s_instance;
		std::vector <std::shared_ptr <Asset> > loadedAssets;
		bool assetLoaded (const char *name);
		std::vector <int> getAsset (const char* name);
	public:
		static AssetLoader *instance ();
		~AssetLoader ();
		std::vector <int> getGroundAssetTopMiddle ();
		std::vector <int> getGroundAssetTopLeft ();
		std::vector <int> getGroundAssetTopRight ();
		std::vector <int> getGroundAssetMiddleLeft ();
		std::vector <int> getGroundAssetMiddleMiddle ();
		std::vector <int> getGroundAssetMiddleRight ();
		std::vector <int> getTreeAsset ();
		std::vector <int> getCrateAsset ();
		std::vector <int> getPlatformLeftAsset ();
		std::vector <int> getPlatformMiddleAsset ();
		std::vector <int> getPlatformRightAsset ();
		std::vector <int> getStoneAsset ();
		std::vector <int> getBushAsset ();
		std::vector <int> getBushAsset2 ();
		std::vector <int> getMushroomAsset ();
		std::vector <int> getExplosionAsset ();
		std::vector <int> getPlayerWalkLeftAsset ();
		std::vector <int> getPlayerWalkRightAsset ();
		std::vector <int> getPlayerStillLeftAsset ();
		std::vector <int> getPlayerStillRightAsset ();
};


#endif
