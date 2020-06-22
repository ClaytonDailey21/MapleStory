#ifndef POSITION_H
#define POSITION_H

#include "character.h"
#include "map.h"

namespace game_framework
{

	class Position								// ��m
	{
	public:
		Position();
		Position(Character *c, Map m);
		int getX();								// ���o�y�ФW X ��m
		int getY();								// ���o�y�ФW Y ��m
		void setPosition(Character *c, Map m);	// ���o����b�y�ФW����m

	private:
		int pos_x, pos_y;						// ���� X Y �Ѽ�
	};
}
#endif
