#include <bits/stdc++.h>
using namespace std;

int main()
{
	// L, R, U, D�� ���� �̵� ����
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	char moveTypes[4] = { 'L', 'R', 'U', 'D' };

	int x = 1, y = 1;

	int n;
	cin >> n;
	
	// C++, Java�� ��� ������ �Է¹��� �� ���ڿ��� �Է¹ޱ� ���� ���ۿ� ���Ͱ� ��������... ���͸� ����ִ� �� 
	// ex) �Է�
	// 4(����)     => 4 \n R R R U D \n => 4 \n (���� �Է� => R R R U D (���ڿ� �Է� => \n�� ���ۿ��� ���� 
	// R R R U D (���ڿ�)
	cin.ignore();  // ���� ����
	
	string plans;
	getline(cin, plans);

	for (int i = 0; i < plans.size(); ++i) // i < plans.size() 
	{
		char plan = plans[i];
		// �̵� �� ��ǥ �ٲٱ� (nx, ny �Ź� �ʱ�ȭ���ֱ� + plan = plans�� ���� �κ��� ��� if�� continue���� �������� �Ѿ 
		int nx = -1, ny = -1;
		for (int j = 0; j < 4; ++j)
		{
			if (plan == moveTypes[j])
			{
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		// ������ ��� ���� ����
		if (nx < 1 || ny < 1 || nx > n || ny > n)
			continue;

		x = nx;
		y = ny;
	}
	cout << x << ' ' << y << endl;

	return EXIT_SUCCESS;
}