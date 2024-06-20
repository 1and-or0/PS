#include <bits/stdc++.h>
using namespace std;

// ��Ŭ���� ȣ���� �ݺ��� a > b
int Euclidean_algorithm_iterative(int a, int b)
{
	int temp_a = a;
	a = a > b ? a : b;
	b = a > b ? b : temp_a;

	int r = a % b;
	if (0 != a % b)
	{
		while (r != 0)
		{
			a = b;
			b = r;
			r = a % b;
		}
		return b;
	}
	else
	{
		return b;
	}
}

// ��Ŭ���� ȣ���� ����� a > b
int Euclidean_algorithm_recursive(int a, int b)
{
	int temp_a = a;
	a = a > b ? a : b;
	b = a > b ? b : temp_a;

	if (0 != a % b)
	{
		return Euclidean_algorithm_recursive(b, a%b);
	}
	else
	{
		return b;
	}
}

int main_ex_Euclidean_algorithm()
{
	int a, b;
	cin >> a >> b;

	cout << Euclidean_algorithm_iterative(a, b) << endl;
	cout << Euclidean_algorithm_recursive(a, b) << endl;

	return 0;
}