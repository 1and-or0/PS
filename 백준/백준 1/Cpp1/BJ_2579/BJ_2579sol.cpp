#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	// ����� ����
	int howMany;
	cin >> howMany;
	// ��ܺ� ������ ������ �迭
	int stairs[300] = { 0 };
	// �Է¹ޱ�
	for (int i = 0; i < howMany; ++i)
	{
		cin >> stairs[i];
	}

	// ���� ������ ����� �������� ���� ���� ������� �ʾƵ� �Ǵ°�
	// ���� ������ ����: result - ������ ��� ������ ����
	int result = stairs[howMany - 1];
	bool towTimes = false;  // �ι� ���ӵ� ����� ��ҳ�
	// int nowOn = howMany - 1;  // ���� �� �ִ� ����� �ε���
	for (int i = howMany - 2; i > 0; )
	{
		if (!towTimes)
		{
			if (stairs[i] > stairs[i - 1])
			{
				result += stairs[i];
				i -= 1;
				towTimes = true;
			}
			else
			{
				result += stairs[i - 1];
				i -= 2;
			}
		}
		else
		{
			towTimes = false;
			result += stairs[i - 1];
			i -= 2;
		}
	}
	cout << result;

	return 0;
}