#pragma once

#include "Enemy.h"
#include "projectileData.h"
#include <SDL.h>

class Enemy;
class Level;
struct projectileData;
 /*projectileData basicArcherProj = {
   4, //atkMin
   7, //atkMax
   10, //height
   10, //width
   4, //speed
   "basicArcherProjectile.png",	// imgName
   false //explo
};
 /*
  projectileData basicMageProj = {
	10, //atkMin
	15, //atkMax
	10, //height
	10, //width
	3, //speed
	"basicMageProjectile.png",	// imgName
	false //explo
};


  projectileData basicBombProj = {
	10, //atkMin
	13, //atkMax
	10, //height
	10, //width
	3, //speed
	"basicBombProjectile.png",	// imgName
	true //explo
};

  projectileData basicPoisonProj = {
	5, //atkMin
	10, //atkMax
	10, //height
	10, //width
	3, //speed
	"basicPoisonProjectile.png",	// imgName
	false //explo
};

*/
class Projectile
{
public:
	Projectile();
	Projectile(int x,int y,projectileData data);
	Projectile(int x,int y,int hei,int wid,int min,int max,int s,const char* img,bool explo,double ang);
	~Projectile();
	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer, RessourceManager* resMan);
	void update();
	void destroy();
	void setTarget(Enemy* enemy);
	void setLevel(Level* level);
private:
	const char* imgName;
	bool explosive;
	int atkMin;
	int atkMax;
	int speed;
//	bool canTarget;
	int xPos;
	int yPos;
	int height;
	int width;
	Enemy* target;
	double angle;
	Level* myLevel;
};

