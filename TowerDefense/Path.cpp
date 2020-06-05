#include "Path.h"



Path::Path()
{
}

Path::Path(int delStart,int delBetween,int nbEnemy)
	:delayStart(delStart),delayBetween(delBetween),enemyToSpawn(nbEnemy),indexEnemy(0),activate(false)
{
}
Path::~Path()
{
}

// start of the path
void Path::start() {
	activate = true;
	myTime = clock();
}



//update : if it's time to spawn  an ennemy spawn an ennemy
void Path::update() {
	if (activate) {
		if ((!delayStart) || myTime + delayStart > clock()) {
			if (delayBetween + myTime > clock()) {

			}
			else {
				myTime = clock();
				//					Enemy temp = Enemy(5, 1, "monster.png", 25, 25);
				indexEnemy++;
				addEnemyToWave();
				if (indexEnemy == enemyToSpawn) {
					stop();
				}
			}
		}
		else {
			if (delayStart) {
				delayStart = 0;
				myTime = clock();
				//Enemy temp = Enemy(5, 1, "monster.png", 25, 25);
				indexEnemy++;
				addEnemyToWave();
			}
			
		}
	}
}

//stop the activation of the path
void Path::stop() {
	activate = false;
}

//push back to the wave an enemy
void Path::addEnemyToWave() {
	Path* test = this;
	int index = myWavePointer->findPathId(this);
	myWavePointer->pushBackEnemy(index);
}

//return the size of the path length
int Path::waypointSize() {
	int size = static_cast<int>(way.size());
	return size;
}

//find the point at the correspondant index
Point Path::findWayPoint(int index) {
	
	return(way.at(index));
}

//return if it have to spawn more enemy
bool Path::noMoreToSpawn() {
	return indexEnemy == enemyToSpawn;
}

// set up way of point
void Path::setupWay(std::vector<Point> theWay) {
	way = theWay;
}

//setup wave pointer
void Path::setupWave(Wave* wave) {
	myWavePointer = wave;
}

//return wave pointer
Wave* Path::getWavePointer() {
	return myWavePointer;
}