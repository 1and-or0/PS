#ifndef BITS_STD_H10809
#define BITS_STD_H10809
#include <bits/stdc++.h>
using namespace std;
#endif // !BITS_STD_H10809

/// <�ذ� ���̵��>
/// A~Z���� 0 ~ 25�� �ε����� �ϴ� �迭 �����
/// �⺻�� -1�� �ʱ�ȭ
/// string st�� �Է¹��� ���ڿ� st[i]�� �ϳ��� ����
/// �̸� �ƽ�Ű�ڵ� ��ȣ�� �̿��� ������ ������� �迭�� �ε����� �ؼ� ���� 
/// st[i]���� i�� ���� ������ �迭�� ���ҷ� ���� ��
/// ����: ���� ���ڰ� st�� �ִ� ��� ���� ó���� ��ġ�� ���� �ϹǷ�
/// st[i]�� ���� -1���� Ȯ�� �� ���� �ֱ�
/// -1�� �ƴϸ� �̹� ���� ó���� ��ġ�� �� ����.
/// </�ذ� ���̵��>
int main_bj_10809()
{
	string st;
	cin >> st;

	int abc[26];
	fill_n(abc, 26, -1);  // abc �迭�� -1�� �ʱ�ȭ

	for (int i = 0; i < st.length(); ++i)
	{
		int index;
		index = (int) st[i] - 'a';
 		if(abc[index] == -1)
			abc[index] = i;
	}


	for (int i = 0; i < 26; ++i)
	{
		cout << abc[i] << ' ';
	}

	return EXIT_SUCCESS;
}