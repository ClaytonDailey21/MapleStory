#ifndef BOSS_H
#define BOSS_H

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class Boss
	{
	public:
		Boss() {};
		~Boss();
		void Initialize();				// �]�wmonster����l��
		void OnMove();					// ����monster
		void OnShow();					// �Nmonster�ϧζK��e��
		void showHPBar(int percent);
		void setMovingLeft(bool flag);
		void setMovingRight(bool flag);
		void setXY(int nx, int ny);


	protected:
		CAnimation bossStand;
		int pos_x, pos_y;
		bool isMovingRight, isMovingLeft;
		bool isDead = false;
		const int HERO_STEP = 8;
		const int floor = 570;
	};
}
#endif
