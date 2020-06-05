#include "Projectile.h"

Projectile::Projectile()

:xPos(0), yPos(0), height(10), width(10), atkMin(3), atkMax(6), speed(3), imgName("basic_projectile.png"), explosive(false), angle(0)
{
}

Projectile::Projectile(int x,int y , projectileData data)

:xPos(x), yPos(y), height(data.height), width(data.width), atkMin(data.atkMin), atkMax(data.atkMax), speed(data.speed), imgName(data.imgName), explosive(data.explo), angle(0)
{
	
}

Projectile::Projectile(int x, int y, int hei, int wid, int min, int max, int s, const char* img, bool explo, double ang)
	:xPos(x),yPos(y),height(hei),width(wid),atkMin(min),atkMax(max),speed(s),imgName(img),explosive(explo),angle(ang)
{
}

Projectile::~Projectile()
{
}


SDL_Rect Projectile::toRect()
{

	SDL_Rect rect = { xPos-width/2,yPos-height/2,width ,height };
	return rect;
}


void Projectile::draw(SDL_Renderer* renderer, RessourceManager* resMan) {
	//draw himself
	//get the size
	SDL_Rect rect = toRect();
	//render the image
	SDL_RenderCopyEx(renderer, resMan->getTextureByString(imgName), NULL, &rect, angle, NULL, SDL_FLIP_NONE);

}

void Projectile::update() {

	if (target == NULL) {
		destroy();
		return;
	}
	int toX = target->getXPos();
	int toY = target->getYPos();
	
	angle = atan2(toY - yPos, toX - xPos);
	double dx = (double)(cos(angle)*speed);
	double dy = (double)(sin(angle)*speed);
	if (abs(toX - xPos) < speed) {
		xPos = int(ceil(toX));
	}
	else {
		xPos += int(ceil(dx));
	}
	if (abs(toY - yPos) < speed) {
		yPos = int(ceil(toY));
	}
	else {
		yPos += int(ceil(dy));
	}
	if (abs(toX - xPos) < speed && abs(toY - yPos) < speed) {
		int damage = rand()%(atkMax - atkMin+1) + atkMin;
		target->loseHealth(damage);
		destroy();
	}
	
}

void Projectile::destroy() {
	myLevel->deleteProjectile(this);
}

void Projectile::setTarget(Enemy* enemy) {
	target = enemy;
}

void Projectile::setLevel(Level* level) {
	myLevel = level;
}