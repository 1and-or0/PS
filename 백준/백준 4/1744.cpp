#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> positive, negative;
    int zeroCount = 0;
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > 1)
            positive.push_back(x);
        else if (x == 1)
            oneCount += 1;
        else if (x == 0)
            zeroCount++;
        else
            negative.push_back(x);
    }

    // ū ���� �տ� ������ ����
    sort(positive.begin(), positive.end(), greater<int>());
    // ������ ���� ���� �տ� ������ ����
    sort(negative.begin(), negative.end());

    long long ans = 0;

    // ��� ó��
    for (size_t i = 0; i + 1 < positive.size(); i += 2)
    {
        // �� ���� ���� ��
        ans += positive[i] * positive[i + 1];
    }
    if (positive.size() % 2 == 1)
    {
        // ���� �ϳ� ���ϱ�
        ans += positive.back();
    }

    ans += oneCount;

    // ���� ó��
    for (size_t i = 0; i + 1 < negative.size(); i += 2)
    {
        // �� ���� ���� ��
        ans += negative[i] * negative[i + 1];
    }
    if (negative.size() % 2 == 1 && zeroCount == 0)
    {
        // ���� �ϳ��� ���Ҵµ� 0�� ������ ���ϱ�
        ans += negative.back();
    }

    cout << ans << endl;
    return 0;
}
