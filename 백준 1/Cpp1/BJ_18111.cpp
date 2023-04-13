#ifndef BJ_18111_CPP
#define BJ_18111_CPP
#include <bits/stdc++.h>
using namespace std;
#endif // !BJ_18111_CPP

int main()
{
	int n, m, b;
	cin >> n >> m >> b;
	int cnt[257];
	fill_n(cnt, 257, 0);

	for (int i = 0; i < 257; ++i)
	{
		cout << cnt[i] << i << endl;
	}
	cout << endl;
	int** arr = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[m];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}
	cout << endl << "arr" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << arr[i][j] << endl;
		}
	}
	delete[] arr;
	return EXIT_SUCCESS;
}