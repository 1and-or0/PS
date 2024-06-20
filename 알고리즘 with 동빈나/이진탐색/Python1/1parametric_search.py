# �����̳� ���� ���ܱ�

# ���� ���̰� 19, 17, 14, 10
# �մ��� ��û�� ���� 6
# ���ܱ� ���� 15
# �ٲ� ���� ���� 15, 15, 14, 10 �߷� ���� ���� ���� 4, 2, �� 6

# �մ��� ��û�� ���̸� �Է¹ް� ��� �� ��ŭ�� ���� �ڸ�������
# ���ܱ� ������ �ִ��� ���ϱ�

request = int(input())

basic_ddack = list(map(int, input().split()))

# ���� ������ �ذ� ���̵�� 
# ���� ���̸� �Է¹��� ����Ʈ����, ���� Ž���� �����ϸ� ���� ������ ����
# �׷��� �߷����� ���� ���̰� �մ��� ��û�� ���� ���̺��� ũ�ų� ���� ��
# �� ã�ư���

basic_ddack.sort()
ddack = [dd for dd in basic_ddack]

start = 0
end = len(basic_ddack) - 1
while start <= end:
    mid = (start + end) // 2
    h = basic_ddack[mid]
    for i in range(start, end+1):
        if basic_ddack[i] > h:
            ddack[i] = basic_ddack[i] - h

    if sum(ddack) == request:
        break
    elif sum(ddack) < request:
        end = mid - 1
    elif sum(ddack) > request:
        start = mid + 1

        
print()