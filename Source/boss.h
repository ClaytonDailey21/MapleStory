#ifndef BOSS_H
#define BOSS_H


#include "character.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class Boss: public Character
	{
	public:
		Boss() {};
		~Boss();
		void Initialize();				// �]�wmonster����l��
		void OnMove();					// ����monster
		void OnShow();					// �Nmonster�ϧζK��e��

	protected:
		CMovingBitmap bossStand;
		int initX, initY;
		const int HERO_STEP = 8;
	};
}
#endif