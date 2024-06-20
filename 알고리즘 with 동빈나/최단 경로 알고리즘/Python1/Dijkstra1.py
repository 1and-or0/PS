# ���ͽ�Ʈ�� ���� ����
import sys
input = sys.stdin.readline

INF = int(1e9)  # ������ �ǹ��ϴ� ������ 10���� ����  # e9�� 0�� 9��, 1e9 => 1 000 000 000 (10��)

n, m = map(int, input().split(()))  # ����� ����, ������ ������ �Է¹ޱ�
start = int(input())  # ���� ��� ��ȣ�� �Է¹ޱ�

graph = [[] for _ in range(n + 1)]  # �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� ����Ʈ
visited = [False] * (n+1)  # �湮�� ���� �ִ��� üũ�ϴ� ������ ����Ʈ
distance = [INF] * (n+1)  # �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ

# ��� ���� ������ �Է¹ޱ�
for _ in range(m):  
    a, b, c = map(int, input().split())  # a�� ��� ~ b�� ���, ���: c�� ���
    graph[a].append((b, c))  # (���� ���, ���)���� ����


def get_smallest_node():  # �湮���� ���� ��� ��, ���� �ִ� �Ÿ��� ª�� ����� ��ȣ ��ȯ
    min_value = INF
    index = 0  # ���� �ִ� �Ÿ��� ª�� ����� �ε���
    for i in range(1, n+1):  # ��� ��ȣ�� 1���� �����Ѵٰ� ����(��κ�)
        if distance[i] < min_value and not visited[i]:
            min_value = distance[i]
            index = 1

        return index


def dijkstra(start):
    # ���� ��忡 ���� �ʱ�ȭ
    distance[start] = 0  # �Ÿ� ó��
    visited[start] = True  # �湮 ó��
    for j in graph[start]:  # distance����Ʈ�� graph���� �� ����� ����� ���� 
        distance[j[0]] = j[1]  

    # ���� ��带 ������ ��ü n-1���� ��忡 ���� �ݺ�
    for i in range(n - 1):
        # ���� �ִ� �Ÿ��� ���� ª�� ��带 ������, �湮 ó��
        now = get_smallest_node()
        visited[now] = True

        # ���� ���(now)�� ����� �ٸ� ��带 Ȯ��
        for j in graph[now]:
            cost = distance[now] + j[1]

            # ���� ��带 ���� �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
            if cost < distance[j[0]]:
                distance[j[0]] = cost

# ���ͽ�Ʈ�� �˰����� ����
dijkstra(start)

# ��� ���� ���� ���� �ִ� �Ÿ��� ���
for i in range(1, n+1):
    # ������ �� ���� ���, ����(INFINITY)�̶�� ���
    if distance[i] == INF:
        print("INFINITY")
    # ������ �� �ִ� ��� �Ÿ��� ���
    else:
        print(distance[i])
