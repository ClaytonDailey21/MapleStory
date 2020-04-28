#ifndef POSITION_H
#define POSITION_H

#include "character.h"
#include "map.h"

namespace game_framework {

	class Position		//��m
	{
	public:
		Position();
		Position(Character* c, Map m);
		int getX();
		int getY();
		void SetPosition(Character* c, Map m);
	private:
		int pos_x, pos_y;
	};
}

#endif // !POSITION_H


