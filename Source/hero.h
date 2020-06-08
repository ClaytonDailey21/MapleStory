#ifndef HERO_H
#define HERO_H

#include "character.h"

namespace game_framework {

	class Hero: public Character
	{
	public:
		Hero();
		void Initialize();				// �]�wHero����l��
		void OnMove();					// ����Hero
		void OnShow();					// �NHero�ϧζK��e��
		void attacking(Character *monster);

	protected:
		const int d = 17;				// UI��r���Z
	};
}
#endif