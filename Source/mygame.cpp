/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
	//
	// �}�l���J���
	//
	CAudio::Instance()->Load(BGM_MENU, "sounds\\bgm_menu.mp3");
	CAudio::Instance()->Play(BGM_MENU, true);
	CAudio::Instance()->Load(BGM_STAGE1, "sounds\\bgm_stage1.mp3");
	CAudio::Instance()->Load(SFX_JUMP, "sounds\\sfx_jump.mp3");
	CAudio::Instance()->Load(BGM_GAMEOVER, "sounds\\bgm_gameover.mp3");

	menu = 1;
	
	ShowInitProgress(33);

	logo.LoadBitmap(IDB_LOGO);
	start1.LoadBitmap(IDB_START1, RGB(255, 255, 255));
	start2.LoadBitmap(IDB_START2, RGB(255, 255, 255));
	exit1.LoadBitmap(IDB_EXIT1, RGB(255, 255, 255));
	exit2.LoadBitmap(IDB_EXIT2, RGB(255, 255, 255));

	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
	//
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ENTER = 0x0D;	// Enter
	const char KEY_UP = 0x26;		// keyboard�W�b�Y
	const char KEY_DOWN = 0x28;		// keyboard�U�b�Y

	if (nChar == KEY_ENTER && menu == 1) {	
		GotoGameState(GAME_STATE_RUN);
	}

	if (nChar == KEY_ENTER && menu == 2) {
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
	}

	if (nChar == KEY_DOWN) {
		menu = 2;
	}

	if (nChar == KEY_UP) {
		menu = 1;
	}
	
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	//GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	//
	// �K�Wlogo
	//
	logo.SetTopLeft(0, 0);
	logo.ShowBitmap();

	if (menu == 1) {
		start2.SetTopLeft(483, 380);
		start2.ShowBitmap();
		exit1.SetTopLeft(483, 520);
		exit1.ShowBitmap();
	}

	if (menu == 2) {
		start1.SetTopLeft(483, 380);
		start1.ShowBitmap();
		exit2.SetTopLeft(483, 520);
		exit2.ShowBitmap();
	}
	//
	// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
	//
	/*
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f,*fp;
	f.CreatePointFont(300,"Times New Roman");	// ���� font f; 160���16 point���r
	fp=pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	pDC->TextOut(450,200,"���U���N��}�l�C��");
	pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
	if (ENABLE_GAME_PAUSE)
		pDC->TextOut(5,455,"Press Ctrl-Q to pause the Game.");
	pDC->TextOut(5,515,"���U Alt-F4 ���}�C��");
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	*/
}								

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����������A(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g)
: CGameState(g)
{
}

void CGameStateOver::OnMove()
{
	counter--;
	if (counter < 0) {
		CAudio::Instance()->Play(BGM_MENU, true);
		GotoGameState(GAME_STATE_INIT);
	}
}

void CGameStateOver::OnBeginState()
{
	counter = 30 * 7; // 7 seconds
	CAudio::Instance()->Stop(BGM_STAGE1);
	CAudio::Instance()->Play(BGM_GAMEOVER, false);

	int over[] = { IDB_GAME_OVER_0 ,IDB_GAME_OVER_1 ,IDB_GAME_OVER_2 ,IDB_GAME_OVER_3,
					IDB_GAME_OVER_4 ,IDB_GAME_OVER_5 ,IDB_GAME_OVER_6 ,IDB_GAME_OVER_7,
					IDB_GAME_OVER_8 ,IDB_GAME_OVER_9 ,IDB_GAME_OVER_10,IDB_GAME_OVER_11,
					IDB_GAME_OVER_12,IDB_GAME_OVER_13,IDB_GAME_OVER_14,IDB_GAME_OVER_0,
					IDB_GAME_OVER_0 ,IDB_GAME_OVER_0 ,IDB_GAME_OVER_0 ,IDB_GAME_OVER_0,
					IDB_GAME_OVER_0 ,IDB_GAME_OVER_0 ,IDB_GAME_OVER_0 ,IDB_GAME_OVER_0,
					IDB_GAME_OVER_0 ,IDB_GAME_OVER_0 ,IDB_GAME_OVER_0 ,IDB_GAME_OVER_0, };

	Gameover = CAnimation(9);
	for (int i = 0; i < 28; i++)
		Gameover.AddBitmap(over[i], RGB(255, 255, 255));
}

void CGameStateOver::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//

	ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
	//
	// �}�l���J���
	//
	//
	// �̲׶i�׬�100%
	//
	ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	Gameover.SetTopLeft(233, 234);
	Gameover.OnShow();
	Gameover.OnMove();
	/*
	CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
	CFont f, *fp;
	f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
	fp = pDC->SelectObject(&f);					// ��� font f
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(255, 255, 0));
	char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
	sprintf(str, "Game Over ! (%d)", counter / 30);
	pDC->TextOut(240, 210, str);
	pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
	CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	*/
}



/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
	initHero(*character);
	
	character->SetMaxHP(500);
	character->SetAttack(30);
	character->SetXP(0);
	character->SetLevel(1);

	CAudio::Instance()->Stop(BGM_MENU);
	CAudio::Instance()->Play(BGM_STAGE1, true);

	for (size_t i = 0; i < monster.size(); i++) {
		monster[i]->Initialize();
		monster[i]->SetMaxHP(100);
		monster[i]->SetAttack(50);
	}

	int blue[] = { IDB_PORTAL_BLUE1,IDB_PORTAL_BLUE2 };

	portal = CAnimation(2);
	for (int i = 0; i < 2; i++)
		portal.AddBitmap(blue[i], RGB(255, 255, 255));

	portal.SetTopLeft(portal1X, 410);
}

#define HEIGHT_CHECK hero_pos.getY() <= monster_pos.getY() + 100 && hero_pos.getY() + 100 >= monster_pos.getY()
#define SLASH_HEIGHT_CHECK hero_pos.getY() <= monster_pos.getY() + 100 && hero_pos.getY() + 300 >= monster_pos.getY()
#define HIT_CHECK_CHARACTER !character->ifHitLeft() && !character->ifHitRight()
#define HIT_CHECK_MONSTER !monster[i]->ifHitLeft() && !monster[i]->ifHitRight()
#define MONSTER_HIT_CHARACTER hero_pos.getX() - monster_pos.getX() <= 50 && monster_pos.getX() - hero_pos.getX() <= 0 || hero_pos.getX() - monster_pos.getX() <= 0 && monster_pos.getX() - hero_pos.getX() <= 50
#define CHARACTER_HIT_MONSTER character->ifAttacking() && character->GetFacing() == 2 && hero_pos.getX() - monster_pos.getX() <= 100 && monster_pos.getX() - hero_pos.getX() <= 0 || character->ifAttacking() && character->GetFacing() == 1 && hero_pos.getX() - monster_pos.getX() <= 0 && monster_pos.getX() - hero_pos.getX() <= 100
#define CHARACTER_SLASH_MONSTER character->ifSlashing() && hero_pos.getX() - monster_pos.getX() <= 340 && monster_pos.getX() - hero_pos.getX() <= 0 || character->ifSlashing() && hero_pos.getX() - monster_pos.getX() <= 0 && monster_pos.getX() - hero_pos.getX() <= 340
#define ON_PLATFORM_STAGE1 hero_pos.getY() <= map1.getFloorY(i) + 50 && hero_pos.getY() >= map1.getFloorY(i) - 14 && hero_pos.getX() >= map1.getFloorXBegin(i) && hero_pos.getX() <= map1.getFloorXLast(i)
#define ON_PLATFORM_STAGE2 hero_pos.getY() <= map2.getFloorY(i) + 50 && hero_pos.getY() >= map2.getFloorY(i) - 14 && hero_pos.getX() >= map2.getFloorXBegin(i) && hero_pos.getX() <= map2.getFloorXLast(i)
#define ON_PLATFORM_STAGE3 hero_pos.getY() <= map3.getFloorY(i) + 50 && hero_pos.getY() >= map3.getFloorY(i) - 14 && hero_pos.getX() >= map3.getFloorXBegin(i) && hero_pos.getX() <= map3.getFloorXLast(i)
#define IN_PORTAL1 hero_pos.getY() == 150 && hero_pos.getX() >= 2060 && hero_pos.getX() <= 2132
#define IN_PORTAL2 hero_pos.getY() <= 20 && hero_pos.getX() >= 2084 && hero_pos.getX() <= 2156
#define IN_PORTAL3 hero_pos.getY() == 100 && hero_pos.getX() >= 2084 && hero_pos.getX() <= 2156

void CGameStateRun::OnMove()							// ���ʹC������
{
	TRACE("----monster_num---%d\n", monster.size());
	character->OnMove();
	if (stage == 1) {
		map1.OnMove();
		hero_pos.SetPosition(character, map1);
	}
	else if (stage == 2) {
		map2.OnMove();
		hero_pos.SetPosition(character, map2);
	}
	else if (stage == 3) {
		map3.OnMove();
		hero_pos.SetPosition(character, map3);
	}
	portal.OnMove();
	TRACE("----hero-pos_xy---(%d, %d)\n", hero_pos.getX(), hero_pos.getY());
	TRACE("--hero-level_HP---(%d, %d)\n", character->GetLevel(), character->GetHP());
	TRACE("----Slash_CD------(%d)\n", slash_cd/60);

	// �a�ϲ��ʬ���
	if (character->getX() <= 100 && character->ifMovingLeft()) {
		if (stage == 1)
			map1.SetMovingLeft(true);
		if (stage == 2)
			map2.SetMovingLeft(true);
		if (stage == 3)
			map3.SetMovingLeft(true);
		if (hero_pos.getX() > 100) {
			if (stage == 1) {
				portal1X += 8;
				portal.SetTopLeft(portal1X, 410);
			}
			if (stage == 2) {
				portal2X += 8;
				portal.SetTopLeft(portal2X, 550);
			}
			if (stage == 3) {
				portal3X += 8;
				portal.SetTopLeft(portal3X, 450);
			}
		}
	}
	else {
		if (stage == 1)
			map1.SetMovingLeft(false);
		if (stage == 2)
			map2.SetMovingLeft(false);
		if (stage == 3)
			map3.SetMovingLeft(false);
	}
	if (character->getX() >= 1164 && character->ifMovingRight()) {
		if (stage == 1)
			map1.SetMovingRight(true);
		if (stage == 2)
			map2.SetMovingRight(true);
		if (stage == 3)
			map3.SetMovingRight(true);
		if (hero_pos.getX() < 2204) {
			if (stage == 1) {
				portal1X -= 8;
				portal.SetTopLeft(portal1X, 410);
			}
			if (stage == 2) {
				portal2X -= 8;
				portal.SetTopLeft(portal2X, 500);
			}
			if (stage == 3) {
				portal3X -= 8;
				portal.SetTopLeft(portal3X, 450);
			}
		}
	}
	else {
		if (stage == 1)
			map1.SetMovingRight(false);
		if (stage == 2)
			map2.SetMovingRight(false);
		if (stage == 3)
			map3.SetMovingRight(false);
	}

	// �H�����ʬ���
	if (hero_pos.getX() <= 100) {
		character->SetXY(100, character->getY());
	}
	else if (hero_pos.getX() >= 2204) {
		character->SetXY(1164, character->getY());
	}

	// �a�O�P�w����
	int flag = 0;
	for (int i = 0; i < 8; i++) {
		if (stage == 1) {
			if (ON_PLATFORM_STAGE1) 
				character->SetFloor(570 - map1.getFloorY(i));
			else 
				flag++;
		}
		if (stage == 2) {
			if (ON_PLATFORM_STAGE2) 
				character->SetFloor(570 - map2.getFloorY(i));
			else
				flag++;
		}
		if (stage == 3) {
			if (ON_PLATFORM_STAGE3) 
				character->SetFloor(570 - map3.getFloorY(i));
			else
				flag++;
		}
	}

	if (flag == 8) {
		character->SetFloor(570);
	}

	// ���a���Ŭ���
	if (character->GetXP() >= 100) {
		character->SetXP(0);
		character->SetLevel(character->GetLevel() + 1);
		character->SetMaxHP(character->GetMaxHP() + character->GetLevel() * 50);
	}

	// ���a�ޯ����
	if (slash_cd <= 299) {
		slash_cd--;
		if (slash_cd == 0)
			slash_cd = 300;
	}

	// ���a���`����
	if (character->GetHP() <= 0)
		GotoGameState(GAME_STATE_OVER);

	for (size_t i = 0; i < monster.size(); i++) {
		Position monster_pos(monster[i], map1);
		monster[i]->OnMove();

		// �H�����ʬ���
		if (character->getX() <= 100 && character->ifMovingLeft()) {
			if (hero_pos.getX() <= 110) {
				monster[i]->SetMovingLeft(false);
			}
			else {
				monster[i]->SetMovingLeft(true);
			}
		}
		else {
			monster[i]->SetMovingLeft(false);
		}
		if (character->getX() >= 1164 && character->ifMovingRight()) {
			if (hero_pos.getX() >= 2200) {
				monster[i]->SetMovingRight(false);
			}
			else {
				monster[i]->SetMovingRight(true);
			}
		}
		else {
			monster[i]->SetMovingRight(false);
		}

		// �Ǫ����ʬ���
		if (monster_pos.getX() >= hero_pos.getX()) {
			monster[i]->Set_Monster_Go_Left(true);
			monster[i]->Set_Monster_Go_Right(false);
		}
		else {
			monster[i]->Set_Monster_Go_Right(true);
			monster[i]->Set_Monster_Go_Left(false);
		}

		// �������ʬ���
		if (MONSTER_HIT_CHARACTER) {
			if (HIT_CHECK_CHARACTER) {
				if (HEIGHT_CHECK) {
					monster[i]->SetAttacking(true);
					character->SetHP(character->GetHP() - monster[i]->GetAttack());
					if (monster_pos.getX() >= hero_pos.getX())
						character->SetHitLeft();
					else if (monster_pos.getX() < hero_pos.getX())
						character->SetHitRight();
				}
			}
		}
		if (CHARACTER_HIT_MONSTER) {
			if (HIT_CHECK_MONSTER) {
				if (HEIGHT_CHECK) {
					monster[i]->SetHP(monster[i]->GetHP() - character->GetAttack());
					if (character->GetFacing() == 2)
						monster[i]->SetHitLeft();
					else if (character->GetFacing() == 1)
						monster[i]->SetHitRight();
				}
			}
		}
		if (CHARACTER_SLASH_MONSTER) {
			if (HIT_CHECK_MONSTER) {
				if (SLASH_HEIGHT_CHECK) {
					monster[i]->SetHP(monster[i]->GetHP() - character->GetAttack() * 2);
					if (monster_pos.getX() >= hero_pos.getX())
						monster[i]->SetHitRight();
					else
						monster[i]->SetHitLeft();
				}
			}
		}

		// �Ǫ����`����
		if (monster[i]->GetHP() <= 0) {
			character->SetXP(character->GetXP() + monster[i]->GetXP());
			monster.erase(monster.begin() + i);
		}
	}
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
	//
	// �}�l���J���
	//
	for (size_t i = 0; i < monster.size(); i++) {
		monster[i]->LoadBitmap();
	}
	character->LoadBitmap();
	map1.LoadBitmap();					// ���J�I�����ϧ�
	map2.LoadBitmap();
	map3.LoadBitmap();
	//
	// ��������Loading�ʧ@�A�����i��
	//
	ShowInitProgress(50);
	//
	// �~����J��L���
	//
	ShowInitProgress(100);
}

int map_position[] = { 0, 0 };

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
	const char KEY_Z = 0x5A; // keyboard Z
	const char KEY_X = 0x58; // keyboard X
	Position hero_pos(character, map1);

	if (nChar == KEY_Z) {
		character->SetAttacking(true);
	}

	if (nChar == KEY_X) {
		if (slash_cd == 300) {
			character->SetSlashing(true);
			slash_cd--;
		}
	}

	if (nChar == KEY_LEFT) {
		character->SetMovingLeft(true);
		character->SetFacing(2);
	}
	
	if (nChar == KEY_RIGHT) {
		character->SetMovingRight(true);
		character->SetFacing(1);
	}

	if (nChar == KEY_UP) {
		if (monster.size() == 0) {
			if (stage == 1) {
				if (IN_PORTAL1)
					stage++;
				else
					character->SetMovingUp(true);
			}
			if (stage == 2) {
				if (IN_PORTAL2)
					stage++;
				else
					character->SetMovingUp(true);
			}
			if (stage == 3) {
				if (IN_PORTAL3)
					stage++;
				else
					character->SetMovingUp(true);
			}
		}else
			character->SetMovingUp(true);
	}
	if (nChar == KEY_DOWN) {
		character->SetMovingDown(true);
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_LEFT  = 0x25; // keyboard���b�Y
	const char KEY_UP    = 0x26; // keyboard�W�b�Y
	const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
	const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
	const char KEY_Z = 0x5A; // keyboard Z

	if (nChar == KEY_Z) {
		character->SetAttacking(false);

	}
	if (nChar == KEY_LEFT) {
		character->SetMovingLeft(false);
		map1.SetMovingRight(false);
	}
	if (nChar == KEY_RIGHT) {
		character->SetMovingRight(false);
		map1.SetMovingLeft(false);
	}
	if (nChar == KEY_UP)
		character->SetMovingUp(false);
	if (nChar == KEY_DOWN)
		character->SetMovingDown(false);
}

/*
		�B�z�ƹ����ʧ@
*/

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)
{
	// �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)
{
}

void CGameStateRun::OnShow()
{
	if (stage == 1) {
		map1.OnShow();			// �K�W�I����
		if (monster.size() == 0)
			portal.OnShow();
	}
	if (stage == 2) {
		if (stage_count == 2) {
			initHero(*character);
			portal.SetTopLeft(portal2X, 550);
			//monster.push_back(new Monster(500, 570, 50));
			//monster.push_back(new Monster(800, 570, 50));
			stage_count++;
		}
		map2.OnShow();			// �K�W�I����
		if (monster.size() == 0)
			portal.OnShow();
	}
	if (stage == 3) {
		if (stage_count == 3) {
			initHero(*character);
			portal.SetTopLeft(portal3X, 450);
			//monster.push_back(new Monster(500, 570, 50));
			//monster.push_back(new Monster(800, 570, 50));
			stage_count++;
		}
		map3.OnShow();			// �K�W�I����
		if (monster.size() == 0)
			portal.OnShow();
	}
	for (size_t i = 0; i < monster.size(); i++) {
		monster[i]->OnShow();
	}
	character->OnShow();			// �K�W�H��
}
}