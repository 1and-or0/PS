#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	// rate: �� ���� ������ ���, weight: �� ������ ����
	vector<int> rate(n + 1), weight(m + 1);
	for (int i = 1; i <= n; i++)
		cin >> rate[i];
	for (int i = 1; i <= m; i++)
		cin >> weight[i];

	set<int> s; // ��� ���� ���� ��ȣ
	for (int i = 1; i <= n; i++)
		s.insert(i);

	int ans = 0;
	unordered_map<int, int> pos;  // ������ ������ ��� ��ȣ
	queue<int> q;  // ���� ���Ա��
	for (int i = 0; i < 2 * m; i++)
	{
		int car; cin >> car;

		if (car > 0) 
			q.push(car);
		else 
		{
			s.insert(pos[-car]); // ������ �����Ǿ� �ִ� ���� �ٽ� �ڸ��� ��
			pos.erase(-car); // ������ �ٽ� ���� ������ ���� �̹� ����� ���� �����
		}

		while (!q.empty() && !s.empty()) 
		{
			set<int>::iterator iter = s.begin();
			pos[q.front()] = *iter; // ������ ������ ���� ��ȣ ���� by map
			ans += weight[q.front()] * rate[*iter];
			s.erase(*iter); // �ش� ���� ������ ������� ����
			q.pop(); // ó���� ���� ���Ա�� ť���� ����
		}
	}

	cout << ans << '\n';
	
	return 0;
}