#include <stdio.h>


// ����ü: ����� ���� �ڷ���(user definded datatype)
typedef struct _tagMyST
{
	// �ڷ��� ������ a�� int �κ� �̶�� ������
	int a;

	// �ڷ��� ������ f�� float �κ� �̶�� ������
	float f;
}MYST;


typedef struct _tagBig
{
	// MYST ��� �ڷ����� �����ϴ� �� ū �ڷ����� ���� 
	MYST k;
	int i;
	char c;

}BIG;


// C��Ÿ�Ϸ� ����ü�� ������. C�� C++ ��ο��� �̿� �����ϱ� ������ 
typedef struct NewStruct
{
	int a;
	short s;
}NEWST; 
// struct NewStruct�� �ڷ����� �̸����� ���⿡ �ʹ� ��⿡ typedef�� ���� �ڷ����� ������
// ���ο� �̸�: NEWST �� �������

// typedef: int �ڷ����� INT�� ������ �߱� ������ ���� �����Ϸ��� INT�� int�� �޾Ƶ���
typedef int INT;


int main()
{
	// �迭 �ʱ�ȭ
	int array_1[10] = {};  // ��� ��� 0���� �ʱ�ȭ
	int array_2[10] = {1, 2, 3, 4, 5, 7, 66, 8, 9, 10};  // ���� ��ҿ� ���� �ʱ�ȭ
	int array_3[10] = {1, 2, 3, 4, };  // ���� ��ҿ� ���� 1, 2, 3, 4, 0, 0, 0, 0, 0, 0 ���� �ʱ�ȭ  

	// ����ü(struct�� �ڷ����� �ϳ��� ����� ���� �ڷ����� ��Ƴ��� �ڷ����̴�)
	// ������ �ʱ�ȭ�� �迭�� ����
	MYST t = {}; // �̷��� �ϸ� MYST�� a �κ� 0���� s �κ� 0���� �ʱ�ȭ
	t = { 1, 3.14f }; // �̷��� �ϸ� MYST(=_tagMyST)�� a�κ��� 1��, s �κ��� 3.14�� �ʱ�ȭ

	int size_int = sizeof(int);
	int size_float = sizeof(float);
	int size_MYST = sizeof(MYST);

	t.a = 10;
	t.f = 10.2354f;

	INT number = 999;

	// struct �ڷ��� �߿��� NewStruct��� ����� ���� �ڷ������� ������ �����
	struct NewStruct a;
	// �ڷ����� �̸��� struct NewStruct�� �ʹ� ����� ���� ���ο� �̸��� ����� �� ����
	NEWST b;
	// -- ������� C ��Ÿ�� -- 
	// C++������ ������ ��
	NewStruct k;
	// �̷��� struct�� ������ �ʰ� �׳� �� �� ����


	return 0;
}