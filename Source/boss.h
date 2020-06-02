#ifndef BOSS_H
#define BOSS_H

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////
	struct BossAnimations
	{
		CAnimation normal;
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


	protected:
		BossAnimations a;
		CMovingBitmap hpIcon;
		int pos_x, pos_y;
		bool isMovingRight, isMovingLeft;
		bool isDead = false;
		const int HERO_STEP = 8;
		const int floor = 570;
		int maxHP = 1000;
		int hp;
	};
}
#endif
