#include <bits/stdc++.h>

using namespace std;

int main4()
{
	int n;
	vector<int> arr;

	cin >> n;
	
	for (int i = 0; i < n; ++i)// vector<int>�� �Է¹��� ���� �߰�
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	int result = 0; // ������� �� �ִ� �� ���谡 �׷� �� 
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		// ���� �׷쿡 ���谡 ����
		count += 1;
		if (count >= arr[i])
		{
			result += 1;
			count = 0;
		}
	}

	cout << result << endl;

	return EXIT_SUCCESS;
}