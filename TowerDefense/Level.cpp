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

std::vector<Point*> Level::getAllPlotsPoint() {
	std::vector<Point*> pointsList;
	for (int i = 0; i < plotsList.size();i++) {
		Point tempPoint = Point(plotsList.at(i)->getPos());
		pointsList.push_back(&tempPoint);
	}
	return pointsList;
}

Plot* Level::getPlotAtPosition(Point p) {
	for (int i = 0; i < plotsList.size(); i++) {
		if (plotsList.at(i)->isInRange(p)) {
			return plotsList.at(i);
		}
		
	}
	return NULL;
}

void Level::pushPlot(Plot* p) {
	plotsList.push_back(p);
	p->setLevel(this);
}

Enemy* Level::checkEnemyInRange(int x, int y, int radius) {
	if (getActualWave() == NULL) {
		return NULL;
	}
	return getActualWave()->checkEnemyInRange(x, y, radius);
	
}

Wave* Level::getActualWave() {
	for (auto &wave : wavesList) {
		if (wave->getIndex() == indexWave) {
			return wave;
		}

	}
	return NULL;
}

void Level::pushBackWave(Wave* wave) {
	wavesList.push_back(wave);
	wave->setLevelPointer(this);
}

Player* Level::getPlayer() {
	return player;
}

void Level::setPlayer(Player* play) {
	player = play;
}

void Level::pushBackProjectile(Projectile* proj) {
	projectileList.push_back(proj);
}

void Level::deleteProjectile(Projectile* proj) {
	for (int i = 0; i < projectileList.size(); i++) {
		if (projectileList.at(i) == proj) {
			projectileList.erase(projectileList.begin() + i);
			return;

		}
	}
}

void Level::startLevel() {
	getActualWave()->start();
}

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