//
// Created by Sjoerd Scheffer on 03-04-17.
//

#include "../include/Bush.h"

Bush::Bush (const int x, const int y)
: GameObject (AssetLoader::instance ()->getBushAsset (), 3, x, y, 4, 2, 0, 0, false)
{
}
