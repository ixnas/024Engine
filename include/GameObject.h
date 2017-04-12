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
		GameObject (std::vector <int> textures, int maxSpriteFrames, int x, int y,
		            int w, int h, float stretchW, float stretchH, bool collidable);
		virtual ~GameObject ();
		virtual void render (int offsetX, int offsetY);
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
