#include "RoussianRoulette.h"

int playRoussianRoulette(int nTurns, int nBullets)
{
	int start_n = rand() % nTurns + 1;
	printf("\n���� ���Ƚ��ϴ�. %d������ �����մϴ�.\n", start_n);

	while (true)
	{
		int pos = rand() % 5 +1 ;
		printf("[%d�� player]\tźâ�� �������� ���Ƚ��ϴ�.\n", start_n);
		printf("\t���͸� ������ ��Ƽ踦 ���ϴ�...");

		getchar();
		if (pos <= nBullets)
		{
			break;
		}
		printf("\t��~~~ ��ҽ��ϴ�!!!\n");
		start_n = (start_n) % nTurns + 1;
	}
	printf("\t��~~~~~!!!\n");
	return start_n;
}