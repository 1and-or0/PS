# DFS�� Ư�� ��带 �湮�ϰ� ����� ��� ���鵵 �湮
def dfs(x, y):
    # �־��� ����(�ε���)�� ��� ���, ����
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False

    # ���� ��带 ���� �湮���� �ʾҴٸ� 
    if graph[x][y] == 0:
        # �ش� ��� �湮ó��
        graph[x][y] = 1
        # �����¿� ��ġ�鵵 ��� ����� ȣ��...
        dfs(x-1, y)
        dfs(x+1, y)
        dfs(x, y-1)
        dfs(x, y+1)
        return True

    return False


# n, m�� ���� �������� ����, �Է� �ޱ�
n, m = map(int, input().split())

# 2���� ����Ʈ�� �� ���� �Է� �ޱ�
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

# ��� ���(��ġ)�� ���� ����� ä���
result = 0
for i in range(n):
    for j in range(m):
        # ���� ��ġ���� DFS ����
        if dfs(i, j) == True:
            result += 1


print(result)
