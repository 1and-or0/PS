#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int x = 1, y = 2;
	char s[100];

	ofstream f1("tmp.txt"); // ������ ���� ���� ����
	
	if (f1)
	{
		f1 << x << " " << y << endl; // ���Ϸ� int �� ����
		f1 << "Game Over !\n\n"; // ���Ϸ� ���ڿ� ����
	}
	f1.close();

	ifstream f2("tmp.txt");  // �б⸦ ���� ���� ����
	if (f2)
	{
		f2 >> x >> y;   // ���Ϸκ��� x�� y �б�
		f2 >> s; // ���Ϸκ��� ���ڿ� �б�

		cout << "x: " << x << "\t" << "y: " << y << endl;
		cout << s << endl;
	}
	f2.close();



	return 0;
}