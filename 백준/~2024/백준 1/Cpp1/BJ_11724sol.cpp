#include <bits/stdc++.h>
using namespace std;

vector<int> vect[1001]; //��������Ʈ
int visited[1001];      //�湮���
int N, M;

/* DFS : �湮��� ����� �뵵 */
void DFS(int vertex)
{
    visited[vertex] = 1;
    for (int i = 0; i < vect[vertex].size(); i++) //�ִ� ���� : ���� �� ���ҿ� �ش��ϴ� ũ�⸸ŭ ���ƾ���
    {
        int idx = vect[vertex][i];
        if (visited[idx] == 0)
        {
            DFS(idx);
        }
    }
}

int main()
{
    int u, v;
    int cnt = 0; // ��� �����ϴ� ����
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        vect[u].push_back(v);
        vect[v].push_back(u); //������ �׷����̱� ����
    }

    for (int i = 1; i <= N; i++) //�������� Ž���ϱ� ����
    {
        if (visited[i] == 0)
        {
            DFS(i);
            cnt++;
        }
    }
    cout << cnt << "\n";
}