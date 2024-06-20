#include <iostream>
#include <iomanip>

using namespace std;

void summ();


int main()
{
	cout << 2017 << endl; // "2017" ���
	cout << setw(8) << 2023 << endl; // 8�ڸ��� ǥ�� "_ _ 2023" ���
	
	cout << fixed;  //  ���� �Ҽ��� ǥ�� ����

	cout << setw(8)  // 8�ڸ��� ǥ��
		 << setprecision(3)  // �Ҽ��� ���� 3�ڸ�
		 << setfill('0')    // �� �ڸ��� 0�� ä��
		 << 3.14159 << endl;   // "0003.142" ���

	cout //<< setw(8)  // 8�ڸ��� ǥ��
		 << setprecision(3)  // �Ҽ��� ���� 3�ڸ�
		 << setfill('0')    // �� �ڸ��� 0�� ä��
		 << 3.14159 << endl;   // "3.142" ���

	cout << setw(8)  // 8�ڸ��� ǥ��
		 << setprecision(3)  // �Ҽ��� ���� 3�ڸ�
		 << setfill('?')    // �� �ڸ��� 0�� ä��
		 << 3.14159 << endl;   // "3.142" ���

	cout << setw(8)  // 8�ڸ��� ǥ��
		 //<< setprecision(3)  // �Ҽ��� ���� 3�ڸ�
		 //<< setfill('?')    // �� �ڸ��� 0�� ä��
		 << 3.14159 << endl;   // "3.142" ���
	
	cout << 21.15743 << endl;

	cout << 54621.15743 << endl;

	return 0;
}



void summ()
{
	int x, y;
	cout << "�� ���� �Է�: ";
	cin >> x >> y;
	cout << " x: " << x;
	cout << " y: " << y;
	cout << " x + y: " << x + y << endl;


	cin >> x >> y;
	cout << "x: " << 3 << endl; // stdout ���� �� ����(endl) ���
	cout << x << y << flush; // flush: ��� ���۸� ���

	char c1, c2, c3 = 'Z';
	c1 = cin.get(); // c = getchar(); �� ���� �Է�

	char s[10];
	cin.get(c2); // char �� ����. �� ���� �Է�
	cin.getline(s, 10, '\n'); // '\n' (default) ���� �� ������ �о� char �迭 s�� ����

	cout << "c1: " << c1 << endl << "c2: " << c2 << endl << "c3: " << c3 << endl;

	cin.get(c3);
	cout << "c1: " << c1 << endl << "c2: " << c2 << endl << "c3: " << c3 << endl;
}