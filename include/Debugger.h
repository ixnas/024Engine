#ifndef DEBUGGER_H
#define DEBUGGER_H

#include "../include/GraphicsEngine.h"
#include <vector>

class Debugger {
	private:
		int name;
		int *value;
		std::vector <int> values;
		std::vector <int> valueTextures;
	public:
		Debugger (const char *name, int *value, const int min, const int max);
		int getName ();
		int getValue ();
};

#endif