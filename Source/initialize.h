#ifndef INITIALIZE_H
#define INITIALIZE_H
#include "hero.h"
#include "map.h"
#include "monster.h"
#include "position.h"
#include <vector>
namespace game_framework
{

	//DEFINE
#define HEIGHT_CHECK hero_pos.getY() <= monster_pos.getY() + 100 && hero_pos.getY() + 100 >= monster_pos.getY()
#define SLASH_HEIGHT_CHECK hero_pos.getY() <= monster_pos.getY() + 100 && hero_pos.getY() + 300 >= monster_pos.getY()
#define HIT_CHECK_CHARACTER !hero.ifHitLeft() && !hero.ifHitRight()
#define HIT_CHECK_MONSTER !(*monster)->ifHitLeft() && !(*monster)->ifHitRight()
#define HIT_CHECK_BOSS !mboss.ifHit()
#define MONSTER_HIT_CHARACTER(a) (hero_pos.getX() - monster_pos.getX() <= a && monster_pos.getX() - hero_pos.getX() <= a)
#define CHARACTER_HIT_MONSTER hero.ifAttacking() && hero.getFacing() == 2 && hero_pos.getX() - monster_pos.getX() <= 100 && monster_pos.getX() - hero_pos.getX() <= 0 || hero.ifAttacking() && hero.getFacing() == 1 && hero_pos.getX() - monster_pos.getX() <= 0 && monster_pos.getX() - hero_pos.getX() <= 100
#define CHARACTER_SLASH_MONSTER hero.ifSlashing() && hero_pos.getX() - monster_pos.getX() <= 340 && monster_pos.getX() - hero_pos.getX() <= 0 || hero.ifSlashing() && hero_pos.getX() - monster_pos.getX() <= 0 && monster_pos.getX() - hero_pos.getX() <= 340
#define CHARACTER_HIT_BOSS hero.ifAttacking() && hero.getFacing() == 1 && hero_pos.getX() >= 1500
#define CHARACTER_SLASH_BOSS hero.ifSlashing() && hero_pos.getX() >= 1320
#define ON_PLATFORM_MONSTER monster_pos.getY() <= map.getFloorY(j) + 50 && monster_pos.getY() >= map.getFloorY(j) - 14 && monster_pos.getX() >= map.getFloorXBegin(j) && monster_pos.getX() <= map.getFloorXLast(j)
#define ON_FLOOR hero_pos.getY() <= map->getFloorY(i) + 50 && hero_pos.getY() >= map->getFloorY(i) - 14 && hero_pos.getX() >= map->getFloorXBegin(i) && hero_pos.getX() <= map->getFloorXLast(i)
#define ON_PORTAL hero_pos.getY() == 560 - map->getPortal().getY() && hero_pos.getX() >= map->getPortal().getX() - 20 && hero_pos.getX() <= map->getPortal().getX() + 40
#define LIGHTING1_CHECK hero_pos.getX() >= 620 + 200 * i &&hero_pos.getX() <= 720 + 200 * i
#define LIGHTING2_CHECK hero_pos.getX() >= 520 + 200 * i &&hero_pos.getX() <= 620 + 200 * i

	// Map 直接回傳物件

	inline Map Map1()
	{
		Map gamemap;
		Platform plats[8] = {{260, 404, 200},			// 設定下列數值
							 {580, 980, 290},			// 地板高度
							 {764, 1316, 590},			// 放大倍率
							 {1204, 1908, 418},			// 平台數量
							 {1436, 1924, 253},			// 背景 Bitmap
							 {1948, 2196, 150},			// 傳送門座標
							 {1780, 2148, 590},			// 平台設定
							 {0, 3000, 0}};
		gamemap.setInitFloor(570);
		gamemap.setInitZoom(2);
		gamemap.setInitXY(0, 0);
		gamemap.setInitPlatform(plats, 8);
		gamemap.setInitBitmap(IDB_BACKGROUND);
		gamemap.setInitPortal(2080, 410);
		return gamemap;
	}
	inline Map Map2()
	{
		Map gamemap;
		Platform plats[8] = {{460, 948, 118},
							 {1044, 1780, 192},
							 {1748, 1980, 323},
							 {1300, 1704, 441},
							 {868, 1276, 560},
							 {460, 780, 513},
							 {20, 404, 390},
							 {1756, 1924, 568}};
		gamemap.setInitFloor(570);
		gamemap.setInitZoom(2);
		gamemap.setInitXY(0, 0);
		gamemap.setInitPlatform(plats, 8);
		gamemap.setInitBitmap(IDB_BACKGROUND2);
		gamemap.setInitPortal(2100, 560);
		return gamemap;
	}
	inline Map Map3()
	{
		Map gamemap;
		Platform plats[8] = {{52, 988, 166},
							 {1468, 2212, 166},
							 {916, 1470, 326},
							 {52, 980, 496},
							 {1316, 2244, 494},
							 {0, 3000, 0},
							 {0, 3000, 0},
							 {0, 3000, 0}};
		gamemap.setInitFloor(570);
		gamemap.setInitZoom(2);
		gamemap.setInitXY(0, 0);
		gamemap.setInitPlatform(plats, 8);
		gamemap.setInitBitmap(IDB_BACKGROUND3);
		gamemap.setInitPortal(2100, 560);
		return gamemap;
	}
	inline Map Map4()
	{
		Map gamemap;
		Platform plats[8] = {{0, 3000, 0},
							 {0, 3000, 0},
							 {0, 3000, 0},
							 {0, 3000, 0},
							 {0, 3000, 0},
							 {0, 3000, 0},
							 {0, 3000, 0},
							 {0, 3000, 0}};
		gamemap.setInitFloor(570);
		gamemap.setInitZoom(2);
		gamemap.setInitXY(0, 0);
		gamemap.setInitPlatform(plats, 8);
		gamemap.setInitBitmap(IDB_BACKGROUND4);
		gamemap.setInitPortal(2100, 560);
		return gamemap;
	}

	// Character 只重置數值

	inline void initHero(Character &hero)		// Hero 初始數值設定
	{
		hero.Initialize();
		hero.setXY(100, 570);
		hero.setFacing(1);
		hero.setMaxHP(500);
		hero.setAttack(30);
	}
	inline void initMonster1(vector<Character *> &monster)	// 第一關 Monster 初始數值設定
	{
		for (size_t i = 0; i < monster.size(); i++)
		{
			monster[i]->Initialize();
			monster[i]->setMaxHP(100);
			monster[i]->setAttack(50);
			monster[i]->setAttackRange(50);
			monster[i]->setSkill(0);
		}
	}
	inline void initMonster2(vector<Character *> &monster)	// 第二關 Monster 初始數值設定
	{
		for (size_t i = 0; i < monster.size(); i++)
		{
			monster[i]->Initialize();
			monster[i]->setMaxHP(350);
			monster[i]->setAttack(100);
			monster[i]->setAttackRange(100);
			monster[i]->setSkill(0);
		}
	}
	inline void initMonster3(vector<Character *> &monster)	// 第三關 Monster 初始數值設定
	{
		for (size_t i = 0; i < monster.size(); i++)
		{
			monster[i]->Initialize();
			monster[i]->setMaxHP(750);
			monster[i]->setAttack(0);
			monster[i]->setAttackRange(200);
			monster[i]->setSkill(1);
		}
	}
} // namespace game_framework

#endif // !INITIALIZE_H
