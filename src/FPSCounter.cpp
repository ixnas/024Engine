//
// Created by Sjoerd Scheffer on 05-04-17.
//

#include "../include/FPSCounter.h"

FPSCounter::FPSCounter ()
: start (time (0))
, time_difference (difftime (time (0), start))
, fps (0)
, passedFrames (0)
{
	std::cout << "FPSCounter initialized" << std::endl;
}

FPSCounter::~FPSCounter () {
	std::cout << "FPSCounter stopped" << std::endl;
}

void FPSCounter::showFPS () {
	(passedFrames)++;
	time_difference = difftime (time (0), start);

	if (time_difference >= 1) {
		fps = passedFrames;
		passedFrames = 0;
		start = time (0);
	}
	GraphicsEngine::instance ()->drawText (1, std::to_string (fps), 30, 30);
}
