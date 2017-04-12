#include <chrono>
#include <zconf.h>
#include "../include/FPSCounter.h"
#include "../include/Camera.h"
#include "../include/Game.h"
#include "../include/Crate.h"
#include "../include/Tree.h"
#include "../include/Bush.h"
#include "../include/Bush2.h"
#include "../include/GroundTop.h"
#include "../include/GroundMiddle.h"
#include "../include/GroundTopLeft.h"
#include "../include/GroundTopRight.h"
#include "../include/GroundMiddleLeft.h"
#include "../include/GroundMiddleRight.h"
#include "../include/PlatformLeft.h"
#include "../include/PlatformMiddle.h"
#include "../include/PlatformRight.h"
#include "../include/InputControllerFactory.h"

AssetLoader * AssetLoader::s_instance;
GraphicsEngine * GraphicsEngine::s_instance;

void gameLoop (SDL_Event *sdl_event, std::shared_ptr <Game> game, std::shared_ptr <InputController> inputController) {

	FPSCounter fpsCounter;
	bool quit = false;

	while (!quit) {
		GraphicsEngine::instance ()->clearScreen ();

		while (SDL_PollEvent (sdl_event) != 0) {
			if (sdl_event->type == SDL_QUIT) {
				quit = true;
			}

			if (sdl_event->type == SDL_KEYDOWN) {
				inputController->pressKey (sdl_event->key.keysym.sym);
			}

			if (sdl_event->type == SDL_KEYUP) {
				inputController->releaseKey (sdl_event->key.keysym.sym);
			}

			if (inputController->keyPressed (SDLK_ESCAPE)) {
				quit = true;
			}
		}

		game->loop ();
		fpsCounter.showFPS ();

		GraphicsEngine::instance ()->refreshScreen ();
	}
}

void loadGame (std::shared_ptr <Game> game) {
	GraphicsEngine::instance ()->loadFont ("fonts/OpenSans-Regular.ttf", 12);
	AssetLoader::instance ()->getExplosionAsset ();

	auto minX = 0;
	auto maxX = 32;
	auto minY = 17;
	auto maxY = 512;

	game->addGameObject (std::make_shared <GroundTopLeft> (minX, minY));
	for (auto i = minY + 4; i < maxY; i = i + 4) {
		game->addGameObject (std::make_shared <GroundMiddleLeft> (minX, i));
	}

	for (auto i = minX + 4; i < maxX; i = i + 4) {
		game->addGameObject (std::make_shared <GroundTop> (i, minY));
		for (int j = minY + 4; j < maxY; j = j + 4) {
			game->addGameObject (std::make_shared <GroundMiddle> (i, j));
		}
	}

	game->addGameObject (std::make_shared <PlatformLeft> (36, 11));
	game->addGameObject (std::make_shared <PlatformMiddle> (40, 11));
	game->addGameObject (std::make_shared <PlatformRight> (44, 11));

	game->addGameObject (std::make_shared <GroundTopRight> (maxX, minY));
	for (auto i = minY + 4; i < maxY; i = i + 4) {
		game->addGameObject (std::make_shared <GroundMiddleRight> (maxX, i));
	}

	game->addGameObject (std::make_shared <Crate> (20, 15));
	game->addGameObject (std::make_shared <Crate> (20, 13));

	game->addGameObject (std::make_shared <Tree> (2, 9));
	game->addGameObject (std::make_shared <Bush> (11, 15));
	game->addGameObject (std::make_shared <Bush2> (13, 15));

	game->addGameObject (std::make_shared <Bullet> (game->getCollisionController (), 4, 14, 5));
}

void drawTitleScreen () {
	auto screen = GraphicsEngine::instance ()->loadMedia ("assets/title.png");
	GraphicsEngine::instance ()->clearScreen ();
	GraphicsEngine::instance ()->drawTexture (screen, 0, 0, GraphicsEngine::instance ()->getFrameWidth (), GraphicsEngine::instance ()->getFrameHeight ());
	GraphicsEngine::instance ()->refreshScreen ();
	GraphicsEngine::instance ()->clearTextures ();
}

int main () {

	/* GLOBAL SETTINGS */
	const char TITLE [] = "30-03-2017";
	const auto RESOLUTION_X = 1920;
	const auto RESOLUTION_Y = 1080;
	const auto BLOCKS_X = 32;
	const auto BLOCKS_Y = 18;
	const char BACKGROUND_PATH [] = "assets/background2.png";

	/* Initialize engine components */
	SDL_Event sdl_event;
	GraphicsEngine::instance (TITLE, RESOLUTION_X, RESOLUTION_Y, BLOCKS_X, BLOCKS_Y);
	//chdir (SDL_GetBasePath ());

	drawTitleScreen ();

	auto camera = std::make_unique <Camera> (0, 0, 5, 5);
	auto inputControllerFactory = std::make_unique <InputControllerFactory> ();
	auto inputController (inputControllerFactory->getInputController ("KeyboardController"));
	auto collisionController = std::make_shared <CollisionController> ();
	auto background = GraphicsEngine::instance ()->loadMedia (BACKGROUND_PATH);

	auto game (std::make_shared <Game> (inputController, collisionController, std::move (camera), background));

	/* Add game assets and objects */
	loadGame (game);

	/* Main game loop */
	gameLoop (&sdl_event, game, inputController);

	/* Clean up engine components */
	delete AssetLoader::instance ();
	delete GraphicsEngine::instance ();

	return 0;

}
