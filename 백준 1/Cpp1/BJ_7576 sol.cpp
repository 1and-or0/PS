#include <bits/stdc++.h>
#define MAX_SIZE 1000 + 1

using namespace std;

struct tomato 
{
    int y, x;
};

queue<tomato> q;

// ��,��,��,��
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

int n, m, result = 0;
int graph[MAX_SIZE][MAX_SIZE];

bool isInside(int ny, int nx) 
{
    return (0 <= nx && 0 <= ny && nx < m && ny < n);
}

void bfs(void) 
{
    while (!q.empty()) 
    {
        // ť�� ���� ����(���� �丶��(1))�� ������
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        // �ش� ��ġ�� �ֺ��� Ȯ��
        for (int i = 0; i < 4; i++) 
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // ������ ����� �ʰ�, �������� �丶��(0)���
            if (isInside(ny, nx) == 1 && graph[ny][nx] == 0) 
            {
                graph[ny][nx] = graph[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    /* �丶�� ����(�׷���)�� ũ�� �Է� (����/����)*/
    cin >> m >> n;

    /* �׷��� ���� �Է�*/
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> graph[i][j];

            if (graph[i][j] == 1) 
            { // �����丶��(1) -> ť
                q.push({ i, j });
            }
        }
    }

    /* �׷����� BFS�� ���� Ž�� */
    bfs();

    /* ��¥ ��� �� ���  */
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            // �������� �丶��(0)�� ������ ���
            if (graph[i][j] == 0) 
            {
                cout << "-1";
                return 0;
            }
            // �丶��� �� �;��µ�, �󸶸��� �;�����?
            if (result < graph[i][j]) 
            {
                result = graph[i][j];
            }
        }
    }
    cout << result - 1;
    return 0;
}
