#include <stdlib.h>
#include <stdio.h>

typedef struct _tagMySt
{// �ɹ�: ����ü�� �����ϴ� �ڷ��� �κе�. MYST�� ��� �ɹ����� int part�� float ��Ʈ�� �ִ� ����
	// ���⼭ a�� f�� ������ �ƴ�!!
	// �ɹ���!

	int i;
	float f;
}MYST;

int main()
{
	// ����ü�� ������
	// ����ü �ʱ�ȭ
	MYST x = {};
	
	MYST* p_x = &x;

	// x = ?;      ==    (*p_x) = ?;
	(*p_x).i = 100;
	 // x.i = 200;      ==    (*p_x).i = 200;
	(*p_x).f = 3.14f;

	// �ٿ����� �;�����? �׷��� ���� ǥ����
	// �������� ���� ��Ʈ�� ��Ī�ϴ� ���� �ѹ��� ǥ��. 
	p_x->i = 200;
	p_x->f = 2.71;



	return 0;
}