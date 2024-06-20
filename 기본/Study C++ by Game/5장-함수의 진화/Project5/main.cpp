#include <cstdio>

#define WIDTH 17
#define HEIGHT 5

void label(unsigned char img[HEIGHT][WIDTH], int x, int y, int color)
{
	// ���� ����
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT || img[y][x] != 9)
		return;
	
	img[y][x] = color;
	label(img, x - 1, y, color); // ��� ȣ��: ���� �̿�ȭ��
	label(img, x + 1, y, color); // ��� ȣ��: ���� �̿�ȭ��
	label(img, x, y - 1, color); // ��� ȣ��: ���� �̿�ȭ��
	label(img, x, y + 1, color); // ��� ȣ��: ���� �̿�ȭ��
}

void blobColoring(unsigned char img[HEIGHT][WIDTH])
{
	int color = 1;
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			if (img[y][x] == 9) // ó���� �� �� ���� ȭ���̸�, �⺻���� ���� ȭ���̸�
			{
				label(img, x, y, color++); // ����� ȭ�� ä�� ���� (�׸��� ����Ʈ��)
			}
		}
	}
}

void printImage(unsigned char img[HEIGHT][WIDTH], const char * msg)
{
	printf("%s\n", msg);
	
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			if (img[y][x] == 0)
			{
				printf(".");
			}
			else
			{
				printf("%d", img[y][x]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	unsigned char image[HEIGHT][WIDTH] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 9, 9, 9, 9, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9, 0, 0},
		{9, 9, 0, 0, 0, 0, 9, 9, 9, 9, 9, 0, 9, 9, 9, 9, 9},
		{0, 9, 9, 9, 9, 0, 0, 0, 9, 0, 0, 0, 0, 0, 9, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};


	printImage(image, "<Original image>");
	blobColoring(image);
	printImage(image, "<Labelled image>");


	return 0;
}