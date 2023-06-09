#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    if (n == 0) //n�� 0�̸� 0��� �� ����
    {
        cout << 0 << endl;
        return 0;
    }

    //�Է�
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());    //����

    float res = 0;

    // 30%�� ��������� ���� - // �Ʒ�, ���� 15%
    float tmp = n * 0.15;
    tmp = round(tmp);    //�ݿø�

    // �ݿø��� ��������� �Ʒ�15%, �� 15%���� �����ϰ� ����
    for (int i = tmp; i < n - tmp; i++)
        res += v[i];

    res /= (n - tmp * 2);    //���
    res = round(res);    //�ݿø�

    cout << res << endl;

    return 0;
}