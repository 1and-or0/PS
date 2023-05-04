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
        cout << sum[i] << endl;
    }
}

void makepaper(int row, int col, int size)
{
    int inner_size = size / 3;
    if (inner_size < 1) // �ּ� ũ���϶� ���� - �����ؾ��ұ�?
        return; //cout << "������ ���Ұ��� ũ��� �ּ� 1�Դϴ�" << endl;
    else
    {
        // ���� ū ���̷� ���� �˻�
        if (checkpaper(row, col, size) == true)
        { // ���� ū ������ ��� ���� ��ġ�� �׻� 0��0�� == graph[0][0]��
            sumpaper(0, 0);
            return;
        }

        // 9��� �� ���� ���� �ϳ��� �����ΰ� �˻�
        if (checkpaper(row, col, inner_size) == false)
        {// �ϳ��� ���̰� �ƴ� ���
            // cout << "graph1 is not same" << endl;
            makepaper(row, col, inner_size);
        }
        else
        { // true�� ��� ���� ������ ������Ұ� �ִٴ� ���̴�.
           // cout << "graph1 is same." << endl;
            sumpaper(row, col);
        }

        // 9��� �� ��� ���� �ϳ��� �����ΰ� �˻�
        if (checkpaper(row, col + inner_size, inner_size) == false)
        { // cout << "graph2�� ������ ��Ҵ� ��� ���� �ʽ��ϴ�" << endl;
            makepaper(row, col + inner_size, inner_size);
        }
        else
        { // cout << "graph2 is  same" << endl;
            sumpaper(row, col + inner_size);
        }

        // 9��� �� ������ ���� �ϳ��� �����ΰ� �˻�
        if (checkpaper(row, col + 2 * inner_size, inner_size) == false)
        {// cout << "graph3 is not same" << endl;
            makepaper(row, col + 2 * inner_size, inner_size);
        }
        else
        {//cout << "graph3 is same" << endl;
            sumpaper(row, col + 2 * inner_size);
        }

        // 9��� �� ���� ����� �ϳ��� �����ΰ� �˻�
        if (checkpaper(row + inner_size, col, inner_size) == false)
        { //cout << "graph4 is not same" << endl;
            makepaper(row + inner_size, col, inner_size);
        }
        else
        { // cout << "graph4 is same" << endl;
            sumpaper(row + inner_size, col);
        }

        // 9��� �� �߾��� �ϳ��� �����ΰ� �˻�
        if (checkpaper(row + inner_size, col + inner_size, inner_size) == false)
        {// cout << "graph5 is not same" << endl;
            makepaper(row + inner_size, col + inner_size, inner_size);
        }
        else
        {// cout << "graph5 is same" << endl;
            sumpaper(row + inner_size, col + inner_size);
        }

        //9��� �� ������ ����� �ϳ��� �����ΰ� �˻�
        if (checkpaper(row + inner_size, col + 2 * inner_size, inner_size) == false)
        {// cout << "graph6 is not same" << endl;
            makepaper(row + inner_size, col + 2 * inner_size, inner_size);
        }
        else
        {//cout << "graph6 is same" << endl;
            sumpaper(row + inner_size, col + 2 * inner_size);
        }
        
        // 9����� ���� �Ʒ��� �ϳ��� �����ΰ� �˻�
        if (checkpaper(row + 2 * inner_size, col, inner_size) == false)
        { // cout << "graph7 is not same" << endl;
            makepaper(row + 2 * inner_size, col, inner_size);
        }
        else
        {// cout << "graph7 is same" << endl;
            sumpaper(row + 2 * inner_size, col);
        }

        // 9��� �� ��� �Ʒ��� �ϳ��� �����ΰ� �˻�
        if (checkpaper(row + 2 * inner_size, col + inner_size, inner_size) == false)
        {// cout << "graph8 is not same" << endl;
            makepaper(row + 2 * inner_size, col + inner_size, inner_size);
        }
        else
        {// cout << "graph8 is same" << endl;
            sumpaper(row + 2 * inner_size, col + inner_size);
        }

        // 9��� �� ������ �Ʒ��� �ϳ��� �����ΰ� �˻�
        if (checkpaper(row + 2 * inner_size, col + 2 * inner_size, inner_size) == false)
        { // cout << "graph9 is not same" << endl;
            makepaper(row + 2 * inner_size, col + 2 * inner_size, inner_size);
        }
        else
        { // cout << "graph9 is same" << endl;
            sumpaper(row + 2 * inner_size, col + 2 * inner_size);
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
