#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <cstdio>
#include <vector>
#include <array>
#include <iostream>

#include "SoundEffect.h"
#include "Text.h"
#include "RessourceManager.h"
#include "Level.h"
#include "Wave.h"
#include "Path.h"
#include "Enemy.h"
#include "InputHandler.h"
using std::cout;
using std::endl;

//Definitions
const int SCREEN_WIDTH = 1900;
const int SCREEN_HEIGHT = 1000;
bool quit = false;



//fonctions
void load(SDL_Renderer*);
bool handleInput();
void update(SDL_Renderer*);
void draw(SDL_Renderer*);
void close(SDL_Window*, SDL_Renderer*);

InputHandler inputHandler = InputHandler();

Player player= Player(500,5);
Level level1;

Plot plot1=Plot(200,0,"Plot.png");
Plot plot2=Plot(0,100,"Plot.png");
Plot plot3=Plot(300,200,"Plot.png");
Plot plot4=Plot(00,300,"Plot.png");
Plot plot5=Plot(00,400,"Plot.png");
Point p1, p2, p3, p4;

Wave wave1 = Wave(1);
Path path1 = Path(5000, 1000, 5);
//Path path2 = Path(5, 5, 5);

RessourceManager ressManager = RessourceManager();

std::string s1[] = { "monster.png","monster_retry.png","Plot.png",
"basicTowerArcher.png","basicTowerMage.png","basicTowerBomb.png","basicTowerPoison.png",
"basicArcherProjectile.png","basicMageProjectile.png","basicBombProjectile.png","basicPoisonProjectile.png" };
std::vector<std::string > imageToLoad;

int main(int argc, char* args[]) {


	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	// setup vector of image
	for (auto string : s1) {
		imageToLoad.push_back(string);
	}
	srand(static_cast <unsigned int> (time(0)));


	//Init Window
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	window = SDL_CreateWindow("TowerDefense", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();
	Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	p1 = { 0,0 };
	p2 = { 200,200 };
	p3 = { 300,350 };
	p4 = { 500,200 };
	std::vector<Point> way1 = { p1,p2,p3,p4 };
	std::vector<Point> way2 ;
//	= { p2,p4,p3,p1 }
	way2.push_back(p2);
	way2.push_back(p4);
	way2.push_back(p3);
	way2.push_back(p1);
	path1.setupWay(way1);
	path1.setupWave(&wave1);
	//path2.setupWay(way2);
	//path2.setupWave(&wave1);
	level1.pushPlot(&plot1);
	level1.pushPlot(&plot2);
	level1.pushPlot(&plot3);
	level1.pushPlot(&plot4);
	level1.pushPlot(&plot5);
	std::vector<Path*> pathWave1{
		&path1,
//		&path2

	};

	wave1.setupPaths(pathWave1);
	level1.pushBackWave(&wave1);
	level1.setPlayer(&player);
	load(renderer);
	while (!quit) {
		//Inputs
		quit = handleInput();

		//Update
		update(renderer);

		//Draw 
		draw(renderer);
	}
	//END
	close(window, renderer);
	return 0;
}


void load(SDL_Renderer* renderer) {
	//image ressources load 
	ressManager.setAllTexture(renderer, imageToLoad);
	player.load(renderer);
	level1.startLevel();

}

bool handleInput() {
	bool doquit = inputHandler.handleAllInput(&level1);
	return doquit;
}

void update(SDL_Renderer* renderer) {
	//wave1.update();
	level1.update();

}


void draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x50, 0xFF);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//wave1.draw(renderer,&ressManager);
	level1.draw(renderer,&ressManager);


	//Render
	SDL_RenderPresent(renderer);
}

void close(SDL_Window* window, SDL_Renderer* renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}
