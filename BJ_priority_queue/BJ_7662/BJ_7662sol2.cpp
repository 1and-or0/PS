#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000 + 1;

int N;
// n��°�� ���� ���ڰ� heap�� �����ִ��� ���θ� ������
bool visited[MAX]; // index: n��°, true: ��������, false: ����(pop�ǹ���)

int main(void)
{
    ios_base::sync_with_stdio(0);    cin.tie(0);

    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++)
    {
        cin >> N;

        priority_queue<pair<int, int>> maxHeap;  // �������� 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // ��������

        for (int i = 0; i < N; i++)
        {
            char op;
            int num;

            cin >> op >> num;

            if (op == 'I')
            {
                maxHeap.push({ num, i });
                minHeap.push({ num, i });

                visited[i] = true;
            }
            else
            {
                if (num == 1)
                {
                    //��ȿ���� ���� ���ڵ� ���� pop
                    while (!maxHeap.empty() && !visited[maxHeap.top().second])
                        maxHeap.pop();

                    if (!maxHeap.empty())
                    {
                        //pop�ϹǷ� ��ȿ���� �ʴٰ� ǥ��
                        visited[maxHeap.top().second] = false;

                        maxHeap.pop();
                    }
                }
                else // D -1
                {
                    while (!minHeap.empty() && !visited[minHeap.top().second])
                        minHeap.pop();

                    if (!minHeap.empty())
                    {
                        visited[minHeap.top().second] = false;

                        minHeap.pop();
                    }
                }
            }
        }

        while (!maxHeap.empty() && !visited[maxHeap.top().second])
            maxHeap.pop();

        while (!minHeap.empty() && !visited[minHeap.top().second])
            minHeap.pop();

        if (minHeap.empty() && maxHeap.empty())
            cout << "EMPTY\n";
        else
            cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
    }

    return 0;
}
