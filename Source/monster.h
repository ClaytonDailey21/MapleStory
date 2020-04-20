#ifndef MONSTER_H
#define MONSTER_H


#include "character.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class Monster: public Character
	{
	public:
		Monster();
		void Initialize();				// �]�wmonster����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ����monster
		void OnShow();					// �Nmonster�ϧζK��e��

	protected:
		CAnimation monsterRight;		// ����
		CAnimation monsterLeft;
		const int HERO_STEP = 8;//
		int range_X;				// Hero���W���y��
		int tempX, tempY;
	};
}
#endif