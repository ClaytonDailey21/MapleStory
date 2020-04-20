#ifndef CHARACTER_H

#define CHARACTER_H

namespace game_framework {

	class Character
	{
	public:
		Character() {
		}
		virtual void Initialize() = 0;	// �]�w��l��
		virtual void LoadBitmap() = 0;	// ���J�ϧ�
		int getX() {		// ���� x �y��
			return pos_x;
		}
		int getY() {		// ���� y �y��
			return pos_y;
		}
		int  getXr() {		// �k�� x �y��
			return pos_rx;
		}
		int  getYr() {		// �k�� y �y��
			return pos_ry;
		}
		void getXY(int nx, int ny)
		{
			pos_x = nx; pos_y = ny;
		}
		virtual void OnMove() = 0;	// ����
		virtual void OnShow() = 0;	// ��ܨ���

		int GetAttack() { return attack; };			// �^�������O
		void SetAttack(int Atk) { attack = Atk; };	// �]�w�����O
		int GetHP() { return hP; };					// �^���ͩR��
		void SetHP(int Health) { hP = Health; };	// �]�w�ͩR��
		void SetMaxHP(int Health){					// �]�w�̤j�ͩR��
			maxHP = Health;
			hP = Health;
		};

		void SetFloor(int Floor) { floor = Floor; };	// �]�w�a�O
		int GetFloor() { return floor; };

		void SetMovingDown(bool flag) { isMovingDown = flag; };	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag) { isMovingLeft = flag; };	// �]�w�O�_���b��������
		void SetMovingRight(bool flag) { isMovingRight = flag; };	// �]�w�O�_���b���k����
		void SetMovingUp(bool flag) { isMovingUp = flag; };		// �]�w�O�_���b���W����
		void SetAttacking(bool flag) { isAttacking = flag; };		// �]�w�O�_���b����
		bool ifAttacking(bool flag) { return isAttacking; };
		void SetFacing(int face) { facing = face; };			// �]�w���V��V
		int GetFacing() { return facing; };
		void SetXY(int nx, int ny) {		// �]�wHero���W���y��

		}
		bool ifMovingLeft() { return isMovingLeft; }
		bool ifMovingRight() { return isMovingRight; }
		bool ifMovingUp() { return isMovingUp; }
		bool ifMovingDown() { return isMovingDown; }
	protected:
		CAnimation hP_0, hP_10, hP_20, hP_30, hP_40, hP_50, hP_60, hP_70, hP_80, hP_90, hP_100;
		int pos_x;
		int pos_y;
		int pos_rx;
		int pos_ry;
		int attack;
		int floor;
		int hP, maxHP;
		int facing = 1;				// 1=���V�k 2=���V��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isAttacking = false;	// �O�_���b����
		bool rising;			// true��W�ɡBfalse��U��
		int initial_velocity;	// ��l�t��
		int velocity;			// �ثe���t��(�I/��)
		int STEP_SIZE = 8;//
	};
}
#endif