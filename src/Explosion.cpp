//
// Created by Sjoerd Scheffer on 02-04-17.
//

#include "../include/Explosion.h"

Explosion::Explosion (int x, int y, int w, int h)
: TemporaryGameObject (AssetLoader::instance ()->getExplosionAsset (), 90, 90, x, y, w, h, 4, 3, false)
{
}

Explosion::~Explosion () {
}
