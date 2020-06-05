#pragma once
#include "Level.h"
#include <SDL.h>
using std::cout;

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	bool handleAllInput(Level* level);

private:
	bool ctrl;
};

