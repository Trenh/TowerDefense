#pragma once
#include <vector>

#include "Enemy.h"
#include "Wave.h"
#include "Point.h"
#include <time.h>


class Enemy;
class Wave;
class Path
{
public:
	Path(int delStart, int delBetween, int nbEnemy);
	Path();
	~Path();
	void start();
	void stop();
	void update();
	void addEnemyToWave();
//	void addEnemyToWave(Enemy* enemy);
	Point findWayPoint(int index);
	bool isFinished;
	int waypointSize();
	bool noMoreToSpawn();
	void setupWay(std::vector<Point> theWay);
	void setupWave(Wave* wave);
	Wave* getWavePointer();

private:
	int delayStart;
	int delayBetween;
	std::vector<Point> way;
	Wave* myWavePointer;
	bool activate;
	clock_t myTime;
	int indexEnemy;
	int enemyToSpawn;
};

