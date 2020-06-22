#ifndef HERO_H
#define HERO_H

#include "character.h"

namespace game_framework
{
	enum Counters							 // �]�w Hero �ޯ�p�ƾ�
	{
		slash,
		heal
	};

	class Hero : public Character
	{
	public:
		Hero();
		~Hero();
		void Initialize();					 // �]�w Hero ����l��
		void OnMove();						 // ���� Hero
		void OnShow();						 // �N Hero �ϧζK��e��
		void attacking(Character *monster);	 // �P�w hero ���� monster ���ĪG

	protected:
		const int d = 17;					 // UI��r���Z
		int skill_time;						 // �ޯ�ʵe�ɶ�
		int heal_time;						 // �ޯ�ʵe�ɶ�
	};
} // namespace game_framework
#endif