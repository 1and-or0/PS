n = 1260
count = 0

# ū ������ ȭ����� ���ʴ�� ȭ���ϱ�
array = [500, 100, 50, 10]

for coin in array:
    count += n // coin  # �ش� ȭ��� �Ž��� �� �� �ִ� ������ ���� ����
    n %= coin

print(count)
