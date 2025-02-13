#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "character.h"

namespace game_framework
{
	Character::Character()						// 宣告基本參數
	{
		level_animation = 0;
		is_Monster_Go_Left = is_Monster_Go_Right = false;
		hit_time = 18;
		STEP_SIZE = 8;
		skill = 0;
	}
	Character::~Character()						// 解構釋放記憶體
	{
		for (auto c : counter)
			delete c;
		counter.clear();
	}
	int Character::getX()
	{
		return pos_x;
	}
	int Character::getY()
	{
		return pos_y;
	}
	void Character::setXY(int nx, int ny)
	{
		pos_x = nx;
		pos_y = ny;
	}
	int Character::getAttack()
	{
		return attack;
	}
	void Character::setAttack(int Atk)
	{
		attack = Atk;
	}
	int Character::getHP()
	{
		return HP;
	}
	int Character::getMaxHP()
	{
		return maxHP;
	}
	void Character::setHP(int Health)
	{
		HP = Health;
	}
	void Character::setMaxHP(int Health)
	{
		maxHP = Health;
		HP = Health;
	}
	void Character::setFloor(int Floor)
	{
		floor = Floor;
	}
	int Character::getFloor()
	{
		return floor;
	}
	void Character::setXP(int nxp)
	{
		exp = nxp;
	}
	int Character::getXP()
	{
		return exp;
	}
	void Character::setLevel(int nlv)
	{
		level = nlv;
	}
	int Character::getLevel()
	{
		return level;
	}
	void Character::setMovingDown(bool flag)
	{
		isMovingDown = flag;
	}
	void Character::setMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}
	void Character::setMovingRight(bool flag)
	{
		isMovingRight = flag;
	}
	void Character::setMovingUp(bool flag)
	{
		isMovingUp = flag;
	}
	void Character::setAttacking(bool flag)
	{
		isAttacking = flag;
	}
	void Character::setPoison(bool flag)
	{
		isPoison = flag;
	}
	bool Character::ifPoison()
	{
		return isPoison;
	}
	void Character::setDead(bool flag)
	{
		isDead = flag;
	}
	bool Character::ifAttacking()
	{
		return isAttacking;
	}
	void Character::setHitLeft()
	{
		isHitLeft = true;
	}
	void Character::setHitLeft(bool flag)
	{
		isHitLeft = flag;
	}
	bool Character::ifHitLeft()
	{
		return isHitLeft;
	}
	void Character::setHitRight()
	{
		isHitRight = true;
	}
	void Character::setHitRight(bool flag)
	{
		isHitRight = flag;
	}
	bool Character::ifHitRight()
	{
		return isHitRight;
	}
	void Character::setFacing(int face)
	{
		facing = face;
	}
	int Character::getFacing()
	{
		return facing;
	}
	void Character::setAttackRange(int x)
	{
		attackRange = x;
	}
	int Character::getAttackRange()
	{
		return attackRange;
	}
	void Character::hp_addBitmaps()
	{									// 10% 一格一張圖
		int hp_bitmaps[] = {IDB_HP_0, IDB_HP_10, IDB_HP_20, IDB_HP_30, IDB_HP_40, IDB_HP_50, IDB_HP_60, IDB_HP_70, IDB_HP_80, IDB_HP_90, IDB_HP_100};
		for (int i = 0; i < 11; i++)
			hp[i].AddBitmap(hp_bitmaps[i]);
	}
	void Character::hp_OnShow()
	{
		for (int i = 10; i > 0; i--)
		{
			if (HP_PERCENT > 10 * (i - 1) && HP_PERCENT <= 10 * i)
			{
				hp[i].SetTopLeft(pos_x, pos_y - 20);
				hp[i].OnShow();
				break;
			}
		}
	}
	void Character::number_addBitmaps()
	{									// 0 ~ 9 各一張圖 + 等級、生命、攻擊
		int number_bitmaps[] = {IDB_0, IDB_1, IDB_2, IDB_3, IDB_4, IDB_5, IDB_6, IDB_7, IDB_8, IDB_9, IDB_LV, IDB_HP, IDB_ATK};
		for (int i = 0; i < 13; i++)
			num[i].AddBitmap(number_bitmaps[i], RGB(230, 212, 132));
	}
	void Character::number_OnShow(int nx, int pos_nx, int pos_ny)
	{									//10 = Lv, 11 = HP, 12 = ATK
		num[nx].SetTopLeft(pos_nx, pos_ny);
		num[nx].OnShow();
	}
	void Character::setLevelUP()
	{
		if (level_animation == 0)
			level_animation = 80;
	}
	bool Character::ifMovingLeft()
	{
		return isMovingLeft;
	}
	bool Character::ifMovingRight()
	{
		return isMovingRight;
	}
	bool Character::ifMovingUp()
	{
		return isMovingUp;
	}
	bool Character::ifMovingDown()
	{
		return isMovingDown;
	}
	bool Character::ifDead()
	{
		return isDead;
	}
	void Character::addBitmap(int standR, int standL, int downR, int downL, int jumpR, int jumpL, vector<int> goR, vector<int> goL, vector<int> attackR, vector<int> attackL, vector<int> slash, vector<int> heal, vector<int> lv_up, int nR, int nG, int nB, int slash_ani)
	{
		if (standR != 0)											// 這個函式將所有一個 Character 需要的圖檔全部合併導入
			a.standRight.AddBitmap(standR, RGB(nR, nG, nB));
		if (standL != 0)
			a.standLeft.AddBitmap(standL, RGB(nR, nG, nB));
		if (downR != 0)
			a.downRight.AddBitmap(downR, RGB(nR, nG, nB));
		if (downL != 0)
			a.downLeft.AddBitmap(downL, RGB(nR, nG, nB));
		if (jumpR != 0)
			a.jumpRight.AddBitmap(jumpR, RGB(nR, nG, nB));
		if (jumpL != 0)
			a.jumpLeft.AddBitmap(jumpL, RGB(nR, nG, nB));
		a.goRight = CAnimation(3);
		a.goLeft = CAnimation(3);
		a.attackRight = CAnimation(2);
		a.attackLeft = CAnimation(2);
		a.slashAnimation = CAnimation(slash_ani);
		a.healAnimation = CAnimation(4);
		a.lv_up = CAnimation(4);
		for (size_t i = 0; i < goR.size(); i++)
			a.goRight.AddBitmap(goR[i], RGB(nR, nG, nB));
		for (size_t i = 0; i < goL.size(); i++)
			a.goLeft.AddBitmap(goL[i], RGB(nR, nG, nB));
		for (size_t i = 0; i < attackR.size(); i++)
			a.attackRight.AddBitmap(attackR[i], RGB(nR, nG, nB));
		for (size_t i = 0; i < attackL.size(); i++)
			a.attackLeft.AddBitmap(attackL[i], RGB(nR, nG, nB));
		for (size_t i = 0; i < slash.size(); i++)
			a.slashAnimation.AddBitmap(slash[i], RGB(0, 0, 0));
		for (size_t i = 0; i < heal.size(); i++)
			a.healAnimation.AddBitmap(heal[i], RGB(0, 0, 0));
		for (size_t i = 0; i < lv_up.size(); i++)
			a.lv_up.AddBitmap(lv_up[i], RGB(3, 3, 3));
		hp_addBitmaps();
		number_addBitmaps();
	}

	Counter &Character::getCounter(int i)
	{
		return *counter[i];
	}

	void Character::countdown()
	{
		for (auto count : counter)
			count->countdown();
	}

	// Monsters
	void Character::set_Monster_Go_Left(bool flag)
	{
		is_Monster_Go_Left = flag;
	}
	void Character::set_Monster_Go_Right(bool flag)
	{
		is_Monster_Go_Right = flag;
	}
	void Character::setSkill(int i)
	{
		skill = i;
	}

	// Hero
	void Character::setSlashing(bool flag)
	{
		isSlashing = flag;
	}
	bool Character::ifSlashing()
	{
		return isSlashing;
	}
	void Character::setHealing(bool flag)
	{
		isHealing = flag;
	}
	bool Character::ifHealing()
	{
		return isHealing;
	}
} // namespace game_framework