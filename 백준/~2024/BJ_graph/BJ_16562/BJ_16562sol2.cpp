#include <bits/stdc++.h>
using namespace std;

int parent[10001]; // parent[��� ��ȣ] == �θ� ��� ��ȣ
int cost[10001]; // 

// �ֻ��� �θ� ã�� ���ε� �Լ�
int find(int x) 
{
    if (parent[x] == x) 
        return x;

    return parent[x] = find(parent[x]);
}

// �� �׷��� ��ġ�� ���Ͽ� �Լ�
void merge_parent(int a, int b) 
{
    a = find(a);
    b = find(b);
    if (a != b) 
    {
        // ����� ���� ���� �θ�� ����
        if (cost[a] > cost[b]) parent[a] = b;
        else parent[b] = a;
    }
}

int main() 
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M, k;
    cin >> N >> M >> k;

    // �ʱ�ȭ = �ڱ� �ڽ��� �θ�� ����
    for (int i = 0; i <= 10000; i++)
        parent[i] = i;
    for (int i = 1; i <= N; i++)
        cin >> cost[i];
    for (int i = 0; i < M; i++) 
    {
        int v, w;
        cin >> v >> w;
        merge_parent(v, w);
    }

    unordered_set<int> s;

    // ���տ� �� ģ���� �ֻ��� �θ� ����(�ߺ� ����)
    for (int i = 1; i <= N; i++)
    {
        s.insert(find(i));
    }
    int ans = 0;

    // �ߺ��� ���ŵ��� �� ����� ����
    for (auto it : s) 
    {
        ans += cost[it];
        k -= cost[it];
    }
    // k���� 0�̻��̶�� ����
    if (k >= 0)
        cout << ans;
    else
        cout << "Oh no";

    return 0;
}