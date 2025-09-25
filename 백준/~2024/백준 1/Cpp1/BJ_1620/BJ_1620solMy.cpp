#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	string* numToName = new string[100000]; // �ε����� ���� �̸� ����, ��ȣ = �ε��� + 1
	map<string, int> nameToNum; // �̸��� ���� �ε��� ����, ��ȣ = �ε��� + 1

	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		numToName[i] = temp;
		nameToNum[temp] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		string temp;
		cin >> temp;
		if ('0' > temp[0] || '9' < temp[0])
		{ // �̸��� �� ��, �ε��� + 1 = ��ȣ
			cout << nameToNum[temp] + 1 << "\n";
		}
		else
		{ // ��ȣ�� �� ��, ��ȣ - 1 = �ε���
			cout << numToName[stoi(temp) - 1] << "\n";
		}
	}
	return 0;
}