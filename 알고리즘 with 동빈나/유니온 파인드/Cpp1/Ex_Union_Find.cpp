#include <bits/stdc++.h>
using namespace std;

// �ε��� == (���: 1~8), 
// �� == �� ��尡 ������ ��
int parent[9];

int find(int x);
void merge(int x, int y);
bool isUnion(int x, int y);

int main()
{
	// �迭 �ʱ�ȭ
	for (int i = 1; i <= 8; i++)
		parent[i] = i;

	merge(1, 2);
	merge(4, 5);
	merge(5, 6);

	cout << "2�� 4���� �����ΰ�?\n";
	cout << isUnion(2, 4) << "\n"; // false

	merge(1, 5);

	cout << "2�� 4���� �����ΰ�?\n";
	cout << isUnion(2, 4) << "\n"; // true

	return 0;
}

// �θ� ������ ���� ��Ʈ ��带 ã�� �Լ�
int find(int x)
{	// �迭 �ε����� ���� ���ٸ�, �ش� �� ����
	// == ��Ʈ �����
	if (parent[x] == x)
		return x;

	// �迭�� ���� �ε����� ���� �� ����
	// == �θ� ����� �θ� ��带 ã�� (���)
	return parent[x] = find(parent[x]);
}

// x��忡 y��带 �ڽ� ���� �����ϴ� �Լ�
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	
	// x�� y�� ���� �θ� ���� ����� 
	// == x, y�� �̹� �����
	if (x == y)
		return;

	// �迭[y] = x�� ���� == ��� ������
	parent[y] = x;

	return;
}

// �� ��尡 ����Ǿ��ִ��� �Ǻ��ϴ� �Լ�
bool isUnion(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return true;
	
	return false;
}
