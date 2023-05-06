#include <bits/stdc++.h>
using namespace std;

void addFromString(string::iterator start, const int len, int* whereAdd);

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	// + 와 - 연산을 기준으로 숫자만을 구분한다
	// - 연산을 기준으로 왼쪽에 있는 숫자와 오른 쪽에 있는 숫자를 따로 저장한다
	// 길이가 5면 연산은 최대 2개 수는 최대 3개 길이가 9이면 1 1 1 1 1 6이면 11 1 1
	// 길이 50 최대로 숫자가 여러번 들어올 경우 25개의 숫자 24개의 연산자
	// 1+2 - 2+5+2 - 5+2 - 5+2 - 5+6								
	// 12345 
	int positive = 0, negative = 0;
	string str;
	cin >> str;

	bool plusLeft = true;
	int _index = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (plusLeft)
			{
				addFromString(str.begin()+_index, i - _index, &positive);
			}
			else
			{
				addFromString(str.begin() + _index, i - _index, &negative);
			}
			_index = i + 1;

			if (str[i] =='-' && plusLeft)
			{
				plusLeft = false;
			}
		}
		else if (i == str.size() - 1)
		{
			if (plusLeft)
			{
				addFromString(str.begin() + _index, i - _index + 1, &positive);
			}
			else
			{
				addFromString(str.begin() + _index, i - _index + 1, &negative);
			}
		}
	}

	cout << positive - negative ;
	return 0;
}

void addFromString(string::iterator start, const int len, int * whereAdd)
{
	stringstream ss;
	string num;
	for (int i = 0; i < len; ++i)
	{
		num += start[i];
	}
	ss << num;
	int temp = 0;
	ss >> temp;
	//cout << temp;
	*whereAdd += temp;
}
