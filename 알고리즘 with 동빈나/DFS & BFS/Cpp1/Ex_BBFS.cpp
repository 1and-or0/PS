#include <bits/stdc++.h>
using namespace std;

void bbfs(vector<vector<int>>& graph, int start, bool(&visited)[9]) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < graph[v].size(); ++i) {
            if (!visited[graph[v][i]]) {
                q.push(graph[v][i]);
                visited[graph[v][i]] = true;
            }
        }
    }
}

int main_ex_bbfs() {
    vector<vector<int>> graph = {
    {}, // 0�� ���
    {2, 3, 8}, // 1�� ���� ������ ���
    {1, 7}, // 2�� ���� ������ ���
    {1, 4, 5}, // 3�� ���� ������ ���
    {3, 5}, // 4�� ���� ������ ���
    {3, 4}, // 5�� ���� ������ ���
    {7}, // 6�� ���� ������ ���
    {2, 6, 8}, // 7�� ���� ������ ���
    {1, 7} // 8�� ���� ������ ���
    };

    bool visited[9] = { false };
    bbfs(graph, 1, visited);

    return 0;
}