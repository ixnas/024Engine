//
// Created by Sjoerd Scheffer on 03-04-17.
//

#include "../include/GroundMiddleLeft.h"

GroundMiddleLeft::GroundMiddleLeft (int x, int y)
: GameObject (AssetLoader::instance ()->getGroundAssetMiddleLeft (), 3, x, y, 4, 4, 0, 0, true)
{

}
