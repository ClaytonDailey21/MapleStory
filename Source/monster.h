#ifndef MONSTER_H
#define MONSTER_H

#include "character.h"

namespace game_framework
{
	enum MonsterCounters					// Monster �ޯ�p�ƾ�
	{
		mage_skill,
		is_poison,
		poison_delay
	};
	class Monster : public Character
	{
	public:
		Monster() {}
		Monster(int nx, int ny, int nxp);	// monster �򥻳]�w
		~Monster();
		void Initialize();					// �]�w monster ����l��
		void OnMove();						// ���� monster
		void OnShow();						// �N monster �ϧζK��e��
		bool ifSkill();						// �P�w monster �O�_�I��ޯ�
		void attacking(Character *hero);	// �P�w monster ���� hero ���ĪG

	protected:
		const int HERO_STEP = 8;			// �ɤJ Hero ���ʰѼ�
		int initX, initY;					// �����Ѽ�
		bool isSkill = false;
		int hero_tempX, hero_tempY;
		int attack_time;					// �����ʵe�p�ƾ�
	};
} // namespace game_framework
#endif