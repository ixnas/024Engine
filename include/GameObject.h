#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../include/GraphicsEngine.h"
#include "../include/Debugger.h"
#include "../include/AssetLoader.h"
#include <vector>

class GameObject {
	private:
		bool reachedFrameLimit ();
		bool debuggersEnabled ();
		bool stretchEnabled ();
		void nextFrame ();
		void drawTexture (const int offsetX, const int offsetY);
		void drawDebug (const int offsetX, const int offsetY);
	protected:
		int x, y, w, h, stretchW, stretchH;
		bool collidable;
		bool remove;
		int passedSpriteFrames;
		int maxSpriteFrames;
		std::vector <int> textures;
		std::vector <Debugger> debuggers;
	public:
		GameObject (const std::vector <int> textures, const int maxSpriteFrames, const int x, const int y,
		            const int w, const int h, const float stretchW, const float stretchH, const bool collidable);
		virtual ~GameObject ();
		virtual void render (const int offsetX, const int offsetY);
		virtual void prepareFrame ();
		bool isCollidable ();
		bool toBeRemoved ();
		virtual void setRemove ();
		virtual bool canReincarnate ();
		virtual bool reincarnateIntoForeground ();
		virtual std::shared_ptr <GameObject> getReincarnation ();
		int getX ();
		int getY ();
		int getW ();
		int getH ();
		int getStretchedX ();
		int getStretchedY ();
		int getStretchedW ();
		int getStretchedH ();
};

#endif
