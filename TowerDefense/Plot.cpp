#include "Plot.h"



Plot::Plot()
{
}
Plot::Plot(int x,int y,bool tow, const char* img, int he, int wi)
	:xPos(x),yPos(y),hasTower(tow),imgName(img),height(he),width(wi)
{

}
Plot::Plot(int x, int y, const char* img) 
	: xPos(x), yPos(y), hasTower(false), imgName(img), height(40), width(40)
{

}
Plot::~Plot()
{
}

/// SDL RECT
SDL_Rect Plot::toRect()
{

	SDL_Rect rect = { xPos,yPos,width ,height };
	return rect;
}

//draw
void Plot::draw(SDL_Renderer* renderer, RessourceManager* resMan) {
	
	//draw himself
	//get the size
	SDL_Rect rect = toRect();
	//render the image
	SDL_RenderCopyEx(renderer, resMan->getTextureByString(imgName), NULL, &rect, 0, NULL, SDL_FLIP_NONE);
	//draw my tower
	//DoingLater
	if (hasTower) {
		myTower->draw(renderer, resMan);
	}
}

//update my tower if i got one
void Plot::update() {
	if (hasTower) {
		myTower->update();

	}
}

// construct a tower
void Plot::constructTower(int selectIndex) {
//	cout << "construction of tower ";
	if (myLevel->getPlayer()->getGold() > getTowerCost(selectIndex,0)) {
		myLevel->getPlayer()->setGold(myLevel->getPlayer()->getGold() - getTowerCost(selectIndex, 0));
		hasTower = true;
		myTower = new Tower(xPos, yPos, getTowerCost(selectIndex, 0), 0, selectIndex);
		myTower->setPlot(this);
	}

}

//return image name 
const char* Plot::getImgName() {
	return imgName;
}

// return position
Point Plot::getPos() {
	Point temp = { xPos, yPos };
	return temp;
}

//return bollean if it's in range
bool Plot::isInRange(Point p) {
	

	return (xPos <= p.xPos &&
		p.xPos <= xPos + width &&
		yPos <= p.yPos &&
		p.yPos <= yPos + height);
}

//return if it has  tower
bool Plot::getHasTower() {
	return hasTower;
}

// set bool hasTower
void Plot::setHasTower(bool tower) {
	hasTower= tower;
}

//return mylevel pointer
Level* Plot::getLevel() {
	return myLevel;
}

//set level pointer
void Plot::setLevel(Level* level) {
	myLevel = level;
}

// get tower cost
int Plot::getTowerCost(int selectIndex, int upgradelevel) {
	switch (selectIndex)
	{
	case 0:
		if (upgradelevel == 0) {
			return 70;
		}
		if (upgradelevel == 1) {
			return 100;
		}
		if (upgradelevel == 2) {
			return 120;
		}
		if (upgradelevel == 3) {
			return 150;
		}
		break;

	case 1:
		if (upgradelevel == 0) {
			return 90;
		}
		if (upgradelevel == 1) {
			return 130;
		}
		if (upgradelevel == 2) {
			return 150;
		}
		if (upgradelevel == 3) {
			return 200;
		}
		break;

	case 2:
		if (upgradelevel == 0) {
			return 50;
		}
		if (upgradelevel == 1) {
			return 120;
		}
		if (upgradelevel == 2) {
			return 150;
		}
		if (upgradelevel == 3) {
			return 180;
		}
		break;
	case 3:
		if (upgradelevel == 0) {
			return 70;
		}
		if (upgradelevel == 1) {
			return 100;
		}
		if (upgradelevel == 2) {
			return 120;
		}
		if (upgradelevel == 3) {
			return 150;
		}
		break;
	default:
		break;
	}
	return 0;
}