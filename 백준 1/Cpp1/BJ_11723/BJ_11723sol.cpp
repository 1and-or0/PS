#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int m;
	cin >> m;
	int set_bit = 0;
	for (int i = 0; i < m; ++i)
	{
		string op;
		cin >> op;
		if (op == "add")
		{
			int temp;
			cin >> temp;
			set_bit |= (1 << temp);
		}
		else if(op == "remove")
		{
			int temp;
			cin >> temp;
			set_bit &= ~(1 << temp);
		}
		else if (op == "check")
		{
			int temp;
			cin >> temp;
			if (set_bit & (1 << temp))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (op == "toggle")
		{
			int temp;
			cin >> temp;
			set_bit ^= (1 << temp);
		}
		else if (op == "all")
		{// 1000... -1�� �ؼ� 0111 11... �� ����. 20~0��° ��ġ�� ��Ʈ ��� 1�� ����
			set_bit = (1 << 21) - 1;  
		}
		else if (op == "empty")
		{
			set_bit = 0;
		}
	}

	return 0;
}