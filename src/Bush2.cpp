//
// Created by Sjoerd Scheffer on 03-04-17.
//

#include "../include/Bush2.h"

Bush2::Bush2 (const int x, const int y)
		: GameObject (AssetLoader::instance ()->getBushAsset2 (), 3, x, y, 4, 2, 0, 0, false)
{
}
