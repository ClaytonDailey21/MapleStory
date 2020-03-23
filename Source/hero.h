namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class Hero
	{
	public:
		Hero();
		int  GetX1();					// Hero���W�� x �y��
		int  GetY1();					// Hero���W�� y �y��
		int  GetX2();					// Hero�k�U�� x �y��
		int  GetY2();					// Hero�k�U�� y �y��
		void Initialize();				// �]�wHero����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ����Hero
		void OnShow();					// �NHero�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�wHero���W���y��

	protected:
		CAnimation stand;			// ����
		CAnimation down;			// �w�U
		CAnimation goLeft;			// �V����
		int x, y;					// Hero���W���y��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		int floor;				// �a�O��Y�y��
		bool rising;			// true��W�ɡBfalse��U��
		int initial_velocity;	// ��l�t��
		int velocity;			// �ثe���t��(�I/��)
	};
}