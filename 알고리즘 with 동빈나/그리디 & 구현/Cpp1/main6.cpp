#include <bits/stdc++.h>
using namespace std;

bool Check(int h, int m, int s);

const int keyNum = 3;  // ���� m�� ���Ե� ��츦 ��� ����, m�� keyNum�� ����

int main6()
{
	int h, count = 0;
	cin >> h;
	for(int i=0; i<=h; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			for (int k = 0; k < 60; ++k)
			{
				if (Check(i, j, k))
					++count;
			}
		}
	}
	cout << count << endl;
	return EXIT_SUCCESS;
}

bool Check(int h, int m, int s)
{
	if (h / 10 == keyNum || h % 10 == keyNum || m / 10 == keyNum || m % 10 == keyNum || s / 10 == keyNum || s % 10 == keyNum)
		return true;
	return false;
}