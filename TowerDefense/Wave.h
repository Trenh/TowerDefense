#pragma once
#include <vector>
#include <list>

#include "RessourceManager.h"
#include "Enemy.h"
#include "Path.h"
#include "Level.h"
class Enemy;
class Level;
class Path;

class Wave
{
public:
	Wave(int i);
	Wave();
	~Wave();
	void start();
	void update();
	void stop();
	void draw(SDL_Renderer* renderer,RessourceManager* resMan);
	void checkAllPathFinished();
	void pushBackEnemy(int pathId);
//	void pushBackEnemy(Enemy* enemy);
	void setupPaths(std::vector<Path*> paths);
	int findPathId(Path* path);
	void deleteEnemy(Enemy* enemy);
	int getIndex();
	Enemy* checkEnemyInRange(int x,int y,int radius);
	Level* getLevelPointer();
	void setLevelPointer(Level* lev);
private:
	std::vector<Path*> pathList;
//	std::vector<Enemy*> enemysAlive;
	std::list<Enemy> enemysAlive;
	int id;
	bool allPathDead;
	Level* level;
	std::list<Enemy>::iterator iteratorListUpdate;

};

