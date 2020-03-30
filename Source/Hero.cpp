#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Hero.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Hero: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	Hero::Hero()
	{
		Initialize();
	}

	int Hero::GetX1()
	{
		return x;
	}

	int Hero::GetY1()
	{
		return y;
	}

	int Hero::GetX2()
	{
		return x + stand.Width();
	}

	int Hero::GetY2()
	{
		return y + stand.Height();
	}

	void Hero::Initialize()
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

	void Hero::LoadBitmap()
	{
		int frogLeft[] = { IDB_FROG_GO_LEFT1,IDB_FROG_GO_LEFT2, IDB_FROG_STAND_LEFT};
		int frogRight[] = { IDB_FROG_GO_RIGHT1,IDB_FROG_GO_RIGHT2, IDB_FROG_STAND_RIGHT };
		goRight = CAnimation(5);
		goLeft = CAnimation(5);
		for (int i = 0; i < 3; i++) {
			goLeft.AddBitmap(frogLeft[i], RGB(255, 255, 255));
			goRight.AddBitmap(frogRight[i], RGB(255, 255, 255));
		}
		stand.AddBitmap(IDB_FROG_STAND_RIGHT, RGB(255, 255, 255));
		standLeft.AddBitmap(IDB_FROG_GO_LEFT, RGB(255, 255, 255));
		down.AddBitmap(IDB_FROG_DOWN, RGB(255, 255, 255));
		jumpRight.AddBitmap(IDB_FROG_JUMP_RIGHT, RGB(255, 255, 255));
		jumpLeft.AddBitmap(IDB_FROG_JUMP_LEFT, RGB(255, 255, 255));
	}

	void Hero::OnMove()
	{
		stand.OnMove();
		int STEP_SIZE;

		if (isMovingDown && y >= floor) { //���ʳt�סB�w�U�R��
			STEP_SIZE = 0;
		}
		else {
			STEP_SIZE = 8;
		}

		if (isMovingLeft && x >= 100 ) 
			x -= STEP_SIZE;

		if (isMovingRight && x <= 1166 )
			x += STEP_SIZE;

		if (isMovingUp  && y == floor) {
			rising = true;
			velocity = initial_velocity;
		}

		if (rising) {			// �W�ɪ��A
			if (velocity > 0) {
				y -= velocity*2;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				rising = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;	// �U������t(velocity)��1
			}
		}
		else {				// �U�����A
			if (y < floor) {  // ��y�y���٨S�I��a�O
				y += velocity*2;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
			}
			else {
				y = floor;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
			}
		}
	}

	void Hero::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Hero::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Hero::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Hero::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void Hero::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void Hero::OnShow()
	{
		stand.SetTopLeft(x, y);
		if (isMovingDown) {
			down.SetTopLeft(stand.Left(), stand.Top() + 78);
			down.OnShow();
		}
		else if (isMovingLeft) {
			goLeft.SetTopLeft(stand.Left(), stand.Top());
			if (y < floor) {
				jumpLeft.SetTopLeft(stand.Left(), stand.Top());
				jumpLeft.OnShow();
				jumpLeft.OnMove();
			}
			else {
				goLeft.OnShow();
				goLeft.OnMove();
			}
		}
		else if (isMovingRight) {
			goRight.SetTopLeft(stand.Left(), stand.Top());
			if (y < floor) {
				jumpRight.SetTopLeft(stand.Left(), stand.Top());
				jumpRight.OnShow();
				jumpRight.OnMove();
			}else{
				goRight.OnShow();
				goRight.OnMove();
			}
		} 
		else {
			stand.OnShow();
		}
	}
}