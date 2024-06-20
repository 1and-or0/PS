// dp�� ��ȭ���� �� ������ ����
// Ư�� ����� ���� ���� ���� ó���� �� �ʿ䰡 ���� ������ �������� ��������
// ���� ����� dp������ ���߳�?
#include <bits/stdc++.h>
using namespace std;

// Ȧ�� �ε����� ���� ������� ���Ǹ� ���� �߰���.
int stairs[301 + 300] = { 0 };

// �������� ������ ���Ƽ� �� ����?
bool cantChoice(short index);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	short howMany;
	cin >> howMany;

	// �Է¹ޱ�
	for (short i = 2; i <= howMany * 2; i += 2) // 0 . 1 . 2 . 3 //  0 .1. 2 .3. 4 .5. 6
	{
		cin >> stairs[i];
	}

	int result = stairs[howMany*2]; // ������ ����� ������ ����
	bool towTimes = false;	// ������ �� ���� ����� ��ҳ�?
	// i �� ���� �� ������ ������ �ε����� �������� �Է¹��� ���� ����̶�� �� �� ����
	for (short i = howMany * 2 - 3; i > 0; )
	{
		if (!towTimes)  // ������ �ΰ��� ����� ���� �ʰ�
		{
			if (!cantChoice(i)) // �������� ������ ���� �ʾ� ������ ������ ��
			{
				if (stairs[i - 1] > stairs[i + 1]) 
				{ // �������� ���� ����� ����; �� ĭ �Ʒ� ����� ����
					result += stairs[i - 1];
					i -= 4;
				}
				else
				{ // ������ ����� ����; �� ĭ �Ʒ� ����� ����
					result += stairs[i + 1];
					i -= 2;
					towTimes = true;
				}
			}
			else  // �������� ������ ���� ������ �Ұ��� �� ��
			{
				result += stairs[i + 1]; // result += stairs[i + 1]; �� ����
				towTimes = true;
				i -= 2;
			}

		}
		else // ������ ����� ���� ��� �������� ������ ����
		{
			towTimes = false; 
			result += stairs[i - 1];
			i -= 4;
		}
	}

	cout << result;
	return 0;
}

bool cantChoice(short index)
{
	short left = index - 1;
	short right = index + 1;

	return (stairs[left] == stairs[right]);
}
