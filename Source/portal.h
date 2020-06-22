#pragma once
namespace game_framework
{
	class Portal
	{
	public:
		Portal() {}
		~Portal();
		Portal(int x, int y);						// �]�w�ǰe�����y�Ц�m
		void addBitMaps(int bitmaps[], int num);	// �]�w�ǰe���K��
		void OnMove();								// �ǰe������
		void OnShow(int x, int y);					// ��ܶǰe��
		int getX();									// ��� x �y��
		int getY();									// ��� y �y��

	private:										// �����Ѽ�
		int _x, _y;
		CAnimation _portal;
	};
}
