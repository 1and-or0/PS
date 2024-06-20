from collections import deque

# BFS �Լ� ����
def bfs(graph, start, visited):
    queue = deque([start])
    # print(type([start]))
    # ���� ��带 �湮 ó��
    visited[start] = True
    
    while queue:
        v = queue.popleft()
        print(v, end=' ')

        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

    
visited = [False] * 9

graph = [
    [],  # 0�� ���... ����...
    [2, 3, 8],  # 1�� ���� ������ ���        ____ 1______
    [1, 7],  # 2�� ���� ������ ���         _2    _3_     8
    [1, 4, 5],  # 3�� ���� ������ ���    _7     4---5   /  
    [3, 5],  #                           6  \___________/ 
    [3, 4],
    [7],
    [2, 6, 8],
    [1, 7]
]

bfs(graph, 1, visited)
