#pragma once
#include <SDL.h>
#include "Path.h"
#define PI 3.14159265

class Path;
class Enemy
{
public:
	Enemy(int hp,int spd,int bount,const char* image,int he,int wid);
	Enemy();
	~Enemy();


	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer, SDL_Texture* img);
	void update();

	void loseHealth(int dmg);
	const char* getImgName();
	void Death();
	bool destinationReached();
	void updatingReach();
	void setup(Path* way);
	int getXPos();
	int getYPos();
	void dealDamage();
private:
	Path* myWay;
	int health;
	int xPos;
	int yPos;
	int speed;
	const char* imgName;
	bool isDead;
	int toX;
	int toY;
	double angle;
	int indexReach;
	int height;
	int width;
	int bounty;
};

