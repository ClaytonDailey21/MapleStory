#ifndef CHARACTER_H
#define CHARACTER_H

#include "counter.h"

namespace game_framework
{

#define HP_PERCENT 100 * HP / maxHP
#define DEFAULT_RGB RGB(255, 255, 255)

	struct Animations
	{
		CAnimation standRight;	   // ����
		CAnimation standLeft;	   // ���߭��V��
		CAnimation downRight;	   // �V�k�w�U
		CAnimation downLeft;	   // �V���w�U
		CAnimation goLeft;		   // �V����
		CAnimation goRight;		   // �V�k��
		CAnimation jumpRight;	   // �V�k��
		CAnimation jumpLeft;	   // �V����
		CAnimation attackRight;	   // �V�k����
		CAnimation attackLeft;	   // �V������
		CAnimation slashAnimation; // �ޯ�ʵe
		CAnimation healAnimation;  // �ޯ�ʵe
		CAnimation lv_up;		   // �ɯŰʵe
	};

	class Character
	{
	public:
		Character();
		~Character();
		virtual void Initialize() = 0; // �]�w��l��
		virtual void OnMove() = 0;	   // ����
		virtual void OnShow() = 0;	   // ��ܨ���
		void addBitmap(int standR, int standL, int downR, int downL, int jumpR, int jumpL, vector<int> goR, vector<int> goL, vector<int> attackR, vector<int> attackL, vector<int> slash, vector<int> heal, vector<int> lv_up, int nR, int nG, int nB, int slash_ani = 2);
		//�[�J�ϧ�(�S������0)
		virtual void attacking(Character *c) = 0;	// ������ virtual �禡
		Counter &getCounter(int i);					// ���o���w Counter ����
		void countdown();							// �P�ɱҰʦP�� class �����Ҧ��p�ɾ�

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
		void setMovingRight(bool flag); // �]�w�O�_���b���k����
		void setMovingUp(bool flag);	// �]�w�O�_���b���W����
		void setAttacking(bool flag);	// �]�w�O�_���b����
		void setFacing(int face);		// �]�w���V��V
		void setXY(int nx, int ny);		// �]�wHero���W���y��
		void setHitLeft();				// �]�w�O�_�Q����
		void setHitRight();				// �]�w�O�_�Q����
		void setHitLeft(bool flag);		// �]�w�O�_�Q����
		void setHitRight(bool flag);	// �]�w�O�_�Q����
		void setDead(bool flag);		// �]�w�O�_���`
		void setPoison(bool flag);		// �]�w�O�_���r
		void setAttackRange(int n);		// �]�w�����Z��

		//Monsters
		void set_Monster_Go_Left(bool flag);	// �]�w�Ǫ���������
		void set_Monster_Go_Right(bool flag);	// �]�w�Ǫ����k����
		void setSkill(int i);					// �]�w�Ǫ��I��ޯ�

		//Hero
		void setSlashing(bool flag);			// �]�w����I��ޯ�
		bool ifSlashing();						// �P�w����I��ޯ�
		void setHealing(bool flag);				// �]�w����I��ޯ�
		bool ifHealing();						// �P�w����I��ޯ�

		//GETs

		int getX();				// ���� x �y��
		int getY();				// ���� y �y��
		int getAttack();		// �^�������O
		int getHP();			// �^���ͩR��
		int getMaxHP();			// �^���̤j�ͩR��
		int getXP();			// �^���g���
		int getLevel();			// �^������
		int getFloor();			// �^���a�O
		int getFacing();		// �^�����ۤ�V
		int getAttackRange();	// �^�������d��

		bool ifAttacking();		// �P�w�O�_���b����
		bool ifHitLeft();		// �P�w�O�_���쩹������
		bool ifHitRight();		// �P�w�O�_���쩹�k����
		bool ifMovingLeft();	// �P�w�O�_���b��������
		bool ifMovingRight();	// �P�w�O�_���b���k����
		bool ifMovingUp();		// �P�w�O�_���b���D
		bool ifMovingDown();	// �P�w�O�_���b�w�U
		bool ifPoison();		// �P�w�O�_���r
		bool ifDead();			// �P�w�O�_���`

	protected:
		CAnimation hp[11];				// �ͩR��
		CAnimation num[13];				// UI �P�Ʀr�K��
		int pos_x, pos_y;				// ����y��
		int floor;						// �a�O����
		int HP, maxHP;					// �ͩR�B�̤j�ͩR
		int exp;						// �g���
		int level;						// ����
		int facing;						// 1=���V�k 2=���V��
		bool isMovingDown, isMovingUp,	// �O�_���b����
			isMovingRight, isMovingLeft;
		bool isAttacking;				// �O�_���b����
		bool isSlashing;				// �O�_���b�I��ޯ�
		bool isHitLeft, isHitRight;		// �O�_�������
		bool isDead;					// �O�_���`
		bool isPoison = false;			// �O�_���r
		bool isHealing;					// �O�_�v����
		bool rising;					// true��W�ɡBfalse��U��
		bool is_Monster_Go_Left, is_Monster_Go_Right;
		int initial_velocity;			// ��l�t��
		int velocity;					// �ثe���t��(�I/��)
		int STEP_SIZE;					// �樫�t��
		int attackRange;				// �����d��
		int skillRange;					// �ޯ�d��
		int skill;						// �ޯ���w
		Animations a;					// �Ҧ� Character �ϥΤ� Animation
		std::vector<Counter *> counter; // �p�ƾ� Vector
		int hit_time;					// ���˵L�Įɶ�
		int attack;						// �����O
		int level_animation;			// �ɵ��ʵe�ɶ�
	};
} // namespace game_framework
#endif