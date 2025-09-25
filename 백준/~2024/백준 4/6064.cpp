#include <iostream>
using namespace std;

// �ִ����� (GCD)�� ���ϴ� �Լ�
int gcd(int a, int b) 
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// �ּҰ���� (LCM)�� ���ϴ� �Լ�
int lcm(int a, int b) 
{
    return a * b / gcd(a, b);
}

int main() 
{
    int T; // �׽�Ʈ ���̽��� ��
    cin >> T;

    while (T--) 
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        // ������ �ذ� �ִ��� ã�� ���� �ݺ�
        bool found = false;
        // M�� �������� x���� ����, LCM(M, N) �ȿ����� Ž��
        int limit = lcm(M, N); // LCM(M, N) �ȿ��� �ظ� ã�´�.
        for (int k = x; k <= limit; k += M) 
        {
            // y�� �����ϴ� �ظ� ã���� ���
            if ((k - 1) % N + 1 == y) 
            {
                cout << k << '\n';
                found = true;
                break;
            }
        }

        // �ظ� ã�� �������� -1 ���
        if (!found) 
        {
            cout << -1 << '\n';
        }
    }

    return 0;
}
