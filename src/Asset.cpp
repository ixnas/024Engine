#include "../include/Asset.h"

Asset::Asset (const char *name)
{
	this->name = name;
}

std::string Asset::getName () {
	return name;
}

std::vector <int> Asset::getTextures () {
	return textures;
}

void Asset::addTexture (const int textureNumber) {
	textures.push_back (textureNumber);
}
