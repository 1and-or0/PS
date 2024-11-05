#include <iostream>
using namespace std;

int ans, cnt;

void DFS(int depth, int& N, int order[], int cost[11][11])
{
    if (depth == N)
    {
        int hap = 0;
        // ������ ���� ���� ���
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                hap += cost[order[i]][order[j]];
            }
        }

        if (hap > ans)
        {
            ans = hap;
            cnt = 1; // ���ο� �ִ밪�� �߰��ϸ� ����� ���� 1�� �ʱ�ȭ
        }
        else if (hap == ans)
        {
            cnt++; // ���� ������ ��� ����� ���� ����
        }
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        bool used = false;
        for (int j = 0; j < depth; j++)
        {
            if (order[j] == i) // �̹� ���� ��ǰ�� ����
            {
                used = true;
                break;
            }
        }
        if (!used)
        {
            order[depth] = i;
            DFS(depth + 1, N, order, cost); // ���� ���̷� �̵�
            order[depth] = -1; // ��Ʈ��ŷ: ���� ������ ���
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

    int T, N, M;
    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        ans = 0;
        cnt = 0;
        int cost[11][11] = { 0 }; // N�� �ִ밪�� 9�̹Ƿ� 11x11 �迭�� ����
        int order[10]; // ��ǰ�� ������ ������ �迭 (�ִ� 9��)

        for (int i = 0; i < M; i++)
        {
            int V, A, B;
            cin >> V >> A >> B;
            cost[A][B] += V; // A�� B���� �տ� ���� �� V��ŭ�� ���� �߰�
        }

        DFS(0, N, order, cost);
        cout << ans << " " << cnt << "\n";
    }

    return 0;
}
