#include "Tower.h"



Tower::Tower()
{
}
Tower::Tower(int x, int y, int hei, int wid, int cos, int range, int speed, int upLev, const char* name,int ty)
	:xPos(x),yPos(y),height(hei),width(wid),cost(cos),atkRange(range),atkSpeed(speed),upgradeLevel(upLev),imgName(name),activate(true),type(ty)
{
}

Tower::Tower(int x, int y, int cos, int upLev,int ty)
	:xPos(x),yPos(y),cost(cos),upgradeLevel(upLev),activate(true),type(ty)
{
	//switch on type to know which tower to spawn
	switch (type) {
	case 0:
		
	
		height = 40;
		width = 40;
		atkRange = 300;
		atkSpeed = 1000;
		imgName = "basicTowerArcher.png";
				
		break;
	case 1:
		height = 40;
		width = 40;
		atkRange = 240;
		atkSpeed = 1250;
		imgName = "basicTowerMage.png";

		break;
	case 2:
		height = 40;
		width = 40;
		atkRange = 200;
		atkSpeed = 1750;
		imgName = "basicTowerBomb.png";

		break;
	case 3:
		height = 40;
		width = 40;
		atkRange = 350;
		atkSpeed = 2000;
		imgName = "basicTowerPoison.png";

		break;
	}
}

Tower::~Tower()
{
}


SDL_Rect Tower::toRect()
{

	SDL_Rect rect = { xPos,yPos,width ,height };
	return rect;
}

void Tower::draw(SDL_Renderer* renderer, RessourceManager* resMan) {
	//draw himself
	//get the size
	SDL_Rect rect = toRect();
	//render the image
	SDL_RenderCopyEx(renderer, resMan->getTextureByString(imgName), NULL, &rect, 0, NULL, SDL_FLIP_NONE);

}

void Tower::update() {
	if (activate) {
		//if ennemy in range
		Enemy* target= myPlot->getLevel()->checkEnemyInRange(xPos,yPos,atkRange);
		//try fire
		if (target != NULL) {
			if (!lastFire) {
				lastFire = clock();

				fire(target);

			}
			else if ( atkSpeed+ lastFire  < clock()) {
				lastFire = clock();

				fire(target);

			}
		}
	}
}

void Tower::fire(Enemy* target) {
	//spawn projectile 
	//setup target of projectile
	Projectile* project;
	project = new Projectile(xPos + width / 2, yPos + height / 2, basicArcherProj);
	
	//swirch to launch correspondant projectile
	switch (type) {
	case 0:
		project = new Projectile(xPos + width / 2,yPos + height / 2, basicArcherProj);
		break;
	case 1:
		project = new Projectile(xPos + width / 2, yPos + height / 2, basicMageProj);
		break;
	case 2:
		project = new Projectile(xPos + width / 2, yPos + height / 2, basicBombProj);
		break;
	case 3:
		project = new Projectile(xPos + width / 2, yPos + height / 2, basicPoisonProj);
		break;

	}
	//setup ptojectile
	project->setLevel(myPlot->getLevel());
	project->setTarget(target);
	myPlot->getLevel()->pushBackProjectile(project);

}

void Tower::setPlot(Plot* plot) {
	myPlot = plot;
}