#pragma once

#include "RessourceManager.h"
#include "Plot.h"
#include "Enemy.h"
#include "Projectile.h"
#include "projectileData.h"
#include <SDL.h>
#include <time.h>

class Plot;
class Enemy;
class Projectile;


class Tower
{
public:
	Tower();
	Tower(int x,int y, int hei, int wid,int cos,int range,int speed,int upLev,const char* name,int ty);
	Tower(int x,int y,int cos,int upLev,int ty);
	~Tower();
	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer, RessourceManager* resMan);
	void update();
	void fire(Enemy* target);

	void setPlot(Plot* plot);
private:
	const char* imgName;
	int atkRange;
	int atkSpeed;
	int xPos;
	int yPos;
	int height;
	int width;
	int cost;
	int upgradeLevel;
	clock_t lastFire;
	bool activate;
	Plot* myPlot;
	int type;
	// powers later

};

