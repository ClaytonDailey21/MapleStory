#ifndef HERO_H
#define HERO_H

#include "character.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class Hero: public Character
	{
	public:
		Hero();
		void Initialize();				// �]�wHero����l��
		void OnMove();					// ����Hero
		void OnShow();					// �NHero�ϧζK��e��

	protected:
	};
}
#endif