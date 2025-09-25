#include <iostream>
#include <algorithm>
using namespace std;

// �� ũ������ ���� ��ġ�� �����ϴ� �迭
int crane_positions[51] = { 0 };

// ũ������ �ִ� ���緮�� �����ϴ� �迭
int crane_capacities[51];

// ������ �湮 ���θ� Ȯ���ϴ� �迭
bool box_moved[10001] = { 0 };

// ������ ���Ը� �����ϴ� �迭
int box_weights[10001];

// ũ���ΰ� ������ ������ ��Ÿ���� ����, ���ڰ� ��� �Ű������� Ȯ���ϴ� ����, ũ���� �ִ� ���緮
int num_cranes, num_boxes, moved_boxes_count = 0, max_crane_capacity = 0;

int main()
{
    int time = 0;  // ��� ���ڸ� �ű�� �� �ɸ��� �ð�

    // ũ������ ���� �ִ� ���緮 �Է� �ޱ�
    cin >> num_cranes;
    for (int i = 0; i < num_cranes; i++)
    {
        cin >> crane_capacities[i];
        if (crane_capacities[i] > max_crane_capacity)
            max_crane_capacity = crane_capacities[i];
    }

    // ������ ���� �� ������ ���� �Է� �ޱ�
    cin >> num_boxes;
    for (int i = 0; i < num_boxes; i++)
        cin >> box_weights[i];

    // ���ڸ� ���� �������� �������� ���� (���ſ� ���ڸ� ���� ó��)
    sort(box_weights, box_weights + num_boxes, greater<>());

    // ũ���� �ִ� ���緮���� ���ſ� ���ڰ� ������ �Ұ����� ����̹Ƿ� -1 ���
    if (box_weights[0] > max_crane_capacity)
    {
        cout << -1;
        return 0;
    }

    // ��� ���ڸ� �ű� ������ �ݺ�
    while (moved_boxes_count != num_boxes)
    {
        for (int i = 0; i < num_cranes; i++)
        {
            // ũ������ �ű� �� �ִ� ���ڸ� ã�� �ݺ���
            for (int j = crane_positions[i]; j < num_boxes; j++)
            {
                // �ش� ���ڰ� ���� �Ű����� �ʾҰ�, ũ������ �ű� �� �ִ� ���Զ��
                if (!box_moved[j] && crane_capacities[i] >= box_weights[j])
                {
                    box_moved[j] = true;   // ���ڸ� �ű� ǥ��
                    moved_boxes_count++;   // �ű� ���� �� ����
                    break;                 // ���� ũ������ ���� ���ڷ� �̵�
                }
                crane_positions[i]++;      // ���� ũ���� ��ġ ����
            }
        }
        time++;  // �� ���� �۾��� ������ �ð� ����
    }

    // ��� ���ڸ� �ű�� �� �ɸ� �ð� ���
    cout << time;
    return 0;
}
