from bisect import bisect_left, bisect_right
# _left�� ���Ұ� ���Ե� �� �ִ� ���� ���� �ε��� ��ȯ
# _right�� ���Ұ� ���Ե� �� �ִ� ���� ������ �ε��� ��ȯ
a = [1, 2, 4, 4, 8]
x = 4

print(bisect_right(a, 4))
print(a)
a.insert(bisect_right(a, 4), x)

print(bisect_left(a, 4))
print(a)

# Ư�� ������ ���ϴ� ������ ���� ���ϱ�
# ���� [left_value, right_value]�� ������ ������ ��ȯ�ϴ� �Լ�
def count_by_range(a, left_val, right_val):
    right_index = bisect_right(a, right_val)
    left_index = bisect_left(a, left_val)
    return right_index - left_index

