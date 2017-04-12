#include <string>
#include <iostream>
#include <vector>
#include "../include/GraphicsEngine.h"

bool GraphicsEngine::initVideo () {
	if (SDL_Init (SDL_INIT_VIDEO) < 0) {
		return false;
	} else {
		return true;
	}
}

bool GraphicsEngine::initWindow (const char* title) {
	window = SDL_CreateWindow (title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		std::cout << "Could not initialize video: " << SDL_GetError () << std::endl;
		return false;
	} else {
		std::cout << "Video initialized." << std::endl;
		return true;
	}
}

bool GraphicsEngine::initImgLoader () {
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init (imgFlags) & imgFlags)) {
		std::cout << "IMG loader failed to load: " << IMG_GetError () << std::endl;
		return false;
	} else {
		std::cout << "IMG loader initialized." << std::endl;
		return true;
	}
}

bool GraphicsEngine::initFontLoader () {
	if (TTF_Init () == -1) {
		std::cout << "Font loader failed to load: " << TTF_GetError () << std::endl;
		return false;
	} else {
		std::cout << "Font loader initialized." << std::endl;
		return true;
	}
}

bool GraphicsEngine::initRenderer () {
	renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		std::cout << "Renderer failed to load: " << SDL_GetError () << std::endl;
		return false;
	} else {
		std::cout << "Renderer initialized." << std::endl;
		SDL_RenderSetLogicalSize (renderer, FRAME_WIDTH, FRAME_HEIGHT);
		SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY, "linear");
		SDL_SetRenderDrawColor (renderer, 0x00, 0x00, 0x00, 0x00);
		return true;
	}
}

void GraphicsEngine::quitRenderer () {
	SDL_DestroyRenderer (renderer);
	renderer = NULL;
	std::cout << "  Stopped renderer" << std::endl;
}

void GraphicsEngine::quitWindow () {
	SDL_DestroyWindow (window);
	window = NULL;
	std::cout << "  Deleted window" << std::endl;
}

void GraphicsEngine::quitSDL () {
	TTF_Quit ();
	IMG_Quit ();
	SDL_Quit ();
	std::cout << "Done" << std::endl;
}

GraphicsEngine *GraphicsEngine::instance () {
	return s_instance;
};

GraphicsEngine * GraphicsEngine::instance (const char *title, const int width, const int height, const int blockX, const int blockY) {
	if (s_instance == NULL) {
		s_instance = new GraphicsEngine (title, width, height, blockX, blockY);
	}
	return s_instance;
}


GraphicsEngine::GraphicsEngine (const char* title, const int width, const int height, const int blockX, const int blockY)
	: SCREEN_WIDTH (width)
	, SCREEN_HEIGHT (height)
	, FRAME_WIDTH (640)
	, FRAME_HEIGHT (360)
	, blockX (FRAME_WIDTH / blockX)
	, blockY (FRAME_HEIGHT / blockY)
	, window (NULL)
	, renderer (NULL)
{
	std::cout << "===== 024 Game Engine =====" << std::endl;
	std::cout << "  v0.1 by Sjoerd Scheffer  " << std::endl;
	std::cout << "===========================" << std::endl;
	if (initVideo ()) {
		if (initWindow (title)) {
			if (initImgLoader ()) {
				if (initFontLoader ()) {
					initRenderer ();
				}
			}
		}
	}

	//SDL_SetWindowFullscreen (window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

GraphicsEngine::~GraphicsEngine () {
	std::cout << "Freeing up resources..." << std::endl;
	clearTextures ();
	clearFonts ();
	quitRenderer ();
	quitWindow ();
	quitSDL ();
}

int GraphicsEngine::getFrameWidth () {
	return FRAME_WIDTH;
}

int GraphicsEngine::getFrameHeight () {
	return FRAME_HEIGHT;
}

int GraphicsEngine::getBlockSizeX () {
	return blockX;
}

int GraphicsEngine::getBlockSizeY () {
	return blockY;
}

int GraphicsEngine::loadMedia (const char* path) {
	SDL_Texture* texture = NULL;
	SDL_Surface* image = IMG_Load (path);
	if (image == NULL) {
		std::cout << "Couldn't load image: " << IMG_GetError () << std::endl;
		return -1;
	} else {
		texture = SDL_CreateTextureFromSurface (renderer, image);
		if (texture == NULL) {
			std::cout << "Couldn't load texture: " << SDL_GetError () << std::endl;
			return -1;
		} else {
			textures.push_back (texture);
			SDL_FreeSurface (image);
			std::cout << "Texture loaded. (ID = " << textures.size ()-1 << ", path = \"" << path << "\")" << std::endl;
			return textures.size ()-1;
		}
	}
}

int GraphicsEngine::loadText (const int fontnumber, const char *text, const Uint8 r, const Uint8 g, const Uint8 b) {
	SDL_Color color = {r, g, b};
	SDL_Surface *surfaceMessage = TTF_RenderText_Solid (fonts [fontnumber], text, color);
	SDL_Texture *textureMessage = NULL;
	if (surfaceMessage == NULL) {
		std::cout << "Couldn't render text: " << TTF_GetError () << std::endl;
		return -1;
	} else {
		textureMessage = SDL_CreateTextureFromSurface (renderer, surfaceMessage);
		SDL_FreeSurface (surfaceMessage);
		if (textureMessage == NULL) {
			std::cout << "Could not load texture: " << TTF_GetError () << std::endl;
			return -1;
		} else {
			textures.push_back (textureMessage);
			return textures.size ()-1;
		}
	}
};


int GraphicsEngine::loadFont (const char* path, const int size) {
	TTF_Font* font = TTF_OpenFont (path, size);
	if (font == NULL) {
		std::cout << "Could not load font: " << TTF_GetError () << std::endl;
		return -1;
	} else {
		fonts.push_back (font);
		std::cout << "Font loaded. (ID = " << fonts.size ()-1 << ", path = \"" << path << "\")" << std::endl;
		return fonts.size () - 1;
	}
}

void GraphicsEngine::clearTextures () {
	int numberOfTextures = textures.size ();
	if (textures.size () > 0) {
		for (int i = 0; i < textures.size (); i++) {
			SDL_DestroyTexture (textures [i]);
			textures [i] = NULL;
		}
	}
	std::cout << "  Removed " << numberOfTextures << " textures" << std::endl;
	textures.clear ();
}

void GraphicsEngine::clearFonts () {
	if (fonts.size () > 0) {
		for (int i = 0; i < fonts.size (); i++) {
			TTF_CloseFont (fonts [i]);
			fonts [i] = NULL;
			std::cout << "  Removed font: " << i << std::endl;
		}
	}
	fonts.clear ();
}

void GraphicsEngine::clearScreen () {
	SDL_RenderClear (renderer);
}

void GraphicsEngine::refreshScreen () {
	SDL_RenderPresent (renderer);
}

void GraphicsEngine::setViewport (const int x, const int y, const int w, const int h) {
	SDL_Rect viewport;
	viewport.x = x;
	viewport.y = y;
	viewport.w = w;
	viewport.h = h;
	SDL_RenderSetViewport (renderer, &viewport);
}

void GraphicsEngine::drawTexture (const int textureNumber, const int x, const int y, const int w, const int h) {
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	SDL_RenderCopy (renderer, textures [textureNumber], NULL, &dest);
}

void GraphicsEngine::drawBox (const int x, const int y, const int w, const int h, const Uint8 r, const Uint8 g, const Uint8 b) {
	SDL_SetRenderDrawColor (renderer, r, g, b, 255);

	SDL_Rect rectangle;
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;

	SDL_RenderDrawRect (renderer, &rectangle);
	SDL_SetRenderDrawColor (renderer, 0, 0, 0, 255);
}

void GraphicsEngine::drawText (const int fontnumber, std::string textToDraw, const int x, const int y) {
	SDL_Color textColor = {255, 0, 0};
	SDL_Surface* textSurface = TTF_RenderText_Solid (fonts [fontnumber], textToDraw.c_str(), textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface (renderer, textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface (textSurface);
	SDL_Rect renderQuad = {x, y, text_width, text_height};
	SDL_RenderCopy(renderer, text, NULL, &renderQuad);
	SDL_DestroyTexture(text);
}

