#include "Player.h"



Player::Player()
{
}

Player::Player(int g, int h)
	:gold(g),health(h)
{
}


Player::~Player()
{
}


void Player::setGold(int newgold) {
	gold = newgold;
};
void Player::setHealth(int newhealth) {
	health = newhealth;
}

int Player::getHealth() {
	return health;
}

int Player::getGold() {
	return gold;
}

void Player::addGold(int bounty) {
	gold += bounty;
//	updateGoldText();
};

void Player::loseHealth(int damage) {
	health -= damage;
	if (health <= 0) {

	}
//	updateHealthText();
};


int Player::getIndex() {
	return indexSelected;
}

void Player::setIndex(int index) {
	indexSelected = index;

}

void Player::load(SDL_Renderer* renderer) {
	healthDisplay.load(renderer, "");
	waveDisplay.load(renderer, "");
	goldDisplay.load(renderer, "");
}

void Player::draw(SDL_Renderer* renderer, RessourceManager* resMan,int wave) {
	//change the text of the interface
	char goldString[32];
	char goldStringComplete[64]="Gold :";
	char healthString[32];
	char healthStringComplete[64]= "Health :";
	char waveString[32];
	char waveStringComplete[64]= "Wave :";
	sprintf_s(goldString, "%d", gold);
	sprintf_s(healthString, "%d", health);
	sprintf_s(waveString, "%d",wave );
	strcat_s(goldStringComplete, goldString);
	strcat_s(healthStringComplete, healthString);
	strcat_s(waveStringComplete, waveString);
	goldDisplay.changeText(renderer,goldStringComplete);
	healthDisplay.changeText(renderer,healthStringComplete);
	waveDisplay.changeText(renderer,waveStringComplete);
	
	///draw tower interface
	SDL_Rect rect = { 1850,950,50 ,50 };
	SDL_RenderCopyEx(renderer, resMan->getTextureByString("basicTowerPoison.png"), NULL, &rect, 0, NULL, SDL_FLIP_NONE);
	rect = { 1800,950,50 ,50 };
	SDL_RenderCopyEx(renderer, resMan->getTextureByString("basicTowerBomb.png"), NULL, &rect, 0, NULL, SDL_FLIP_NONE);

	rect = { 1750,950,50 ,50 };
	SDL_RenderCopyEx(renderer, resMan->getTextureByString("basicTowerMage.png"), NULL, &rect, 0, NULL, SDL_FLIP_NONE);

	rect = { 1700,950,50 ,50 };
	SDL_RenderCopyEx(renderer, resMan->getTextureByString("basicTowerArcher.png"), NULL, &rect, 0, NULL, SDL_FLIP_NONE);


	SDL_RenderDrawLine(renderer, 1700+(50*indexSelected), 950, 1750 + (50 * indexSelected), 950);
	SDL_RenderDrawLine(renderer, 1700 + (50 * indexSelected), 950, 1700 + (50 * indexSelected), 1000);
	SDL_RenderDrawLine(renderer, 1750 + (50 * indexSelected), 950, 1750 + (50 * indexSelected), 1000);
	SDL_RenderDrawLine(renderer, 1700 + (50 * indexSelected), 1000, 1750 + (50 * indexSelected), 1000);
	healthDisplay.draw(renderer);
	waveDisplay.draw(renderer);
	goldDisplay.draw(renderer);
}