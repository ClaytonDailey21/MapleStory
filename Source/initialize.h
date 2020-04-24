#ifndef INITIALIZE_H
#define INITIALIZE_H
#include "hero.h"
#include "map.h"
#include "monster.h"
#include "position.h"
#include <vector>
namespace game_framework {
	inline Map Map1() {
		Map gamemap;
		Platform plats[8] = {	{260, 404, 200},
								{580, 980, 290},
								{764, 1316,590},
								{1204,1908,418},
								{1436,1924,253},
								{1948,2196,150},
								{1780,2148,590},
								{0,3000,0} };
		gamemap.setInitFloor(570);
		gamemap.setInitZoom(2);
		gamemap.setInitXY(0, 0);
		gamemap.setInitPlatform(plats, 8);
		gamemap.setInitBitmap(IDB_BACKGROUND);
		return gamemap;
	}
	inline Character* Hero1() {
		Character *hero = new Hero;
		hero->setInitXY(100, 570);
		return hero;
	}
	//inline vector<Character*> Monster1() {
	inline Character* Monster1() {
		/*int monster_num = 5;
		Character* m = new Monster;
		vector<Character*> monster;
		for (int i = 0; i < monster_num; i++) {
			monster.push_back(m);
		}
		monster[0]->setInitXY(500, 570);
		return monster;*/
		Character* monster = new Monster;
		monster->setInitXY(500, 570);
		return monster;
	}
}

#endif // !INITIALIZE_H