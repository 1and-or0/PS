#include <stdio.h> 
#include "func.h"  
// func.h ������ ������ ���̴�
// #inlcude�� ��ó����� ����س��� func.h ������ �����ϴ� ������. ���̽� import ����



//// �������� ���� 
//static int g_iStatic = 0;
#include "common.h"

void printing()
{
	printf("g_iStatic�� ��: %d", g_iStatic);
	g_iExtern += 1;
	printf("����?: \n%d\n", g_iExtern);
}

// ������ func.h ���Ͽ��� �߰� �̸� �����߱� ������ ���Ǹ� ���ָ� ��
// ���� ��������
int Add(int a, int b)
{
	printf("�̰� ����..:\n");
	g_iExtern += 1;
	printf("g_iExtern: %d\n", g_iExtern);

	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}


int Mul(int a, int b)
{
	return a * b;
}


int Div(int a, int b)
{
	return a / b;
}
