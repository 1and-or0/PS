#include "calcTax.h"


void main()
{
	printf("%d\n", sizeof(char));

	int income = 0;
	double tax;
	printf("������ �Է��ϼ���: ");
	scanf_s("%d", &income);

	tax = calcTax(income);
	printf("��ü ������ %7.2f�����Դϴ�.\n", tax);
	printf("���� �ҵ��� %7.2f�����Դϴ�.\n", income - tax);

	return;
}