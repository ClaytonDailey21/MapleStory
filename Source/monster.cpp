#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "monster.h"
#include "hero.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Monster: class
	/////////////////////////////////////////////////////////////////////////////

	Monster::Monster()
	{
		Initialize();
	}

	void Monster::Initialize()
	{
		const int X_POS = 500;
		const int Y_POS = 570;
		pos_x = X_POS;
		pos_y = Y_POS;
		isMovingLeft = isMovingRight = false;
		STEP_SIZE = 3;
		const int FLOOR = 570;
		floor = FLOOR;
	}

	void Monster::LoadBitmap()
	{
		a.standRight.AddBitmap(IDB_MONSTER_STAND_RIGHT, RGB(255, 255, 255));
		a.standLeft.AddBitmap(IDB_MONSTER_STAND_LEFT, RGB(255, 255, 255));
		hp_addBitmaps();
	}

	void Monster::OnMove()
	{
		a.standRight.OnMove();
		if (is_Monster_Go_Left) {	//�Y�I���N�ʦa�Ϫ���a�Ϫ���t
			STEP_SIZE = -3;
			pos_x += STEP_SIZE;
		}
		else if (is_Monster_Go_Right) {		//�Y�I���N�ʦa�Ϫ���a�Ϫ���t
			STEP_SIZE = 3;
			pos_x += STEP_SIZE;
		}
		if (isMovingRight) {
			pos_x -= HERO_STEP;
		}
		else if (isMovingLeft) {
			pos_x += HERO_STEP;
		}
	}



	void Monster::OnShow()
	{
		a.standRight.SetTopLeft(pos_x, pos_y);
		a.standLeft.SetTopLeft(pos_x, pos_y);
		if (STEP_SIZE >= 0) {
			a.standRight.OnShow();
		}
		else a.standLeft.OnShow();
		hp_OnShow();
	}
}