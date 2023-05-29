#include <bits/stdc++.h>
using namespace std;

int n, m, k; // ģ����: n, �����: m, �ʱ��ں�: k
vector<int>vec; // ģ�� ���
vector<int>graph[10001]; // ģ�� ���� �׷���
bool visited[10001]; // ģ�� �湮���� Ȯ��
int result = 0;

void init()
{	// �Է¹ޱ� - ���
	cin >> n >> m >> k;
	vec.resize(n + 1); // vec[ģ����ȣ]�� �����ϰ� �ʱ�ȭ
	for (int i = 1; i <= n; i++) 
	{
		int num; cin >> num;
		vec[i] = num;
	}

	for (int i = 1; i <= m; i++)
	{	// �Է¹ޱ� - ����	
		int v, w; cin >> v >> w;
		graph[v].push_back(w);
		graph[w].push_back(v);
	}

	// �湮 Ȯ�ο� �迭 ��� �湮���� ���� ������ �ʱ�ȭ
	memset(visited, false, sizeof(visited));
	
	return;
}


// ���� �Ұ� minimum�� ������ �����ΰ�? �� min�Լ���... ��...
// dfs ���鼭 ���� �׷������� ���� ���� �� ���ϱ�
// �� ���� k ���ϸ� �װ� ����, �ƴϸ� fail
int dfs(int node, int minimum)
{
	visited[node] = true;

	for (auto next_node : graph[node]) 
	{
		if (visited[next_node])
			continue;

		minimum = dfs(next_node, min(minimum, vec[next_node]));
	}

	return min(minimum, vec[node]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// �ʱ�ȭ + �Է¹ޱ�
	init();

	// ???
	int minimum = 100000000; // 100,000,000 = 10,000 ** 2

	for (int node = 1; node <= n; node++) 
	{	// �湮���� ���� ��쿡 dfs ����
		if (visited[node] == true)
			continue;
		result += dfs(node, minimum);
	}

	if (result > k)
		cout << "Oh no";
	else
		cout << result;
	
	return 0;
}
