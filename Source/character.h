#ifndef CHARACTER_H

#define CHARACTER_H


namespace game_framework {

#define HP_PERCENT 100*hP/maxHP

	class Character
	{
	public:
		Character() {
		}
		virtual void Initialize() = 0;	// �]�w��l��
		virtual void LoadBitmap() = 0;	// ���J�ϧ�
		int getX();						// ���� x �y��
		int getY();						// ���� y �y��
		int getXr();						// �k�� x �y��
		int getYr();						// �k�� y �y��
		virtual void OnMove() = 0;		// ����
		virtual void OnShow() = 0;		// ��ܨ���

		int GetAttack();					// �^�������O
		void SetAttack(int Atk);			// �]�w�����O
		int GetHP();						// �^���ͩR��
		void SetHP(int Health);			// �]�w�ͩR��
		void SetMaxHP(int Health);		// �]�w�̤j�ͩR��
		void SetFloor(int Floor);		// �]�w�a�O
		int GetFloor();					// �^���a�O

		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag);	// �]�w�O�_���b���k����
		void SetMovingUp(bool flag);		// �]�w�O�_���b���W����
		void SetAttacking(bool flag);	// �]�w�O�_���b����
		bool ifAttacking(bool flag);
		void SetFacing(int face);		// �]�w���V��V
		int GetFacing();
		void SetXY(int nx, int ny);		// �]�wHero���W���y��
		void hp_addBitmaps();
		void hp_OnShow();
		bool ifMovingLeft();
		bool ifMovingRight();
		bool ifMovingUp();
		bool ifMovingDown();
	protected:
		CAnimation hp[11];
		int pos_x,	pos_y;				//����y��
		int pos_rx, pos_ry;				//�k��y��
		int attack;
		int floor;						//�a�O����
		int hP, maxHP;
		int facing = 1;					// 1=���V�k 2=���V��
		bool isMovingDown, isMovingUp,// �O�_���b����
			 isMovingRight, isMovingLeft;
		bool isAttacking = false;		// �O�_���b����
		bool rising;						// true��W�ɡBfalse��U��
		int initial_velocity;			// ��l�t��
		int velocity;					// �ثe���t��(�I/��)
		int STEP_SIZE = 8;				// �樫�t��
	};
}
#endif