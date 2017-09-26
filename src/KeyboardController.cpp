#include "../include/KeyboardController.h"
#include <iostream>

KeyboardController::KeyboardController () {
	std::cout << "[KeyboardController] Initialized" << std::endl;
}

KeyboardController::~KeyboardController () {
	std::cout << "[KeyboardController] Stopped" << std::endl;
}

void KeyboardController::pressKey (const int key) {
	auto cont = true;
	for (int i = 0; i < keysPressed.size (); i++) {
		if (keysPressed [i] == key) {
			cont = false;
		}
	}

	if (cont) {
		keysPressed.push_back (key);
	}
}

void KeyboardController::releaseKey (const int key) {
	for (int i = 0; i < keysPressed.size (); i++) {
		if (keysPressed [i] == key) {
			keysPressed.erase (keysPressed.begin () + i);
		}
	}
}

bool KeyboardController::keyPressed (const int key) {
	auto result = false;
	for (int i = 0; i < keysPressed.size (); i++) {
		if (keysPressed [i] == key) {
			result = true;
		}
	}
	return result;
}

void KeyboardController::printKeys () {
	for (int i = 0; i < keysPressed.size (); i++) {
		std::cout << "Pressed: " << keysPressed [i] << " ";
	}
	std::cout << std::endl;
}
