#ifndef CHARACTER_H

#define CHARACTER_H


namespace game_framework {

#define HP_PERCENT 100*HP/maxHP
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
		CAnimation slashAnimation;	// �ޯ�ʵe
		CAnimation lv_up;			// �ɯŰʵe
	};

	class Character
	{
	public:
		Character() {}
		virtual void Initialize() = 0;	// �]�w��l��
		virtual void OnMove() = 0;		// ����
		virtual void OnShow() = 0;		// ��ܨ���
		void addBitmap(int standR, int standL, int downR, int downL, int jumpR, int jumpL, vector<int> goR, vector<int> goL, vector<int> attackR, vector<int> attackL,vector<int> slash, vector<int> lv_up);
		//�[�J�ϧ�(�S������0)

		//HP

		void hp_addBitmaps();
		void hp_OnShow();

		//�Ʀr

		void number_addBitmaps();
		void number_OnShow(int nx, int pos_nx, int pos_ny);

		//SETs

		void setHP(int Health);			// �]�w�ͩR��
		void setAttack(int Atk);		// �]�w�����O
		void setMaxHP(int Health);		// �]�w�̤j�ͩR��
		void setXP(int nxp);			// �]�w�g���
		void setLevel(int nlv);			// �]�w����
		void setLevelUP();				// �ɯ��o
		void setFloor(int Floor);		// �]�w�a�O
		void setMovingDown(bool flag);	// �]�w�O�_���b���U����
		void setMovingLeft(bool flag);	// �]�w�O�_���b��������
		void setMovingRight(bool flag);	// �]�w�O�_���b���k����
		void setMovingUp(bool flag);	// �]�w�O�_���b���W����
		void setAttacking(bool flag);	// �]�w�O�_���b����
		void setFacing(int face);		// �]�w���V��V
		void setXY(int nx, int ny);		// �]�wHero���W���y��
		void setHitLeft();				// �]�w�O�_�Q����
		void setHitRight();				// �]�w�O�_�Q����
		void setHitLeft(bool flag);		// �]�w�O�_�Q����
		void setHitRight(bool flag);	// �]�w�O�_�Q����
		void setDead(bool flag);		// �]�w�O�_���`
		void setAttackRange(int n);

		//Monsters
		void set_Monster_Go_Left(bool flag);
		void set_Monster_Go_Right(bool flag);

		//Hero
		void setSlashing(bool flag);
		bool ifSlashing();
		
		//GETs

		int getX();						// ���� x �y��
		int getY();						// ���� y �y��
		int getXr();					// �k�� x �y��
		int getYr();					// �k�� y �y��
		int getAttack();				// �^�������O
		int getHP();					// �^���ͩR��
		int getMaxHP();
		int getXP();
		int getLevel();
		int getFloor();					// �^���a�O
		int getFacing();
		int getAttackRange();

		bool ifAttacking();
		bool ifHitLeft();
		bool ifHitRight();
		bool ifMovingLeft();
		bool ifMovingRight();
		bool ifMovingUp();
		bool ifMovingDown();
		bool ifDead();
	protected:
		CAnimation hp[11];
		CAnimation num[13];
		int pos_x,	pos_y;				//����y��
		int pos_rx, pos_ry;				//�k��y��
		int attack;
		int floor;						//�a�O����
		int HP, maxHP;
		int exp = 0;
		int level = 1;
		int level_animation = 0;
		int facing = 1;					// 1=���V�k 2=���V��
		bool isMovingDown, isMovingUp,	// �O�_���b����
			 isMovingRight, isMovingLeft;
		bool isAttacking = false;		// �O�_���b����
		bool isSlashing = false;		// �O�_���b�I��ޯ�
		bool isHitLeft = false;			// �O�_�������
		bool isHitRight = false;		// �O�_�������
		bool isDead = false;
		bool rising;					// true��W�ɡBfalse��U��
		bool is_Monster_Go_Left = false;
		bool is_Monster_Go_Right = false;
		int initial_velocity;			// ��l�t��
		int hit_time = 18;
		int attack_time = 15;
		int skill_time = 26;		// �ޯ�ʵe�ɶ�
		int velocity;					// �ثe���t��(�I/��)
		int STEP_SIZE = 8;				// �樫�t��
		int cooldown = 30 * 10;			// �ޯ�N�o 10 ��
		int attackRange;
		Animations a;
	};
}
#endif