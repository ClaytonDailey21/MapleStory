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
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ����Hero
		void OnShow();					// �NHero�ϧζK��e��

	protected:
		CAnimation stand;			// ����
		CAnimation standLeft;		// ���߭��V��
		CAnimation downRight;		// �V�k�w�U
		CAnimation downLeft;			// �V���w�U
		CAnimation goLeft;			// �V����
		CAnimation goRight;			// �V�k��
		CAnimation jumpRight;		// �V�k��
		CAnimation jumpLeft;			// �V����
		CAnimation attackRight;		// �V�k����
		CAnimation attackLeft;		// �V������
	};
}
#endif