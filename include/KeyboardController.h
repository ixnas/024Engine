#ifndef BUTTONCONTROLLER_H
#define BUTTONCONTROLLER_H

#include <vector>
#include "../include/InputController.h"

class KeyboardController : public InputController {
	private:
		std::vector <int> keysPressed;
	public:
		KeyboardController ();
		~KeyboardController ();
		void pressKey (const int key);
		void releaseKey (const int key);
		bool keyPressed (const int key);
		void printKeys ();
};

#endif
