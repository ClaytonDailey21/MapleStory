#ifndef CHARACTER_H

#define CHARACTER_H

namespace game_framework {

	class Character
	{
	public:
		Character() {
		}
		virtual void Initialize() = 0;	// 設定初始值
		virtual void LoadBitmap() = 0;	// 載入圖形
		int getX() {		// 左邊 x 座標
			return pos_x;
		}
		int getY() {		// 左邊 y 座標
			return pos_y;
		}
		int  GetXr() {		// 右邊 x 座標
			return pos_rx;
		}
		int  GetYr() {		// 右邊 y 座標
			return pos_ry;
		}
		virtual void OnMove() = 0;	// 移動
		virtual void OnShow() = 0;	// 顯示角色

		int GetAttack() { return attack; };			// 擷取攻擊力
		void SetAttack(int Atk) { attack = Atk; };	// 設定攻擊力
		int GetHP() { return hP; };					// 擷取生命值
		void SetHP(int Health) { hP = Health; };	// 設定生命值
		void SetMaxHP(int Health){					// 設定最大生命值
			maxHP = Health;
			hP = Health;
		};

		void SetMovingDown(bool flag) { isMovingDown = flag; };	// 設定是否正在往下移動
		void SetMovingLeft(bool flag) { isMovingLeft = flag; };	// 設定是否正在往左移動
		void SetMovingRight(bool flag) { isMovingRight = flag; };	// 設定是否正在往右移動
		void SetMovingUp(bool flag) { isMovingUp = flag; };		// 設定是否正在往上移動
		void SetAttacking(bool flag) { isAttacking = flag; };		// 設定是否正在攻擊
		bool ifAttacking(bool flag) { return isAttacking; };
		void SetFacing(int face) { facing = face; };			// 設定面向方向
		int GetFacing() { return facing; };
		void SetXY(int nx, int ny) {		// 設定Hero左上角座標

		}
		bool ifMovingLeft() { return isMovingLeft; }
		bool ifMovingRight() { return isMovingRight; }
		bool ifMovingUp() { return isMovingUp; }
		bool ifMovingDown() { return isMovingDown; }
		//protected:
		CAnimation hP_0;
		CAnimation hP_10;
		CAnimation hP_20;
		CAnimation hP_30;
		CAnimation hP_40;
		CAnimation hP_50;
		CAnimation hP_60;
		CAnimation hP_70;
		CAnimation hP_80;
		CAnimation hP_90;
		CAnimation hP_100;
		int pos_x;
		int pos_y;
		int pos_rx;
		int pos_ry;
		int attack;
		int hP, maxHP;
		int facing = 1;				// 1=面向右 2=面向左
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isAttacking = false;	// 是否正在攻擊
	};
}
#endif