#include "SpeedGugu.h"

void main()
{
	srand(time(NULL));

	int nPlay = 10;
	printf("<���ǵ� ������ ����>\n\n");
	printf("����� ������ �Ƿ��� �׽�Ʈ�ϼ���.!!!\n\n");
	printf(" ���� %d���� ���� �׽�Ʈ �ϰڽ��ϴ�.\n", nPlay);
	printf("ũ�� ��ȣ���� �Ͻð�...\n �غ�Ǹ� ���͸� ��������...");
	getchar();

	// ȭ�� ����
	system("cls"); 

	double score = playSpeedGugu(nPlay);
	printf("\n ����: %4.2lf��(�� %4.2lf��)\n", score, tElapsed);


	return;
}