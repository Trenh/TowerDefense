#pragma once
#include <SDL.h>

#include "Point.h"
#include "Tower.h"
#include "Level.h"
#include "RessourceManager.h"
#include <iostream>
using std::cout;

class Level;
class Tower;

class Plot
{
public:
	Plot(int x,int y,bool tow,const char* img,int he,int wi);
	Plot(int x,int y,const char* img);
	Plot();
	~Plot();

	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer, RessourceManager* resMan);
	void update();
	const char* getImgName();
	void constructTower(int selectTower);
	Point getPos();
	bool isInRange(Point p);
	bool getHasTower();
	void setHasTower(bool tower);
	Level* getLevel();
	void setLevel(Level* level);
	int getTowerCost(int selectIndex, int upgradeLevel);

private:
	int xPos;
	int yPos;
	bool hasTower;
	const char* imgName;

	int height;
	int width;
	Tower* myTower;
	Level* myLevel;
};

