#pragma once

struct projectileData {
	int atkMin;
	int atkMax;
	int height;
	int width;
	int speed;
	const char* imgName;
	bool explo;
};

 extern projectileData basicArcherProj ;
 extern projectileData basicMageProj ;
 extern projectileData basicBombProj ;
 extern projectileData basicPoisonProj ;
