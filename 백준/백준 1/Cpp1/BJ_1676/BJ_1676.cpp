#include <bits/stdc++.h>
using namespace std;

int main()
{
	// �����÷ο� �������� �̷��� Ǯ�� �ȵ˴ϴ�
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	// ���丮�󿡼� 10�� ����� ����� �������� ���ֹ���
	// 3! = 6������ 2�� ��������.
	unsigned long long fact[500 + 1] = { 0 };
	fact[0] = 1;
	fact[1] = 1;

	// 0�� ������ �����ϴ� �迭
	int answer[500 + 1] = { 0 };

	int n;
	cin >> n;

	for (int j = 2; j < n + 1; ++j)
	{
		fact[j] = fact[j - 1] * j;
		
		if (fact[j] % 3 == 0)
			fact[j] = fact[j] / 3;
		else if (fact[j] % 7 == 0)
			fact[j] = fact[j] / 7;

	}

	return 0;
}