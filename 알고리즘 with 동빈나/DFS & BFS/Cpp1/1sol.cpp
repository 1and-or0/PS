#include <bits/stdc++.h>
using namespace std;

bool ddfs(int x, int y);

int n1, m1;
vector<vector<int>> graph;

int main_1sol()
{
    // n, m�� ���� �������� ����, �Է� �ޱ�
    cin >> n1 >> m1;

    // 2���� ������ �� ���� �Է� �ޱ�
    graph.assign(n1, vector<int>(m1, 0));
    for (int i = 0; i < n1; i++) 
    {
        for (int j = 0; j < m1; j++) 
        {
            char c;
            cin >> c;
            graph[i][j] = c - '0';
        }
    }

    // ��� ���(��ġ)�� ���� ����� ä���
    int result = 0;
    for (int i = 0; i < n1; i++) 
    {
        for (int j = 0; j < m1; j++) 
        {
            // ���� ��ġ���� DFS ����
            if (ddfs(i, j)) 
            {
                result += 1;
            }
        }
    }
    cout << result << '\n';

	return EXIT_SUCCESS;
}

// DFS�� Ư�� ��带 �湮�ϰ� ����� ��� ���鵵 �湮
bool ddfs(int x, int y)
{
    // �־��� ����(�ε���)�� ��� ���, ����
    if (x <= -1 || x >= n1 || y <= -1 || y >= m1)
    {
        return false;
    }

    // ���� ��带 ���� �湮���� �ʾҴٸ� 
    if (graph[x][y] == 0) 
    {
        // �ش� ��� �湮 ó��
        graph[x][y] = 1;
        // �����¿� ��ġ�鵵 ��� ����� ȣ��
        ddfs(x - 1, y);
        ddfs(x + 1, y);
        ddfs(x, y - 1);
        ddfs(x, y + 1);
        return true;
    }

    return false;
}