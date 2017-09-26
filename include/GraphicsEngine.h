#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class GraphicsEngine {
	private:
		const int SCREEN_WIDTH, SCREEN_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT;
		SDL_Window* window;
		SDL_Renderer* renderer;
		std::vector <SDL_Texture*> textures;
		std::vector <TTF_Font*> fonts;
		void initVideo ();
		void initWindow (const std::string title);
		void initImgLoader ();
		void initFontLoader ();
		void initRenderer ();
		void quitRenderer ();
		void quitWindow ();
		void quitSDL ();
	public:
		GraphicsEngine (const std::string title, const int width, const int height);
		~GraphicsEngine ();
		int getFrameWidth ();
		int getFrameHeight ();
		int loadMedia (const std::string path);
		int loadFont (const std::string path, const int size);
		int loadText (const int fontnumber, const std::string text, const Uint8 r, const Uint8 g, const Uint8 b);
		void clearTextures ();
		void removeTexture (const int textureNumber);
		void clearFonts ();
		void clearScreen ();
		void refreshScreen ();
		void setViewport (const int x, const int y, const int w, const int h);
		void drawTexture (const int textureNumber, const int x, const int y, const int w, const int h);
		void drawBox (const int x, const int y, const int w, const int h, const Uint8 r, const Uint8 g, const Uint8 b);
		void drawText (const int fontnumber, const std::string textToDraw, const int x, const int y, const Uint8 r, const Uint8 g, const Uint8 b);
};

#endif
