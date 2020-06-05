#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

Enemy::Enemy(int hp, int spd,int bount, const char* image, int he, int wid)
	:health(hp),speed(spd),bounty(bount),imgName(image),height(he),width(wid),isDead(false)
{
	
}

void Enemy::setup(Path* way) {
	//setup the myWay pointer,and set the next position
	myWay = way;
	indexReach = 1;
	Point start = myWay->findWayPoint(0);
	xPos = start.xPos;
	yPos = start.yPos;
	Point nextStop = myWay->findWayPoint(indexReach);
	toX = nextStop.xPos;
	toY = nextStop.yPos;

}

void Enemy::update() {
	//if the next point isn't reach go to this way
	if (xPos != toX || yPos != toY) {
		angle = atan2(toY - yPos, toX - xPos);
		double dx = (double)(cos(angle)*speed);
		double dy = (double)(sin(angle)*speed);

		if (abs(toX - xPos) < speed) {
			xPos = int(ceil(toX));
		}
		else{
			xPos += int(ceil(dx));
		}
		if (abs(toY - yPos) < speed) {
			yPos = int(ceil(toY));
		}
		else {
			yPos += int(ceil(dy));
		}
	}
	//if the enemy have reach his destination destroy him and make the player lose health
	else if (destinationReached()) {
		dealDamage();
		myWay->getWavePointer()->deleteEnemy(this); 
	}
	//update the next way point
	else {
		updatingReach();
	}
}

void Enemy::draw(SDL_Renderer* renderer,SDL_Texture* img) {
	//get the size
	SDL_Rect rect = toRect();
	//render the image
	SDL_RenderCopyEx(renderer, img, NULL, &rect, (angle*180/PI), NULL, SDL_FLIP_NONE);
}

//update index and find the next point
void Enemy::updatingReach() {
	indexReach++;
	Point goTo = myWay->findWayPoint(indexReach);
	toX = goTo.xPos;
	toY = goTo.yPos;
}

//check if thewaypoint is the last
bool Enemy::destinationReached() {
	myWay->waypointSize();
	return indexReach == myWay->waypointSize()-1;
}

//made a sdl_rect 
SDL_Rect Enemy::toRect()
{

	SDL_Rect rect = { xPos,yPos,width ,height };
	return rect;
}

//get the image name
const char* Enemy::getImgName() {
	return imgName;
}

//get x position
int Enemy::getXPos() {
	return xPos;
}

//get y position
int Enemy::getYPos() {
	return yPos;
}

//lose health if <0 died
void Enemy::loseHealth(int damage) {
	if (health - damage<=0) {
		Death();
	}
	health = health - damage;
}

//deald damage to player
void Enemy::dealDamage() {
	myWay->getWavePointer()->getLevelPointer()->getPlayer()->loseHealth(1);
}

//add gold equivalent to bounty and then tell the wave to erase the enemy
void Enemy::Death() {
	myWay->getWavePointer()->getLevelPointer()->getPlayer()->addGold(bounty);
	myWay->getWavePointer()->deleteEnemy(this);
}