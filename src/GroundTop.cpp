//
// Created by Sjoerd Scheffer on 03-04-17.
//

#include "../include/GroundTop.h"

GroundTop::GroundTop (const int x, const int y)
: GameObject (AssetLoader::instance ()->getGroundAssetTopMiddle (), 3, x, y, 4, 4, 0, 0, true)
{
}
