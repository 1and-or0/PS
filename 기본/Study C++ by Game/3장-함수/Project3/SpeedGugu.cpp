#include "SpeedGugu.h"

// ���� �ҿ�ð�
double tElapsed = 0;

// ��ü �õ� Ƚ��
static int NumGames = 0;
// ���� Ƚ��
static int NumWins = 0;
// ����
static double Score = 0;

static bool playGuguOnce()
{
	int a = rand() % 8 + 2;
	int b = rand() % 8 + 2;
	int result;

	++NumGames;
	printf("[���� %d��] %2d x %2d = ", NumGames, a, b);
	scanf_s("%d", &result);
	
	if (result == a * b) ++NumWins;

	return (result == a * b);
}               

double playSpeedGugu(int nPlay)
{
	clock_t t0 = clock();
	
	for (int i = 0; i < nPlay; ++i)
	{
		if (playGuguOnce() == false)
		{
			printf("\tƲ�Ƚ��ϴ�.\n");
		}
	}

	clock_t t1 = clock();

	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;
	Score = (NumGames > NumWins) ? 0.0 : 100 * (10.0 * NumGames - tElapsed) / (10.0 * NumGames);
	
	return Score;
}