#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, int v, vector<bool>& visited) 
{
    // ���� ��带 �湮 ó��
    visited[v] = true;
    cout << v << ' ';

    // ���� ���� ����� �ٸ� ��带 ��������� �湮
    for (int i = 0; i < graph[v].size(); i++) 
    {
        int next_node = graph[v][i];
        if (!visited[next_node]) 
        {
            dfs(graph, next_node, visited);
        }
    }
}

int main_ex_dfs() {
    vector<vector<int>> graph = {
        {},           // 0�� ���
        {2, 3, 8},    // 1�� ���� ������ ���
        {1, 7},       // 2�� ���� ������ ���
        {1, 4, 5},    // 3�� ���� ������ ���
        {3, 5},       // 4�� ���� ������ ���
        {3, 4},       // 5�� ���� ������ ���
        {7},          // 6�� ���� ������ ���
        {2, 6, 8},    // 7�� ���� ������ ���
        {1, 7}        // 8�� ���� ������ ���
    };
    vector<bool> visited(9, false);

    dfs(graph, 1, visited);

    return 0;
}