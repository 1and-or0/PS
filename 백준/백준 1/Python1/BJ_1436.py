goal = int(input())

num = 665
count = 0
while count != goal:
    num += 1
    # �̷��� �ϸ� 6�� ���ӵ��� ���� �͵� �������
    # if list(str(num)).count('6') >= 3:
    if "666" in str(num):  # �̷��� �ϸ� ����!
        count += 1
        
print(num)
