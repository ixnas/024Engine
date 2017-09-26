//
// Created by Sjoerd Scheffer on 05-04-17.
//

#ifndef CLION_SDL_FPSCOUNTER_H
#define CLION_SDL_FPSCOUNTER_H

#include <chrono>
#include <iostream>
#include "../include/GraphicsEngine.h"

class FPSCounter {
	private:
		std::shared_ptr <GraphicsEngine> graphicsEngine;
		time_t start;
		double time_difference;
		int fps;
		int passedFrames;
	public:
		FPSCounter (std::shared_ptr <GraphicsEngine> graphicsEngine);
		~FPSCounter ();
		void showFPS ();
};

#endif //CLION_SDL_FPSCOUNTER_H
