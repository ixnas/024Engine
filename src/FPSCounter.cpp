//
// Created by Sjoerd Scheffer on 05-04-17.
//

#include "../include/FPSCounter.h"

FPSCounter::FPSCounter (std::shared_ptr <GraphicsEngine> graphicsEngine)
: graphicsEngine (graphicsEngine)
, start (time (0))
, time_difference (difftime (time (0), start))
, fps (0)
, passedFrames (0)
{
	std::cout << "[FPSCounter] Initialized" << std::endl;
}

FPSCounter::~FPSCounter () {
	std::cout << "[FPSCounter] Stopped" << std::endl;
}

void FPSCounter::showFPS () {
	(passedFrames)++;
	time_difference = difftime (time (nullptr), start);

	if (time_difference >= 1) {
		fps = passedFrames;
		passedFrames = 0;
		start = time (nullptr);
	}
	graphicsEngine->drawText (0, std::to_string (fps), 30, 30, 255, 255, 255);
}
