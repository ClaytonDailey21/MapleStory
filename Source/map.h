#ifndef MAP_H
#define MAP_H

#include "floor.h"
#include "portal.h"

namespace game_framework
{
	class Portal;
	class Map
	{
	public:
		Map();
		void Initialize();					// ��l�Ʀa��
		void LoadBitmap();					// Ū���I����
		void OnShow();						// ��ܦa��
		void OnMove();						// ���ʦa��
		void portalOnShow();				// ��ܶǰe��

		//SETs Init �]�w�Ҧ���¦�ƭ�

		void setInitFloor(int i);
		void setInitXY(int x, int y);
		void setInitZoom(double i);
		void setInitPlatform(Platform *plats, int i);
		void setInitBitmap(int bitmap);
		void setInitPortal(int x, int y);

		//SETs in game

		void setMovingLeft(bool flag);		// �]�w�O�_���b��������
		void setMovingRight(bool flag);		// �]�w�O�_���b���k����

		//GETs

		int getFloorXBegin(int i) const;	// ����a�O x �_�l��m
		int getFloorXLast(int i) const;		// ����a�O x ������m
		int getFloorY(int i) const;			// ����a�O y ����
		int getX() const;
		int getY() const;
		bool ifMovingLeft() const;
		bool ifMovingRight() const;
		Portal &getPortal();				// ����ǰe���]�w

	protected:
		CMovingBitmap map;					// �a�Ϫ��K��
		Portal _portal;						// �ǰe�����ɤJ
		int _x, _y, floor;					// �����Ѽ�
		double zoom;						// ��j���v
		bool rising;						// true��W�ɡBfalse��U��
		int velocity;						// �ثe���t��(�I/��)
		int _bitmap;
		bool isMovingRight, isMovingLeft;
		Floor floors;						// �ɤJ Floor �a�O�ƾ�
	};
}
#endif