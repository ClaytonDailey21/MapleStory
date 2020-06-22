#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

namespace game_framework {
	CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
	{
	}

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����}�l���A(Begin)
	/////////////////////////////////////////////////////////////////////////////

	void CGameStateInit::OnInit()
	{
		ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
		CAudio::Instance()->Load(BGM_MENU, "sounds\\bgm_menu.mp3");					// ���BGM
		CAudio::Instance()->Play(BGM_MENU, true);									// �}�l������BGM
		CAudio::Instance()->Load(BGM_STAGE1, "sounds\\bgm_stage1.mp3");				// �Ĥ@��BGM
		CAudio::Instance()->Load(BGM_STAGE2, "sounds\\bgm_stage2.mp3");				// �ĤG��BGM
		CAudio::Instance()->Load(BGM_STAGE3, "sounds\\bgm_stage3.mp3");				// �ĤT��BGM
		CAudio::Instance()->Load(BGM_BOSS, "sounds\\bgm_boss.mp3");					// BOSS��BGM
		CAudio::Instance()->Load(BGM_GAMEOVER, "sounds\\bgm_gameover.mp3");			// GameOver BGM
		CAudio::Instance()->Load(BGM_CLEAR, "sounds\\bgm_clear.mp3");				// �q�� BGM
		CAudio::Instance()->Load(SFX_JUMP, "sounds\\sfx_jump.mp3");					// ���D �ĪG��
		CAudio::Instance()->Load(SFX_ATTACK, "sounds\\sfx_attack.mp3");				// ���� �ĪG��
		CAudio::Instance()->Load(SFX_SLASH, "sounds\\sfx_slash.mp3");				// �}�ű� �ĪG��
		CAudio::Instance()->Load(SFX_HEAL, "sounds\\sfx_heal.mp3");					// �^�K�N �ĪG��
		CAudio::Instance()->Load(SFX_HERO_HIT, "sounds\\sfx_hero_hit.mp3");			// �Q�R�� �ĪG��
		CAudio::Instance()->Load(SFX_MONSTER_HIT, "sounds\\sfx_monster_hit.mp3");	// �R���Ǫ� �ĪG��
		CAudio::Instance()->Load(SFX_GUN, "sounds\\sfx_gun.mp3");					// �j�n �ĪG��
		CAudio::Instance()->Load(SFX_LEVEL_UP, "sounds\\sfx_levelup.mp3");			// �ɯ� �ĪG��
		CAudio::Instance()->Load(SFX_ROOT, "sounds\\sfx_root.mp3");					// �w�� �ĪG��
		CAudio::Instance()->Load(SFX_LASER, "sounds\\sfx_laser.mp3");				// BOSS �p�g �ĪG��
		CAudio::Instance()->Load(SFX_LIGHTING, "sounds\\sfx_lighting.mp3");			// BOSS �{�q �ĪG��
		CAudio::Instance()->Load(SFX_KNOCKBACK, "sounds\\sfx_knockback.mp3");		// BOSS ���h �ĪG��

		menu = 1;			// ���w�]��� �}�l�C��

		ShowInitProgress(5);

		logo.LoadBitmap(IDB_LOGO);													// 
		info.LoadBitmap(IDB_INFO);													//
		start1.LoadBitmap(IDB_START1, RGB(255, 255, 255));							//
		start2.LoadBitmap(IDB_START2, RGB(255, 255, 255));							// ���J����Bitmap
		exit1.LoadBitmap(IDB_EXIT1, RGB(255, 255, 255));							//
		exit2.LoadBitmap(IDB_EXIT2, RGB(255, 255, 255));							//
		info1.LoadBitmap(IDB_INFO1, RGB(255, 255, 255));							//
		info2.LoadBitmap(IDB_INFO2, RGB(255, 255, 255));							//

		ShowInitProgress(10);
	}

	void CGameStateInit::OnBeginState()
	{
	}

	void CGameStateInit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ENTER = 0x0D;	// Enter
		const char KEY_LEFT = 0x25;		// keyboard���b�Y
		const char KEY_UP = 0x26;		// keyboard�W�b�Y
		const char KEY_DOWN = 0x28;		// keyboard�U�b�Y

		if (nChar == KEY_ENTER && menu == 1 && ifInfoOn == 0)				// ��ܶ}�l�C����
		{
			GotoGameState(GAME_STATE_RUN);
		}

		if (nChar == KEY_ENTER && menu == 2 && ifInfoOn == 0)				// ��ܾާ@����
		{
			ifInfoOn = 1;
		}

		if (nChar == KEY_LEFT && ifInfoOn == 1)								// �q�ާ@������^
		{
			ifInfoOn = 0;
		}

		if (nChar == KEY_ENTER && menu == 3 && ifInfoOn == 0)				// ������}�C��
		{
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
		}

		if (nChar == KEY_DOWN && ifInfoOn == 0)								// ��橹�U
		{
			if (menu < 3)
				menu++;
		}

		if (nChar == KEY_UP && ifInfoOn == 0) 								// ��橹�W
		{
			if (menu > 1)
				menu--;
		}

	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
	}

	void CGameStateInit::OnShow()
	{
		if (ifInfoOn == 1)							// �i�J�ާ@�������u����ܾާ@����
		{
			info.SetTopLeft(0, 0);
			info.ShowBitmap();
		}
		else
		{
			logo.SetTopLeft(0, 0);					// ��D�e������ܥD�e���I��
			logo.ShowBitmap();

			if (menu == 1)							// ��ܶ}�l�C���ɤT�ӫ��s���K��
			{
				start2.SetTopLeft(483, 350);
				start2.ShowBitmap();
				info1.SetTopLeft(483, 460);
				info1.ShowBitmap();
				exit1.SetTopLeft(483, 570);
				exit1.ShowBitmap();
			}

			if (menu == 2)							// ��ܾާ@�����ɤT�ӫ��s���K��
			{
				start1.SetTopLeft(483, 350);
				start1.ShowBitmap();
				info2.SetTopLeft(483, 460);
				info2.ShowBitmap();
				exit1.SetTopLeft(483, 570);
				exit1.ShowBitmap();
			}

			if (menu == 3)							// ������}�C���ɤT�ӫ��s���K��
			{
				start1.SetTopLeft(483, 350);
				start1.ShowBitmap();
				info1.SetTopLeft(483, 460);
				info1.ShowBitmap();
				exit2.SetTopLeft(483, 570);
				exit2.ShowBitmap();
			}
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	/////////////////////////////////////////////////////////////////////////////

	CGameStateOver::CGameStateOver(CGame *g) : CGameState(g)
	{
	}

	void CGameStateOver::OnMove()
	{
		if (!gameClear)
			Gameover.OnMove();										// �Y�S�q���h���� GameOver �ʵe
		counter--;
		if (counter < 0) 										// �˼Ƶ�����^��D��� + ���� BGM
		{
			CAudio::Instance()->Play(BGM_MENU, true);
			GotoGameState(GAME_STATE_INIT);
		}
	}

	void CGameStateOver::OnBeginState()
	{
		counter = 30 * 7;											// �S�q���|�˼� 7 seconds								
		clearTime = timeCounter / 30;								// �x�s�q���ɶ�

		CAudio::Instance()->Stop(BGM_STAGE1);						// �����Ҧ��C���� BGM
		CAudio::Instance()->Stop(BGM_STAGE2);
		CAudio::Instance()->Stop(BGM_STAGE3);
		CAudio::Instance()->Stop(BGM_BOSS);
		CAudio::Instance()->Stop(SFX_ATTACK);

		if (!gameClear)
			CAudio::Instance()->Play(BGM_GAMEOVER, false);			// �Y�S�q���|���� GameOver ����
		else
		{
			counter = 30 * 13;										// ���q���|�˼� 13 seconds
			CAudio::Instance()->Play(BGM_CLEAR, false);				// �Y�q���|���� Clear ����
		}
	}

	void CGameStateOver::OnInit()
	{

		int over[] = { IDB_GAME_OVER_0 ,IDB_GAME_OVER_1 ,IDB_GAME_OVER_2 ,IDB_GAME_OVER_3,			// 
					   IDB_GAME_OVER_4 ,IDB_GAME_OVER_5 ,IDB_GAME_OVER_6 ,IDB_GAME_OVER_7,			//
					   IDB_GAME_OVER_8 ,IDB_GAME_OVER_9 ,IDB_GAME_OVER_10,IDB_GAME_OVER_11,			//
					   IDB_GAME_OVER_12,IDB_GAME_OVER_13,IDB_GAME_OVER_14,IDB_GAME_OVER_0,			//
					   IDB_GAME_OVER_0 ,IDB_GAME_OVER_0 ,IDB_GAME_OVER_0 ,IDB_GAME_OVER_0,			//
					   IDB_GAME_OVER_0 };															// Gameover �ʵe�]�w
		int number_bitmaps[] = { IDB_0,IDB_1,IDB_2,IDB_3,IDB_4,IDB_5,IDB_6,IDB_7,IDB_8,IDB_9 };		//
		for (int i = 0; i < 10; i++)																//
			num[i].AddBitmap(number_bitmaps[i], RGB(230, 212, 132));								//
		Gameover = CAnimation(10);																	//
		for (int i = 0; i < 21; i++)																//
			Gameover.AddBitmap(over[i], RGB(255, 255, 255));										//

		clear_info.LoadBitmap(IDB_CLEAR_INFO);														// �q���I���ϳ]�w

		ShowInitProgress(15);
	}

	void CGameStateOver::OnShow()
	{
		if (gameClear)
		{
			clear_info.SetTopLeft(0, 0);							//
			clear_info.ShowBitmap();								//
			number_OnShow(clearTime / 60 / 10, 678, 215);			// �q������ܹL���Ϥ� + �ɶ�
			number_OnShow(clearTime / 60 % 10, 678 + 20, 215);		//
			number_OnShow(clearTime % 60 / 10, 778, 215);			//
			number_OnShow(clearTime % 60 % 10, 778 + 20, 215);		//
		}
		else 														// �S�L������� GameOver �ʵe
		{
			Gameover.SetTopLeft(233, 234);
			Gameover.OnShow();
		}
	}

	void CGameStateOver::number_OnShow(int nx, int pos_nx, int pos_ny)		// �K�W 0~9 �Ʀr bmp ��
	{
		num[nx].SetTopLeft(pos_nx, pos_ny);
		num[nx].OnShow();
	}



	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	/////////////////////////////////////////////////////////////////////////////

	CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
	{
	}

	CGameStateRun::~CGameStateRun()				// �Ѻc����O����
	{
		delete hero;
		for (auto i : monster1)
			delete i;
		for (auto i : monster2)
			delete i;
		for (auto i : monster3)
			delete i;
		monster1.clear();
		monster2.clear();
		monster3.clear();
		maps.clear();
	}

	void CGameStateRun::OnBeginState()			// �}�l�C���ɪ�l�Ƥ��U���]�w
	{
		gameClear = false;
		stage = 1;
		timeCounter = 0;
		stage_count = stage;
		initHero(*hero);
		for (int i = 0; i < 4; i++)
			maps[i].setInitXY(0, 0);
		initMonster1(monster1);
		initMonster2(monster2);
		initMonster3(monster3);
		boss.setXY(1550, 220);
		boss.setHP(boss.getMaxHP());

		CAudio::Instance()->Stop(BGM_MENU);				// ����D��� BGM
		CAudio::Instance()->Play(BGM_STAGE1, true);		// �}�l�Ĥ@�� BGM
	}

	void CGameStateRun::OnMove()
	{
		checkStage();						// �T�{��e���d
		hero->OnMove();						// ���ʨ���
		map->OnMove();						// ���ʦa��
		map->getPortal().OnMove();			// ���ʶǰe��
		timeCounter++;						// �p�ɾ��ϥ�
		hero_pos.setPosition(hero, *map);	// ���⤧��e�y�Шt��

		// �a�ϲ��ʬ�������]�w
		if (hero->getX() <= 300 && hero->ifMovingLeft() || hero->getX() <= 300 && hero->ifHitLeft())
			map->setMovingLeft(true);
		else
			map->setMovingLeft(false);
		if (hero->getX() >= 964 && hero->ifMovingRight() || hero->getX() >= 964 && hero->ifHitRight())
			map->setMovingRight(true);
		else
			map->setMovingRight(false);

		// �H�����ʦb�e���W����ܮĪG
		if (map->getX() == 0)
		{
			if (hero->getX() <= 10)
				hero->setXY(10, hero->getY());
		}
		else if (hero->getX() <= 300)
			hero->setXY(300, hero->getY());

		if (map->getX() == -1024)
		{
			if (hero->getX() >= 1280)
				hero->setXY(1280, hero->getY());
		}
		else if (hero->getX() >= 980)
			hero->setXY(980, hero->getY());

		// �a�O�P�w�ϥ�
		int flag = 0;

		for (int i = 0; i < 8; i++)
		{
			if (ON_FLOOR)
				hero->setFloor(570 - map->getFloorY(i));
			else
				flag++;
		}

		if (flag == 8)
			hero->setFloor(570);

		// ���a���šB�ɵ��B�ƭ��ܤ�
		if (hero->getLevel() < 20)
		{
			if (hero->getXP() >= hero->getLevel() * 50)
			{
				hero->setXP(0);
				CAudio::Instance()->Play(SFX_LEVEL_UP, false);
				hero->setLevelUP();
				hero->setLevel(hero->getLevel() + 1);
				hero->setMaxHP(hero->getMaxHP() + hero->getLevel() * 50);
				hero->setAttack(hero->getAttack() + hero->getLevel() * 5);
			}
		}

		// ���a�ޯ�˼�
		hero->countdown();

		// ���a�P�Ǫ����ʬ���
		if (stage <= 3)
		{
			for (auto m : *monster)
				m->countdown();
			heroMonsterInteraction(*hero, *monster, *map);
		}

		// ���a�PBOSS���ʬ���
		if (stage == 4)
		{
			boss.countdown();
			heroBossInteraction(*hero, boss, *map);
		}

		// ���a���`����
		if (hero->getHP() <= 0)
			GotoGameState(GAME_STATE_OVER);

	}

	void CGameStateRun::OnInit() {

		// �]�w Hero ����Ҧ��һݶK��
		hero = new Hero;
		vector<int> hero_goLeft = { IDB_FROG_GO_LEFT1,IDB_FROG_GO_LEFT2, IDB_FROG_STAND_LEFT };
		vector<int> hero_goRight = { IDB_FROG_GO_RIGHT1,IDB_FROG_GO_RIGHT2, IDB_FROG_STAND_RIGHT };
		vector<int> hero_attackRight = { IDB_FROG_ATTACK_RIGHT1, IDB_FROG_ATTACK_RIGHT2, IDB_FROG_ATTACK_RIGHT3,
								  IDB_FROG_ATTACK_RIGHT4, IDB_FROG_ATTACK_RIGHT5, IDB_FROG_ATTACK_RIGHT6 };
		vector<int> hero_attackLeft = { IDB_FROG_ATTACK_LEFT1, IDB_FROG_ATTACK_LEFT2, IDB_FROG_ATTACK_LEFT3,
								 IDB_FROG_ATTACK_LEFT4, IDB_FROG_ATTACK_LEFT5, IDB_FROG_ATTACK_LEFT6 };
		vector<int> slash = { IDB_SLASH_01, IDB_SLASH_02, IDB_SLASH_03, IDB_SLASH_04,
					IDB_SLASH_05, IDB_SLASH_06, IDB_SLASH_07, IDB_SLASH_08,
					IDB_SLASH_09, IDB_SLASH_10, IDB_SLASH_11, IDB_SLASH_12,
					IDB_SLASH_13 };
		vector<int> lv_up = { IDB_LV_UP_01, IDB_LV_UP_02, IDB_LV_UP_03, IDB_LV_UP_04, IDB_LV_UP_05
							, IDB_LV_UP_06, IDB_LV_UP_07, IDB_LV_UP_08, IDB_LV_UP_09, IDB_LV_UP_10
							, IDB_LV_UP_11, IDB_LV_UP_12, IDB_LV_UP_13, IDB_LV_UP_14, IDB_LV_UP_15
							, IDB_LV_UP_16, IDB_LV_UP_17, IDB_LV_UP_18, IDB_LV_UP_19, IDB_LV_UP_20 };

		vector<int> heal = { IDB_HEAL_01, IDB_HEAL_02, IDB_HEAL_03, IDB_HEAL_04, IDB_HEAL_05,
							 IDB_HEAL_06, IDB_HEAL_07, IDB_HEAL_08, IDB_HEAL_09 };
		hero->addBitmap(
			IDB_FROG_STAND_RIGHT, IDB_FROG_STAND_LEFT,
			IDB_FROG_DOWN_RIGHT, IDB_FROG_DOWN_LEFT,
			IDB_FROG_JUMP_RIGHT, IDB_FROG_JUMP_LEFT,
			hero_goRight, hero_goLeft,
			hero_attackRight, hero_attackLeft, slash, heal, lv_up, 255, 255, 255);

		ShowInitProgress(20);

		// �]�w�Ĥ@���Ǫ��K�ϻP�Ǫ��ͩR�B�����O�B�g���
		monster1.push_back(new Monster(500, 570, 40));
		monster1.push_back(new Monster(350, 370, 40));
		monster1.push_back(new Monster(700, 280, 40));
		monster1.push_back(new Monster(750, 280, 40));
		monster1.push_back(new Monster(1000, -20, 40));
		monster1.push_back(new Monster(1300, 152, 40));
		monster1.push_back(new Monster(1500, 317, 40));
		monster1.push_back(new Monster(2000, 420, 40));
		monster1.push_back(new Monster(2100, -20, 40));

		for (auto monster : monster1)
		{
			vector<int> attackRight = { IDB_MONSTER_ATTACK_RIGHT1,IDB_MONSTER_ATTACK_RIGHT2, IDB_MONSTER_ATTACK_RIGHT3 };
			vector<int> attackLeft = { IDB_MONSTER_ATTACK_LEFT1,IDB_MONSTER_ATTACK_LEFT2, IDB_MONSTER_ATTACK_LEFT3 };
			vector<int> goRight;
			vector<int> goLeft;
			vector<int> slash;
			monster->addBitmap(
				IDB_MONSTER_STAND_RIGHT, IDB_MONSTER_STAND_LEFT,
				0, 0, 0, 0,
				goRight, goLeft,
				attackRight, attackLeft, slash, heal, lv_up, 255, 255, 255);
		}

		ShowInitProgress(35);

		// �]�w�ĤG���Ǫ��K�ϻP�Ǫ��ͩR�B�����O�B�g���
		monster2.push_back(new Monster(500, 570, 70));
		monster2.push_back(new Monster(800, 570, 70));
		monster2.push_back(new Monster(1000, 570, 70));
		monster2.push_back(new Monster(1100, 570, 70));
		monster2.push_back(new Monster(1300, 570, 70));
		monster2.push_back(new Monster(2000, 570, 70));
		monster2.push_back(new Monster(700, 452, 70));
		monster2.push_back(new Monster(1600, 378, 70));
		monster2.push_back(new Monster(1900, 570 - 323, 70));
		monster2.push_back(new Monster(1700, 570 - 441, 70));
		monster2.push_back(new Monster(1200, 570 - 560, 70));
		monster2.push_back(new Monster(700, 570 - 513, 70));
		monster2.push_back(new Monster(400, 570 - 390, 70));
		monster2.push_back(new Monster(1900, 570 - 568, 70));

		for (auto monster = monster2.begin(); monster < monster2.end(); monster++)
		{
			vector<int> attackRight = { IDB_GUNER_ATTACK_RIGHT1,IDB_GUNER_ATTACK_RIGHT2, IDB_GUNER_ATTACK_RIGHT3 };
			vector<int> attackLeft = { IDB_GUNER_ATTACK_LEFT1,IDB_GUNER_ATTACK_LEFT2, IDB_GUNER_ATTACK_LEFT3 };
			vector<int> goRight;
			vector<int> goLeft;
			vector<int> slash;
			(*monster)->addBitmap(
				IDB_GUNER_STAND_RIGHT, IDB_GUNER_STAND_LEFT,
				0, 0, 0, 0,
				goRight, goLeft,
				attackRight, attackLeft, slash, heal, lv_up, 255, 255, 255);
		}

		ShowInitProgress(50);

		// �]�w�ĤT���Ǫ��K�ϻP�Ǫ��ͩR�B�����O�B�g���
		monster3.push_back(new Monster(100, 570 - 166, 150));
		monster3.push_back(new Monster(300, 570 - 166, 150));
		monster3.push_back(new Monster(500, 570 - 166, 150));
		monster3.push_back(new Monster(700, 570 - 166, 150));
		monster3.push_back(new Monster(900, 570 - 166, 150));
		monster3.push_back(new Monster(1500, 570 - 166, 150));
		monster3.push_back(new Monster(1700, 570 - 166, 150));
		monster3.push_back(new Monster(1900, 570 - 166, 150));
		monster3.push_back(new Monster(2100, 570 - 166, 150));
		monster3.push_back(new Monster(200, 570 - 496, 150));
		monster3.push_back(new Monster(400, 570 - 496, 150));
		monster3.push_back(new Monster(600, 570 - 496, 150));
		monster3.push_back(new Monster(800, 570 - 496, 150));
		monster3.push_back(new Monster(1400, 570 - 494, 150));
		monster3.push_back(new Monster(1600, 570 - 494, 150));
		monster3.push_back(new Monster(1800, 570 - 494, 150));
		monster3.push_back(new Monster(2000, 570 - 494, 150));
		monster3.push_back(new Monster(2200, 570 - 494, 150));

		PoisonRoot.LoadBitmap(IDB_POISON_ROOT, RGB(255, 255, 255));		// �ĤT���Ǫ��ޯ�ĪG�K��

		for (auto monster = monster3.begin(); monster < monster3.end(); monster++)
		{
			vector<int> attackRight = { IDB_MAGE_ATTACK_RIGHT1, IDB_MAGE_ATTACK_RIGHT2, IDB_MAGE_ATTACK_RIGHT3,
										IDB_MAGE_ATTACK_RIGHT4, IDB_MAGE_ATTACK_RIGHT5, IDB_MAGE_ATTACK_RIGHT6,
										IDB_MAGE_ATTACK_RIGHT7, IDB_MAGE_ATTACK_RIGHT8 };
			vector<int> attackLeft = { IDB_MAGE_ATTACK_LEFT1, IDB_MAGE_ATTACK_LEFT2, IDB_MAGE_ATTACK_LEFT3,
										IDB_MAGE_ATTACK_LEFT4, IDB_MAGE_ATTACK_LEFT5, IDB_MAGE_ATTACK_LEFT6,
										IDB_MAGE_ATTACK_LEFT7, IDB_MAGE_ATTACK_LEFT8 };
			vector<int> goRight;
			vector<int> goLeft;
			vector<int> slash = { IDB_POISON_01, IDB_POISON_02, IDB_POISON_03, IDB_POISON_04, IDB_POISON_05,
						 IDB_POISON_06, IDB_POISON_07, IDB_POISON_08, IDB_POISON_09, IDB_POISON_10,
						 IDB_POISON_11, IDB_POISON_12, IDB_POISON_13, IDB_POISON_14, IDB_POISON_15,
						 IDB_POISON_16, IDB_POISON_17, IDB_POISON_18, IDB_POISON_19, IDB_POISON_20 };;
			(*monster)->addBitmap(
				IDB_MAGE_STAND_RIGHT, IDB_MAGE_STAND_LEFT,
				0, 0, 0, 0,
				goRight, goLeft,
				attackRight, attackLeft, slash, heal, lv_up, 0, 0, 0, 4);
		}
		ShowInitProgress(65);

		ShowInitProgress(80);

		// �]�wBOSS�~�[�K�ϡB�ޯ�K��
		boss.addBitmap();
		boss.Initialize();

		Boss_laser_delay = CAnimation(5);
		Boss_laser = CAnimation(5);
		Boss_knockback_delay = CAnimation(5);
		Boss_knockback = CAnimation(2);
		Boss_lighting_delay1 = CAnimation(5);
		Boss_lighting_delay2 = CAnimation(5);
		Boss_lighting1 = CAnimation(6);
		Boss_lighting2 = CAnimation(6);

		int laser_delay_bitmaps[] = { IDB_LASER_01, IDB_LASER_02, IDB_LASER_03,
									  IDB_LASER_04, IDB_LASER_05, IDB_LASER_06 };
		for (int i = 0; i < 6; i++)
			Boss_laser_delay.AddBitmap(laser_delay_bitmaps[i], RGB(255, 255, 255));

		int laser_bitmaps[] = { IDB_LASER_07, IDB_LASER_08, IDB_LASER_09, IDB_LASER_10, IDB_LASER_11,
								IDB_LASER_12, IDB_LASER_13, IDB_LASER_14, IDB_LASER_15, IDB_LASER_16 };
		for (int i = 0; i < 10; i++)
			Boss_laser.AddBitmap(laser_bitmaps[i], RGB(255, 255, 255));

		int knockback_delay_bitmaps[] = { IDB_KNOCK_00, IDB_KNOCK_01, IDB_KNOCK_02,
										  IDB_KNOCK_03, IDB_KNOCK_04, IDB_KNOCK_05 };
		for (int i = 0; i < 6; i++)
			Boss_knockback_delay.AddBitmap(knockback_delay_bitmaps[i], RGB(255, 255, 255));

		int knockback_bitmaps[] = { IDB_KNOCK_06, IDB_KNOCK_07, IDB_KNOCK_08, IDB_KNOCK_09 };
		for (int i = 0; i < 4; i++)
			Boss_knockback.AddBitmap(knockback_bitmaps[i], RGB(255, 255, 255));

		int lighting_delay1_bitmaps[] = { IDB_LIGHTING_01, IDB_LIGHTING_02, IDB_LIGHTING_03,
										  IDB_LIGHTING_04, IDB_LIGHTING_05, IDB_LIGHTING_06 };
		for (int i = 0; i < 6; i++)
			Boss_lighting_delay1.AddBitmap(lighting_delay1_bitmaps[i], RGB(255, 255, 255));

		int lighting_delay2_bitmaps[] = { IDB_LIGHTING_07, IDB_LIGHTING_08, IDB_LIGHTING_09,
										  IDB_LIGHTING_10, IDB_LIGHTING_11, IDB_LIGHTING_12 };
		for (int i = 0; i < 6; i++)
			Boss_lighting_delay2.AddBitmap(lighting_delay2_bitmaps[i], RGB(255, 255, 255));

		int lighting1_bitmaps[] = { IDB_LIGHTING_13, IDB_LIGHTING_14, IDB_LIGHTING_15, IDB_LIGHTING_16, IDB_LIGHTING_17 };
		for (int i = 0; i < 5; i++)
			Boss_lighting1.AddBitmap(lighting1_bitmaps[i], RGB(255, 255, 255));

		int lighting2_bitmaps[] = { IDB_LIGHTING_18, IDB_LIGHTING_19, IDB_LIGHTING_20, IDB_LIGHTING_21, IDB_LIGHTING_22 };
		for (int i = 0; i < 5; i++)
			Boss_lighting2.AddBitmap(lighting2_bitmaps[i], RGB(255, 255, 255));

		ShowInitProgress(90);

		// �]�w�ǰe���P�a�϶K��
		int portal_bitmaps[] = { IDB_PORTAL_BLUE1,IDB_PORTAL_BLUE2 };
		int portal_boss_bitmaps[] = { IDB_PORTAL_PURPLE1,IDB_PORTAL_PURPLE2 };
		maps.push_back(Map1());
		maps.push_back(Map2());
		maps.push_back(Map3());
		maps.push_back(Map4());

		for (size_t i = 0; i < maps.size(); i++)
		{
			maps[i].LoadBitmap();
			if (i < 2)
				maps[i].getPortal().addBitMaps(portal_bitmaps, 2);
			if (i >= 2)
				maps[i].getPortal().addBitMaps(portal_boss_bitmaps, 2);
		}

		ShowInitProgress(95);

		// �ޯ�N�o�ɶ���ܥζK��
		int slash_cd_bitmaps[] = {
			IDB_SLASH_CD_1,IDB_SLASH_CD_2,IDB_SLASH_CD_3,
			IDB_SLASH_CD_4,IDB_SLASH_CD_5,IDB_SLASH_CD_6,
			IDB_SLASH_CD_7,IDB_SLASH_CD_8,IDB_SLASH_CD_0 };
		for (int i = 0; i < 9; i++)
			slashCD[i].LoadBitmap(slash_cd_bitmaps[i]);


		int heal_cd_bitmaps[] = {
			IDB_HEAL_CD_1,IDB_HEAL_CD_2, IDB_HEAL_CD_3,
			IDB_HEAL_CD_4,IDB_HEAL_CD_5, IDB_HEAL_CD_6,
			IDB_HEAL_CD_7,IDB_HEAL_CD_8, IDB_HEAL_CD_0 };
		for (int i = 0; i < 9; i++)
			healCD[i].LoadBitmap(heal_cd_bitmaps[i]);

		ShowInitProgress(100);
	}


	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		const char KEY_Z = 0x5A;	// keyboard Z
		const char KEY_Y = 0x59;	// keyboard Y
		const char KEY_X = 0x58;	 // keyboard X
		const char KEY_C = 0x43;	// keyboard C
		const char KEY_T = 0x54;	// keyboard T
		const char KEY_O = 0x4F;	// keyboard O
		const char KEY_Q = 0x51;	// keyboard Q
		Position hero_pos(hero, *map);	// ����y�ЧP�w��

		if (nChar == KEY_Z) 								// ���U Z �i������ü��񭵮�
		{
			hero->setAttacking(true);
			CAudio::Instance()->Play(SFX_ATTACK, true);
		}

		if (nChar == KEY_X) 								// ���U X �I��}�ű٨ü��񭵮�
		{
			if (hero->getCounter(slash).getCount() == 300)
			{
				hero->setSlashing(true);
				CAudio::Instance()->Play(SFX_SLASH, false);
				hero->getCounter(slash).start();
			}
		}

		if (nChar == KEY_C) 								// ���U C �I��^�K�N�ü��񭵮�
		{
			if (hero->getCounter(heal).getCount() == 600)
			{
				hero->setHealing(true);
				hero->setHP(hero->getMaxHP());
				CAudio::Instance()->Play(SFX_HEAL, false);
				hero->getCounter(heal).start();
			}
		}
		if (nChar == KEY_Y && stage <= 3) 					// ���U Y �����a�Ϥ��Ҧ��Ǫ�
		{
			for (auto i = monster->begin(); i < monster->end(); i++)
				(*i)->setDead(1);
		}
		if (nChar == KEY_Q)									// ���U Q ������o�g���
			hero->setXP(hero->getXP() + 100);

		if (nChar == KEY_T)									// ���U T �����i�J�U�@��
			stage++;

		if (nChar == KEY_O)									// ���U O �������h
			GotoGameState(GAME_STATE_OVER);

		if (nChar == KEY_LEFT)								// ���U����V������
		{
			hero->setMovingLeft(true);
			hero->setFacing(2);
		}

		if (nChar == KEY_RIGHT) 							// ���U�k��V�k����
		{
			hero->setMovingRight(true);
			hero->setFacing(1);
		}

		if (nChar == KEY_UP) 								// ���U�W����D
		{
			if (stage <= 3) 								// �Y�b�ǰe�����h�i�J�U�@��
			{
				if (monster_num(*monster) == 0 && ON_PORTAL)
				{
					stage++;
					return;
				}
			}
			if (hero->ifMovingUp() == false)
				CAudio::Instance()->Play(SFX_JUMP, false);
			hero->setMovingUp(true);
		}

		if (nChar == KEY_DOWN)								// ���U�U��w�U
			hero->setMovingDown(true);
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25;	// keyboard���b�Y
		const char KEY_UP = 0x26;	// keyboard�W�b�Y
		const char KEY_RIGHT = 0x27;	// keyboard�k�b�Y
		const char KEY_DOWN = 0x28;	// keyboard�U�b�Y
		const char KEY_Z = 0x5A;		// keyboard Z

		if (nChar == KEY_Z) 								// ��} Z ��������ð���񭵮�
		{
			hero->setAttacking(false);
			CAudio::Instance()->Stop(SFX_ATTACK);
		}

		if (nChar == KEY_LEFT)								// ��}���䰱���
		{
			hero->setMovingLeft(false);
			map->setMovingRight(false);
		}

		if (nChar == KEY_RIGHT) 							// ��}�k�䰱���
		{
			hero->setMovingRight(false);
			map->setMovingLeft(false);
		}

		if (nChar == KEY_UP)								// ��}�W��������D�P�w
			hero->setMovingUp(false);

		if (nChar == KEY_DOWN)								// ��}�U�䰱��w�U
			hero->setMovingDown(false);
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnShow()
	{
		checkStage();										// �T�{��e���d
		map->OnShow();										// �K�W�a��

		if (stage <= 3) 									// �b�DBOSS���d�ɡA�Ǫ�������|�϶ǰe���X�{
		{
			if (monster_num(*monster) == 0)
				map->portalOnShow();

			for (auto m : *monster) 						// �K�W�C�өǪ��A�b�ĤT���ɦh�@�ӧޯ�K�ϧP�w
			{
				m->OnShow();
				if ((m)->getCounter(is_poison).getCount() < 40)
				{
					PoisonRoot.SetTopLeft(hero->getX() - 30, hero->getY() - 10);
					PoisonRoot.ShowBitmap();
				}
			}
		}
		else if (stage == 4) 								// BOSS ������� BOSS + �Ҧ� BOSS �ޯ�K�ϧP�w
		{
			boss.OnShow();

			if (boss.getCounter(laser_delay).getCount() < 30)
			{
				Boss_laser_delay.SetTopLeft(0, 580);
				Boss_laser_delay.OnShow();
			}

			if (boss.getCounter(laser_skill).getCount() < 50)
			{
				Boss_laser.SetTopLeft(0, 580);
				Boss_laser.OnShow();
			}

			if (boss.getCounter(knockback_delay).getCount() < 60)
			{
				Boss_knockback_delay.SetTopLeft(boss.getX() - 200, 0);
				Boss_knockback_delay.OnShow();
			}

			if (boss.getCounter(knockback_skill).getCount() < 8)
			{
				Boss_knockback.SetTopLeft(boss.getX() - 200, 0);
				Boss_knockback.OnShow();
			}

			if (boss.getCounter(lighting_delay1).getCount() < 60)
			{
				Boss_lighting_delay1.SetTopLeft(boss.getX() - 1000, -20);
				Boss_lighting_delay1.OnShow();
			}

			if (boss.getCounter(lighting_skill1).getCount() < 30)
			{
				Boss_lighting1.SetTopLeft(boss.getX() - 1000, -20);
				Boss_lighting1.OnShow();
			}

			if (boss.getCounter(lighting_delay2).getCount() < 60)
			{
				Boss_lighting_delay2.SetTopLeft(boss.getX() - 1000, -20);
				Boss_lighting_delay2.OnShow();
			}

			if (boss.getCounter(lighting_skill2).getCount() < 30)
			{
				Boss_lighting2.SetTopLeft(boss.getX() - 1000, -20);
				Boss_lighting2.OnShow();
			}

			boss.showHPBar();
		}

		hero->OnShow();										// �K�W����ëO���b��L����W�h

		// �ޯ�N�o�ɶ��K�����
		int slash_part = hero->getCounter(slash).getCount() / (300 / 8);
		slashCD[slash_part].SetTopLeft(15, 125);
		slashCD[slash_part].ShowBitmap();

		int heal_part = hero->getCounter(heal).getCount() / (600 / 8);
		healCD[heal_part].SetTopLeft(60, 125);
		healCD[heal_part].ShowBitmap();
	}

	// �p���e�a�ϩǪ����`�ƶq
	inline int CGameStateRun::monster_num(vector<Character*>monsters)
	{
		int n = 0;

		for (auto monster = monsters.begin(); monster < monsters.end(); monster++)
			if (!(*monster)->ifDead())
				n++;

		return n;
	}

	// ���a�P�Ǫ������ʨ禡
	void CGameStateRun::heroMonsterInteraction(Character&hero, vector<Character*> & monsters, Map &map)
	{

		for (auto monster = monsters.begin(); monster < monsters.end(); monster++)
		{
			if ((*monster)->ifDead())
				continue;

			Position monster_pos(*monster, map);			// �^���Ǫ��y��
			(*monster)->OnMove();							// �U�өǪ�����

			// �H�����ʨϩǪ��������ʬ���
			if (hero.getX() <= 300 && hero.ifMovingLeft() || hero.getX() <= 300 && hero.ifHitLeft())
			{
				if (hero_pos.getX() <= 310)
					(*monster)->setMovingLeft(false);
				else
					(*monster)->setMovingLeft(true);
			}
			else
				(*monster)->setMovingLeft(false);

			if (hero.getX() >= 964 && hero.ifMovingRight() || hero.getX() >= 964 && hero.ifHitRight())
			{
				if (hero_pos.getX() >= 2000)
					(*monster)->setMovingRight(false);
				else
					(*monster)->setMovingRight(true);
			}
			else
				(*monster)->setMovingRight(false);

			// �Ǫ��l�v���a����P�]�w����
			if (monster_pos.getX() - hero_pos.getX() >= (*monster)->getAttackRange() && monster_pos.getX() - hero_pos.getX() <= 500)
			{
				(*monster)->set_Monster_Go_Left(true);
				(*monster)->set_Monster_Go_Right(false);
			}
			else if (hero_pos.getX() - monster_pos.getX() >= (*monster)->getAttackRange() && hero_pos.getX() - monster_pos.getX() <= 500)
			{
				(*monster)->set_Monster_Go_Right(true);
				(*monster)->set_Monster_Go_Left(false);
			}
			else
			{
				(*monster)->set_Monster_Go_Right(false);
				(*monster)->set_Monster_Go_Left(false);
			}

			// �Ǫ����a�O�P�w����
			(*monster)->setFloor(570);

			for (int j = 0; j < 8; j++)
				if (ON_PLATFORM_MONSTER)
					(*monster)->setFloor(570 - map.getFloorY(j));

			// ���a�P�Ǫ��������ʬ���
			if (MONSTER_HIT_CHARACTER((*monster)->getAttackRange())) 		// ���a�O�_�b�Ǫ������d��
			{
				if (HIT_CHECK_CHARACTER && HEIGHT_CHECK) 					// ���a�O�_�b���˵L�Ī��A�P���קP�w
				{
					(*monster)->attacking(&hero);
					(*monster)->setAttacking(true);

					if (stage == 2)											// �ĤG���Ǫ��������j�n
						CAudio::Instance()->Play(SFX_GUN, false);

					if (stage != 3) 										// �ĤT���Ǫ����|�����G���|���ĪG���P���h�P�w
					{
						CAudio::Instance()->Play(SFX_HERO_HIT, false);

						if (monster_pos.getX() >= hero_pos.getX())
							hero.setHitLeft();

						else if (monster_pos.getX() < hero_pos.getX())
							hero.setHitRight();
					}
				}
				if (hero.getHP() <= 0)
					return;
			}

			if (CHARACTER_HIT_MONSTER)										// �Ǫ��O�_�b���a�����d��
			{
				if (HIT_CHECK_MONSTER && HEIGHT_CHECK)						// �Ǫ��O�_�b���˵L�Ī��A�P���קP�w
				{
					hero.attacking(*monster);
					CAudio::Instance()->Play(SFX_MONSTER_HIT, false);
				}
			}

			if (CHARACTER_SLASH_MONSTER)									// �Ǫ��O�_�b���a�}�ű٧ޯ�d��
			{
				if (HIT_CHECK_MONSTER && SLASH_HEIGHT_CHECK)				// �Ǫ��O�_�b���˵L�Ī��A�P���קP�w
				{
					hero.attacking(*monster);
					CAudio::Instance()->Play(SFX_MONSTER_HIT, false);
				}
			}

			// �Ǫ����`����
			if ((*monster)->getHP() <= 0)
			{
				hero.setXP(hero.getXP() + (*monster)->getXP());
				(*monster)->setDead(true);
				(*monster)->setXY(-1, -1);
			}
		}
	}

	// ���a�P BOSS �����ʨ禡
	void CGameStateRun::heroBossInteraction(Character& hero, Boss &mboss, Map &map)
	{
		mboss.OnMove();

		// �H�����ʨ� BOSS �������ʬ���
		if (hero.getX() <= 300 && hero.ifMovingLeft() || hero.getX() <= 300 && hero.ifHitLeft())
		{
			if (hero_pos.getX() <= 310)
				mboss.setMovingLeft(false);
			else
				mboss.setMovingLeft(true);
		}
		else
			mboss.setMovingLeft(false);

		if (hero.getX() >= 964 && hero.ifMovingRight() || hero.getX() >= 964 && hero.ifHitRight())
		{
			if (hero_pos.getX() >= 2000)
				mboss.setMovingRight(false);
			else
				mboss.setMovingRight(true);
		}
		else
			mboss.setMovingRight(false);

		// BOSS �Ҧ��ޯ઺�H���üƻP�˼ƾ���B�ˮ`�P�w����
		int skill = mboss.getSkill();									// ���o�����I�񤧧ޯ�

		if (skill == 1) 												// �U���I��p�g
		{
			if (mboss.getCounter(skills).getCount() == 149 && mboss.getCounter(laser_delay).getCount() == 30)
				mboss.getCounter(laser_delay).start();					// �Y�ޯ�N�o�ɶ������N�}�l�I��ޯ�

			if (mboss.getCounter(laser_delay).getCount() < 30)			// �ޯੵ������ʵe
				Boss_laser_delay.OnMove();

			if (mboss.getCounter(laser_delay).getCount() == 0)			// ���𧹲���ޯ�I��
			{
				mboss.getCounter(laser_skill).start();
				CAudio::Instance()->Play(SFX_LASER, false);
			}

			if (mboss.getCounter(laser_skill).getCount() < 50)			// �I��ޯ�᪺�ʵe�P�R������y���ˮ`
			{
				Boss_laser.OnMove();
				if (hero.ifMovingDown() == false)
					hero.setHP(hero.getHP() - 10);
			}
		}

		if (skill == 2)													// �U���I�����h
		{
			if (mboss.getCounter(skills).getCount() == 149 && mboss.getCounter(knockback_delay).getCount() == 60)
				mboss.getCounter(knockback_delay).start();				// �Y�ޯ�N�o�ɶ������N�}�l�I��ޯ�

			if (mboss.getCounter(knockback_delay).getCount() < 60)		// �ޯੵ������ʵe
				Boss_knockback_delay.OnMove();

			if (mboss.getCounter(knockback_delay).getCount() == 0)		// ���𧹲���ޯ�I��
			{
				mboss.getCounter(knockback_skill).start();
				CAudio::Instance()->Play(SFX_KNOCKBACK, false);
			}

			if (mboss.getCounter(knockback_skill).getCount() < 8)		// �I��ޯ�᪺�ʵe�P�R������y���ˮ`
			{
				Boss_knockback.OnMove();
				if (HIT_CHECK_CHARACTER && hero_pos.getX() >= 1300) {
					hero.setHitLeft();
					hero.setHP(hero.getHP() - 2000);
				}
			}
		}

		if (skill == 3)													// �U���I��{�q
		{
			if (mboss.getCounter(skills).getCount() == 149 && mboss.getCounter(lighting_delay1).getCount() == 60)
				mboss.getCounter(lighting_delay1).start();				// �Y�ޯ�N�o�ɶ������N�}�l�I��ޯ�

			if (mboss.getCounter(lighting_delay1).getCount() < 60) 		// �Ĥ@�q�ޯੵ������ʵe
				Boss_lighting_delay1.OnMove();

			if (mboss.getCounter(lighting_delay1).getCount() == 0)		// ���𧹲���Ĥ@�q�ޯ�I��
			{
				mboss.getCounter(lighting_skill1).start();
				mboss.getCounter(lighting_delay2).start();				// �P���P�ɲĤG�q�ޯੵ��}�l
				CAudio::Instance()->Play(SFX_LIGHTING, false);
			}
			if (mboss.getCounter(lighting_delay2).getCount() < 60)		// �ĤG�q�ޯੵ������ʵe
				Boss_lighting_delay2.OnMove();

			if (mboss.getCounter(lighting_skill1).getCount() < 30)		// �Ĥ@�q�ޯ઺�ʵe�P�R������y���ˮ`
			{
				Boss_lighting1.OnMove();
				for (int i = 0; i < 5; i++)
				{
					if (HIT_CHECK_CHARACTER && LIGHTING1_CHECK)
					{
						hero.setHitLeft();
						hero.setHP(hero.getHP() - 1000);
					}
				}
			}

			if (mboss.getCounter(lighting_delay2).getCount() == 0)		// ���𧹲���ĤG�q�ޯ�I��
			{
				mboss.getCounter(lighting_skill2).start();
				CAudio::Instance()->Play(SFX_LIGHTING, false);
			}

			if (mboss.getCounter(lighting_skill2).getCount() < 30)		// �ĤG�q�ޯ઺�ʵe�P�R������y���ˮ`
			{
				Boss_lighting2.OnMove();
				for (int i = 0; i < 5; i++)
				{
					if (HIT_CHECK_CHARACTER && LIGHTING2_CHECK)
					{
						hero.setHitLeft();
						hero.setHP(hero.getHP() - 1000);
					}
				}
			}
		}

		if (HIT_CHECK_CHARACTER && hero_pos.getX() >= 1550)				// ���a���� BOSS �R���P�w
		{
			hero.setHP(hero.getHP() - mboss.getAttack());
			CAudio::Instance()->Play(SFX_HERO_HIT, false);
			hero.setHitLeft();

			if (hero.getHP() <= 0)
				return;
		}

		if (CHARACTER_HIT_BOSS && HIT_CHECK_BOSS)						// ���a���� BOSS �R���P�w
		{
			mboss.setHP(mboss.getHP() - hero.getAttack());
			CAudio::Instance()->Play(SFX_MONSTER_HIT, false);
			mboss.setHit();
		}
		if (CHARACTER_SLASH_BOSS && HIT_CHECK_BOSS)						// ���a�I��}�ű� BOSS �R���P�w
		{
			mboss.setHP(mboss.getHP() - hero.getAttack() * 2);
			CAudio::Instance()->Play(SFX_MONSTER_HIT, false);
			mboss.setHit();
		}

		// BOSS ���`�i�J�L���e��
		if (mboss.getHP() <= 0)
			stage++;
	}

	// �˴���e���d��
	void CGameStateRun::checkStage()
	{
		if (stage == stage_count)
		{
			hero->setXY(100, 570);								// �i�J�U�@���ɦ^���l��m
			stage_count++;										// ���d�P�w�p�ƾ��շ�

			if (stage == 1)										// �Ĥ@���ɬ��Ĥ@�թǪ� + �Ĥ@�i�a��
			{
				monster = &monster1;
				map = &maps[0];
			}

			if (stage == 2)										// �ĤG���ɬ��ĤG�թǪ� + �ĤG�i�a��
			{													// �����Ĥ@�� BGM + ����ĤG�� BGM
				CAudio::Instance()->Stop(BGM_STAGE1);
				CAudio::Instance()->Play(BGM_STAGE2, true);
				monster = &monster2;
				map = &maps[1];
			}

			if (stage == 3)										// �ĤT���ɬ��ĤG�թǪ� + �ĤT�i�a��
			{													// �����ĤG�� BGM + ����ĤT�� BGM
				CAudio::Instance()->Stop(BGM_STAGE2);
				CAudio::Instance()->Play(BGM_STAGE3, true);
				monster = &monster3;
				map = &maps[2];
			}

			if (stage == 4)										// BOSS ���L���q�Ǫ�
			{													// �����ĤT�� BGM + ���� BOSS �� BGM
				CAudio::Instance()->Stop(BGM_STAGE3);
				CAudio::Instance()->Play(BGM_BOSS, true);
				monster = nullptr;
				map = &maps[3];
			}

			if (stage == 5)										// ���� BOSS ��Ĳ�o�����q
			{													// �]�w�C�����q�����A��i�J�������q
				gameClear = true;
				GotoGameState(GAME_STATE_OVER);
			}
		}
	}
}