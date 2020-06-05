#include "Wave.h"
#include <iostream>

using std::cout;

Wave::Wave()
{
}

Wave::Wave(int i)
	:id(i), allPathDead(false)
{
}


Wave::~Wave()
{
}


//start all of the path
void Wave::start() {
	for (auto &path : pathList) {
		path->start();
	}
}

//draw  each enemy
void Wave::draw(SDL_Renderer* renderer,RessourceManager* resMan) {
	for (auto &enemy : enemysAlive) {
//		enemy->draw(renderer,resMan->getTextureByString(enemy->getImgName()));
		enemy.draw(renderer,resMan->getTextureByString(enemy.getImgName()));
	}
}

void Wave::stop() {
	
}

//if allPath Dead upgrade wave ekse update paths and enemies 
void Wave::update() {
	if (allPathDead) {
		level->upgradeWave();
		return;
	}
	if (!enemysAlive.size()) {
		checkAllPathFinished();
		if (allPathDead) {
			stop();
			return;
		}
	}
	
	for (auto  &path : pathList) {
		path->update();
	}

	//for (auto &enemy : enemysAlive) {
	//	enemy.update();
	//}

	for (iteratorListUpdate = enemysAlive.begin(); iteratorListUpdate != enemysAlive.end(); ++iteratorListUpdate) {
		
		iteratorListUpdate->update();
		if (enemysAlive.empty()) {
			return;
		}
	}
}

//modify allPathDead if all path have finished 
void Wave::checkAllPathFinished() {
	for (auto &path : pathList) {
		if (!path->noMoreToSpawn()) {
			allPathDead = false;
			return ;
		}
	}
	allPathDead = true;
}


//creation of enemies
void Wave::pushBackEnemy(int pathId) {
	Enemy* temp = new Enemy(5, 1,5, "monster_retry.png", 25, 25);
	temp->setup(pathList.at(pathId));

	enemysAlive.push_back(*temp);
}


//set up path pointer
void Wave::setupPaths(std::vector<Path*> paths) {
	pathList = paths;
}

//find the int correspondant to the path
int Wave::findPathId(Path* path) {
	std::vector<Path*>::iterator itr = std::find(pathList.begin(), pathList.end(), path);
	return (int)std::distance(pathList.begin(), itr);
}

//erase enemy
void Wave::deleteEnemy(Enemy* enemy) {
	std::list<Enemy>::iterator it1;
	for (it1 = enemysAlive.begin(); it1 != enemysAlive.end(); ++it1) {
		if (&(*it1) == enemy) {
			enemysAlive.erase(it1);
			iteratorListUpdate = enemysAlive.begin();

			return;
		}
	}

	/*
	back when it was a vector
	for (int i = 0; i < enemysAlive.size(); i++) {
		if (&enemysAlive.at(i) == enemy) {
			enemysAlive.erase(enemysAlive.begin()+i);
			return;

		}
	}
	*/

	//	std::vector<Enemy>::iterator itr = std::find(enemysAlive.begin(), enemysAlive.end(), enemy);
//	enemysAlive.erase(itr);
//	delete &enemy;
}

//return index
int Wave::getIndex() {
	return id;
}

//return a pointer to the first enemy in range
Enemy* Wave::checkEnemyInRange(int x, int y, int radius) {
	for (auto &enemy : enemysAlive) {
		if ((enemy.getXPos() - x)*(enemy.getXPos() - x)
			+ (enemy.getYPos() - y)*(enemy.getYPos() - y) <= radius * radius) {
			return &enemy;
		}
	
	}
	return NULL;
}

// return level pointer
Level* Wave::getLevelPointer() {
	return level;
}

//set level pointer
void Wave::setLevelPointer(Level* lev) {
	level = lev;
}