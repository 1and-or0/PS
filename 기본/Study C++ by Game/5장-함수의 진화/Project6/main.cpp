#include "MineSweeper.h"

#define DIM 9

int main()
{
	int total;
	printf(" <Mine Sweeper>\n");
	printf(" �ż��� �� ������ ���� �Է�: ");
	scanf("%d", &total);
	
	playMineSweeper(total);


	return 0;
}