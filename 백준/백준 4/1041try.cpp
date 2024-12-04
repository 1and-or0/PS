#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int n;
int a, b, c, d, e, f;
//const int a = 0, b = 1, c = 2, d = 3, e = 5, f = 5;

const int n_vertex = 4, n_edge = 4, n_side = 1;
// �ֻ��� �ϳ�����, index��ŭ�� ���� �������� �ֻ��� ����
unsigned long long a_dice_n_side[6 + 1] = { 0 };
unsigned long long ans = -1;

unsigned long long min_three_side = 50 * 3 + 1;
unsigned long long min_two_side = 50 * 2 + 1;

void check_n()
{
	int max_value = max({ a, b, c, d, e, f });
	int min_value = min({ a, b, c, d, e, f });
	if (n == 1)
	{
		ans = a + b + c + d + e + f - max_value;
	}
	else if (n == 2)
	{
		a_dice_n_side[3] = (unsigned long long) n_vertex;
		a_dice_n_side[2] = (unsigned long long) n_edge;
		ans = a_dice_n_side[3] * min_three_side + a_dice_n_side[2] * min_two_side;
	}
	else
	{
		a_dice_n_side[3] = (unsigned long long) n_vertex; // 4 = (8-4)
		a_dice_n_side[2] = (unsigned long long) (n - 2) * 2 * n_edge + 4; // 12 = (12 + 4 - 4)
		a_dice_n_side[1] = (unsigned long long) (n - 2) * (n - 2) * (6 - 1) * n_side + (n - 2) * n_edge; // 9 = (6+4-1) 

		ans = a_dice_n_side[3] * min_three_side + a_dice_n_side[2] * min_two_side + a_dice_n_side[1] * min_value;
	}
}

int main()
{
	cin >> n >> a >> b >> c >> d >> e >> f;

	unsigned long long bc = b + c, bd = b + d, ce = c + e, de = d + e;

	// find min_three_side's value
	for (unsigned long long i : {a, f})
	{
		for (unsigned long long ii : { bc, bd, ce, de })
		{
			min_three_side = min_three_side > i + ii ? (i + ii): min_three_side;
		}
	}
	// find min_two_side's value
	int abcdef[] = { a, b, c, d, e, f };
	char temp_gap1 = 5, temp_gap2 = 1;
	for (int i = 0; i < sizeof(abcdef)/sizeof(abcdef[0]); i++)
	{
		for (int ii = 0; ii < sizeof(abcdef)/sizeof(abcdef[0]); ii++)
		{
			if (i == ii)
				continue;
			
			// �ֻ��� ������ �Ұ���, ������ �鿡 �ִ� �� ������ ���
			if (i < ii && ii - i == temp_gap1)
			{
				temp_gap1 -= 2;
				continue;
			}
			else if (ii < i && i - i == temp_gap2)
			{
				temp_gap2 += 2;
				continue;
			}

			min_two_side = min_two_side > abcdef[i] + abcdef[ii] ? (abcdef[i] + abcdef[ii]) : min_two_side;
		}
	}

	check_n();

	cout << ans << endl;

	return 0;
}