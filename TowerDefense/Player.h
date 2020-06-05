#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "RessourceManager.h"
#include "Text.h"

/*
#include <iostream>

#include <unordered_map>
typedef void(*ScriptFunction)(void);
typedef std::unordered_map<std::string, ScriptFunction> script_map;
*/
class Player
{
public:
	Player();
	Player(int g,int h);
	~Player();
	void draw(SDL_Renderer* renderer, RessourceManager* resMan,int wave);
	void load(SDL_Renderer* renderer);
	void setGold(int newgold);
	void setHealth(int newhealth);
	int getHealth();
	int getGold();
	void addGold(int bounty);
	void loseHealth(int damage);
	void setIndex(int index);
//	void updateWaveText();
	int getIndex();
private:
	int gold;
	int health;
	int indexSelected;
	Text healthDisplay = Text(1900 - 150, 1000 -200, 150, 50);
	Text waveDisplay = Text(1900 - 150, 1000 - 250, 150, 50);
	Text goldDisplay = Text(1900 - 150, 1000 - 150, 150, 50);
//	void updateGoldText();
//	void updateHealthText();

//	std::unordered_map<int, ScriptFunction> towerMap;
};

