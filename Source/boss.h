#ifndef BOSS_H
#define BOSS_H

#include "character.h"
#include "counter.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	struct BossAnimations
	{
		CAnimation normal;
	};
	enum BossCounter {
		skills,
		laser_delay,
		laser_skill,
		knockback_delay,
		knockback_skill
	};
	class Boss
	{
	public:
		Boss() {};
		~Boss();
		void addBitmap();
		void Initialize();				// �]�wmonster����l��
		void OnMove();					// ����monster
		void OnShow();					// �Nmonster�ϧζK��e��
		void showHPBar();
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setXY(int nx, int ny);
		bool ifHit();
		int getX();
		int getHP();					// �^���ͩR��
		int getMaxHP();
		int getAttack();				// �^�������O
		Counter& getCounter(int i);
		void countdown();
		void setHit();				// �]�w�O�_�Q����
		void setHit(bool flag);		// �]�w�O�_�Q����
		void setHP(int Health);			// �]�w�ͩR��
		int getSkill();

	protected:
		BossAnimations a;
		CMovingBitmap hpIcon;
		int pos_x, pos_y;
		bool isMovingRight, isMovingLeft;
		bool isDead = false;
		bool isHit = false;
		int hit_time = 18;
		const int HERO_STEP = 8;
		const int floor = 570;
		int maxHP = 100000;
		int HP;
		int attack = 400;
		std::vector<Counter*> counter;
		int skill;
	};
}
#endif
