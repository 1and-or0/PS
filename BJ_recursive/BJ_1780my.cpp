#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph;  // ���� �Է¹��� ����
vector<int> sum(3);  // ���� �����ϴ� ����

void makepaper(int row, int col, int size);
bool checkpaper(int row, int col, int size);
void sumpaper(int row, int col);

int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    // resize(10, 100) vector ũ�� 10�� ���� 100���� �ʱ�ȭ �Ѵٴ� ��. 
    graph.resize(n, vector<int>(n, 0)); // ������ ���͸� �ʱ�ȭ��
    // �Է¹���
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    makepaper(0, 0, n);

    for (int i = 0; i < sum.size(); i++)
    {
        cout << sum[i] << "\n";
    }
}

void makepaper(int row, int col, int size)
{
    int inner_size = size / 3;
    if (size == 1) // �ּ� ũ���϶� ���� - �����ؾ��ұ�?
    { //cout << "������ ���Ұ��� ũ��� �ּ� 1�Դϴ�" << endl;
        for (int i = 0; i < size; ++i)
        {
            sumpaper(row + (i / 3), col + (i % 3));
        }
    }
    else
    {
        // ���� ū ���̷� ���� �˻�
        if (checkpaper(row, col, size) == true)
        { // ���� ū ������ ��� ���� ��ġ�� �׻� 0��0�� == graph[0][0]��
            sumpaper(row, col);
            return;
        }
        else
        {
            for (int i = 0; i < 9; ++i)
            {
                makepaper(row + (i / 3) * inner_size, col + (i % 3) * inner_size, inner_size);
            }
        }
    }
}

// -1�� sum[0]��, 0�� sum[1]��, 1�� sum[2]�� ������ ������ ������
void sumpaper(int row, int col)
{
    int num = graph[row][col];
    switch (num)
    {
    case -1:
        sum[0] += 1;
        break;
    case 0:
        sum[1] += 1;
        break;
    case 1:
        sum[2] += 1;
        break;
    }
}

// row�� col������ ũ�� s�� ��������� ��� ���� �������� �˻��ϴ� �Լ�
bool checkpaper(int row, int col, int s)
{
    int check = graph[row][col]; //-1,0,1 �ƴ� ���ڸ� ����
    bool cp = true;
    for (int i = row; i < row + s; i++)
    {
        if (cp == false)
        {
            break;
        }
        for (int j = col; j < col + s; j++)
        {
            if (check != graph[i][j]) {
                cp = false;
                break;
            }
        }
    }
    return cp;
}
