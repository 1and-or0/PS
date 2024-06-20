#include "MonsterWorld.h"
#include <ctime>

int main()
{
	srand(time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);
	Monster m1("����", "��", rand() % w, rand() % h);

	game.add(m1);

	// string name[6] = { "������", "��", "����", "��", "����", "��" };
	Monster m2("������", "��", rand() % w, rand() % h);
	Monster m3("����", "��", rand() % w, rand() % h);
	Monster m4("����", "��", rand() % w, rand() % h);
	game.add(m2);
	game.add(m3);
	game.add(m4);
	// game.add(Monster("������", "��", rand() % w, rand() % h));
	// game.add(Monster("����", "��", rand() % w, rand() % h));
	// game.add(Monster("����", "��", rand() % w, rand() % h));



	game.play(500, 10);
	printf("----------���� ����----------\n");

	return 0;
}