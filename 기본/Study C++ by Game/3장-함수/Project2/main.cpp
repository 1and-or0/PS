#include "RoussianRoulette.h"

void main()
{
	int how_many_p;
	int how_many_b;

	srand(time(NULL));

	printf("���� �ο� �Է�: ");
	scanf_s("%d", &how_many_p);

	printf("�Ѿ� ���� �Է�(1~5��): ");
	scanf_s("%d", &how_many_b);

	while (how_many_b < 1 || how_many_b>5)
	{
		printf("�Ѿ� ������ ������ �����ϼ���!\n");
		printf("�Ѿ� ���� �Է�(1~5��): ");
		scanf_s("%d", &how_many_b);
	}

	getchar();

	
	int shotted_p = playRoussianRoulette(how_many_p, how_many_b);
	printf("\n %d�� player�� �ѿ� �¾ҽ��ϴ�.\n", shotted_p);

	return;
}