#include <cstdio>
#include <conio.h>

void main()
{
	int n, min = 1, max = 99, input, i;

	printf("�� �ڸ� �� �Է�(1~99): ");
	char a = _getch();
	printf("*");
	char b = _getch();
	printf("*\n\n");

	n = (a - '0') * 10 + (b - '0');

	for (i = 0; i < 10; ++i)
	{
		printf("[%2dȸ] %2d ~ %2d ������ �� ���� =>", i + 1, min, max);
		scanf_s("%d", &input);

		if (n == input)
			break;
		else if (n > input)
		{
			printf("�� ū �����Դϴ�!\n");
			min = input;
		}
		else
		{
			printf("�� ���� �����Դϴ�!\n");
			max = input;
		}
	}

	printf("%s !!! ������ %d\n", (n == input) ? "����" : "����", n);
	printf(" ���� ����: %d\n", 10 * (10 - i));

	return;
}