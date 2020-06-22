#ifndef HERO_H
#define HERO_H

#include "character.h"

namespace game_framework
{
	enum Counters
	{
		slash,
		heal
	};

	class Hero : public Character
	{
	public:
		Hero();
		~Hero();
		void Initialize(); // �]�wHero����l��
		void OnMove();	   // ����Hero
		void OnShow();	   // �NHero�ϧζK��e��
		void attacking(Character *monster);

	protected:
		const int d = 17; // UI��r���Z
		int skill_time;	  // �ޯ�ʵe�ɶ�
		int heal_time;	  // �ޯ�ʵe�ɶ�
	};
} // namespace game_framework
#endif