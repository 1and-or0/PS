#include <bits/stdc++.h>
using namespace std;

bool graph[128][128];
int blue_n, white_n;


// ���̿� �ϳ��� ���� �ִ��� Ȯ���ϴ� �Լ�
bool isSame(int x, int y, int size)
{
	bool color = graph[x][y];

	for (int xx = x; xx < x + size; ++xx)
	{
		for (int yy = y; yy < y + size; ++yy)
		{
			if (color != graph[xx][yy])
				return false;
		}
	}
	return true;
}

void myPaper(int x, int y, int size)
{
	if (size < 1)
		return;

	if (isSame(x, y, size))
	{
		if (graph[x][y])
			blue_n++;
		else
			white_n++;
		return;
	}
	else
	{
		myPaper(x, y, size / 2);  // ���� ��
		myPaper(x, y + size / 2, size / 2);  // ������ ��
		myPaper(x + size / 2, y, size / 2);  // ���� �Ʒ�
		myPaper(x + size / 2, y + size / 2, size / 2);  // ������ �Ʒ�
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> graph[i][j];
		}
	}

	myPaper(0, 0, n);
	cout << white_n << "\n";
	cout << blue_n << "\n";
	
	return 0;
}