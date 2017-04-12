#include "../include/Debugger.h"

Debugger::Debugger (const char *name, int *value, const int min, const int max) {
	this->name = GraphicsEngine::instance ()->loadText (0, name, 0, 0, 0);
	this->value = value;
	for (int i = min; i <= max; i++) {
		values.push_back (i);
		char buffer [50];
		sprintf (buffer, "%d", i);
		valueTextures.push_back (GraphicsEngine::instance ()->loadText (0, buffer, 0, 0, 0));
	}
}

int Debugger::getName () {
	return name;
}

int Debugger::getValue () {
	int index = 0;

	for (int i = 0; i < values.size (); i++) {
		if (values [i] == *value) {
			index = i;
		}
	}

	return valueTextures [index];
}
