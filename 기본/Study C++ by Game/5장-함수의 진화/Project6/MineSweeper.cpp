#include "MineSweeper.h"

#define DIM 9

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };

static int MineMapLabel[DIM][DIM]; // 0 ~ 8, 9(= Bomb)
static int MineMapMask[DIM][DIM]; // Hide, Open, Flag

static int nx = DIM, ny = DIM;
static int nBomb = DIM;

// ���� ���� ���� �Լ���
inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }

inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; } // isValid �˻� �� ��ź�� ������ true, ������ false ��ȯ
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; } // isValid �˻� �� ��������� true, �ƴϸ� false ��ȯ

static void dig(int x, int y)
{
	if (isValid(x, y) && mask(x, y) != Open)
	{
		mask(x, y) = Open;
		if (label(x, y) == 0)
		{
			dig(x - 1, y - 1);
			dig(x - 1, y);
			dig(x - 1, y + 1);
			dig(x, y + 1);
			dig(x, y - 1);
			dig(x + 1, y - 1);
			dig(x + 1, y);
			dig(x + 1, y + 1);
		}
	}
}

static void mark(int x, int y)
{
	if (isValid(x, y) && mask(x, y) == Hide)
	{
		mask(x, y) = Flag;
	}
}

static int getBombCount()
{
	int count = 0;
	for (int y = 0; y < ny; ++ y)
	{
		for (int x = 0; x < nx; ++x)
		{
			if (mask(x, y) == Flag)
			{
				++count;
			}
		}
	}
	return count;
}

static void print()
{
	system("cls");
	printf(" �߰�: %2d, ��ü: %2d\n", getBombCount(), nBomb);
	printf("   ����������\n");

	for (int y = 0; y < ny; ++y)
	{
		printf("%2c ", 'A' + y);
		for (int x = 0; x < nx; ++x)
		{
			if (mask(x, y) == Hide) // ���� ���� ��
				printf("��");
			else if (mask(x, y) == Flag) // ���� ���� �ڸ�(��� ���� ��)
				printf("��");
			else // ��(dig) �ڸ�
			{
				if (isBomb(x, y)) // (MapLabel) 9: ����   
					printf("��");
				else if (isEmpty(x, y)) // (MapLabel) 0: ��ĭ ǥ��
					printf("  ");
				else
					printf("%2d", label(x, y)); // (MapLabel) 1 ~ 8: ���� ǥ��
			}
		}
		printf("\n");
	}
}

// ������ ������ �� ��� �Լ�
static int countNbrBombs(int x, int y)
{
	int count = 0;
	for (int yy = y - 1; yy <= y + 1; ++yy)
	{
		for (int xx = x - 1; xx <= x + 1; ++xx)
		{
			if (isValid(xx, yy) && label(xx, yy) == Bomb)
			{
				++count;
			}
		}
	}
	return count;
}

static void init(int total = 9)
{
	srand((unsigned int)time(NULL));
	
	// ���� ��, ����ũ �� �ʱ�ȭ
	for (int y = 0; y < ny; ++y)
	{
		for (int x = 0; x < nx; ++x)
		{
			mask(x, y) = Hide;
			label(x, y) = 0;
		}
	}

	nBomb = total;
	// ���� �ż�
	for (int i = 0; i < nBomb; ++i)
	{
		int x, y;
		do {
			x = rand() % nx;
			y = rand() % ny;
		} while (label(x, y) != Empty);
		label(x, y) = Bomb;
	}

	// ������ ������ �� ���
	for (int y = 0; y < ny; ++y)
	{
		for (int x = 0; x < nx; ++x)
		{
			if (label(x, y) == Empty)
				label(x, y) = countNbrBombs(x, y);
		}
	}
}

// Ű���� ��ǥ �Է� �Լ�
static bool getPos(int& x, int& y)
{
	printf("\n����(P) ��(A-I) ��(1-9)\n �Է� --> ");

	bool isBomb = false;
	y = toupper(_getch()) - 'A';    // 'a' -> 'A'   'A' --> 0

	// ��� �ȱ� ���� P�� ���� ���
	if (y == 'P' - 'A') 
	{
		isBomb = true;
		y = toupper(_getche()) - 'A';    // 'a' -> 'A'   'A' --> 0
	}

	x = _getch() - '1';    // '1' --> 1
	return isBomb;
}

// ���� ���� �˻� �Լ�
static int checkDone()
{
	int count = 0;
	for (int y = 0; y < ny; ++y)
	{
		for (int x = 0; x < nx; ++x)
		{
			if (mask(x, y) != Open)
				++count;
			else if (isBomb(x, y))
				return -1;
		}
	}
	return (count == nBomb) ? 1 : 0;
}

// ���� ã�� �� �Լ�
void playMineSweeper(int total)
{
	int x, y, status;

	init(total); // ���� �ʰ� ����ũ �ʱ�ȭ
	
	do {
		print();

		bool isBomb = getPos(x, y); // ��ġ �Է�
		if (isBomb) // ��� ��ġ�̸� ==> mark() ȣ��
			mark(x, y); 
		else  // �ƴϸ� ==> dig() ȣ��
			dig(x, y);
		status = checkDone(); // ���� ���� ��Ȳ �˻�
	} while (status == 0);
	print();
	if (status < 0)
	{
		printf("\n����: ���� ����!!!\n");
	}
	else
	{
		printf("\n����: Ž�� ����!!!\n\n");
	}
}