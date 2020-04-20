#ifndef MAP_H
#define MAP_H

#include "floor.h"

namespace game_framework {
	class Map
	{
	public:
		Map();
		void Initialize();
		void LoadBitmap(int bitmap);
		void OnShow();
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void OnMove();
		int getFloorXBegin(int i) const;
		int getFloorXLast(int i) const;
		int getFloorY(int i) const;
		int getX();
		int getY();
		bool ifMovingLeft();
		bool ifMovingRight();

	protected:
		CMovingBitmap map1;
		int x, y, zoom, charX, charY, floor;
		bool rising;			// true��W�ɡBfalse��U��
		int initial_velocity;	// ��l�t��
		int velocity;			// �ثe���t��(�I/��)
		bool isMovingRight, isMovingLeft;
		P plats[7] = {  {294,452,200},
						{624,1018,205},
						{802,1264,52 },
						{1240,1964,140},
						{1478,1966,220},
						{1802,2198,50},
						{1990,2228,272} };
		Floor *floors=new Floor(plats, 7);
	};
}
#endif