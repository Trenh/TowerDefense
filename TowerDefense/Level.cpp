#include "Level.h"



Level::Level()
	:indexWave(1)
{
}

Level::Level(int index)
	: indexWave(index)
{
}
Level::~Level()
{
}

//update of the tower
//update all of his component and the actual wave
void Level::update() {
	Wave* actualWave = getActualWave();
	if (actualWave != NULL) {

		actualWave->update();
	}

	for (auto &plot : plotsList) {
		plot->update();
	}
	for (auto &project : projectileList) {
		project->update();
	}
}



//draw of the tower
//draw all of his component and the actual wave
void Level::draw(SDL_Renderer* renderer,RessourceManager* resMan) {
	Wave* actualWave = getActualWave();
	if (actualWave != NULL) {

		actualWave->draw(renderer,resMan);
	}
	
	for (auto &plot : plotsList) {
		plot->draw(renderer, resMan);
	}
	
	for (auto &project : projectileList) {
		project->draw(renderer, resMan);
	}
	player->draw(renderer,resMan,indexWave);
}

//return a vector of points of the plot Points
std::vector<Point*> Level::getAllPlotsPoint() {
	std::vector<Point*> pointsList;
	for (int i = 0; i < plotsList.size();i++) {
		Point tempPoint = Point(plotsList.at(i)->getPos());
		pointsList.push_back(&tempPoint);
	}
	return pointsList;
}


//return a plot pointer of a plot which is at a position passed   
Plot* Level::getPlotAtPosition(Point p) {
	for (int i = 0; i < plotsList.size(); i++) {
		if (plotsList.at(i)->isInRange(p)) {
			return plotsList.at(i);
		}
		
	}
	return NULL;
}

//push back a plot pointer at the end of our vector
void Level::pushPlot(Plot* p) {
	plotsList.push_back(p);
	p->setLevel(this);
}


//return a pointer to an ennemy if it's in range
Enemy* Level::checkEnemyInRange(int x, int y, int radius) {
	if (getActualWave() == NULL) {
		return NULL;
	}
	return getActualWave()->checkEnemyInRange(x, y, radius);
	
}


//return the actual wave
Wave* Level::getActualWave() {
	for (auto &wave : wavesList) {
		if (wave->getIndex() == indexWave) {
			return wave;
		}

	}
	return NULL;
}

//push back a wave pointer at the end of our vector
void Level::pushBackWave(Wave* wave) {
	wavesList.push_back(wave);
	wave->setLevelPointer(this);
}


//return the player pointer
Player* Level::getPlayer() {
	return player;
}


//set the player pointer
void Level::setPlayer(Player* play) {
	player = play;
}


//oush back a projectile pointer at the end of our pointer
void Level::pushBackProjectile(Projectile* proj) {
	projectileList.push_back(proj);
}

//erase a projectile of our list
void Level::deleteProjectile(Projectile* proj) {
	for (int i = 0; i < projectileList.size(); i++) {
		if (projectileList.at(i) == proj) {
			projectileList.erase(projectileList.begin() + i);
			return;

		}
	}
}

//start  the level
void Level::startLevel() {
	getActualWave()->start();
}

//upgrade the wave index and start this wave
void Level::upgradeWave() {
	indexWave++;
//	player->updateWaveText();
	if (indexWave < wavesList.size()) {
		getActualWave()->start();
	}
	else {
		endLevel();
	}

}

void Level::endLevel() {
	

}