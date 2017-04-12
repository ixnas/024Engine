//
// Created by Sjoerd Scheffer on 03-04-17.
//

#include "../include/GroundTopLeft.h"

GroundTopLeft::GroundTopLeft (const int x, const int y)
: GameObject (AssetLoader::instance ()->getGroundAssetTopLeft (), 3, x, y, 4, 4, 0, 0, true)
{
}
