//
// Created by Sjoerd Scheffer on 02-04-17.
//

#include "../include/Tree.h"

Tree::Tree (int x, int y)
: GameObject (AssetLoader::instance ()->getTreeAsset (), 3, x, y, 8, 8, 0, 0, false)
{
}
