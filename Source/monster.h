namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class Monster
	{
	public:
		Monster();
		int  GetX1();					// monster���W�� x �y��
		int  GetY1();					// monster���W�� y �y��
		int  GetX2();					// monster�k�U�� x �y��
		int  GetY2();					// monster�k�U�� y �y��
		void Initialize();				// �]�wmonster����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ����monster
		void OnShow();					// �Nmonster�ϧζK��e��
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetXY(int nx, int ny);		// �]�wmonster���W���y��
		int GetAttack();				// �^�������O
		void SetAttack(int Atk);		// �]�w�����O
		int GetHP();					// �^���ͩR��
		void SetHP(int Health);			// �]�w�ͩR��

	protected:
		CAnimation monsterRight;		// ����
		CAnimation monsterLeft;
		const int HERO_STEP = 8;
		int x, y, range_X;				// Hero���W���y��
		int STEP_SIZE;
		int tempX, tempY;
		int hP;					// �ͩR��
		int attack;				// �����O
		int floor;				// �a�O��Y�y��
		bool isMovingRight, isMovingLeft;
	};
}