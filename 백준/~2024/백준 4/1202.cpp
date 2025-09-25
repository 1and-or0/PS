#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int n, k;
vector<pair<int, int>> v;
vector<int> bag;

priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    // ���� ���� �Է�
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second; // {����, ����}
    }
    sort(v.begin(), v.end()); // ���Ը� �������� ����

    // ���� ���� �Է�
    bag.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> bag[i];
    }
    sort(bag.begin(), bag.end()); // �뷮�� �������� ����

    long long ans = 0;
    int index_jewel = 0;

    for (int i = 0; i < k; i++) // �� ���濡 ����
    {
        // ���� ���濡 ���� �� �ִ� ��� ������ �켱���� ť�� �߰�
        while (index_jewel < n && v[index_jewel].first <= bag[i])
        {
            pq.push(v[index_jewel].second);
            index_jewel++;
        }

        // ���� ��� ������ ������ ���濡 ����
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;
    return 0;
}
