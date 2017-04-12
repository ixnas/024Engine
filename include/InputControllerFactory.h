//
// Created by Sjoerd Scheffer on 07-04-17.
//

#ifndef CLION_SDL_INPUTCONTROLLERFACTORY_H
#define CLION_SDL_INPUTCONTROLLERFACTORY_H

#include "../include/InputController.h"
#include "../include/KeyboardController.h"
#include <string>

class InputControllerFactory {
	public:
		std::shared_ptr <InputController> getInputController (std::string type);
};


#endif //CLION_SDL_INPUTCONTROLLERFACTORY_H
