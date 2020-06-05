#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <vector>
#include <array>
#include <iostream>
#include <time.h> 

#include "Wave.h"
class Wave;
class Enemy;

#include "Plot.h"
class Plot;

#include "Player.h"
class Player;

#include "Point.h"
#include "Projectile.h"
class Projectile;


#include "RessourceManager.h"
class Level
{
public:
	Level();
	Level(int index);
	~Level();
	
	
	void update();
	void draw(SDL_Renderer* renderer,RessourceManager* resMan);
	std::vector<Point*> getAllPlotsPoint();
	Plot* getPlotAtPosition(Point p);
	void pushPlot(Plot* p);
	Enemy* checkEnemyInRange(int x,int y,int radius);
	Wave* getActualWave();
	void pushBackWave(Wave* wave);
	Player* getPlayer();
	void setPlayer(Player* play);
	void pushBackProjectile(Projectile* project);
	void deleteProjectile(Projectile* project);
	void startLevel();
	void upgradeWave();
	void endLevel();

private:
	std::vector<Wave*> wavesList;
	std::vector<Plot*> plotsList;
	std::vector<Projectile*> projectileList;
	int indexWave;
	Player* player;
};

