#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

// Find �Լ�: �θ� ����Ʈ ã��
int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]); // ��� ����
}

// Union �Լ�: �� ���� ����
void unionGate(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        parent[x] = y; // x�� �θ� y�� ����
    }
}

int main()
{
    int G, P;
    cin >> G >> P;

    parent.resize(G + 1);
    for (int i = 1; i <= G; i++)
    {
        parent[i] = i; // �ʱ�ȭ: �� ����Ʈ�� �ڱ� �ڽ��� �θ�� ����
    }

    int count = 0;
    for (int i = 0; i < P; i++)
    {
        int gi;
        cin >> gi;

        int dockingGate = find(gi); // ���� ������ ���� ū ����Ʈ ã��
        if (dockingGate == 0)
        {
            break; // �� �̻� ��ŷ�� ����Ʈ�� ����
        }

        unionGate(dockingGate, dockingGate - 1); // ��ŷ �� ����Ʈ ����
        count++;
    }

    cout << count << endl;
    return 0;
}
