#pragma once
namespace game_framework
{
	class Counter
	{
	public:
		Counter(int max, int min = 0);	// �ŧi
		void start();					// �}�l�p��
		void stop();					// ����p��
		void countdown();				// �p�ƾ��˼�
		int getCount();					// ���o��e�p��

	private:
		int _count;						// �����ϥΰѼ�
		int _max;
		int _min;
	};
} // namespace game_framework
