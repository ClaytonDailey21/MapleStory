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

	Monster::Monster(int nx, int ny, int nxp)
	{
		exp = nxp;
		initX = nx;
		initY = ny;
	}

	Monster::~Monster() {
	}

	void Monster::Initialize()
	{
		isMovingLeft = isMovingRight = false;
		isAttacking = isHitLeft = isHitRight = isDead = false;
		STEP_SIZE = 3;
		const int FLOOR = 570;
		floor = FLOOR;
		const int INITIAL_VELOCITY = 14;
		rising = true;
		initial_velocity = INITIAL_VELOCITY;
		setXY(initX, initY);
	}

	void Monster::OnMove()
	{
		if (isDead)
			return;
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

		if (isHitLeft) {
			if (hit_time == 0) {
				hit_time = 18;
				isHitLeft = false;
			}
			else if (hit_time >= 17) {
				rising = true;
				velocity = initial_velocity - 7;
			}
			else if (hit_time > 0)
			{
				pos_x -= HERO_STEP * 2;
			}
			hit_time--;
		}
		if (isHitRight) {
			if (hit_time == 0) {
				hit_time = 18;
				isHitRight = false;
			}
			else if (hit_time >= 17) {
				rising = true;
				velocity = initial_velocity - 7;
			}
			else if (hit_time > 0)
			{
				pos_x += HERO_STEP * 2;
			}
			hit_time--;
		}

		if (rising) {			// �W�ɪ��A
			if (velocity > 0) {
				pos_y -= velocity * 2;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				rising = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;	// �U������t(velocity)��1
			}
		}
		else {				// �U�����A
			if (pos_y < floor) {  // ��y�y���٨S�I��a�O
				pos_y += velocity * 2;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				if (velocity < 7)
					velocity++;
			}
			else {
				pos_y = floor;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
				velocity = 0;
			}
		}

		if (isAttacking) {
			if (attack_time == 0) {
				attack_time = 15;
				isAttacking = false;
			}
			attack_time--;
		}
	}



	void Monster::OnShow()
	{
		if (!isDead) {

			a.standRight.SetTopLeft(pos_x, pos_y);
			a.standLeft.SetTopLeft(pos_x, pos_y);

			if (STEP_SIZE >= 0) {
				if (isAttacking) {
					a.attackRight.SetTopLeft(a.standRight.Left(), a.standRight.Top());
					a.attackRight.OnShow();
					a.attackRight.OnMove();
				}
				else {
					a.standRight.OnShow();
					a.standRight.OnMove();
				}
			}
			else {
				if (isAttacking) {
					a.attackLeft.SetTopLeft(a.standLeft.Left(), a.standLeft.Top());
					a.attackLeft.OnShow();
					a.attackLeft.OnMove();
				}
				else {
					a.standLeft.OnShow();
					a.standLeft.OnMove();
				}
			}
			hp_OnShow();
		}
	}
}