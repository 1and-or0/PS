#include <iostream>
#include <string>
using namespace std;
int main3()
{
	string str;
	cin >> str;

	// �ƽ�Ű�ڵ� ��ȯ 0(= 48) - '0'(= 48) = 0    '1' = 49
	int result = str[0] - '0';

	for (int i = 1; i < str.size(); ++i)
	{
		int num = str[i] - '0';
		// �� �� �߿��� �ϳ��� '0' or '1'�� ��� + ����
		if (num <= 1 || result <= 1)
			result += num;
		else
			result *= num;
		// else x ���� 
	}

	cout << result;

	return 0;
}