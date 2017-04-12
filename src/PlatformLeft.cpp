//
// Created by Sjoerd Scheffer on 06-04-17.
//

#include "../include/PlatformLeft.h"

PlatformLeft::PlatformLeft (int x, int y)
: GameObject (AssetLoader::instance ()->getPlatformLeftAsset (), 3, x, y, 4, 3, 0, 0, true)
{
}
