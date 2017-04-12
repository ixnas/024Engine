//
// Created by Sjoerd Scheffer on 06-04-17.
//

#ifndef CLION_SDL_INPUTCONTROLLER_H
#define CLION_SDL_INPUTCONTROLLER_H


class InputController {
	public:
		virtual ~InputController () {}
		virtual void pressKey (const int key) = 0;
		virtual void releaseKey (const int key) = 0;
		virtual bool keyPressed (const int key) = 0;
		virtual void printKeys () = 0;
};


#endif //CLION_SDL_INPUTCONTROLLER_H
