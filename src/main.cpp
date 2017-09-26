#include <chrono>
#include <string>
#include <thread>
#include <zconf.h>
#include "../include/FPSCounter.h"
#include "../include/Camera.h"
#include "../include/InputControllerFactory.h"
#include "../include/AssetLoader.h"

void drawBox (std::shared_ptr <GraphicsEngine> graphicsEngine, int &factor, int &boxX, int &boxY) {
	if (boxX >= graphicsEngine->getFrameWidth ()/2 || boxY >= graphicsEngine->getFrameHeight ()/2) {
		factor = -23;
	} else if (boxX == 0 || boxY == 0) {
		factor = 23;
	}

	boxX = boxX + factor*2;
	boxY = boxY + factor;

	int x = graphicsEngine->getFrameWidth () / 2 - boxX;
	int y = graphicsEngine->getFrameHeight () / 2 - boxY;
	int w = boxX * 2;
	int h = boxY * 2;

	graphicsEngine->drawBox (x, y, w, h, boxY*24, boxY*53, boxY*42);
}

bool inputListener (const std::shared_ptr <InputController> inputController) {
	SDL_Event sdl_event;

	while (SDL_PollEvent (&sdl_event) != 0) {
		if (sdl_event.type == SDL_QUIT) {
			return true;
		}

		if (sdl_event.type == SDL_KEYDOWN) {
			inputController->pressKey (sdl_event.key.keysym.sym);
		}

		if (sdl_event.type == SDL_KEYUP) {
			inputController->releaseKey (sdl_event.key.keysym.sym);
		}

		if (inputController->keyPressed (SDLK_ESCAPE)) {
			return true;
		}
	}
	return false;
}

void gameLoop (const std::shared_ptr <GraphicsEngine> graphicsEngine) {
	InputControllerFactory inputControllerFactory;
	auto inputController = inputControllerFactory.getInputController ("KeyboardController");
	auto assetLoader = std::make_unique <AssetLoader> ();

	graphicsEngine->loadFont ("fonts/OpenSans-Regular.ttf", graphicsEngine->getFrameHeight ()/16);
	FPSCounter fpsCounter (graphicsEngine);
	bool quit = false;

	int boxX, boxY = 0;
	int factor = 1;

	while (!quit) {
		graphicsEngine->clearScreen ();
		quit = inputListener (inputController);
		drawBox (graphicsEngine, factor, boxX, boxY);
		fpsCounter.showFPS ();
		graphicsEngine->refreshScreen ();
	}
}

void drawTitleScreen (const std::shared_ptr <GraphicsEngine> graphicsEngine) {
	auto screen = graphicsEngine->loadMedia ("assets/title.png");
	graphicsEngine->clearScreen ();
	graphicsEngine->drawTexture (screen, 0, 0, graphicsEngine->getFrameWidth (), graphicsEngine->getFrameHeight ());
	graphicsEngine->refreshScreen ();
	graphicsEngine->clearTextures ();
}

int main () {
	/* GLOBAL SETTINGS */
	const std::string TITLE = "30-03-2017";
	const auto RESOLUTION_X = 1200;
	const auto RESOLUTION_Y = 600;
	const std::string BACKGROUND_PATH = "assets/background2.png";

	/* Initialize engine components */
	std::shared_ptr <GraphicsEngine> graphicsEngine;
	try {
		graphicsEngine = std::make_shared <GraphicsEngine> (TITLE, RESOLUTION_X, RESOLUTION_Y);
	} catch (std::string &error) {
		std::cout << "[GraphicsEngine] Error: " << error << std::endl;
		return 1;
	}
	// Required for Mac bundles
	//chdir (SDL_GetBasePath ());

	drawTitleScreen (graphicsEngine);

	/* Main game loop */
	gameLoop (graphicsEngine);

	return 0;

}
