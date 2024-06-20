#include <stdio.h>

class GuguGame
{
	private:
		int from;
		int to;
	public:
		GuguGame()
		{
			set(1, 9);
		}
		~GuguGame(){}
		void set(int f, int t) { from = f; to = t; }
		void play(int dan)
		{
			printf("��ü���� ���α׷���\n");
			printf("������ %d ��\n", dan);
			for (int i = from; i <= to; ++i)
			{
				printf("%2d x %2d = %2d\n", dan, i, dan*i);
			}
		}
};

void main()
{
	GuguGame myGame;
	myGame.play(3);
	myGame.set(3, 8);
	myGame.play(3);
	myGame.play(5);
	return;
}