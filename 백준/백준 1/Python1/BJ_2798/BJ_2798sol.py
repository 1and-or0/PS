import itertools

N, M = map(int, input().split())
cards = list(map(int, input().split()))

# M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ��
combis = [sum(combi) for combi in itertools.combinations(cards , 3) if sum(combi) <= M]

print(max(combis))  # ���� ��� : M�� �ִ��� ����� ī�� 3���� ��