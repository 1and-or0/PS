#include <bits/stdc++.h>
using namespace std;

string graph[100];
char now; // Ž������ ������ R, G, B �� ��� ������ ������
queue<pair<int, int>> q;

//  �Ʒ�, ������, ��, ����
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs() 
{
    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (graph[x][y] == '.' || graph[x][y] == 'K')
            continue;

        if (now == 'B')
            graph[x][y] = '.';
        else // R - G �� ��� K�� �ٲٰ� bfs�� �����ϸ� �������� ���� ������ ����
            graph[x][y] = 'K';

        for (int i = 0; i < 4; ++i) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // ������ ��� ���
            if (nx < 0 || nx >= graph[0].length() || ny < 0 ||
                ny >= graph[0].length())
                continue;

            // Ž���ϰ� �ִ� ��尡 ���� ����� ���
            if (now == graph[nx][ny]) 
            {
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void bfs2()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (graph[x][y] == '.')
            continue;
        else
            graph[x][y] = '.';

        for(int i=0; i<4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // ������ ��� ���
            if (nx < 0 || nx >= graph[0].length() || ny < 0 ||
                ny >= graph[0].length())
                continue;

            // Ž���ϰ� �ִ� ��尡 ���� ����� ���
            if (now == graph[nx][ny])
            {
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    // �Է¹ޱ�
    for (int i = 0; i < n; ++i) 
    {
        cin >> graph[i];
    }

    int n_R = 0, n_G = 0, n_B = 0, n_RG = 0;

    now = graph[0][0];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < graph[i].length(); ++j) 
        {
            if (graph[i][j] != '.' && graph[i][j] != 'K')
            {
                now = graph[i][j];
                q.push(make_pair(i, j));
                bfs();
                switch (now)
                {
                case 'R':
                    n_R++;
                    break;
                case 'G':
                    n_G++;
                    break;
                case 'B':
                    n_B++;
                    break;
                }
            }
        }
    }


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < graph[i].length(); ++j)
        {
            if (graph[i][j] != '.')
            {
                now = graph[i][j];
                q.push(make_pair(i, j));
                bfs2();
                n_RG++;
            }
        }
    }
    cout << n_R + n_G + n_B << " " << n_RG + n_B;

    return 0;
}