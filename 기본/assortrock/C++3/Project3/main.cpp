#include <stdio.h>

int main()
{
	int* pint = nullptr;
	short* pshort = nullptr;
	char* pchar = nullptr;
	// int*  short*  char* �� �ش� �ּ��� ��ġ�� �ִ� �����͸� �ν��ϴ� type�� ������ �� ���̴�
	// ���� pint�� pshort, pchar�� ��� �ּҸ� �����ϹǷ� �� ������ ũ��� ����
	// �������� ũ��� ��� ���ٸ� ������ �������°�
	// �ü���� ���� ��������
	// 32bit �ü���� ���� 4byte ������ ����� ������� ����Ǳ� ������, �������� ũ��� 4byte�� �������
	// 64bit �ü���� ���� 8byte ������ ����� ������� ����Ǳ� ������, �������� ũ��� 8byte�� �������


	int itest = 10;
	int* pitest = &itest;
	printf("%d\n", pitest);
	printf("%d\n", sizeof(pitest));

	short stest = 12;
	short* pstest = &stest;
	printf("%d\n", pstest);
	printf("%d\n", sizeof(pstest));


	int itest2 = 10;
	int* pitest2 = &itest2;
	printf("%d\n", pitest2);
	printf("%d\n", sizeof(pitest2));

	short stest2 = 12;
	short* pstest2 = &stest2;
	printf("%d\n", pstest2);
	printf("%d\n", sizeof(pstest2));

	int itest3 = 10;
	int* pitest3 = &itest3;
	printf("%d\n", pitest3);
	printf("%d\n", sizeof(pitest3));

	short stest3 = 12;
	short* pstest3= &stest3;
	printf("%d\n", pstest3);
	printf("%d\n", sizeof(pstest3));
	
	return 0;
}