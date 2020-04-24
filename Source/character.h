#ifndef CHARACTER_H

#define CHARACTER_H


namespace game_framework {

#define HP_PERCENT 100*hP/maxHP
#define DEFAULT_RGB RGB(255, 255, 255)

	struct Animations {
		CAnimation standRight;		// ����
		CAnimation standLeft;		// ���߭��V��
		CAnimation downRight;		// �V�k�w�U
		CAnimation downLeft;			// �V���w�U
		CAnimation goLeft;			// �V����
		CAnimation goRight;			// �V�k��
		CAnimation jumpRight;		// �V�k��
		CAnimation jumpLeft;			// �V����
		CAnimation attackRight;		// �V�k����
		CAnimation attackLeft;		// �V������
	};

	class Character
	{
	public:
		Character() {}
		virtual void Initialize() = 0;	// �]�w��l��
		virtual void LoadBitmap() = 0;	// ���J�ϧ�
		virtual void OnMove() = 0;		// ����
		virtual void OnShow() = 0;		// ��ܨ���

		//HP

		void hp_addBitmaps();
		void hp_OnShow();

		//SETs

		void SetHP(int Health);			// �]�w�ͩR��
		void SetAttack(int Atk);			// �]�w�����O
		void SetMaxHP(int Health);		// �]�w�̤j�ͩR��
		void SetFloor(int Floor);		// �]�w�a�O
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag);	// �]�w�O�_���b���k����
		void SetMovingUp(bool flag);		// �]�w�O�_���b���W����
		void SetAttacking(bool flag);	// �]�w�O�_���b����
		void SetFacing(int face);		// �]�w���V��V
		void SetXY(int nx, int ny);		// �]�wHero���W���y��
		void SetHitLeft();				// �]�w�O�_�Q����
		void SetHitRight();				// �]�w�O�_�Q����
		void SetDead(bool flag);		// �]�w�O�_���`

		//Monsters
		void Set_Monster_Go_Left(bool flag);
		void Set_Monster_Go_Right(bool flag);

		//GETs

		int getX();						// ���� x �y��
		int getY();						// ���� y �y��
		int getXr();						// �k�� x �y��
		int getYr();						// �k�� y �y��
		int GetAttack();					// �^�������O
		int GetHP();						// �^���ͩR��
		int GetFloor();					// �^���a�O
		int GetFacing();
		bool ifAttacking();
		bool ifHitLeft();
		bool ifHitRight();
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
		bool isHitLeft = false;			// �O�_�������
		bool isHitRight = false;		// �O�_�������
		bool isDead = false;
		bool rising;					// true��W�ɡBfalse��U��
		bool is_Monster_Go_Left = false;
		bool is_Monster_Go_Right = false;
		int initial_velocity;			// ��l�t��
		int hit_time = 18;
		int velocity;					// �ثe���t��(�I/��)
		int STEP_SIZE = 8;				// �樫�t��
		Animations a;
	};
}
#endif