/*
 * mygame.h: ���ɮ��x�C��������class��interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 TY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "hero.h"
#include "map.h"
#include "monster.h"
#include "boss.h"
#include "position.h"
#include "initialize.h"

namespace game_framework {
#define SEC 30
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
		BGM_MENU,				// 0
		BGM_STAGE1,				// 1
		BGM_STAGE2,				// 2
		BGM_STAGE3,				// 3
		BGM_BOSS,				// 4
		BGM_GAMEOVER,			// 5
		SFX_JUMP,				// 6
		SFX_ATTACK,				// 7
		SFX_SLASH,				// 8
		SFX_HERO_HIT,			// 9
		SFX_MONSTER_HIT,		// 10
		SFX_GUN,				// 11
		SFX_LEVEL_UP,			// 12
		SFX_HEAL,				// 13
		SFX_ROOT,				// 14
		BGM_CLEAR,				// 15
		SFX_LASER,				// 16
		SFX_LIGHTING,			// 17
		SFX_KNOCKBACK			// 18
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyDown(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap logo;								// csie��logo
		CMovingBitmap info;
		CMovingBitmap start1;
		CMovingBitmap start2;
		CMovingBitmap exit1;
		CMovingBitmap exit2;
		CMovingBitmap info1;
		CMovingBitmap info2;
		int menu = 1;									//�P�O�� 1=�W 2=�U
		int ifInfoOn = 0;								//������� 0=�� 1=�}
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int stage, stage_count;
		CMovingBitmap slashCD[9], healCD[9];
		CMovingBitmap background;						// �I����
		CMovingBitmap PoisonRoot;
		CAnimation Boss_laser_delay, Boss_laser;
		CAnimation Boss_knockback_delay, Boss_knockback;
		CAnimation Boss_lighting_delay1, Boss_lighting_delay2, Boss_lighting1, Boss_lighting2;
		Character *hero;								// ����
		vector<Map> maps;								// �a��
		Map *map;
		vector<Character*> monster1, monster2, monster3;// �Ǫ�
		vector<Character*> *monster;
		Boss boss;
		Position hero_pos;
		int temp = 300;
		inline int monster_num(vector<Character*> monster);
		void heroMonsterInteraction(Character&hero, vector<Character*> & monster, Map &map);
		void heroBossInteraction(Character&hero, Boss &mboss, Map &map);
		void checkStage();
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void number_OnShow(int nx, int pos_nx, int pos_ny);
	private:
		int counter = 210;	// �˼Ƥ��p�ƾ�
		int clearTime = 0;
		CAnimation Gameover;
		CMovingBitmap clear_info;
		CAnimation num[10];
	};

}