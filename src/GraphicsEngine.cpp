#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "../include/GraphicsEngine.h"

void GraphicsEngine::initVideo () {
	if (SDL_Init (SDL_INIT_VIDEO) < 0) {
		throw std::string ("Couldn't initialize video");
	} else {
		std::cout << "[GrahpicsEngine] Video initialized." << std::endl;
	}
}

void GraphicsEngine::initWindow (const std::string title) {
	window = SDL_CreateWindow (title.c_str (), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		throw std::string ("Could not initialize window: " + (std::string) SDL_GetError ());
	} else {
		std::cout << "[GrahpicsEngine] Window initialized." << std::endl;
	}
}

void GraphicsEngine::initImgLoader () {
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init (imgFlags) & imgFlags)) {
		throw std::string ("IMG loader failed to load: " + (std::string) IMG_GetError ());
	} else {
		std::cout << "[GrahpicsEngine] IMG loader initialized." << std::endl;
	}
}

void GraphicsEngine::initFontLoader () {
	if (TTF_Init () == -1) {
		throw std::string ("Font loader failed to load: " + (std::string) TTF_GetError ());
	} else {
		std::cout << "[GrahpicsEngine] Font loader initialized." << std::endl;
	}
}

void GraphicsEngine::initRenderer () {
	renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		throw std::string ("Renderer failed to load: " + (std::string) SDL_GetError ());
	} else {
		std::cout << "[GrahpicsEngine] Renderer initialized." << std::endl;
		SDL_RenderSetLogicalSize (renderer, FRAME_WIDTH, FRAME_HEIGHT);
		SDL_SetHint (SDL_HINT_RENDER_SCALE_QUALITY, "linear");
		SDL_SetRenderDrawColor (renderer, 0x00, 0x00, 0x00, 0x00);
	}
}

void GraphicsEngine::quitRenderer () {
	SDL_DestroyRenderer (renderer);
	renderer = nullptr;
	std::cout << "[GrahpicsEngine]   Stopped renderer" << std::endl;
}

void GraphicsEngine::quitWindow () {
	SDL_DestroyWindow (window);
	window = nullptr;
	std::cout << "[GrahpicsEngine]   Deleted window" << std::endl;
}

void GraphicsEngine::quitSDL () {
	TTF_Quit ();
	IMG_Quit ();
	SDL_Quit ();
	std::cout << "[GrahpicsEngine] Stopped" << std::endl;
}

GraphicsEngine::GraphicsEngine (const std::string title, const int width, const int height)
	: SCREEN_WIDTH (width)
	, SCREEN_HEIGHT (height)
	, FRAME_WIDTH (width)
	, FRAME_HEIGHT (height)
	, window (nullptr)
	, renderer (nullptr)
{
	std::cout << "===== 024 Game Engine =====" << std::endl;
	std::cout << "  v0.1 by Sjoerd Scheffer  " << std::endl;
	std::cout << "===========================" << std::endl;
	initVideo ();
	initWindow (title);
	initImgLoader ();
	initFontLoader ();
	initRenderer ();

	//SDL_SetWindowFullscreen (window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

GraphicsEngine::~GraphicsEngine () {
	std::cout << "[GraphicsEngine] Freeing up resources..." << std::endl;
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

int GraphicsEngine::loadMedia (const std::string path) {
	SDL_Texture* texture = nullptr;
	SDL_Surface* image = IMG_Load (path.c_str ());
	if (image == nullptr) {
		std::cout << "[GrahpicsEngine] Couldn't load image: " << IMG_GetError () << std::endl;
		return -1;
	} else {
		texture = SDL_CreateTextureFromSurface (renderer, image);
		if (texture == nullptr) {
			std::cout << "[GrahpicsEngine] Couldn't load texture: " << SDL_GetError () << std::endl;
			return -1;
		} else {
			textures.push_back (texture);
			SDL_FreeSurface (image);
			std::cout << "[GrahpicsEngine] Texture loaded. (ID = " << textures.size ()-1 << ", path = \"" << path << "\")" << std::endl;
			return textures.size ()-1;
		}
	}
}

int GraphicsEngine::loadText (const int fontnumber, const std::string text, const Uint8 r, const Uint8 g, const Uint8 b) {
	SDL_Color color = {r, g, b};
	SDL_Surface *surfaceMessage = TTF_RenderText_Solid (fonts [fontnumber], text.c_str (), color);
	SDL_Texture *textureMessage = nullptr;
	if (surfaceMessage == nullptr) {
		std::cout << "[GrahpicsEngine] Couldn't render text: " << TTF_GetError () << std::endl;
		return -1;
	} else {
		textureMessage = SDL_CreateTextureFromSurface (renderer, surfaceMessage);
		SDL_FreeSurface (surfaceMessage);
		if (textureMessage == nullptr) {
			std::cout << "[GrahpicsEngine] Could not load texture: " << TTF_GetError () << std::endl;
			return -1;
		} else {
			textures.push_back (textureMessage);
			return textures.size ()-1;
		}
	}
};


int GraphicsEngine::loadFont (const std::string path, const int size) {
	TTF_Font* font = TTF_OpenFont (path.c_str (), size);
	if (font == nullptr) {
		std::cout << "[GrahpicsEngine] Could not load font: " << TTF_GetError () << std::endl;
		return -1;
	} else {
		fonts.push_back (font);
		std::cout << "[GrahpicsEngine] Font loaded. (ID = " << fonts.size ()-1 << ", path = \"" << path << "\")" << std::endl;
		return fonts.size () - 1;
	}
}

void GraphicsEngine::clearTextures () {
	int numberOfTextures = 0;
	if (textures.size () > 0) {
		for (int i = 0; i < textures.size (); i++) {
			if (textures [i] != nullptr) {
				numberOfTextures++;
				SDL_DestroyTexture (textures [i]);
				textures [i] = nullptr;
			}
		}
	}
	std::cout << "[GrahpicsEngine]   Removed " << numberOfTextures << " textures" << std::endl;
	textures.clear ();
}

void GraphicsEngine::clearFonts () {
	if (fonts.size () > 0) {
		for (int i = 0; i < fonts.size (); i++) {
			TTF_CloseFont (fonts [i]);
			fonts [i] = nullptr;
			std::cout << "[GrahpicsEngine]   Removed font: " << i << std::endl;
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
	SDL_RenderCopy (renderer, textures [textureNumber], nullptr, &dest);
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

void GraphicsEngine::drawText (const int fontnumber, std::string textToDraw, const int x, const int y, const Uint8 r, const Uint8 g, const Uint8 b) {
	SDL_Color textColor = {r, g, b};
	SDL_Surface* textSurface = TTF_RenderText_Solid (fonts [fontnumber], textToDraw.c_str(), textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface (renderer, textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface (textSurface);
	SDL_Rect renderQuad = {x, y, text_width, text_height};
	SDL_RenderCopy(renderer, text, nullptr, &renderQuad);
	SDL_DestroyTexture(text);
}

void GraphicsEngine::removeTexture (const int textureNumber) {
	if (textures.size () > textureNumber) {
		if (textures [textureNumber] != nullptr) {
			SDL_DestroyTexture (textures [textureNumber]);
			textures [textureNumber] = nullptr;
		} else {
			throw std::string ("Not a valid texture number");
		}
	} else {
		throw std::string ("Not a valid texture number");
	}
}

