#include "../include/AssetLoader.h"
#include <iostream>

AssetLoader::~AssetLoader () {
	std::cout << "Clearing assets from AssetLoader..." << std::endl;
	for (int i = 0; i < loadedAssets.size (); i++) {
		std::cout << "  [" << i << "] " << loadedAssets [i]->getName () << std::endl;
	}
	std::cout << "Done" << std::endl;
	loadedAssets.clear ();
}

std::vector <int> AssetLoader::getAsset (const char *name) {
	std::vector <int> result;
	for (int i = 0; i < loadedAssets.size (); i++) {
		if (loadedAssets[i]->getName () == name) {
			result = loadedAssets[i]->getTextures ();
		}
	}
	return result;
}

std::vector <int> AssetLoader::getGroundAssetTopLeft () {
	if (!assetLoaded ("groundAssetTopLeft")) {
		auto asset = std::make_shared <Asset> ("groundAssetTopLeft");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Tiles/1.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("groundAssetTopLeft");
}

std::vector <int> AssetLoader::getGroundAssetTopMiddle () {
	if (!assetLoaded ("groundAssetTopMiddle")) {
		auto asset = std::make_shared <Asset> ("groundAssetTopMiddle");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Tiles/2.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("groundAssetTopMiddle");
}

std::vector <int> AssetLoader::getGroundAssetTopRight () {
	if (!assetLoaded ("groundAssetTopRight")) {
		auto asset = std::make_shared <Asset> ("groundAssetTopRight");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Tiles/3.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("groundAssetTopRight");
}

std::vector <int> AssetLoader::getGroundAssetMiddleLeft () {
	if (!assetLoaded ("groundAssetMiddleLeft")) {
		auto asset = std::make_shared <Asset> ("groundAssetMiddleLeft");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Tiles/4.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("groundAssetMiddleLeft");
}

std::vector <int> AssetLoader::getGroundAssetMiddleMiddle () {
	if (!assetLoaded ("groundAssetMiddleMiddle")) {
		auto asset = std::make_shared <Asset> ("groundAssetMiddleMiddle");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Tiles/5.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("groundAssetMiddleMiddle");
}

std::vector <int> AssetLoader::getGroundAssetMiddleRight () {
	if (!assetLoaded ("groundAssetMiddleRight")) {
		auto asset = std::make_shared <Asset> ("groundAssetMiddleRight");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Tiles/6.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("groundAssetMiddleRight");
}

std::vector <int> AssetLoader::getTreeAsset () {
	if (!assetLoaded ("treeAsset")) {
		auto asset = std::make_shared <Asset> ("treeAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Object/Tree_2.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("treeAsset");
}

std::vector <int> AssetLoader::getCrateAsset () {
	if (!assetLoaded ("crateAsset")) {
		auto asset = std::make_shared <Asset> ("crateAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Object/Crate.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("crateAsset");
}

std::vector <int> AssetLoader::getPlatformLeftAsset () {
	if (!assetLoaded ("platformLeftAsset")) {
		auto asset = std::make_shared <Asset> ("platformLeftAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Tiles/13.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("platformLeftAsset");
}

std::vector <int> AssetLoader::getPlatformMiddleAsset () {
	if (!assetLoaded ("platformMiddleAsset")) {
		auto asset = std::make_shared <Asset> ("platformMiddleAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Tiles/14.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("platformMiddleAsset");
}

std::vector <int> AssetLoader::getPlatformRightAsset () {
	if (!assetLoaded ("platformRightAsset")) {
		auto asset = std::make_shared <Asset> ("platformRightAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Tiles/15.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("platformRightAsset");
}

std::vector <int> AssetLoader::getStoneAsset () {
	if (!assetLoaded ("stoneAsset")) {
		auto asset = std::make_shared <Asset> ("stoneAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Object/Stone.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("stoneAsset");
}

std::vector <int> AssetLoader::getBushAsset () {
	if (!assetLoaded ("bushAsset")) {
		auto asset = std::make_shared <Asset> ("bushAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Object/Bush (2).png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("bushAsset");
}

std::vector <int> AssetLoader::getBushAsset2 () {
	if (!assetLoaded ("bushAsset2")) {
		auto asset = std::make_shared <Asset> ("bushAsset2");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Object/Bush (1).png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("bushAsset2");
}

std::vector <int> AssetLoader::getMushroomAsset () {
	if (!assetLoaded ("mushRoomAsset")) {
		auto asset = std::make_shared <Asset> ("mushRoomAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Object/Mushroom_1.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/Object/Mushroom_2.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("mushRoomAsset");
}

std::vector <int> AssetLoader::getExplosionAsset () {
	if (!assetLoaded ("explosionAsset")) {
		auto asset = std::make_shared <Asset> ("explosionAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0001.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0002.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0003.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0004.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0005.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0006.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0007.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0008.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0009.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0010.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0011.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0012.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0013.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0014.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0015.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0016.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0017.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0018.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0019.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0020.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0021.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0022.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0023.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0024.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0025.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0026.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0027.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0028.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0029.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0030.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0031.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0032.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0033.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0034.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0035.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0036.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0037.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0038.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0039.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0040.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0041.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0042.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0043.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0044.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0045.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0046.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0047.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0048.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0049.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0050.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0051.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0052.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0053.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0054.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0055.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0056.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0057.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0058.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0059.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0060.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0061.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0062.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0063.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0064.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0065.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0066.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0067.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0068.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0069.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0070.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0071.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0072.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0073.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0074.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0075.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0076.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0077.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0078.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0079.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0080.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0081.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0082.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0083.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0084.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0085.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0086.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0087.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0088.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0089.png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/explosions/explosion1_0090.png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("explosionAsset");
}

bool AssetLoader::assetLoaded (const char *name) {
	bool result = false;
	for (int i = 0; i < loadedAssets.size (); i++) {
		if (loadedAssets[i]->getName () == name) {
			result = true;
		}
	}
	return result;
}

AssetLoader *AssetLoader::instance () {
	if (!s_instance) {
		s_instance = new AssetLoader;
	}
	return s_instance;
}

std::vector <int> AssetLoader::getPlayerWalkLeftAsset () {
	if (!assetLoaded ("playerWalkLeftAsset")) {
		auto asset = std::make_shared <Asset> ("playerWalkLeftAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (1).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (2).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (3).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (4).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (5).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (6).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (7).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (8).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (9).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/WalkLeft (10).png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("playerWalkLeftAsset");
}

std::vector <int> AssetLoader::getPlayerWalkRightAsset () {
	if (!assetLoaded ("playerWalkRightAsset")) {
		auto asset = std::make_shared <Asset> ("playerWalkRightAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (1).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (2).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (3).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (4).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (5).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (6).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (7).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (8).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (9).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Walk (10).png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("playerWalkRightAsset");
}

std::vector <int> AssetLoader::getPlayerStillLeftAsset () {
	if (!assetLoaded ("playerStillLeftAsset")) {
		auto asset = std::make_shared <Asset> ("playerStillLeftAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (1).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (2).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (3).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (4).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (5).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (6).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (7).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (8).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (9).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/IdleLeft (10).png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("playerStillLeftAsset");
}

std::vector <int> AssetLoader::getPlayerStillRightAsset () {
	if (!assetLoaded ("playerStillRightAsset")) {
		auto asset = std::make_shared <Asset> ("playerStillRightAsset");
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (1).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (2).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (3).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (4).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (5).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (6).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (7).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (8).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (9).png"));
		asset->addTexture (GraphicsEngine::instance ()->loadMedia ("assets/png/dog/Idle (10).png"));
		loadedAssets.push_back (asset);
	}
	return getAsset ("playerStillRightAsset");
}
