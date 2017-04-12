//
// Created by Sjoerd Scheffer on 06-04-17.
//

#include "../include/PlatformRight.h"

PlatformRight::PlatformRight (int x, int y)
: GameObject (AssetLoader::instance ()->getPlatformRightAsset (), 3, x, y, 4, 3, 0, 0, true)
{
}
