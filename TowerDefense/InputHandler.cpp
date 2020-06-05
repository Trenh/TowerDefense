
#include "InputHandler.h"



InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

bool InputHandler::handleAllInput(Level* level) {

	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_RIGHT) {
				cout << "right button";

				//get mouse position
				int xMpos, yMpos;
				SDL_GetMouseState(&xMpos, &yMpos);
				Point p = { xMpos,yMpos };
				p;
				p.xPos = xMpos;
				p.yPos = yMpos;
				//clikeck plot exist and it does'nt have a tower 
				Plot* clickedPlot =level->getPlotAtPosition(p) ;
				if (clickedPlot != NULL) {
					if (!clickedPlot->getHasTower()) {
						clickedPlot->constructTower(level->getPlayer()->getIndex());
					}
				}
			}
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_1) {
				level->getPlayer()->setIndex(0);
			}
			else if (event.key.keysym.sym == SDLK_2) {
				level->getPlayer()->setIndex(1);

			}
			else if (event.key.keysym.sym == SDLK_3) {
				level->getPlayer()->setIndex(2);

			}
			else if (event.key.keysym.sym == SDLK_4) {
				level->getPlayer()->setIndex(3);

			}

			break;
		case SDL_QUIT:
			return true;

		}
		return false;

	}
	return false;
}