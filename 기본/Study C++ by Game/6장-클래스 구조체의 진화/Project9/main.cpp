#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string s1, s2 = "Game";
	s1.size(), s2.size();  // ���ڿ��� ����: 0, 5
	s1 = s2 + ' ' + "Over";
	if (s1 == "Game Over")
	{
		cout << s1 << "�� �½��ϴ�\n";
	}

	cout << s1.find("Over") << endl;  // ���ڿ��� ó������ Over �˻�, ��ġ ��ȯ.
	cout << s1.find("e", 4) << endl;  // 4�� ��ġ���� "e"�˻�. ��ġ ��ȯ // ������ (string::nnpos   or  -1) ��ȯ

	cout << s1[0] << endl;
	cout << s1.substr(5, 4) << endl; // s1[5] ���� ���� 4 ��ŭ ���ڿ� ����
	printf("s1: %s\n", s1.c_str());  // string���� ���� �迭 �ּ� char* ����
	getline(cin, s1);
	cout << s1 << endl; 

	
	
	
	return 0;
}