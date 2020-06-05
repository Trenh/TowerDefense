#include "projectileData.h"

projectileData basicArcherProj = {
  4, //atkMin
  7, //atkMax
  20, //height
  20, //width
  4, //speed
  "basicArcherProjectile.png",	// imgName
  false //explo
};


 projectileData basicMageProj = {
   10, //atkMin
   15, //atkMax
   20, //height
   20, //width
   3, //speed
   "basicMageProjectile.png",	// imgName
   false //explo
};


  projectileData basicBombProj = {
	10, //atkMin
	13, //atkMax
	20, //height
	20, //width
	3, //speed
	"basicBombProjectile.png",	// imgName
	true //explo
};

  projectileData basicPoisonProj = {
	5, //atkMin
	10, //atkMax
	20, //height
	20, //width
	3, //speed
	"basicPoisonProjectile.png",	// imgName
	false //explo
};
