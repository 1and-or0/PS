#include <iostream>
#include <vector>
using namespace std;

const int n_max = 200000;

// ���� ���� ����
vector<int> stk; // ������ ���� ����
int parent[(n_max+1)/2 + 1]; // ������ ������ �迭 (�ִ� 100,000���� ���)

// ���� �Լ� ����
int main() 
{   // �Է� �� ����� �� ������ �ϱ� ���� ����
    ios::sync_with_stdio(0); cin.tie(0); // cin�� cout�� ����ȭ ����

    int N;
    cin >> N; // ����� �� N �Է�
    int NN = (N + 1) / 2; // ����� ������ ���� (N�� ���� + 1)

    N--; // ù ��° ��Ҹ� �̹� �о����Ƿ� N�� 1 ����

    int x;
    cin >> x; // ù ��° ��� ���� �Է�
    parent[x] = -1; // parent �迭�� �ش� �ε����� -1 �Ҵ�

    stk.emplace_back(x); // ù ��° ��带 ���ÿ� �߰�

    // N���� ��忡 ���� �ݺ�
    while (N--) 
    {
        cin >> x; // ���� ��� ���� �Է�
        // ���� ��� x�� ������ ��� ���� ���� ���
        if (x == parent[stk.back()]) 
        {
            stk.pop_back(); // ���ÿ��� ������ ��� ����
        }
        else 
        {
            parent[x] = stk.back();

            // ���� ��� x�� ���ÿ� �߰�
            stk.emplace_back(x);
        }
    }

    // ���� ���� NN ���
    cout << NN << '\n';
    // ���� �迭�� ������ ���
    for (int i = 0; i < NN; i++)
        cout << parent[i] << ' '; // �� ������ �������� �����Ͽ� ���

    return 0;
}
