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
		Monster(){}
		Monster(int nx, int ny, int nxp);
		~Monster();
		void Initialize();				// �]�wmonster����l��
		void OnMove();					// ����monster
		void OnShow();					// �Nmonster�ϧζK��e��
		bool ifSkill();
		void setSkill(bool flag);

	protected:
		const int HERO_STEP = 8;
		int initX, initY;
		int skill = 0;
		bool isSkill = false;
	};
}
#endif