#ifndef MAP_H
#define MAP_H

#include "floor.h"
#include "portal.h"


namespace game_framework {
	class Portal;
	class Map
	{
	public:
		Map();
		void Initialize();
		void LoadBitmap();
		void OnShow();		void OnMove(); 
		void portalOnShow();

		//SETs Init

		void setInitFloor(int i);
		void setInitXY(int x, int y);
		void setInitZoom(double i);
		void setInitPlatform(Platform *plats,int i);
		void setInitBitmap(int bitmap);
		void setInitPortal(int x, int y);

		//SETs in game

		void setMovingLeft(bool flag);	// �]�w�O�_���b��������
		void setMovingRight(bool flag); // �]�w�O�_���b���k����

		//GETs

		int getFloorXBegin(int i) const;
		int getFloorXLast(int i) const;
		int getFloorY(int i) const;
		int getX() const;
		int getY() const;
		bool ifMovingLeft() const;
		bool ifMovingRight() const;
		Portal& getPortal();

	protected:
		CMovingBitmap map;
		Portal _portal;
		int _x, _y, floor;
		double zoom;
		bool rising;			// true��W�ɡBfalse��U��
		int velocity;			// �ثe���t��(�I/��)
		int _bitmap;
		bool isMovingRight, isMovingLeft;
		Floor floors;
	};
}
#endif