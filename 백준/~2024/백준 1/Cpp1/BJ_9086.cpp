#ifndef BITS_STDC_H9086
#define BITS_STDC_H9086
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STDC_H9086

int main_bj_9086()
{
	int n;
	cin >> n;

	string st;
	cin.ignore(); // ���� ����, C, JAVA������ ���ڸ� �Է¹޴ٰ� ���ڿ��� �Է¹ޱ� ���� ���ۿ� �����ִ� ���͸� ���־���
	for (int i = 0; i < n; ++i)
	{
		getline(cin, st);
		cout << st[0] << st[st.size() - 1] << endl;
	}


	return EXIT_SUCCESS;
}