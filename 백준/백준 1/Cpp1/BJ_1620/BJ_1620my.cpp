// ��~ ��~ ��~ ��~ ��...
#include <bits/stdc++.h>
using namespace std;

// �������� Ȯ���ϴ� �Լ�
bool isNumber(char a)
{
	return (48 <= a && a <= 57);
}

// value�� key ���� ã�� �Լ�
int getKey(string value, int len, map<int, string>& book)
{
	for (int i = 0; i < len; ++i)
	{
		if (book[i+1] == value)
			return i+1;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	map<int, string> book;
	book[0] = "don't use";
	
	int n, m;
	cin >> n >> m; 
	for (int i = 0; i < n; ++i)
	{
		cin >> book[i + 1];
	}

	for (int i = 0; i < m; ++i)
	{
		string temp;
		cin >> temp;

		if (isNumber(temp[0]))
		{
			cout << book[stoi(temp)] << "\n";
		}
		else
		{
			cout << getKey(temp, n, book) << "\n";
		}
	}
	
	return 0;
}