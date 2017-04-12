//
// Created by Sjoerd Scheffer on 07-04-17.
//

#include "../include/InputControllerFactory.h"

std::shared_ptr <InputController> InputControllerFactory::getInputController (std::string type) {
	if (type == "KeyboardController") {
		return std::make_shared <KeyboardController> ();
	} else {
		return nullptr;
	}
}
