#include <bits/stdc++.h>
using namespace std;

int main_ex_stack()
{
	stack<int> s;

	s.push(5);
	s.push(2);
	s.push(3);
	s.push(7);

	s.pop();

	s.push(1);
	s.push(4);

	s.pop();
	
	// s���� �ֻ�� ���Һ��� ���(= LI���� ���), Last In First Out
	stack<int> revers_s;
	while (!s.empty())
	{
		cout << s.top() << ' ';
		revers_s.push(s.top());
		s.pop();
	}
	cout << endl;
	
	// revers_s���� �ֻ�� ���Һ��� ��� s���� ���ϴ� ���ҿ��� �� ���� ���
	while (!revers_s.empty())
	{
		cout << revers_s.top() << ' ';
		s.push(revers_s.top());
		revers_s.pop();
	}
	cout << endl;
	

	return EXIT_SUCCESS;
}