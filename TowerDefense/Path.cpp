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


void Path::start() {
	activate = true;
	myTime = clock();
}




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

void Path::stop() {
	activate = false;
}

void Path::addEnemyToWave() {
	Path* test = this;
	int index = myWavePointer->findPathId(this);
	myWavePointer->pushBackEnemy(index);
}

int Path::waypointSize() {
	int size = static_cast<int>(way.size());
	return size;
}

Point Path::findWayPoint(int index) {
	
	return(way.at(index));
}


bool Path::noMoreToSpawn() {
	return indexEnemy == enemyToSpawn;
}

void Path::setupWay(std::vector<Point> theWay) {
	way = theWay;
}
void Path::setupWave(Wave* wave) {
	myWavePointer = wave;
}

Wave* Path::getWavePointer() {
	return myWavePointer;
}