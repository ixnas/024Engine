#include "../include/GameObject.h"
#include <iostream>

/*
bool GameObject::reachedFrameLimit () {
	return passedSpriteFrames >= maxSpriteFrames;
}

bool GameObject::debuggersEnabled () {
	return debuggers.size () > 0;
}

bool GameObject::stretchEnabled () {
	return stretchH != 0 || stretchW != 0;
}

void GameObject::nextFrame () {
	if (!reachedFrameLimit ()) {
		passedSpriteFrames++;
	} else {
		passedSpriteFrames = 0;
	}
}

void GameObject::drawTexture (const int offsetX, const int offsetY) {
	int currenttexture = ((textures.size () * 1000) / maxSpriteFrames * passedSpriteFrames) / 1000;
	GraphicsEngine::instance ()->drawTexture (textures [currenttexture], x+offsetX-stretchW, y+offsetY-stretchH, w+stretchW*2, h+stretchH*2);
}

void GameObject::drawDebug (const int offsetX, const int offsetY) {
	for (int i = 0; i < debuggers.size (); i++) {
		GraphicsEngine::instance ()->drawTexture (debuggers [i].getName (), x+offsetX-stretchW, y+offsetY-stretchH+10*i, 20, 10);
		GraphicsEngine::instance ()->drawTexture (debuggers [i].getValue (), x+offsetX-stretchW+25, y+offsetY-stretchH+10*i, 10, 10);
	}
	GraphicsEngine::instance ()->drawBox (x+offsetX, y+offsetY, w, h, 255, 0, 0);
	if (stretchEnabled ()) {
		GraphicsEngine::instance ()->drawBox (x+offsetX-stretchW, y+offsetY-stretchH, w+stretchW*2, h+stretchH*2, 0, 255, 0);
	}
}

GameObject::GameObject (const std::vector <int> textures, const int maxSpriteFrames, const int x, const int y, const int w, const int h, const float stretchW, const float stretchH, const bool collidable)
: x (GraphicsEngine::instance ()->getBlockSizeX () * x)
, y (GraphicsEngine::instance ()->getBlockSizeY () * y)
, w (GraphicsEngine::instance ()->getBlockSizeX () * w)
, h (GraphicsEngine::instance ()->getBlockSizeY () * h)
, stretchW (GraphicsEngine::instance ()->getBlockSizeX () * stretchW)
, stretchH (GraphicsEngine::instance ()->getBlockSizeY () * stretchH)
, collidable (collidable)
, remove (false)
, passedSpriteFrames (0)
, maxSpriteFrames (maxSpriteFrames)
, textures (textures)
{
	//debuggers.push_back (Debugger ("sFrames", &passedSpriteFrames, 0, maxSpriteFrames));
}

GameObject::~GameObject () {
}

void GameObject::render (const int offsetX, const int offsetY) {
	drawTexture (offsetX, offsetY);

	if (debuggersEnabled ()) {
		drawDebug (offsetX, offsetY);
	}

	nextFrame ();
}

void GameObject::prepareFrame () {
}

bool GameObject::isCollidable () {
	return collidable;
}

bool GameObject::toBeRemoved () {
	return remove;
}

void GameObject::setRemove () {
	remove = true;
}

bool GameObject::canReincarnate () {
	return false;
}

std::shared_ptr <GameObject> GameObject::getReincarnation () {
	return nullptr;
}

int GameObject::getX () {
	return x;
}

int GameObject::getY () {
	return y;
}

int GameObject::getW () {
	return w;
}

int GameObject::getH () {
	return h;
}

int GameObject::getStretchedX () {
	return x-stretchW;
}

int GameObject::getStretchedY () {
	return y-stretchH;
}

int GameObject::getStretchedW () {
	return w+stretchW*2;
}

int GameObject::getStretchedH () {
	return h+stretchH*2;
}

bool GameObject::reincarnateIntoForeground () {
	return false;
}
 */
