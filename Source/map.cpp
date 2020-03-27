#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "map.h"

namespace game_framework {
	Map::Map(){
		Initialize();
	}
	void Map::Initialize() {
		const int X_POS = 0;
		const int Y_POS = 0;
		x = X_POS;
		y = Y_POS;
		zoom = 2;
		isMovingLeft = isMovingRight = false;
	}
	void Map::LoadBitmap(int bitmap) {
		map1.LoadBitmap(bitmap);
	}
	void Map::OnShow() {
		map1.SetTopLeft(x,y);
		map1.ShowBitmap(zoom);
	}
	void Map::SetMovingLeft(bool flag) {	// �]�w�O�_���b��������
		isMovingRight = flag;
	}
	void Map::SetMovingRight(bool flag) {	// �]�w�O�_���b���k����
		isMovingLeft = flag;
	}
	void Map::OnMove() {
		const int STEP_SIZE = 8;

		if (x >= -1036 && isMovingRight) {	//�Y�I���N�ʦa�Ϫ���a�Ϫ���t
			x -= STEP_SIZE;
		}
		if (x < 0 && isMovingLeft) {		//�Y�I���N�ʦa�Ϫ���a�Ϫ���t
			x += STEP_SIZE;
		}
	}
}