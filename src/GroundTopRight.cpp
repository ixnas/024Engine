//
// Created by Sjoerd Scheffer on 03-04-17.
//

#include "../include/GroundTopRight.h"

GroundTopRight::GroundTopRight (const int x, const int y)
: GameObject (AssetLoader::instance ()->getGroundAssetTopRight (), 3, x, y, 4, 4, 0, 0, true)
{

}
