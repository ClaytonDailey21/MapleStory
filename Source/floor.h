#ifndef FLOOR_H
#define FLOOR_H

namespace game_framework
{
	struct Platform
	{
		int xBegin, xLast, y;				// ���x x �_�l��m�B������m�H�� y ����
	};
	class Floor								// ���x���X��
	{
	public:
		Floor() : _count(0) {}
		Floor(Platform plats[], int count); // �@�Ӧa�ϩҦ����x�զX���}�C
		int getXBegin(int i) const;			// �^�ǥ��x x �_�l��m
		int getXLast(int i) const;			// �^�ǥ��x x ������m
		int getY(int i) const;				// �^�ǥ��x y ����

	private:								// �����Ѽ�
		int _count;
		vector<Platform> _plat;
	};
} // namespace game_framework

#endif // !FLOOR_H