#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "hero.h"
#include "position.h"

namespace game_framework {

	Hero::Hero() {
		counter.push_back(new Counter(300));	//slash
		counter.push_back(new Counter(600));	//heal
		Initialize();
	}
	Hero::~Hero() {
	}
	void Hero::Initialize()
	{
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isAttacking = isSlashing = isHitLeft = isHitRight = isDead =isHealing = false;
		rising = false;
		floor = 570;
		initial_velocity = 14;
		exp = 0;
		level = 1;
		counter[slash]->stop();
		counter[heal]->stop();
		skill_time =26;
		heal_time =72;
		level_animation = 0;
	}

	void Hero::OnMove()
	{
		STEP_SIZE = 8;			//���ʳt��

		if (isMovingDown  && pos_y >= floor || isAttacking && pos_y >= floor || isSlashing)
			STEP_SIZE = 0;		//�w�U�R��

		if (isMovingLeft && !isHitLeft && !isHitRight)
			pos_x -= STEP_SIZE;

		if (isMovingRight && !isHitLeft && !isHitRight)
			pos_x += STEP_SIZE;

		if (isMovingUp && pos_y == floor && !isHitLeft && !isHitRight) {
			rising = true;
			velocity = initial_velocity;
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
				pos_x -= STEP_SIZE * 2;
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
				pos_x += STEP_SIZE * 2;
			}
			hit_time--;
		}

		if (rising) {			// �W�ɪ��A
			if (velocity > 0) {
				pos_y -= velocity*2;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				rising = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;	// �U������t(velocity)��1
			}
		}
		else {				// �U�����A
			if (pos_y < floor) {  // ��y�y���٨S�I��a�O
				pos_y += velocity*2;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				if (velocity < 7) 
					velocity++;
			}
			else {
				pos_y = floor;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
				velocity = 0;
			}
		}

	}

	void Hero::OnShow()
	{	
		// �I��ޯ�ɪ��K��
		if (isSlashing) {
			if (skill_time == 0) {
				skill_time = 26;
				isSlashing = false;
			}
			else {
				a.slashAnimation.SetTopLeft(pos_x - 370, pos_y - 240);
				a.slashAnimation.OnShow();
				a.slashAnimation.OnMove();
				skill_time--;
			}
		}
		else {
			if (isHealing) {
				if (heal_time == 0) {
					heal_time = 72;
					isHealing = false;
				}
				else {
					a.healAnimation.SetTopLeft(pos_x - 320, pos_y - 240);
					a.healAnimation.OnShow();
					a.healAnimation.OnMove();
					heal_time--;
				}
			}
			// �V�k�ݪ��K��
			if (facing == 1) {
				a.standRight.SetTopLeft(pos_x, pos_y);
				if (isAttacking) {
					a.attackRight.SetTopLeft(a.standRight.Left(), a.standRight.Top() - 12);
					a.attackRight.OnShow();
					a.attackRight.OnMove();
				}
				else if (isMovingDown) {
					a.downRight.SetTopLeft(a.standRight.Left(), a.standRight.Top() + 78);
					a.downRight.OnShow();
				}
				else if (isMovingLeft) {
					a.goLeft.SetTopLeft(a.standRight.Left(), a.standRight.Top());
					if (pos_y < floor) {
						a.jumpLeft.SetTopLeft(a.standRight.Left(), a.standRight.Top());
						a.jumpLeft.OnShow();
						a.jumpLeft.OnMove();
					}
					else {
						a.goLeft.OnShow();
						a.goLeft.OnMove();
					}
				}
				else if (isMovingRight) {
					a.goRight.SetTopLeft(a.standRight.Left(), a.standRight.Top());
					if (pos_y < floor) {
						a.jumpRight.SetTopLeft(a.standRight.Left(), a.standRight.Top());
						a.jumpRight.OnShow();
						a.jumpRight.OnMove();
					}
					else {
						a.goRight.OnShow();
						a.goRight.OnMove();
					}
				}
				else {
					a.standRight.OnShow();
				}
			}

			// �V���ݪ��K��
			if (facing == 2) {
				a.standLeft.SetTopLeft(pos_x, pos_y);
				if (isAttacking) {
					a.attackLeft.SetTopLeft(a.standLeft.Left() - 35, a.standLeft.Top() - 12);
					a.attackLeft.OnShow();
					a.attackLeft.OnMove();
				}
				else if (isMovingDown) {
					a.downLeft.SetTopLeft(a.standLeft.Left() - 40, a.standLeft.Top() + 78);
					a.downLeft.OnShow();
				}
				else if (isMovingLeft) {
					a.goLeft.SetTopLeft(a.standLeft.Left(), a.standLeft.Top());
					if (pos_y < floor) {
						a.jumpLeft.SetTopLeft(a.standLeft.Left(), a.standLeft.Top());
						a.jumpLeft.OnShow();
						a.jumpLeft.OnMove();
					}
					else {
						a.goLeft.OnShow();
						a.goLeft.OnMove();
					}
				}
				else if (isMovingRight) {
					a.goRight.SetTopLeft(a.standLeft.Left(), a.standLeft.Top());
					if (pos_y < floor) {
						a.jumpRight.SetTopLeft(a.standLeft.Left(), a.standLeft.Top());
						a.jumpRight.OnShow();
						a.jumpRight.OnMove();
					}
					else {
						a.goRight.OnShow();
						a.goRight.OnMove();
					}
				}
				else {
					a.standLeft.OnShow();
				}
			}
		}
		hp_OnShow();

		if (level_animation > 0) {
			a.lv_up.SetTopLeft(pos_x - 500, pos_y - 650);
			a.lv_up.OnShow();
			a.lv_up.OnMove();
			level_animation--;
		}

		//10 = Lv, 11 = HP, 12 = ATK
		// UI ����
		number_OnShow(10, 10, 10);
		number_OnShow(12, 10, 45);
		number_OnShow(11, 10, 80);

		// LV ���
		if(level < 10)
			number_OnShow(level, 165, 10);
		else {
			number_OnShow(level / 10, 165, 10);
			number_OnShow(level % 10, 165+d, 10);
		}

		// ATK ���
		if (attack < 100) {
			number_OnShow(attack / 10, 133, 45);
			number_OnShow(attack % 10, 133 + d, 45);
		}
		if (attack < 1000) {
			number_OnShow(attack / 100, 133, 45);
			number_OnShow(attack / 10 % 10, 133 + d, 45);
			number_OnShow(attack % 10, 133 + d * 2, 45);
		}
		else {
			number_OnShow(attack / 1000, 133, 45);
			number_OnShow(attack / 100 % 10, 133 + d, 45);
			number_OnShow(attack / 10 % 10, 133 + d * 2, 45);
			number_OnShow(attack % 10, 133 + d * 3, 45);
		}

		// HP ���
		if (HP > 0) {
			if (HP < 10) {
				number_OnShow(HP, 133, 80);
			}
			else if (HP < 100) {
				number_OnShow(HP / 10, 133, 80);
				number_OnShow(HP % 10, 133 + d, 80);
			}
			else if (HP < 1000) {
				number_OnShow(HP / 100, 133, 80);
				number_OnShow(HP / 10 % 10, 133 + d, 80);
				number_OnShow(HP % 10, 133 + d * 2, 80);
			}
			else if (HP < 10000) {
				number_OnShow(HP / 1000, 133, 80);
				number_OnShow(HP / 100 % 10, 133 + d, 80);
				number_OnShow(HP / 10 % 10, 133 + d * 2, 80);
				number_OnShow(HP % 10, 133 + d * 3, 80);
			}
			else if (HP < 100000) {
				number_OnShow(HP / 10000, 133, 80);
				number_OnShow(HP / 1000 % 10, 133 + d, 80);
				number_OnShow(HP / 100 % 10, 133 + d * 2, 80);
				number_OnShow(HP / 10 % 10, 133 + d * 3, 80);
				number_OnShow(HP % 10, 133 + d * 4, 80);
			}
		}
	}

	void Hero::attacking(Character *monster) {
		if(isSlashing == true)
			monster->setHP(monster->getHP() - attack * 2);
		if(isAttacking == true)
			monster->setHP(monster->getHP() - attack);
		if (facing == 2)
			monster->setHitLeft();
		else if (facing == 1)
			monster->setHitRight();
	}
}