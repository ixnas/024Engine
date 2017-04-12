//
// Created by Sjoerd Scheffer on 03-04-17.
//

#include "../include/GroundMiddleRight.h"

GroundMiddleRight::GroundMiddleRight (const int x, const int y)
: GameObject (AssetLoader::instance ()->getGroundAssetMiddleRight (), 3, x, y, 4, 4, 0, 0, true)
{

}
