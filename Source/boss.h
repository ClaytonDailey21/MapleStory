#ifndef BOSS_H
#define BOSS_H

#include "character.h"
#include "counter.h"

namespace game_framework
{
	struct BossAnimations // �ʵe
	{
		CAnimation normal;
	};
	enum BossCounter // �˼ƾ��W��
	{
		skills,
		laser_delay,
		laser_skill,
		knockback_delay,
		knockback_skill,
		lighting_delay1,
		lighting_skill1,
		lighting_delay2,
		lighting_skill2
	};
	class Boss
	{
	public:
		Boss(){};
		~Boss();
		void addBitmap();				// �]�w����
		void Initialize();				// �]�wBoss����l��
		void OnMove();					// ����Boss
		void OnShow();					// �NBoss�ϧζK��e��
		void showHPBar();				// ��ܦ�q��
		void setMovingLeft(bool flag);	// �]�w�O�_�V������
		void setMovingRight(bool flag); // �]�w�O�_�V������
		void setXY(int nx, int ny);		// �]�wBoss��m
		void setHit();					// �]�w�O�_�Q����
		void setHit(bool flag);			// �]�w�O�_�Q����
		void setHP(int Health);			// �]�w�ͩR��
		bool ifHit();					// �^���O�_�Q����
		int getX();						// �^��X�y��
		int getHP();					// �^���ͩR��
		int getMaxHP();					// �^���̤j�ͩR��
		int getAttack();				// �^�������O
		int getSkill();					// �^���ޯ�եN��
		Counter &getCounter(int i);		// ���o�˼ƾ�
		void countdown();				// �˼ƾ��˼�
	private:
		const int HERO_STEP = 8;		  // �D�Ԫ̨B��j�p
		const int floor = 570;			  // �a�O����
		BossAnimations a;				  // �ʵe
		CMovingBitmap hpIcon;			  // HP���Ǫ��ϧ�
		std::vector<Counter *> counter;	  // �˼ƾ�
		int pos_x, pos_y;				  // Boss��m
		bool isMovingRight, isMovingLeft; // �O�_����
		bool isDead;					  // �O�_���`
		bool isHit;						  // �O�_�Q����
		int attack;						  // �����O
		int maxHP, HP;					  // �̰���q, �ثe��q
		int skill;						  // �ޯ�եN��
		int hit_time;
	};
} // namespace game_framework
#endif