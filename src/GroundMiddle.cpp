//
// Created by Sjoerd Scheffer on 03-04-17.
//

#include "../include/GroundMiddle.h"

GroundMiddle::GroundMiddle (int x, int y)
: GameObject (AssetLoader::instance ()->getGroundAssetMiddleMiddle (), 3, x, y, 4, 4, 0, 0, true)
{

}
