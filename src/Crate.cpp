//
// Created by Sjoerd Scheffer on 02-04-17.
//

#include "../include/Crate.h"

Crate::Crate (const int x, const int y)
: GameObject (AssetLoader::instance ()->getCrateAsset (), 3, x, y, 2, 2, 0, 0, true)
{
}
