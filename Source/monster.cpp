#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "monster.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Hero: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	Monster::Monster()
	{
		Initialize();
	}

	int Monster::GetX1()
	{
		return x;
	}

	int Monster::GetY1()
	{
		return y;
	}

	int Monster::GetX2()
	{
		return x + stand.Width();
	}

	int Monster::GetY2()
	{
		return y + stand.Height();
	}

	void Monster::Initialize()
	{
		const int X_POS = 100;
		const int Y_POS = 570;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		const int INITIAL_VELOCITY = 14;
		const int FLOOR = 570;
		rising = false;
		floor = FLOOR;
		initial_velocity = INITIAL_VELOCITY;
	}

	void Monster::LoadBitmap()
	{
		stand.AddBitmap(IDB_FROG_STAND, RGB(255, 255, 255));
		down.AddBitmap(IDB_FROG_DOWN, RGB(255, 255, 255));
	}

	void Monster::OnMove()
	{
		stand.OnMove();
		int STEP_SIZE;

		if (isMovingDown && y >= floor) { //���ʳt�סB�w�U�R��
			STEP_SIZE = 0;
		}
		else {
			STEP_SIZE = 8;
		}

		if (isMovingLeft && x >= 100)
			x -= STEP_SIZE;

		if (isMovingRight && x <= 1166)
			x += STEP_SIZE;

		if (isMovingUp  && y == floor) {
			rising = true;
			velocity = initial_velocity;
		}

		if (rising) {			// �W�ɪ��A
			if (velocity > 0) {
				y -= velocity * 2;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				rising = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;	// �U������t(velocity)��1
			}
		}
		else {				// �U�����A
			if (y < floor) {  // ��y�y���٨S�I��a�O
				y += velocity * 2;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
			}
			else {
				y = floor;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
			}
		}
	}

	void Monster::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Monster::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Monster::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Monster::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void Monster::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void Monster::OnShow()
	{
		stand.SetTopLeft(x, y);
		if (isMovingDown) {
			down.SetTopLeft(stand.Left(), stand.Top() + 78);
			down.OnShow();
		}
		else {
			stand.OnShow();
		}
	}
}