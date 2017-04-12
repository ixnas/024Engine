#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class GraphicsEngine {
	private:
		GraphicsEngine (const char* title, const int width, const int height, const int blockX, const int blockY);
		static GraphicsEngine *s_instance;
		const int SCREEN_WIDTH, SCREEN_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT;
		const int blockX, blockY;
		SDL_Window* window;
		SDL_Renderer* renderer;
		std::vector <SDL_Texture*> textures;
		std::vector <TTF_Font*> fonts;
		bool initVideo ();
		bool initWindow (const char* title);
		bool initImgLoader ();
		bool initFontLoader ();
		bool initRenderer ();
		void quitRenderer ();
		void quitWindow ();
		void quitSDL ();
	public:
		static GraphicsEngine *instance (const char* title, const int width, const int height, const int blockX, const int blockY);
		static GraphicsEngine *instance ();
		~GraphicsEngine ();
		int getFrameWidth ();
		int getFrameHeight ();
		int getBlockSizeX ();
		int getBlockSizeY ();
		int loadMedia (const char* path);
		int loadFont (const char* path, const int size);
		int loadText (const int fontnumber, const char *text, const Uint8 r, const Uint8 g, const Uint8 b);
		void clearTextures ();
		void clearFonts ();
		void clearScreen ();
		void refreshScreen ();
		void setViewport (const int x, const int y, const int w, const int h);
		void drawTexture (const int textureNumber, const int x, const int y, const int w, const int h);
		void drawBox (const int x, const int y, const int w, const int h, const Uint8 r, const Uint8 g, const Uint8 b);
		void drawText (const int fontnumber, std::string textToDraw, const int x, const int y);
};

#endif
