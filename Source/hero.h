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
		int  GetX1();					// Hero���W�� x �y��
		int  GetY1();					// Hero���W�� y �y��
		int  GetX2();					// Hero�k�U�� x �y��
		int  GetY2();					// Hero�k�U�� y �y��
		void Initialize();				// �]�wHero����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ����Hero
		void OnShow();					// �NHero�ϧζK��e��
		//void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		//void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		//void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		//void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�wHero���W���y��

	protected:
		CAnimation stand;			// ����
		CAnimation standLeft;		// ���߭��V��
		CAnimation downRight;		// �V�k�w�U
		CAnimation downLeft;		// �V���w�U
		CAnimation goLeft;			// �V����
		CAnimation goRight;			// �V�k��
		CAnimation jumpRight;		// �V�k��
		CAnimation jumpLeft;		// �V����
		CAnimation attackRight;		// �V�k����
		CAnimation attackLeft;		// �V������
		//bool isMovingDown;			// �O�_���b���U����
		//bool isMovingLeft;			// �O�_���b��������
		//bool isMovingRight;			// �O�_���b���k����
		//bool isMovingUp;			// �O�_���b���W����
		int floor;				// �a�O��Y�y��
		int attack;				// �����O
		bool rising;			// true��W�ɡBfalse��U��
		int initial_velocity;	// ��l�t��
		int velocity;			// �ثe���t��(�I/��)
		int STEP_SIZE = 8;
	};
}
#endif