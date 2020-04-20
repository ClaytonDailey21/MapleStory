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
		int floor_num = 2;
		P plats[2] = { {2,2,3},{2,4,3} };
		Floor *floors=new Floor(plats, 2);
	};
}
#endif