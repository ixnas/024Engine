//
// Created by Sjoerd Scheffer on 06-04-17.
//

#include "../include/PlatformMiddle.h"

PlatformMiddle::PlatformMiddle (int x, int y)
: GameObject (AssetLoader::instance ()->getPlatformMiddleAsset (), 3, x, y, 4, 3, 0, 0, true)
{
}
